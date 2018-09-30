#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROWS 10
#define MAX_COLS 10

#define CARRIER 5
#define BATTLESHIP 4
#define CRUISER 3
#define SUBMARINE 3
#define DESTROYER 2

//Header 
void welcome_screen(void);
int select_who_starts_first(void);
void initialize_game_board(char board[][MAX_COLS], int num_rows, int num_cols);
void print_board(char board[][MAX_COLS], int num_rows, int num_cols);
typedef enum dir
{
	HORIZONTAL = 0, VERTICAL = 1
} Dir;
typedef struct coordinate
{
	int row;
	int col;
}Coordinate;
typedef struct stats
{
	int total_shots;
	int total_misses;
	int total_hits;
	double hits_misses_ratio;
}Stats;
Dir gen_dir(void);
void gen_start_pt(Coordinate *start_pt_ptr, Dir direction, int length);
int *randomly_place_ships(char board[][MAX_COLS], int num_rows, int num_cols, Dir direction, Coordinate * start_point, int length
	, int pterodactly_gang_gang);
int check_shot(char board1[][MAX_COLS], char board2[][MAX_COLS], int player_1or2, Stats p1, Stats p2, FILE *outfile);
int check_win(char board[][MAX_COLS]);