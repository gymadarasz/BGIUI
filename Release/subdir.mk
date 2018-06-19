################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Button.cpp \
../Canvas.cpp \
../Cursor.cpp \
../GUITest.cpp \
../Keyboard.cpp \
../Label.cpp \
../Mouse.cpp \
../Painter.cpp \
../Scroll.cpp \
../ScrollAreaCanvas.cpp \
../ScrollHandlerCanvas.cpp \
../ScrollMinusButton.cpp \
../ScrollPlusButton.cpp \
../Switch.cpp \
../Window.cpp \
../main.cpp 

OBJS += \
./Button.o \
./Canvas.o \
./Cursor.o \
./GUITest.o \
./Keyboard.o \
./Label.o \
./Mouse.o \
./Painter.o \
./Scroll.o \
./ScrollAreaCanvas.o \
./ScrollHandlerCanvas.o \
./ScrollMinusButton.o \
./ScrollPlusButton.o \
./Switch.o \
./Window.o \
./main.o 

CPP_DEPS += \
./Button.d \
./Canvas.d \
./Cursor.d \
./GUITest.d \
./Keyboard.d \
./Label.d \
./Mouse.d \
./Painter.d \
./Scroll.d \
./ScrollAreaCanvas.d \
./ScrollHandlerCanvas.d \
./ScrollMinusButton.d \
./ScrollPlusButton.d \
./Switch.d \
./Window.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


