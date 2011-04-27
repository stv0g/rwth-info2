################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cramer.cpp \
../src/Gauss.cpp \
../src/LGSLoeser.cpp \
../src/LR.cpp \
../src/QMatrix.cpp \
../src/Vektor.cpp \
../src/main.cpp 

OBJS += \
./src/Cramer.o \
./src/Gauss.o \
./src/LGSLoeser.o \
./src/LR.o \
./src/QMatrix.o \
./src/Vektor.o \
./src/main.o 

CPP_DEPS += \
./src/Cramer.d \
./src/Gauss.d \
./src/LGSLoeser.d \
./src/LR.d \
./src/QMatrix.d \
./src/Vektor.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


