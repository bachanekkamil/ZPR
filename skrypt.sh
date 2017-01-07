#!/bin/bash


if [ "$1" = "clean" ];
then
	rm *.gcov *.gcno *.gcda *.os *.txt *.o 
else
	rm -rf build
	mkdir build
	cd build
	cmake ../src
	make
	cd ../build
	./tests
	cd CMakeFiles/tests.dir/src_test
	gcov tests.cpp.gcno
	lcov --capture --directory . --output-file SuperMemo.info
	genhtml SuperMemo.info --output-directory CODE_COVERAGE

	fi
