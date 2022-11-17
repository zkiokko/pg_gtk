main: 
	$ cc `pkg-config --cflags gtk4` prog.cpp -o prog `pkg-config --libs gtk4`

exe: prog
	./prog
