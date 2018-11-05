CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

all: simple_main coins_main coins_menu

simple_main: simple_main.cpp Coins.h
	echo ----------compiling simple_main.cpp to create executable program main----------
	g++ -ggdb -std=c++11 simple_main.cpp -o simple_main

coins_main: coins_main.cpp Coins.h
	echo ----------compiling coins_main.cpp to create executable program main----------
	g++ -ggdb -std=c++11 coins_main.cpp -o coins_main

coins_menu: coins_menu.cpp Coins.h
	echo ----------compiling coins_menu.cpp to create exectuable program main----------
	g++ -ggdb -std=c++11 coins_menu.cpp -o coins_menu

clean:
	echo ----------removing executable program main----------
	/bin/rm main

test:
	create_script simple_main.cpp simple_main
