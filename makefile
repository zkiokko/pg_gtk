main: 
	$ cc `pkg-config --cflags gtk4` -fmodules-ts prog.cpp -o prog `pkg-config --libs gtk4`

exe: prog
	./prog
