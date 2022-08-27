################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/01-MCAL/Dio/Src/Dio.c 

OBJS += \
./Source/01-MCAL/Dio/Src/Dio.o 

C_DEPS += \
./Source/01-MCAL/Dio/Src/Dio.d 


# Each subdirectory must supply rules for building sources it contributes
Source/01-MCAL/Dio/Src/%.o: ../Source/01-MCAL/Dio/Src/%.c Source/01-MCAL/Dio/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\Oct20_Embdded\Source\01-MCAL\Dio\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\Led\Inc" -I"F:\Oct20_Embdded\Source\00-Lib" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


