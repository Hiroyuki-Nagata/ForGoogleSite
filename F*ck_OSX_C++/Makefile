#============================================================================
# Author      : Hiroyuki Nagata
# Version     : 1.0.0
# Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
# Description : Hello World in wxWidgets with Japanese
# Licence     : wxWindows Library Licence, Version 3.1
#============================================================================

# /usr/local/src/wxWidgets/bk-deps clang++-mp-3.3 -isysroot /Developer/SDKs/MacOSX10.7.sdk -mmacosx-version-min=10.7 -c -o minimal_minimal.o -D__WXOSX_COCOA__      -I. -DWXUSINGDLL -I./../../samples -Wall -Wundef -Wunused-parameter -Wno-ctor-dtor-privacy -Woverloaded-virtual -Wno-deprecated-declarations -D_FILE_OFFSET_BITS=64 -I/usr/local/src/wxWidgets/lib/wx/include/osx_cocoa-unicode-2.9 -I../../include -stdlib=libc++ -DWX_PRECOMP -g -O0 -stdlib=libc++ -std=c++11 -DHAVE_TYPE_TRAITS -fno-common  ./minimal.cpp
# clang++-mp-3.3 -isysroot /Developer/SDKs/MacOSX10.7.sdk -mmacosx-version-min=10.7 -o minimal   minimal_minimal.o    -L/usr/local/src/wxWidgets/lib   -stdlib=libc++ -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL   -lwx_osx_cocoau_core-2.9  -lwx_baseu-2.9    -lwxtiff-2.9 -lwxjpeg-2.9 -lwxpng-2.9  -framework WebKit -lwxzlib-2.9 -lwxregexu-2.9 -lwxexpat-2.9 -stdlib=libc++ -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL  -lpthread  -lpthread
# SetFile -t APPL minimal
# mkdir -p minimal.app/Contents
# mkdir -p minimal.app/Contents/MacOS
# mkdir -p minimal.app/Contents/Resources
# sed -e "s/IDENTIFIER/`echo . | sed -e 's,\.\./,,g' | sed -e 's,/,.,g'`/" \
# 	-e "s/EXECUTABLE/minimal/" \
# 	-e "s/VERSION/2.9.5/" \
# 	../../src/osx/carbon/Info.plist.in >minimal.app/Contents/Info.plist
# /bin/echo "APPL????" >minimal.app/Contents/PkgInfo
# ln -f minimal minimal.app/Contents/MacOS/minimal
# cp -f ../../src/osx/carbon/wxmac.icns minimal.app/Contents/Resources/wxmac.icns

# target and sources
TARGET	= hellowx
CXX	= /opt/local/bin/clang++-mp-3.3 -v -isysroot /Developer/SDKs/MacOSX10.7.sdk -mmacosx-version-min=10.7 -O2 -Wall
CXXFLAGS= `wx-config --cxxflags`  `curlpp-config --cflags` -std=c++11 -stdlib=libc++ -DHAVE_TYPE_TRAITS
#-I/usr/local/include/wx-2.9 -D__WXOSX_COCOA__ -DWXUSINGDLL -D_FILE_OFFSET_BITS=64 -I/usr/local/src/wxWidgets/lib/wx/include/osx_cocoa-unicode-2.9 -DWX_PRECOMP -g -O0 -Wundef -Wunused-parameter -Wno-ctor-dtor-privacy -Woverloaded-virtual -Wno-deprecated-declarations -std=c++11 -stdlib=libc++ -DHAVE_TYPE_TRAITS -fno-common
LIBS	= #`wx-config base` -stdlib=libc++ `curlpp-config --libs` -ObjC
-L/usr/local/src/wxWidgets/lib   -stdlib=libc++ -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL   -lwx_osx_cocoau_core-2.9  -lwx_baseu-2.9    -lwxtiff-2.9 -lwxjpeg-2.9 -lwxpng-2.9  -framework WebKit -lwxzlib-2.9 -lwxregexu-2.9 -lwxexpat-2.9 -stdlib=libc++ -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL  -lpthread `curlpp-config --libs`

SOURCES = main.cpp hello.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# basic command
RM	= rm

# dependency
DEP		= dep

# basic command
RM		= rm

# setting for Mac
OUTPUTPATH	= .
PROGVER		= 1.0
ICONPATH	= wxmac.icns
ICON		= wxmac.icns

# Info.plist
COMPANY		= Hiroyuki Nagata
BUNDLEPACKAGE	= APPL
BUNDLESIGNATURE	= ????

# application bundle
BUNDLE		=$(OUTPUTPATH)/$(TARGET).app
MACPKGINFO	=$(BUNDLE)/Contents/PkgInfo
MACINFOPLIST	=$(BUNDLE)/Contents/Info.plist 

# Make all
all : $(DEP) $(BUNDLE) $(MACICON) $(MACPKGINFO) $(MACINFOPLIST) $(TARGET) 

$(TARGET): $(OBJECTS)
		$(CXX) $^ -o $@ $(LIBS)
		SetFile -t APPL $(TARGET)
		cp -f $(TARGET) $(BUNDLE)/Contents/MacOS/$(TARGET)

# suffix rule
.SUFFIXES: .cpp .o
.cpp.o:
		$(CXX) $(CXXFLAGS) -c $<
# make dependency
dep:
	$(CXX) -MM -MG $(SOURCES) >makefile.dep

clean:
	$(RM) -rf *.o $(TARGET) $(BUNDLE)

# dummy target
.PHONY	: Debug Release clean $(BUNDLE) $(MACICON) $(MACPKGINFO) $(MACINFOPLIST)

# Building bundle directory structure
$(BUNDLE):
	mkdir -p $(OUTPUTPATH)
	mkdir -p $(BUNDLE)/Contents
	mkdir -p $(BUNDLE)/Contents/MacOS
	mkdir -p $(BUNDLE)/Contents/Resources

# Copying icon file into bundle
	$(MACICON):
	cp -f $(ICONPATH) $(BUNDLE)/Contents/Resources/$(ICONFILE)

#  This creates the Contents/PkgInfo file.
$(MACPKGINFO):
	touch $(MACPKGINFO)
	@echo "$(BUNDLEPACKAGE)$(BUNDLESIGNATURE)" > $(MACPKGINFO)

#  This creates the Contents/Info.plist file.
$(MACINFOPLIST):
	touch $(MACINFOPLIST)
	@echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" >> $(MACINFOPLIST)
	@echo "<!DOCTYPE plist PUBLIC " >> $(MACINFOPLIST)
	@echo "\"-//Apple Computer//DTD PLIST 1.0//EN\" " >> $(MACINFOPLIST)
	@echo "\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">" >> $(MACINFOPLIST)
	@echo "<plist version=\"1.0\">" >> $(MACINFOPLIST)
	@echo "<dict>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleDevelopmentRegion</key>" >> $(MACINFOPLIST)
	@echo "   <string>English</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleExecutable</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(TARGET)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleIconFile</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(ICON)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleName</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(TARGET)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleIdentifier</key>" >> $(MACINFOPLIST)
	@echo "   <string>com.$(COMPANY).$(TARGET)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleInfoDictionaryVersion</key>" >> $(MACINFOPLIST)
	@echo "   <string>6.0</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundlePackageType</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(BUNDLEPACKAGE)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleSignature</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(BUNDLESIGNATURE)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleVersion</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(PROGVER)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleShortVersionString</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(PROGVER)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleGetInfoString</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(TARGET), Version $(PROGVER), $(COMPANY)</string>" >> $(MACINFOPLIST)
	@echo "</dict>" >> $(MACINFOPLIST)
	@echo "</plist>" >> $(MACINFOPLIST)
