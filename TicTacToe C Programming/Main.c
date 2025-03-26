#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Ran();
void Game(int *w);
void Computer(char b[3][3], int* i);
void User(char b[3][3], int* i);


int main()
{
	srand(time(NULL));
	char ans = 'n';
	int win = 0;
	char again[] = "Want to play again? (Y/N):";
	do
	{
		Game(&win);
		printf("Number of wins: %i\n", win);
		printf("%s", again);
		scanf(" %c", &ans);
	} while (ans == 'Y' || ans == 'y');

	return 0;
}

void Game(int *w)
{
	char board[3][3];
	int i, j;
	char result = 'n';

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}

	for (i = 0; i < 9; i++)
	{

		if (i % 2 != 0)
		{
			Computer(board, &i);
		}
		else
		{
			User(board, &i);
		}



		if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			result = 'y';
		}

		for (j = 0; j < 3; j++)
		{
			if (board[j][0] != 0 && board[j][0] == board[j][1] && board[j][1] == board[j][2] || board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j])
			{
				result = 'y';
				break;
			}
		}

		if (result == 'y')
		{
			break;
		}
	}

	if (i % 2 == 0 && result == 'y')
	{
		printf("Congrats player 1, you won!\n\n");
		*w += 1;
	}
	else if (i % 2 != 0 && result == 'y')
	{
		printf("You lose! The computer won!\n\n");
	}
	else
	{
		printf("Draw, try again next time!\n\n");
	}
}

int Ran()
{
	return (rand() % 9) + 1;
}

void Computer(char b[3][3], int* i)
{
	char ch = 'O';
	int play = Ran();

	int row = (play - 1) / 3;
	int col = (play - 1) % 3;



	if (b[row][col] == 0)
	{
		b[row][col] = ch;

		printf("The computer chose %i\n", play);

		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				printf(" %c ", b[k][j]);
				if (j < 2) {
					printf("|");
				}
			}
			printf("\n");
			if (k < 2) {
				printf("-----------\n");
			}
		}
		printf("\n");
	}
	else
	{
		*i -= 1;
	}
}

void User(char b[3][3], int* i)
{
	int play;
	char ch = 'X';
	printf("Please enter a go (1-9). ");
	scanf("%i", &play);

	if (play>9 || play<1)
	{
		printf("Please choose a number between 1-9\n");
		*i -= 1;
	}
	else
	{
		int row = (play - 1) / 3;
		int col = (play - 1) % 3;



		if (b[row][col] == 0)
		{
			b[row][col] = ch;

			for (int k = 0; k < 3; k++) {
				for (int j = 0; j < 3; j++) {
					printf(" %c ", b[k][j]);
					if (j < 2) {
						printf("|");
					}
				}
				printf("\n");
				if (k < 2) {
					printf("-----------\n");
				}
			}
			printf("\n");
		}
		else
		{
			printf("This box is already taken, pick again!\n");
			*i -= 1;
		}
	}
}