CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

all: test_string standard_main

test_string: test_string.cpp String.cpp
	echo ----------compiling string_test.cpp to create executable program main----------
	g++ -ggdb -std=c++11 String.cpp test_string.cpp -o test_string

standard_main: standard_main.cpp String.cpp
	echo ----------compiling standard_main.cpp to create executable program main----------
	g++ -ggdb -std=c++11 String.cpp standard_main.cpp -o standard_main

clean:
	echo ----------removing executable program main----------
	/bin/rm test_string
	/bin/rm standard_main

test:
	create_script string_test.cpp string_testi
