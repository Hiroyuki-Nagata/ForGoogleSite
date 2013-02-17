# target and sources
TARGET  = TreeCtrlTest
SOURCES = $(notdir $(shell find src/ -name '*.cpp'))
RCS	= $(notdir $(shell find include/ -name '*.rc'))
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS +=$(RCS:.rc=.o)
# sources for dependency
DEPSRCS = $(shell find src/ -name '*.cpp')
DEP	= dep
# basic command
CXX	:= g++ -gstabs
RM 	:= rm
WINDRES := windres
MAKE	:= make

# compile option
CXXFLAGS = -Wall `wx-config --cxxflags` -I include
LDFLAGS  = -static -lwx_mswu_aui-2.9 `wx-config --libs`
RCFLAGS  = $(shell wx-config --cxxflags | awk '{ print $$2 }')
VPATH	 = include src

# dummy target
.PHONY	: all clean

# make all
all : $(DEP) $(TARGET)
$(TARGET): $(OBJECTS)
		$(CXX) $^ -o $@ $(LDFLAGS)
# suffix rule
.SUFFIXES: .cpp .o
.cpp.o:
		$(CXX) $(CXXFLAGS) -c $<
# icon build
sample.o : sample.rc
		$(WINDRES) -i $^ -O coff -o $@  $(RCFLAGS)
# make dependency
dep:
	$(CXX) -MM -MG $(DEPSRCS) >makefile.dep
# make clean
.PHONY: clean
clean:
	rm -f *.o *.exe *.dep
