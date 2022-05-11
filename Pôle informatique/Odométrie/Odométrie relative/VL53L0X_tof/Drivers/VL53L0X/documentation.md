# Documentation for VL53L0X Driver

## Parameters

### Set the STM reference

all the parameters files are in `Implementation` folder

* In the file `TOF_STM_Reference.h`, change the include to point the right reference. For a STM32F303K8T6, the file will be `stm32f3xxx.h`

* In the file `TOF_Units.h` set one enum value for each sensor
* In the file `TOF_Units.c` declare as extern variable the hi2c handler
* In the file `TOF_Units.c` declare every devices with this template :
```c
		{
				.Id = TOF_UNIT_NAME,
				.I2cHandle = &hi2c1,
				.XSHUT_Port = TOF_X_XSHUT_GPIO_Port,
				.XSHUT_Pin = TOF_X_XSHUT_Pin
		}
```