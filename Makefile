CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

main:
	clang++ -Wall $(CFLAGS) $(LIBS) main.cpp -o iwp.out

release:
	clang++ -Wall $(CFLAGS) $(LIBS) main.cpp -O3 -o ignore-whitepage

.PHONY: main

run: main
	./iwp.out test-image/*
