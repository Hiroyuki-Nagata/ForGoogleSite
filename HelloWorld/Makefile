#============================================================================
# Author      : http://nantonaku-shiawase.hatenablog.com/
# Version     : 1.0.0
# Copyright   : Common Public License
# Description : Hello World in wxWidgets with Japanese
#============================================================================

# target and sources
CXX		= g++ -O2 -Wall
TARGET	= HelloWorld
OBJECTS = Main.o HelloWorld.o

# basic command
RM		= rm

# make all
all : $(TARGET)

$(TARGET) : $(OBJECTS) 
		$(CXX) $(OBJECTS) -o $(TARGET) `wx-config --libs`

HelloWorld.o : HelloWorld.h
		$(CXX) -c HelloWorld.cpp `wx-config --cxxflags`

Main.o : HelloWorld.h
		$(CXX) -c Main.cpp `wx-config --cxxflags`

clean:
	$(RM) -f *.o $(TARGET).exe