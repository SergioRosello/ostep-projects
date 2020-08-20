all:
	gcc -o wgrep wgrep.c -Wall -Werror

run: all 
	# Prueba para buscar hola en varios archivos
	./wgrep hola pruebaConHola pruebaSinHola
	# Prueba con arvhivo inexistente
	#./wgrep hola pruebaConArchivoInexistente
	# Prueba para buscar hola en un archivo
	./wgrep hola pruebaConHola
	# Prueba pasando hola, sin archivo
	./wgrep hola 
	# Prueba sin pasarle nada
	#./wgrep

clear:
	rm -rf wgrep
