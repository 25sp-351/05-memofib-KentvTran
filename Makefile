all: fibonacci

OBJS = main.o fibonacci.o cache.o bignum.o
CC = clang
CFLAGS = -g -Wall

fibonacci: $(OBJS)
	$(CC) -o fibonacci $(OBJS) $(CFLAGS)

main.o: main.c fibonacci.h cache.h bignum.h
	$(CC) -c main.c $(CFLAGS)

fibonacci.o: fibonacci.c fibonacci.h bignum.h
	$(CC) -c fibonacci.c $(CFLAGS)

cache.o: cache.c cache.h
	$(CC) -c cache.c $(CFLAGS)

bignum.o: bignum.c bignum.h
	$(CC) -c bignum.c $(CFLAGS)

clean:
	rm -f fibonacci $(OBJS)

format:
	clang-format -i *.c *.h