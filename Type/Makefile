#============================================================================
# Author      : Hiroyuki Nagata
# Version     : 1.0.0
# Copyright   : Copyright (C) 2014 Hiroyuki Nagata, All rights reserved.
# Description : Type test...
# Licence     : wxWindows Library Licence, Version 3.1
#============================================================================

# target and sources
CXX	= g++ -O2 -Wall
TARGET	= type
SOURCES = $(notdir $(shell find . -name '*.cpp'))
OBJECTS = $(SOURCES:.cpp=.o)

# dependency
DEP	= dep

# basic command
RM	= rm

# make all
all : $(DEP) $(TARGET)
$(TARGET): $(OBJECTS)
		$(CXX) $^ -o $@ $(LDFLAGS)
# suffix rule
.SUFFIXES: .cpp .o
.cpp.o:
		$(CXX) $(CXXFLAGS) -c $<
# make dependency
dep:
	$(CXX) -MM -MG $(SOURCES) >makefile.dep

clean:
	$(RM) -f *.o $(TARGET).exe

run:
	./$(TARGET)