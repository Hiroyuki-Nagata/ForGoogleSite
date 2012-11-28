#============================================================================
# Author      : Hiroyuki Nagata
# Version     : 1.0.0
# Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
# Description : wxHtmlWindow test in wxWidgets with Japanese
# Licence     : wxWindows Library Licence, Version 3.1
#============================================================================

# target and sources
CXX		= g++ -O2 -Wall
TARGET	= HtmlWindowTest
SOURCES = $(notdir $(shell find . -name '*.cpp'))
OBJECTS = $(SOURCES:.cpp=.o)

# dependency
DEP		= dep

# basic command
RM		= rm

# compile option
CXXFLAGS = `wx-config --cxxflags`
LDFLAGS	 = `wx-config --libs` -static

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