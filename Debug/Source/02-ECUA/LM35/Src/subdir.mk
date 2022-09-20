################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/02-ECUA/LM35/Src/Lm35.c 

OBJS += \
./Source/02-ECUA/LM35/Src/Lm35.o 

C_DEPS += \
./Source/02-ECUA/LM35/Src/Lm35.d 


# Each subdirectory must supply rules for building sources it contributes
Source/02-ECUA/LM35/Src/%.o: ../Source/02-ECUA/LM35/Src/%.c Source/02-ECUA/LM35/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\Oct20_Embdded\Source\01-MCAL\Dio\Inc" -I"F:\Oct20_Embdded\Source\01-MCAL\SPI\Inc" -I"F:\Oct20_Embdded\Source\01-MCAL\Timer0\Inc" -I"F:\Oct20_Embdded\Source\01-MCAL\UART\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\DC_Motor\Inc" -I"F:\Oct20_Embdded\Source\01-MCAL\ADC\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\LM35\Inc" -I"F:\Oct20_Embdded\Source\01-MCAL\EXTINT\Inc" -I"F:\Oct20_Embdded\Source\01-MCAL\GINT\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\Keypad\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\LCD\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\SSD\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\Button\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\Led\Inc" -I"F:\Oct20_Embdded\Source\00-Lib" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


