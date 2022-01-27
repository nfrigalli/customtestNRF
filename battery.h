#ifndef BATTERY_H__
#define BATTERY_H__

#include "nrf.h"
#include "nrf_soc.h"
#include "nrf_drv_saadc.h"
#include "sdk_macros.h"
#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_bas.h"
#include "ble_srv_common.h"
#include "nrf_log.h"

/**@brief Macro to convert the result of ADC conversion in millivolts.
 *
 * @param[in]  ADC_VALUE   ADC result.
 *
 * @retval     Result converted to millivolts.
 */
#define ADC_RESULT_IN_MILLI_VOLTS(ADC_VALUE)\
        ((((ADC_VALUE) * ADC_REF_VOLTAGE_IN_MILLIVOLTS) / ADC_RES_10BIT) * ADC_PRE_SCALING_COMPENSATION)

#define BATTERY_LEVEL_MEAS_INTERVAL     APP_TIMER_TICKS(10000)                 /**< Battery level measurement interval (ticks).*/
#define ADC_REF_VOLTAGE_IN_MILLIVOLTS   600                                     /**< Reference voltage (in milli volts) used by ADC while doing conversion. */
#define ADC_PRE_SCALING_COMPENSATION    6                                       /**< The ADC is configured to use VDD with 1/3 prescaling as input. And hence the result of conversion is to be multiplied by 3 to get the actual value of the battery voltage.*/
#define DIODE_FWD_VOLT_DROP_MILLIVOLTS  270                                     /**< Typical forward voltage drop of the diode . */
#define ADC_RES_10BIT                   1024                                    /**< Maximum digital value for 10-bit ADC conversion. */

/**@brief Function for handling the ADC interrupt.
 *
 * @details  This function will fetch the conversion result from the ADC, convert the value into
 *           percentage and send it to peer.
 */
void saadc_event_handler(nrf_drv_saadc_evt_t const * p_event);

/**@brief Function for handling the Battery measurement timer timeout.
 *
 * @details This function will be called each time the battery level measurement timer expires.
 *          This function will start the ADC.
 *
 * @param[in] p_context   Pointer used for passing some arbitrary information (context) from the
 *                        app_start_timer() call to the timeout handler.
 */
void battery_level_meas_timeout_handler(void * p_context);


/**@brief Function for configuring ADC to do battery level conversion.
 */
void adc_configure(void);

/**@brief Function for initializing the Battery Service.
 */
uint32_t service_bas_init(ble_bas_t * m_bas, const ble_bas_init_t * b_bas_init);

#endif