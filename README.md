# Project Description

    Write firmware to create BLE custom service with 128 bytes of UUID. This will have 1 custom service and 1 custom characteristic
    Send 50 bytes of dummy data every 5 seconds over this custom characteristics in 1 chunk of data (1 payload should contain at least 50 dummy bytes)
    Create/use BLE SIG battery service and send battery voltage (read battery voltage from power pin) every 10 seconds over this service.

Starting from this [Example](https://github.com/bjornspockeli/custom_ble_service_example) for target [SparkFun Pro nRF52840 Mini - Bluetooth Development Board](https://www.sparkfun.com/products/15025)
