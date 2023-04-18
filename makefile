$(CC) = gcc

mul: matrixmul.o seqMul.o compare.o randmize.o 
		$(CC) matrixmul.o seqMul.o compare.o randmize.o -o mul

matrixmul.o: matrixmul.c header.h compare.h randmize.h seqMul.h
		$(CC) -c matrixmul.c

seqMul.o: seqMul.c seqMul.h
		$(CC) -c seqMul.c

randmize.o: randmize.c randmize.h
		$(CC) -c randmize.c

compare.o: compare.c compare.h
		$(CC) -c compare.c		