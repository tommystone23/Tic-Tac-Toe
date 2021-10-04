#include <stdio.h>

char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int player = 1, result = -1;

int main(){
	int userInput; 
	char symbol;
	
	do{
		gameBoard();
		player = (player % 2 == 0) ? 2 : 1;
		if(player == 1){
			symbol = 'X';
		}else{
			symbol = 'O';
		}
		printf("\nPlayer %d make a move: ", player);
		scanf("%d", &userInput);
		if(userInput == 1 && square[0] == '1'){
			square[0] = symbol;
		}else if(userInput == 2 && square[1] == '2'){
			square[1] = symbol;
		}else if(userInput == 3 && square[2] == '3'){
			square[2] = symbol;
		}else if(userInput == 4 && square[3] == '4'){
			square[3] = symbol;
		}else if(userInput == 5 && square[4] == '5'){
			square[4] = symbol;
		}else if(userInput == 6 && square[5] == '6'){
			square[5] = symbol;
		}else if(userInput == 7 && square[6] == '7'){
			square[6] = symbol;
		}else if(userInput == 8 && square[7] == '8'){
			square[7] = symbol;
		}else if(userInput == 9 && square[8] == '9'){
			square[8] = symbol;
		}else{
			printf("Invalid Input, please try again\n");
			player--;
		}	
		player++;	
		result = winCondition();					
	}while(result == -1);
	if(result == 1){
		printf("Player %d has won!", --player);
	}else{
		puts("Cats game!");
	}
}

int winCondition(){
	if(square[0] == square[1] && square[1] == square[2]){
		return 1;
	}else if(square[0] == square[3] && square[3] == square[6]){
		return 1;
	}else if(square[0] == square[4] && square[4] == square[8]){
		return 1;
	}else if(square[2] ==square[5] && square[5] == square[8]){
		return 1;
	}else if(square[2] == square[4] && square[4] == square[6]){
		return 1;
	}else if(square[6] == square[7] && square[7] == square[8]){
		return 1;
	}else if(square[3] == square[4] && square[4] == square[5]){
		return 1;
	}else if(square[0] != '1' && square[1] != '2' && square[2] != '3' 
		&& square[3] != '4' && square[4] != '5' && square[5] != '6'
		&& square[6] != '7' && square[7] != '8' && square[8] != '9'){
			return 0;
	} else{
		return -1;
	}
}

void gameBoard(){
	printf("Player 1 = X & Player 2 = O\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c\n", square[0], square[1], square[2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c\n", square[3], square[4], square[5]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c\n", square[6], square[7], square[8]);
	printf("_____|_____|_____");
}
