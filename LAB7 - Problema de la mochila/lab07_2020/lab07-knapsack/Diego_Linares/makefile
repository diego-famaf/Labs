
CC = gcc
CFLAGS  = -no-pie -Wall -Werror -Wextra -pedantic -std=c99 -g

 

all: Knapsack


Knapsack:  main.o helpers.o item.o knapsack.o string.o   
	$(CC) $(CFLAGS) -o Knapsack main.o helpers.o item.o knapsack.o string.o 
	
main.o:	main.c knapsack.h string.h helpers.h
	$(CC) $(CFLAGS) -c main.c

helpers.o: helpers.c helpers.h
	$(CC) $(CFLAGS) -c helpers.c

knapsack.o: knapsack.c	knapsack.h
	$(CC) $(CFLAGS) -c knapsack.c

item.o: item.c item.h	 
	$(CC) $(CFLAGS) -c item.c

string.o: string.c string.h
	$(CC) $(CFLAGS) -c string.c

clean:
	rm -f	main.o helpers.o knapsack.o item.o string.o Knapsack 
	
