# Makefile
TARGET 	= VirtualListTest.exe
OBJECTS = VirtualListTest.o VirtualList.o Main.o

# 基本コマンド
RM 		:= rm
CXX 	:= g++ -gstabs

# 基本オプション
CPPFLAGS = -Wall -I/c/MinGW/include -I include `wx-config --cxxflags`
LDFLAGS  = -static -lwx_mswu_aui-2.9 `wx-config --libs`
VPATH = include src

all : $(TARGET)
$(TARGET) : $(OBJECTS)
		$(CXX) $^ -o $@ $(LDFLAGS)
VirtualList.o : VirtualList.cpp VirtualList.h
		$(CXX) -c $< $(CPPFLAGS)
VirtualListTest.o : VirtualListTest.cpp VirtualListTest.h VirtualList.h
		$(CXX) -c $< $(CPPFLAGS)
Main.o : Main.cpp VirtualListTest.h
		$(CXX) -c $< $(CPPFLAGS)

# make clean
.PHONY: clean
clean:
	rm -f *.o *.exe