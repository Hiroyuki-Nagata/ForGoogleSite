# Makefile
TARGET 	= VirtualListTest
SOURCES = $(shell find . -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)
# sources for dependency
DEPSRCS = $(shell find . -name '*.cpp')
DEP	= dep

# basic command
RM 	:= rm
CXX 	:= g++ -s

# basic option
CXXFLAGS = -Wall -I . `wx-config --cxxflags`
LDFLAGS  = `wx-config --libs base,core,aui`
# dummy target
.PHONY	: clean
# suffix rule
.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<
# make dependency
dep:
	$(CXX) -MM -MG $(DEPSRCS) >makefile.dep
# make all
all : $(DEP) $(OBJECTS) $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)
# clean
clean:
	$(RM) -f *.o $(TARGET) makefile.dep