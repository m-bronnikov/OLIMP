FLAGS=-std=c++17 -Wall -pedantic -Werror

all: complex.o fft.o main.o
	g++ build/complex.o build/fft.o build/main.o -o build/fft_main
	rm build/*.o

complex.o: src/complex.cpp build_dir
	g++ $(FLAGS) -c -I./include src/complex.cpp -o build/complex.o

fft.o: src/fft.cpp build_dir
	g++ $(FLAGS) -c -I./include src/fft.cpp -o build/fft.o

main.o: main.cpp build_dir
	g++ $(FLAGS) -c -I./include main.cpp -o build/main.o

build_dir:
	mkdir -p build

clean:
	rm -r build
