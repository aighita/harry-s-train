all: build run

check: checker clean

build:
	gcc -o main *.c ./lib/*.c
run:
	./main
clean:
	rm main
checker:
	./checker.sh
valgrind:
	valgrind --leak-check=yes --track-origins=yes ./tema1
