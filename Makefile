flags := --std=c++17 -Werror -Wall -g

run: main
	./main

main: main.cpp set.o
	g++ $^ -o $@ $(flags)

set.o: set.cpp set.hpp
	g++ $< -c $< $(flags)

.PHONY: clean
clean:
	rm ./*.o
