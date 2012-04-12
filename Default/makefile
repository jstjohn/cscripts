################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(BC_DEPS)),)
-include $(BC_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LLVM_EXECUTABLES += \
USER_OBJS.exe \


# All Target
all: cscripts secondary-outputs

# Tool invocations
cscripts: $(BCS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: LLVM C++ linker'
	llvm-ld -v -L/usr/local/lib -o "cscripts" $(BCS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

USER_OBJS.exe: cscripts $(BCS) $(USER_OBJS)

# Other Targets
clean:
	-$(RM) $(BCS)$(C++_DEPS)$(CC_DEPS)$(CPP_DEPS)$(BC_DEPS)$(LLVM_EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS)$(LLVM_BC_EXECUTABLES) cscripts
	-@echo ' '

secondary-outputs: $(LLVM_BC_EXECUTABLES)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
