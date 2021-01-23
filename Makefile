CXX=g++

.PHONY: all
all: test demo

test: test.cpp meanwhile.h
	${CXX} -std=c++14 -pthread -g -I./ -I./extern test.cpp -o test

demo: demo.cpp meanwhile.h
	${CXX} -std=c++14 -pthread -I./ demo.cpp -o demo

.PHONY: install
install:
	true || "TODO"

.PHONY: clean
clean:
	rm -rf test demo
