CXX=g++

.PHONY: all
all: test demo

test: test.cpp meanwhile/meanwhile.h
	${CXX} -std=c++17 -pthread -g -Wall -Wextra -Wpedantic -Wsign-conversion -fprofile-arcs -ftest-coverage -I./ -I./extern test.cpp -o test.out

demo: demo.cpp meanwhile/meanwhile.h
	${CXX} -std=c++17 -pthread -O3 -Wall -Wextra -Wpedantic -Wsign-conversion -I./ demo.cpp -o demo.out

.PHONY: install
install:
	true || "TODO"

.PHONY: clean
clean:
	rm -rf *.out.* *.gcda *.gcno
