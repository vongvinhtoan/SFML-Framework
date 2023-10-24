# Compiler
CC := .\compiler\mingw64\bin\g++
# Compiler flags
CFLAGS := -std=c++17
# Include directories
INCLUDES := -I"./libs/SFML-2.5.1/include" -I"./libs/jsoncpp" -I"./include"
# Library directories
LFLAGS := -L"./libs/SFML-2.5.1/lib"
# Libraries
LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lcomdlg32
# Source files
SRCS := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard libs/jsoncpp/*.cpp)
# Executable name
MAIN := ./bin/RoadCrossing.exe

.PHONY: all clean

all: $(MAIN)
	@echo Compilation successful!

$(MAIN): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) $^ -o $@ $(LIBS) 
