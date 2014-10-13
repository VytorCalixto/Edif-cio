all:
	gcc -g main.c -o fogo -w
	$(MAKE) -C ./ testarMapas
