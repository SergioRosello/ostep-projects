all: main

main:
	g++ -o reverse main.cpp -Wall -Werror

run: clear main
	# Run reverse with no parameters
	#./main
	# Run reverse with one parameter
	./reverse normal
	# Run reverse with two parameters
	./reverse normal normalReversed
	# Run with too many input
	./reverse normal normalReversed other

clear:
	rm -rf reverse

