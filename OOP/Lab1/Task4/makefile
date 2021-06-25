.PHONY:	all	clean

##### USER VAR
TARGET:=rle
CXX=clang++
LIBS:=
SOURCE_DIR:=./src/
BUILD_DIR:=./build/


##### STANDARD VAR
CXXFLAGS:=-std=c++11
LDFLAGS:=$(LIBS)

## recursive find files into directory
rwfind=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwfind,$d/,$2))

SOURCES:=$(call rwfind,$(SOURCE_DIR),*.cpp)
OBJECTS:=$(addprefix $(BUILD_DIR),$(patsubst %.cpp,%.o,$(notdir $(SOURCES))))
VPATH:=$(sort $(dir $(SOURCES)))

PCH_H:=$(SOURCE_DIR)stdafx.h
ifeq ($(CXX),g++)
	PCH=$(PCH_H).gch
else
	PCH=$(PCH_H).pch
endif


##### BUILD
all:	$(BUILD_DIR)$(TARGET)
	@echo	"DONE!"

$(BUILD_DIR)$(TARGET):	$(OBJECTS)
	$(CXX)	$(LDFLAGS)	$^	-o	$@

$(BUILD_DIR)%.o:	%.cpp	$(PCH)
	$(CXX)	$(CXXFLAGS)	-include	$(PCH_H)	$<	-c	-o	$@

$(PCH):	$(PCH_H)
	$(CXX)	$(CXXFLAGS)	-x	c++-header	$<	-o	$@


##### CLEAN (NOT WORK FOR WINDOWS)
clean:
	@rm	-f	$(BUILD_DIR)$(TARGET)	$(PCH)	$(GCH)
	@find ./ -type f -name "*.o" -delete
