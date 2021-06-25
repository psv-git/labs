.PHONY:	task	test	clean


##### TARGET
TASK_TARGET=task4
TEST_TARGET=test

##### LIBS
TASK_LIBS=
TEST_LIBS=-lboost_unit_test_framework

##### COMPILER
CXX:=clang++
CXXFLAGS:=-std=c++11

##### LINKER
LD:=$(CXX)
LDFLAGS=-Wl, -Bdynamic $(TEST_LIBS)

##### DIRECTORIES
LIBS_DIR:=./src/libs/
TASK_DIR:=./src/task/
TEST_DIR:=./src/test/
BUILD_DIR:=./build/


## custom function to recursive find files into directory
rwfind=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwfind,$d/,$2))

TASK_SOURCES:=$(call rwfind,$(TASK_DIR),*.cpp)$(call rwfind,$(LIBS_DIR),*.cpp)
TEST_SOURCES:=$(call rwfind,$(TEST_DIR),*.cpp)$(call rwfind,$(LIBS_DIR),*.cpp)
TASK_OBJECTS:=$(addprefix $(BUILD_DIR),$(patsubst %.cpp,%.o,$(notdir $(TASK_SOURCES))))
TEST_OBJECTS:=$(addprefix $(BUILD_DIR),$(patsubst %.cpp,%.o,$(notdir $(TEST_SOURCES))))
VPATH:=$(sort $(dir $(TASK_SOURCES))) $(sort $(dir $(TEST_SOURCES)))

PCH_H:=$(TASK_DIR)stdafx.h
ifeq ($(CXX),g++)
	PCH=$(PCH_H).gch
else
	PCH=$(PCH_H).pch
endif


##### BUILD TASK
task:	$(BUILD_DIR)$(TASK_TARGET)
	@echo	"DONE!"

$(BUILD_DIR)$(TASK_TARGET):	$(TASK_OBJECTS)
	$(LD)	$^	-o	$@


##### BUILD TEST
test:	$(BUILD_DIR)$(TEST_TARGET)
	@echo	"DONE!"

$(BUILD_DIR)$(TEST_TARGET):	$(TEST_OBJECTS)
	$(LD)	$^	-o	$@	$(LDFLAGS)


##### MAKE OBJECTS
$(BUILD_DIR)%.o:	%.cpp	$(PCH)
	$(CXX)	$(CXXFLAGS)	-include	$(PCH_H)	$<	-c	-o	$@

$(PCH):	$(PCH_H)
	$(CXX)	$(CXXFLAGS)	-x	c++-header	$<	-o	$@


##### CLEAN
clean:
	@rm	-f	$(PCH)	$(GCH)
	@find $(BUILD_DIR) -type f -name "*" -delete
