CXX?=g++

FLAGS=-std=c++20 -pthread -Wall -Wextra -Wpedantic -Wsign-conversion
DEBUG_FLAGS=-g -fprofile-arcs -ftest-coverage
RELEASE_FLAGS=-O3

.PHONY: all
all: test test-fmtlib test-stdfmt demo

test: tests/test.cpp barkeep/barkeep.h
	${CXX} ${FLAGS} ${DEBUG_FLAGS} -I./ -I./subprojects/Catch2_/single_include/ tests/test.cpp -o test.out

test-fmtlib: tests/test-fmtlib.cpp barkeep/barkeep.h
	${CXX} ${FLAGS} ${DEBUG_FLAGS} -I./ -I./subprojects/Catch2_/single_include/ -I./subprojects/fmt_/include/ tests/test-fmtlib.cpp -o test-fmtlib.out

test-stdfmt: tests/test-stdfmt.cpp barkeep/barkeep.h
	${CXX} ${FLAGS} ${DEBUG_FLAGS} -I./ -I./subprojects/Catch2_/single_include/ tests/test-stdfmt.cpp -o test-stdfmt.out

demo: tests/demo.cpp barkeep/barkeep.h
	${CXX} ${FLAGS} ${RELEASE_FLAGS} -I./ tests/demo.cpp -o demo.out

.PHONY: clean
clean:
	rm -rf *.out *.out.* *.gcda *.gcno
