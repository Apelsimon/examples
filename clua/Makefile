config=Debug
luajit_dir=LuaJIT-2.1.ROLLING
project_root_dir=$(shell pwd)

.PHONY: default clean init build run

default:
	clean init build

clean:
	rm -rf build; \
	cd $(LUAJIT_DIR); \
	make clean

init:
	mkdir -p build

build:
	cd $(luajit_dir); \
	make; \
	cp src/luajit.exe $(project_root_dir)/build; \
	cp src/lua51.dll $(project_root_dir)/build; \
	cd ../build; \
	gendef lua51.dll; \
	dlltool -d lua51.def -l lua51.lib; \
	mkdir -p lua; \
	cp -r ../$(luajit_dir)/src/jit ./lua; \
	cmake .. -G "Visual Studio 17 2022" -DLUA_INCLUDE_DIR="$(luajit_dir)/src" -DLUA_LIB="$(project_root_dir)/build/lua51.lib" -DCMAKE_BUILD_TYPE=$(config); \
	cmake --build . --config $(config); \
	cp $(config)/oink.dll .

run:
	./build/luajit app.lua