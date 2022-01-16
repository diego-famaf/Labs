
CC = gcc
CFLAGS  = -no-pie -Wall -Werror -Wextra -pedantic -std=c99 -g

 

all: Dijkstra


Dijkstra:  main.o cost.o dijkstra.o graph.o set.o   
	$(CC) $(CFLAGS) -o Dijkstra main.o cost.o dijkstra.o graph.o set.o 
	
main.o:	main.c dijkstra.h
	$(CC) $(CFLAGS) -c main.c

cost.o:	cost.c	cost.h
	$(CC) $(CFLAGS) -c cost.c

dijkstra.o: dijkstra.c	dijkstra.h
	$(CC) $(CFLAGS) -c dijkstra.c

graph.o: graph.c graph.h	 
	$(CC) $(CFLAGS) -c graph.c

clean:
	rm -f	main.o cost.o dijkstra.o graph.o Dijkstra 
	
