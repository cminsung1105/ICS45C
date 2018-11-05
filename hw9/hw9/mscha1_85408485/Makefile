CXXFLAGS=-std=c++11 -std=gnu++11 -Wpedantic -Wall -Wextra -Werror  -Wzero-as-null-pointer-constant -ggdb
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

all: main 

main: main.cpp
	g++ $(CXXFLAGS) SetList.h MapArray.h  main.cpp -o main

setlist: SetList.cpp
	g++ -ggdb -std=c++11 SetList.cpp -o setlist

maparray: MapArray.cpp
	g++ -ggdb -std=c++11 MapArray.cpp -o maparray

clean:
	/bin/rm main
