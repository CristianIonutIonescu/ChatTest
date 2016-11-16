################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatMessage.cpp \
/home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatRoom.cpp \
/home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatServer.cpp \
/home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatSession.cpp 

OBJS += \
./SourcesChatServer/ChatMessage.o \
./SourcesChatServer/ChatRoom.o \
./SourcesChatServer/ChatServer.o \
./SourcesChatServer/ChatSession.o 

CPP_DEPS += \
./SourcesChatServer/ChatMessage.d \
./SourcesChatServer/ChatRoom.d \
./SourcesChatServer/ChatServer.d \
./SourcesChatServer/ChatSession.d 


# Each subdirectory must supply rules for building sources it contributes
SourcesChatServer/ChatMessage.o: /home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatMessage.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__cplusplus=201103L -I/usr/include/c++/4.8.4 -O0 -g3 -Wall -std=c++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SourcesChatServer/ChatRoom.o: /home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatRoom.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__cplusplus=201103L -I/usr/include/c++/4.8.4 -O0 -g3 -Wall -std=c++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SourcesChatServer/ChatServer.o: /home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatServer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__cplusplus=201103L -I/usr/include/c++/4.8.4 -O0 -g3 -Wall -std=c++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SourcesChatServer/ChatSession.o: /home/cionescu/workspace/ChatProj/ChatServer/Sources/ChatSession.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__cplusplus=201103L -I/usr/include/c++/4.8.4 -O0 -g3 -Wall -std=c++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


