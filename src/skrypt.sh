#!/bin/bash


if [ "$1" = "clean" ];
then
	rm *.gcov *.gcno *.gcda *.os *.txt *.o 
else
	cmake .
	make
	./tests
	cd CMakeFiles/tests.dir/src_test
	gcov tests.cpp.gcno
	lcov --capture --directory . --output-file SuperMemo.info
	genhtml SuperMemo.info --output-directory CODE_COVERAGE

	fi
