#include "header.h"
/*
Brevin Simon
LAB 3
USED SOME CODE FROM ANDY
SPAGHETTI CODE
*/
//Main Function  
int main(void)
{
	srand(time(NULL));
	int tilda_count, tilda_count_2, ship_cells = 0, random_or_not = 0, t1, t2, t3, t4, t5, t6;
	char p1_board[MAX_ROWS][MAX_COLS] = { '\0' }, p2_board[MAX_ROWS][MAX_COLS] = { '\0' }, comp_ghost_board[MAX_ROWS][MAX_COLS] = { '\0' };
	
	Coordinate start_pt = { -1, -1 };
	Dir direction = HORIZONTAL;
	Coordinate *start_pt_ptr = &start_pt;
	Stats player_one = { 0, 0, 0, 0 };
	Stats player_two = { 0, 0, 0, 0 };
	
	player_one.total_hits = 0;
	player_one.total_misses = 0;
	player_one.total_shots = 0;

	player_two.total_hits = 0;
	player_two.total_misses = 0;
	player_two.total_shots = 0;

	FILE *outfile = NULL;
	outfile = fopen("battleshiplog.txt", "w");

	initialize_game_board(comp_ghost_board, MAX_ROWS, MAX_COLS);
	
	//MAKING SURE SHIPS DONT OVERLAP
	do {
		system("cls");
		initialize_game_board(p2_board, MAX_ROWS, MAX_COLS);
		tilda_count = 0;

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 5);
		randomly_place_ships(p2_board, 10, 10, direction, &start_pt, 5, 1);

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 4);
		randomly_place_ships(p2_board, 10, 10, direction, &start_pt, 4, 1);

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 3);
		randomly_place_ships(p2_board, 10, 10, direction, &start_pt, 3, 1);

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 3);
		randomly_place_ships(p2_board, 10, 10, direction, &start_pt, 3, 0);

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 2);
		randomly_place_ships(p2_board, 10, 10, direction, &start_pt, 2, 1);

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (p2_board[i][j] == '~') {
					tilda_count += 1;
				}
			}
		}
	} while (tilda_count != 83);
	system("cls");
	welcome_screen();
	//COMPUTER SHIPS ARE NOW PLACED

	//PLAYER ONE IS MAKING BOARD
	printf("Press 1 to place ships manually, Press 2 to have it done automatically. HINT: Auto Works Fine & Is Fast :)\n");
	scanf("%d", &random_or_not);
	int x1, x2, x3, x4, x5, y1, y2, y3, y4, y5, carrier[10] = { '\0' }, temp1, temp2;
	char ship_id1 = 'c', ship_id2 = 'b', ship_id3 = 'r', ship_id4 = 's', ship_id5 = 'd';
	if (random_or_not == 1) {
		int tilda_count = 0;
		printf("YOU ARE PLACING SHIPS MANUALLY!\n");
		printf("Carrier: 'c' Battleship: 'b' Cruiser: 'r' Submarine: 's' Destroyer: 'd'\n");

		printf("Enter the coordinates for the Carrier (5)!\n");
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x1);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y1);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x2);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y2);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x3);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y3);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x4);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y4);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x5);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y5);
		p1_board[x1][x2] = ship_id1;
		p1_board[x2][y2] = ship_id1;
		p1_board[x3][y3] = ship_id1;
		p1_board[x4][y4] = ship_id1;
		p1_board[x5][y5] = ship_id1;
		print_board(p1_board, MAX_ROWS, MAX_COLS);

		printf("Enter the coordinates for the Battleship (4)!\n");
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x1);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y1);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x2);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y2);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x3);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y3);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x4);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y4);
		p1_board[x1][x2] = ship_id2;
		p1_board[x2][y2] = ship_id2;
		p1_board[x3][y3] = ship_id2;
		p1_board[x4][y4] = ship_id2;
		print_board(p1_board, MAX_ROWS, MAX_COLS);

		printf("Enter the coordinates for the Cruiser (3)!\n");
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x1);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y1);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x2);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y2);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x3);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y3);
		p1_board[x1][x2] = ship_id3;
		p1_board[x2][y2] = ship_id3;
		p1_board[x3][y3] = ship_id3;
		print_board(p1_board, MAX_ROWS, MAX_COLS);

		printf("Enter the coordinates for the Submarine (3)!\n");
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x1);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y1);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x2);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y2);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x3);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y3);
		p1_board[x1][x2] = ship_id4;
		p1_board[x2][y2] = ship_id4;
		p1_board[x3][y3] = ship_id4;
		print_board(p1_board, MAX_ROWS, MAX_COLS);

		printf("Enter the coordinates for the Destroyer (2)!\n");
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x1);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y1);
		printf("Enter the x value of the ship: \n");
		scanf("%d", &x2);
		printf("Enter the y value of the ship: \n");
		scanf("%d", &y2);
		p1_board[x1][x2] = ship_id5;
		p1_board[x2][y2] = ship_id5;
		
		for (int r = 0; r < 10; r++) {
			for (int w = 0; w < 10; w++) {
				if (p1_board[r][w] == '~') {
					tilda_count += 1;
				}
			}
		}


		print_board(p1_board, MAX_ROWS, MAX_COLS);

	} else if (random_or_not == 2) {
	do {
		system("cls");
		initialize_game_board(p1_board, MAX_ROWS, MAX_COLS);
		tilda_count = 0;

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 5);
		randomly_place_ships(p1_board, 10, 10, direction, &start_pt, 5, 1);

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 4);
		randomly_place_ships(p1_board, 10, 10, direction, &start_pt, 4, 1);

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 3);
		randomly_place_ships(p1_board, 10, 10, direction, &start_pt, 3, 1);

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 3);
		randomly_place_ships(p1_board, 10, 10, direction, &start_pt, 3, 0);

		direction = gen_dir();
		gen_start_pt(&start_pt, direction, 2);
		randomly_place_ships(p1_board, 10, 10, direction, &start_pt, 2, 1);

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (p1_board[i][j] == '~') {
					tilda_count += 1;
				}
			}
		}
	} while (tilda_count != 83);
	system("cls");
	}
	//PLAYER ONE BOARD IS MADE AT THIS POINT
	int end_game, x_count1 = 0, x_count2 = 0, red_flag, blue_flag;
		
		//ACT OF PLAYING GAME
		//--------------------------IF PLAYER ONE GOES FIRST-----------------------------
	if (select_who_starts_first() == 0) {
		//Player One Goes First
		printf("Player One Turn Goes First\n");
		int i = 0;
		do {
			

			if (i % 2 == 0) {
				t1 = check_shot(p2_board, comp_ghost_board, 1, player_one, player_two, outfile);
				player_one.total_shots += 1;
				if (t1 == 1) {
					player_one.total_hits += 1;
				}
				else if (t1 == 0) {
					player_one.total_misses += 1;
				}
				printf("Player One Board\n");
				print_board(p1_board, MAX_ROWS, MAX_COLS);
				printf("Player Two Board\n");
				print_board(comp_ghost_board, MAX_ROWS, MAX_COLS);
			}
			else if (i % 2 != 0) {
				t2 = check_shot(p1_board, p2_board, 2, player_one, player_two, outfile);
				player_two.total_shots += 1;
				if (t2 == 1) {
					player_two.total_hits += 1;
				}
				else if (t2 == 0) {
					player_two.total_misses += 1;
				}
			}

			if (check_win(comp_ghost_board) == 1) {
				end_game = 1;
			}
			i = i + 1;
		} while (end_game != 1);

		int tiger, lion, bird, bear;
		double slay;
		tiger = player_two.total_hits;
		lion = player_two.total_misses;
		bird = player_two.total_shots;
		slay = (((double)(tiger)) / ((double)(bird))) * 100;

		int z, want, to, be;
		double done;
		z = player_one.total_hits; 
		want = player_one.total_misses;
		to = player_one.total_shots;
		done = (((double)(z))  / ((double)(to))) * 100;

		fprintf(outfile, "\nSTATS\n");
		fprintf(outfile, "\n*** Player One Stats ***\n");
		fprintf(outfile, "Number Hits: %d\n", z);
		fprintf(outfile, "Number Misses: %d\n", want);
		fprintf(outfile, "Number Shots: %d\n", to);
		fprintf(outfile, "Hit/Miss Ratio: %lf\n", done);

		fprintf(outfile, "\n*** Player Two Stats ***\n");
		fprintf(outfile, "Number Hits: %d\n", tiger);
		fprintf(outfile, "Number Misses: %d\n", lion);
		fprintf(outfile, "Number Shots: %d\n", bird);
		fprintf(outfile, "Hit/Miss Ratio: %lf\n", slay);
	}

		//-------------------------IF COMPUTER GOES FIRST--------------------------------
		if (select_who_starts_first() == 1) {
			//Player Two Goes First
			printf("Player Two Goes First\n");
			int j = 0;
			do {
				
					if (j % 2 == 0) {
						t3 = check_shot(p1_board, p2_board, 2, player_one, player_two, outfile);
						if (t3 == 1) {
							player_two.total_hits += 1;
						}
						else if (t3 == 0) {
							player_two.total_misses += 1;
						}
					}
					else if (j % 2 != 0) {
						t4 = check_shot(p2_board, comp_ghost_board, 1, player_one, player_two, outfile);
						if (t4 == 1) {
							player_one.total_hits += 1;
						}
						else if (t4 == 0) {
							player_two.total_misses += 1;
						}
						printf("Player One Board\n");
						print_board(p1_board, MAX_ROWS, MAX_COLS);
						printf("Player Two Board\n");
						print_board(comp_ghost_board, MAX_ROWS, MAX_COLS);
					}
				
					if (check_win(comp_ghost_board) == 1) {
						end_game = 1;
				}
					j = j + 1;
			} while (end_game != 1);

			int tiger, lion, bird, bear;
			double slay;
			tiger = player_two.total_hits;
			lion = player_two.total_misses;
			bird = player_two.total_shots;
			slay = (((double)(tiger)) / ((double)(bird))) * 100;
			
			int z, want, to, be;
			double done;
			z = player_one.total_hits;
			want = player_one.total_misses;
			to = player_one.total_shots;
			done = (((double)(z)) / ((double)(to))) * 100;

			fprintf(outfile, "\nSTATS\n");
			fprintf(outfile, "\n*** Player One Stats ***\n");
			fprintf(outfile, "Number Hits: %d\n", z);
			fprintf(outfile, "Number Misses: %d\n", want);
			fprintf(outfile, "Number Shots: %d\n", to);
			fprintf(outfile, "Hit/Miss Ratio: %lf\n", done);

			fprintf(outfile, "\n*** Player Two Stats ***\n");
			fprintf(outfile, "Number Hits: %d\n", tiger);
			fprintf(outfile, "Number Misses: %d\n", lion);
			fprintf(outfile, "Number Shots: %d\n", bird);
			fprintf(outfile, "Hit/Miss Ratio: %lf\n", slay);

		}
	fclose(outfile);
	return 0;
}