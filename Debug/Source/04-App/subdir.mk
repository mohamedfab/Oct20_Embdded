################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/04-App/main.c 

OBJS += \
./Source/04-App/main.o 

C_DEPS += \
./Source/04-App/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source/04-App/%.o: ../Source/04-App/%.c Source/04-App/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\Oct20_Embdded\Source\01-MCAL\Dio\Inc" -I"F:\Oct20_Embdded\Source\02-ECUA\Led\Inc" -I"F:\Oct20_Embdded\Source\00-Lib" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

