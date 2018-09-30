#include "header.h"

//Equations
int select_who_starts_first(void) {
	int one_or_two;
	one_or_two = rand() % 1 + 0;
	return one_or_two;
}

/*PRETTY BASIC*/
void welcome_screen(void) {
	printf("----------------BATTLESHIP----------------\n");
	printf("    Shoot Down The Other Team's Ships!\n");
	printf("------------------------------------------\n");
}

/*PRETTY BASIC*/
Dir gen_dir(void)
{
	Dir direction = HORIZONTAL;

	direction = (Dir)rand() % 2;

	return direction;
}

/*
Function: GENERATES START POINT USING POINTER
Date Created: 4/4/2018
Date Last Modified: 4/4/2018
Description: GENERATES A START POINT USING RANDOM VALUES FOR BOTH
ROWS AND COLUMNS
Input Parameters: THE STRUCT FOR THE START POINT AND FOR THE DIRECTION
AND THE LENGTH OF THE SHIP
Returns: RETURNS THE POINTER OF THE FUNCTION
Preconditions: INITIALIZED STRUCTS
Postconditions: USING POINTERS INTO THE MAIN FUNCTION
*/
void gen_start_pt(Coordinate *start_pt_ptr, Dir direction, int length)
{
	if (direction == HORIZONTAL)
	{
		start_pt_ptr->row = rand() % MAX_ROWS;
		start_pt_ptr->col = rand() % (MAX_COLS - length + 1);
	}
	else if (direction == VERTICAL)
	{
		start_pt_ptr->col = rand() % MAX_COLS;
		start_pt_ptr->row = rand() % (MAX_ROWS - length + 1);
	}
	return start_pt_ptr;
}

void initialize_game_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

void print_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;
	printf(" ");
	for (int i = 0; i < 10; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (row_index = 0; row_index < num_rows; ++row_index)
	{
		printf("%d ", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%c ", board[row_index][col_index]);
		}
		putchar('\n');
	}
}

/*
Function: RANDOMLY PLACES SHIPS
Date Created: 4/4/2018
Date Last Modified: 4/4/2018
Description: THIS FUNCTION RANDOMLY POSITIONS SEVERAL SHIPS AND
OVERLAYING IS POSSIBLE (SEE MAIN.C FOR SOLUTION)
Input Parameters: THE BOARD FOR THAT IS GETTING SHIPS PLACED ON IT,
NUMBER OF ROWS/COLUMNS, RANDOM DIRECTION STRUCT, POINTER FOR RANDOM
START POINT, LENGTH OF SHIP, AND AN INTEGER SO THAT BOTH 3 LENGTH
SHIPS HAVE A UNIQUE ID
Returns: THE EDITED ARRAY
Preconditions: BOARD AND STRUCTS INITIALIZED
Postconditions: RUN WITH DO WHILE LOOP TO POISITION THE SHIPS
*/
int *randomly_place_ships(char board[][MAX_COLS], int num_rows, int num_cols, Dir direction, Coordinate *start_pt_ptr, int length
, int pterodactly_gang_gang) {
	if (pterodactly_gang_gang == 1) {
		if (length == 5) {
			if (direction == HORIZONTAL) {
				for (int i = 0; i < length; i++) {
					board[start_pt_ptr->row][start_pt_ptr->col + i] = 'c';
				}
			}
			else if (direction == VERTICAL) {
				for (int i = 0; i < length; i++) {
					board[start_pt_ptr->row + i][start_pt_ptr->col] = 'c';
				}
			}
			putchar('\n');
		}
		if (length == 4) {
			if (direction == HORIZONTAL) {
				for (int i = 0; i < length; i++) {
					board[start_pt_ptr->row][start_pt_ptr->col + i] = 'b';
				}
			}
			else if (direction == VERTICAL) {
				for (int i = 0; i < length; i++) {
					board[start_pt_ptr->row + i][start_pt_ptr->col] = 'b';
				}
			}
			putchar('\n');
		}
		if (length == 3) {
			if (direction == HORIZONTAL) {
				for (int i = 0; i < length; i++) {
					board[start_pt_ptr->row][start_pt_ptr->col + i] = 'r';
				}
			}
			else if (direction == VERTICAL) {
				for (int i = 0; i < length; i++) {
					board[start_pt_ptr->row + i][start_pt_ptr->col] = 'r';
				}
			}
			putchar('\n');
		}
		if (length == 2) {
			if (direction == HORIZONTAL) {
				for (int i = 0; i < length; i++) {
					board[start_pt_ptr->row][start_pt_ptr->col + i] = 'd';
				}
			}
			else if (direction == VERTICAL) {
				for (int i = 0; i < length; i++) {
					board[start_pt_ptr->row + i][start_pt_ptr->col] = 'd';
				}
			}
			putchar('\n');
		}

	}else if (pterodactly_gang_gang == 0) {
			if (length == 3) {
				if (direction == HORIZONTAL) {
					for (int i = 0; i < length; i++) {
						board[start_pt_ptr->row][start_pt_ptr->col + i] = 's';
					}
				}
				else if (direction == VERTICAL) {
					for (int i = 0; i < length; i++) {
						board[start_pt_ptr->row + i][start_pt_ptr->col] = 's';
					}
				}
				putchar('\n');
			}
		}
		
	return board;
}

/*
Function: CHECKS FOR MISS OR HIT
Date Created: 4/4/2018
Date Last Modified: 4/4/2018
Description: CHECKS FOR HIT OR MISS AND RETURNS 1 FOR HIT AND 0 FOR MISS
Input Parameters: TWO BOARD, ONE TO CHECK FOR HIT AND ONE FOR CHANGING BOARD
SO THAT THE PLAYER CAN SEE HITS OR MISSES
Returns: RETURNS AN INTEGER TO INDICATE HIT OR MISS
Preconditions: BOARDS AND STRUCTS INITIALIZED
Postconditions: USED WITH CONDITIONALS TO INDICATE IF HIT OR MISS
*/
int check_shot(char board1[][MAX_COLS], char board2[][MAX_COLS], int player_1or2, Stats p1, Stats p2, FILE *outfile) {
	int x, y, computer_x, computer_y;
	//p1.total_shots += 1; //-------------------------------
	if (player_1or2 == 1) {
		printf("Where you like to shoot captain?\n");
		printf("x: \n");
		scanf("%d", &x);
		printf("y: \n");
		scanf("%d", &y);
		if (board1[y][x] != '~') {
			board2[y][x] = 'x';
			printf("It's a hit\n");
			//p1.total_hits += 1; //----------------------------
			fprintf(outfile, "Player 1: %d,%d is a hit\n", x, y);
			return 1;
		}
		else {
			board2[y][x] = 'L';
			printf("Miss\n");
			//p1.total_misses += 1; //-------------------------------
			fprintf(outfile, "Player 1: %d,%d is a miss\n", x, y);
			return 0;
		}
	}
	else if (player_1or2 == 2) {
		computer_x = rand() % 9 + 0;
		computer_y = rand() % 9 + 0;
		//p2.total_shots += 1; //-------------------------
		if (board1[computer_x][computer_y] != '~') {
			board1[computer_x][computer_y] = 'x';
			printf("You have been hit\n");
			//p2.total_hits += 1; //---------------------------------
			fprintf(outfile, "Player 2: %d,%d is a hit\n", computer_x, computer_y);
			return 1;
		}
		else {
			printf("Computer Miss\n");
			board1[computer_x][computer_y] = 'L';
			/*p2.total_misses += 1;*/
			fprintf(outfile, "Player 2: %d,%d is a miss\n", computer_x, computer_y);
			return 0;
		}
	}

}

/*
Function: CHECK FOR WIN
Date Created: 4/4/2018
Date Last Modified: 4/4/2018
Description: THIS CODE CHECKS FOR THE WINNER BE SEARCHING FOR 17 'x' CHARACTERS
Input Parameters: CHAR BOARD (PLAYER BOARD)
Returns: RETURNS ONE OR ZERO TO INDICATE IF THE PLAYER WON
Preconditions: THE BOARD HAS TO BE INITIALIZED
Postconditions: MAIN.C MUST BE ABLE TO USE THE ONE OR ZERO VALUES
*/
int check_win(char board[][MAX_COLS]) {
	int countex = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 'x') {
				countex += 1;
			}
		}
	}
	if (countex == 17) {
		return 1;
	}
	else if (countex != 17) {
		return 0;
	}
}