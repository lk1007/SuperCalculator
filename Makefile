CC=g++
all: main
	./main
main: main.o func.h calculator.cpp
	$(CC) $^ -o $@
%.o: %.cpp
	$(CC) $^ -c
clean:
	rm *.o
	rm main