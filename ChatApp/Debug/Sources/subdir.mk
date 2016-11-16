################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/ChatClient.cpp 

OBJS += \
./Sources/ChatClient.o 

CPP_DEPS += \
./Sources/ChatClient.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__cplusplus=201103L -I/usr/include/c++/4.8.4 -include"/home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatMessage.h" -O0 -g3 -Wall -std=c++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


