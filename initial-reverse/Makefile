all: reverse main

main:
	g++ -o main main.cpp -Wall -Werror

reverse: 
	# Compile and link with shared library
	#g++ -o reverse reverse.cpp -Wall -Werror

run: clear main
	# Run reverse with no parameters
	#./reverse
	# Run reverse with one parameter
	#./reverse normal
	# Run reverse with two parameters
	./main normal normalReversed
	# Run with too many input
	#./reverse normal normalReversed other

clear:
	rm -rf main stack

