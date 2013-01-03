#sh-3.2# make

#　.cppファイルのオブジェクトコード化
#/usr/local/src/wxWidgets-2.9.4/bk-deps g++ -mmacosx-version-min=10.6 -c -o minimal_minimal.o -D__WXOSX_COCOA__      -I.  -I./../../samples -Wall -Wundef -Wunused-parameter -Wno-ctor-dtor-privacy -Woverloaded-virtual -Wno-deprecated-declarations -D_FILE_OFFSET_BITS=64 -I/usr/local/src/wxWidgets-2.9.4/lib/wx/include/osx_cocoa-unicode-static-2.9 -I../../include -arch x86_64 -DWX_PRECOMP -O2 -fno-strict-aliasing -arch x86_64 -fno-common  ./minimal.cpp

#　.oファイルのリンク
#g++ -mmacosx-version-min=10.6 -o minimal   minimal_minimal.o    -L/usr/local/src/wxWidgets-2.9.4/lib   -arch x86_64 -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL   -lwx_osx_cocoau_core-2.9  -lwx_baseu-2.9   -lwxtiff-2.9 -lwxjpeg-2.9 -lwxpng-2.9 -framework WebKit  -lwxregexu-2.9  -arch x86_64 -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL  -lz -lpthread  -lz -lpthread

#　SetFileコマンドにて実行ファイルの形式を"APPL"に設定する
#SetFile -t APPL minimal

# application bundle用ディレクトリ構造を作成
#mkdir -p minimal.app/Contents
#mkdir -p minimal.app/Contents/MacOS
#mkdir -p minimal.app/Contents/Resources

# Info.plistの元ネタをsedで書き換える
#sed -e "s/IDENTIFIER/`echo . | sed -e 's,\.\./,,g' | sed -e 's,/,.,g'`/" \
#	-e "s/EXECUTABLE/minimal/" \
#	-e "s/VERSION/2.9.4/" \
#	../../src/osx/carbon/Info.plist.in >minimal.app/Contents/Info.plist
#/bin/echo "APPL????" >minimal.app/Contents/PkgInfo

#　実行ファイルとapplication bundle内の実行ファイルをシンボリックリンクする
#ln -f minimal minimal.app/Contents/MacOS/minimal

#　アイコンをリソース用ディレクトリに移す
#cp -f ../../src/osx/carbon/wxmac.icns minimal.app/Contents/Resources/wxmac.icns

# Makefile
TARGET 	= VirtualListTest
SOURCES = $(shell find . -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)
# sources for dependency
DEPSRCS = $(shell find . -name '*.cpp')
DEP	= dep

# basic command
CXX		:= g++ -m64
RM 		:= rm
MAKE	:= make

# basic option
CXXFLAGS = -Wall -I . `wx-config --cxxflags`
LDFLAGS  = /usr/lib/libwx_osx_cocoau_aui-2.9.a `wx-config --libs`

# dummy target
.PHONY	: clean $(LIBNKF) $(BUNDLE) $(MACICON) $(MACPKGINFO) $(MACINFOPLIST)

# suffix rule
.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<
# make dependency
dep:
	$(CXX) -MM -MG $(DEPSRCS) >makefile.dep
	
# setting for Mac
OUTPUTPATH	= .
PROGRAM		= $(TARGET)
PROGVER		= 1.0
ICONFILE	= wxmac.icns

# Info.plist用の設定
COMPANY			= Hiroyuki Nagata
BUNDLEPACKAGE	= APPL
BUNDLESIGNATURE	= ????

# application bundle用の設定
BUNDLE			=$(OUTPUTPATH)/$(PROGRAM).app
MACPKGINFO		=$(BUNDLE)/Contents/PkgInfo
MACINFOPLIST	=$(BUNDLE)/Contents/Info.plist 

# Building bundle directory structure
$(BUNDLE):
	mkdir -p $(OUTPUTPATH)
	mkdir -p $(BUNDLE)/Contents
	mkdir -p $(BUNDLE)/Contents/MacOS
	mkdir -p $(BUNDLE)/Contents/Resources

# Copying icon file into bundle
	$(MACICON):
	cp -f $(ICONFILE) $(BUNDLE)/Contents/Resources/$(nodir $(ICONFILE))

#  This creates the Contents/PkgInfo file.
$(MACPKGINFO):
	touch $(MACPKGINFO)
	@echo -n "$(BUNDLEPACKAGE)$(BUNDLESIGNATURE)" > $(MACPKGINFO)

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
	@echo "   <string>$(ICONFILE)</string>" >> $(MACINFOPLIST)
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

# make all
all : $(BUNDLE) $(MACICON) $(MACPKGINFO) $(MACINFOPLIST) $(TARGET)

$(TARGET): $(OBJECTS)
		$(CXX) $^ -o $@ $(LDFLAGS)
		SetFile -t APPL $(PROGRAM)
		cp -p $(TARGET) $(BUNDLE)/Contents/MacOS/$(PROGRAM)
		ln -f $(TARGET) $(BUNDLE)/Contents/MacOS/$(PROGRAM)
		
# clean
clean:
	$(RM) -rf *.o $(TARGET) $(TARGET).app makefile.dep