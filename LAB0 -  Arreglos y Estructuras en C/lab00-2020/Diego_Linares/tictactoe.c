#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;
    
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    board = board;
   
    
    char winner = '-';
    //filas
    for(int row =0;row<BOARD_SIZE;row++){
        
        	if(board[row][0]=='X'&&board[row][1]=='X'&&board[row][2]=='X'){
        		winner = 'X';
        	}
        	else if(board[row][0]=='O'&&board[row][1]=='O'&&board[row][2]=='O'){
        		winner = 'O';  
            }
    }
    //columnas
    for(int column =0;column<BOARD_SIZE;column++){   		
        		
        	
        	if(board[0][column]=='X'&&board[1][column]=='X'&&board[2][column]=='X'){
        		winner = 'X';
        	}
        	else if(board[0][column]=='O'&&board[1][column]=='O'&&board[2][column]=='O'){
        		winner = 'O';  
            }
        }
    //diagonales
    if (board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X'||board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X'){
        		winner = 'X';
	}
     else if(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O'||board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O'){
        		winner = 'O';   	
    }		
    
    return winner;
}
bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    board = board;
    bool vacia = false;
	 
    for(int i = 0; i < BOARD_SIZE;i++){
	    for(int j = 0; j < BOARD_SIZE;j++){
	    	if(board[i][j]=='-'){
	    		 vacia = true;
	    		 
	        }	
	    }
	}
	    
	return vacia;
}
int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posicion (numero del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un numero desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        }else {
            printf("\nCelda invalida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Gano %c\n", winner);
    }
    return 0;
}
