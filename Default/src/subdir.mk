################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/alignPairSemiGlobal.cpp \
../src/chromLenListToIncludeEdgesBed.cpp \
../src/singletonsFromChromPosList.cpp \
../src/test1.cpp 

BCS += \
./src/alignPairSemiGlobal.bc \
./src/chromLenListToIncludeEdgesBed.bc \
./src/singletonsFromChromPosList.bc \
./src/test1.bc 

CPP_DEPS += \
./src/alignPairSemiGlobal.d \
./src/chromLenListToIncludeEdgesBed.d \
./src/singletonsFromChromPosList.d \
./src/test1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.bc: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: LLVM Clang++'
	clang++ -I/usr/local/include -I"/Users/jstjohn/Programming/cscripts/seqan-1.3.1" -O2 -emit-llvm -g -Wall -c -fmessage-length=0 -MMD -MP -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


