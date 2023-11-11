CXX=g++

.PHONY: all
all: test demo

test: test.cpp meanwhile/meanwhile.h
	${CXX} -std=c++17 -pthread -g -I./ -I./extern test.cpp -o test.out

demo: demo.cpp meanwhile/meanwhile.h
	${CXX} -std=c++17 -pthread -O3 -I./ demo.cpp -o demo.out

.PHONY: install
install:
	true || "TODO"

.PHONY: clean
clean:
	rm -rf *.out.*
