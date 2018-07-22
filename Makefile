CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

main:
	clang++ -Wall $(CFLAGS) $(LIBS) main.cpp -o bpd.out

release:
	clang++ -Wall $(CFLAGS) $(LIBS) main.cpp -O3 -o blankpage-detector

.PHONY: main

run: main
	./bpd.out test-image/*
