CFLAGS = `pkg-config --cflags opencv4` -std=c++11
LIBS = `pkg-config --libs opencv4`

main:
	clang++ -Wall $(CFLAGS) $(LIBS) main.cpp -o bpd.out

release:
	clang++ -Wall $(CFLAGS) $(LIBS) main.cpp -O3 -o blankpage-detector

.PHONY: main

run: main
	./bpd.out test-image/*
