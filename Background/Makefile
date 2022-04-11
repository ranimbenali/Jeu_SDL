prog:main.o collision.o backg.o
	gcc *.h *.c -lm -lSDL -lSDL_image  -lSDL_ttf -lSDL_mixer -o pr0 -g
main.o:main.c
	gcc -c main.c -g
collision.o:collision.c
	gcc -c collision.c -g
backg.o:backg.c
	gcc -c backg.c -g

