main: main.o
	g++ -o main main.o
main.o: main.cpp
	g++ -g -c -o main.o main.cpp
.PHONY: clean
clean:
	-rm main main.o
