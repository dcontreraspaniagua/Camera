build: pre compile asm linker

pre:
	cpp Camera.c > Camera.i

compile:
	gcc -S Camera.i

asm:
	as -o Camera.o Camera.s

linker:
	gcc -Wall -pthread -o Camera.exe Camera.o -lpigpio

Build:
	#gcc -I/usr/include/python3.4m -L/usr/lib/python3.4/config-3.4m-arm-linux-gnueabihf -L/usr/lib -lpython3.4m -Xlinker -export-dynamic -o Camera Camera.c -Wall 
	gcc -I/usr/include/python3.4m -I/usr/include/python3.4m  -Wno-unused-result -g -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -o Camera source/Camera.c source/pycam.c -L/usr/lib/python3.4/config-3.4m-arm-linux-gnueabihf -L/usr/lib -lpython3.4m -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions
run:
	./Camera

clean:
	rm *.i *.s *.o *.exe
