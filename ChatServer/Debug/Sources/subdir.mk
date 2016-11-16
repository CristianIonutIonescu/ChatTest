################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/ChatMessage.cpp \
../Sources/ChatRoom.cpp \
../Sources/ChatServer.cpp \
../Sources/ChatSession.cpp 

OBJS += \
./Sources/ChatMessage.o \
./Sources/ChatRoom.o \
./Sources/ChatServer.o \
./Sources/ChatSession.o 

CPP_DEPS += \
./Sources/ChatMessage.d \
./Sources/ChatRoom.d \
./Sources/ChatServer.d \
./Sources/ChatSession.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -D__cplusplus=201103L -O0 -g3 -Wall -std=c++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


