#============================================================================
# Author      : Hiroyuki Nagata
# Version     : 1.0.0
# Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
# Description : Hello World in wxWidgets with Japanese
# Licence     : wxWindows Library Licence, Version 3.1
#============================================================================

# target and sources
CXX	= g++ -O2 -Wall -std=c++11
TARGET	= HelloWorld
OBJECTS = Main.o HelloWorld.o

# basic command
RM	= rm
ifeq ($(OS), Windows_NT)
    EXT := .exe
else
    EXT :=
endif

# make all
all : $(TARGET)

$(TARGET) : $(OBJECTS)
		$(CXX) $(OBJECTS) -o $(TARGET) `wx-config --libs`

HelloWorld.o : HelloWorld.h LockedQueue.hpp
		$(CXX) -c HelloWorld.cpp `wx-config --cxxflags`

Main.o : HelloWorld.h
		$(CXX) -c Main.cpp `wx-config --cxxflags`

clean:
	$(RM) -f *.o $(TARGET) $(TARGET)$(EXT)
