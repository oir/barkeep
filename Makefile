CXX=g++

.PHONY: all
all: test test-fmt demo

test: tests/test.cpp barkeep/barkeep.h
	${CXX} -std=c++17 -pthread -g -Wall -Wextra -Wpedantic -Wsign-conversion -fprofile-arcs -ftest-coverage -I./ -I./subprojects/Catch2_/single_include/ tests/test.cpp -o test.out

test-fmt: tests/test.cpp barkeep/barkeep.h
	${CXX} -std=c++17 -pthread -g -Wall -Wextra -Wpedantic -Wsign-conversion -fprofile-arcs -ftest-coverage -I./ -I./subprojects/Catch2_/single_include/ -I./subprojects/fmt_/include/ tests/test-fmt.cpp -o test-fmt.out

demo: tests/demo.cpp barkeep/barkeep.h
	${CXX} -std=c++17 -pthread -O3 -Wall -Wextra -Wpedantic -Wsign-conversion -I./ tests/demo.cpp -o demo.out

.PHONY: install
install:
	true || "TODO"

.PHONY: clean
clean:
	rm -rf *.out *.out.* *.gcda *.gcno
