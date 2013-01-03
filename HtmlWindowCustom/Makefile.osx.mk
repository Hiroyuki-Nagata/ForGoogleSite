#============================================================================
# Author      : Hiroyuki Nagata
# Version     : 1.0.0
# Copyright   : Copyright (C) 2013 Hiroyuki Nagata, All rights reserved.
# Description : wxHtmlWindow test in wxWidgets with Japanese
# Licence     : wxWindows Library Licence, Version 3.1
#============================================================================

# target and sources
TARGET  = HtmlWindowCustom
SOURCES = $(notdir $(shell find . -name '*.cpp'))
OBJECTS = $(SOURCES:.cpp=.o)

# sources for dependency
DEPSRCS = $(shell find . -name '*.cpp')
DEP		= dep

# setting for Mac
OUTPUTPATH	= .
PROGRAM		= $(TARGET)
PROGVER		= 1.0
ICONPATH	= wxmac.icns
ICON		= wxmac.icns

# Info.plist用の設定
COMPANY			= Hiroyuki Nagata
BUNDLEPACKAGE	= APPL
BUNDLESIGNATURE	= ????

# application bundle用の設定
BUNDLE			=$(OUTPUTPATH)/$(PROGRAM).app
MACPKGINFO		=$(BUNDLE)/Contents/PkgInfo
MACINFOPLIST	=$(BUNDLE)/Contents/Info.plist 

# depend library
LIBNKF	= libwxnkf.a
NKFDIR	= libwxnkf

# basic command
CXX		:= g++ -m64
RM 		:= rm
MAKE	:= make

# オプション
CXXFLAGS = -Wall -I include `wx-config --cxxflags`
LDFLAGS  = /usr/lib/libwx_osx_cocoau_aui-2.9.a `wx-config --libs` -L/usr/lib

# debug and release
CXX_DEBUG_FLAGS		=	-gstabs
CXX_RELEASE_FLAGS	=	-s -O2

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
	@echo "   <string>$(PROGRAM)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleIconFile</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(ICON)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleName</key>" >> $(MACINFOPLIST)
	@echo "   <string>$(PROGRAM)</string>" >> $(MACINFOPLIST)
	@echo "   <key>CFBundleIdentifier</key>" >> $(MACINFOPLIST)
	@echo "   <string>com.$(COMPANY).$(PROGRAM)</string>" >> $(MACINFOPLIST)
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
	@echo "   <string>$(PROGRAM), Version $(PROGVER), $(COMPANY)</string>" >> $(MACINFOPLIST)
	@echo "</dict>" >> $(MACINFOPLIST)
	@echo "</plist>" >> $(MACINFOPLIST)

# suffix rule
.SUFFIXES: .cpp .o
.cpp.o:
		$(CXX) $(CXXFLAGS) -c $<

# make all
all : $(BUNDLE) $(MACICON) $(MACPKGINFO) $(MACINFOPLIST) $(TARGET)

$(TARGET): $(OBJECTS)
		$(CXX) $^ -o $@ $(LDFLAGS)
		SetFile -t APPL $(PROGRAM)
		cp -f $(TARGET) $(BUNDLE)/Contents/MacOS/$(PROGRAM)

# debug
.PHONY	: Debug
Debug 	: CXX+=$(CXX_DEBUG_FLAGS)
Debug 	: all
# release
.PHONY	: Release
Release	: CXX+=$(CXX_RELEASE_FLAGS)
Release	: all

# clean
clean:
	$(RM) -rf *.o $(TARGET) $(TARGET).app makefile.dep