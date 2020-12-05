CC = gcc

all:
	export MESA_GL_VERSION_OVERRIDE=3.3
	$gcc -Wall -Wextra -Wpedantic -std=c99 -O0 mygl.c main.c -lglut -lGLU -lGL -o mygl

clean:
	rm mygl
