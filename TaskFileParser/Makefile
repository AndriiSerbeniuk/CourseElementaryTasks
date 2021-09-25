CXX      := g++
CXXFLAGS := -std=c++17 -ggdb -Wall

BUILD   := $(shell pwd)/build
SRC     := src
INCLUDE := headers

# LIBRARIES   :=
EXECUTABLE  := app

export BUILD
export CXX
export CXXFLAGS

.PHONY: clean all

all: setup $(BUILD)/*.o
	$(CXX) $(CXXFLAGS) $(shell find $(BUILD)/ -type f -name \*.o) -o $(BUILD)/$(EXECUTABLE)

setup:
	$(MAKE) -C $(SRC)

clean:
	-rm $(BUILD)/*

