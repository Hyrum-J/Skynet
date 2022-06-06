
#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

// Declaring Functions
void linearSearch();

void bianarySearchPattern();

void randomSearchPattern();

void updateMap();

void resetGrid();

bool alreadyGuessed();

//A few global variables
bool guessed = false;

int randomGuess;

int searchGridHighNumber = 64;

int searchGridLowNumber = 1;

int enemyAI;

int lastGuess;

//Amount of tries for the linear search results
int linearSearchResults;

//Amount of tries for the bianary search results
int bianarySearchResults;

//Amount of tries for the random search results
int randomSearchResults;

// The grid
int grid[8][8] = {
		{1,2,3,4,5,6,7,8},
		{9,10,11,12,13,14,15,16},
		{17,18,19,20,21,22,23,24},
		{25,26,27,28,29,30,31,32},
		{33,34,35,36,37,38,39,40},
		{41,42,43,44,45,46,47,48},
		{49,50,51,52,53,54,55,56},
		{57,58,59,60,61,62,63,64}
};

//The function that runs it all
int main()
{

	srand(time(0));

	enemyAI = (rand() % 64) + 1;

	for (int k = 0; k < 8; k++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (j == 7)
			{

				cout << grid[k][j] << " " << endl;

			}
			else if (j < 7)
			{

				cout << grid[k][j] << " ";

			}

		}

	}

	linearSearch();

	system("pause");

	resetGrid();

	bianarySearchPattern();

	system("pause");

	resetGrid();

	cout << "It took " << linearSearchResults << " tries for the linear search pattern." << endl;

	cout << "It took " << bianarySearchResults << " tries for the bianary search pattern." << endl;

	return 0;

}

//This function searches the grid line by line
void linearSearch()
{
	int i = 0;

	while (true)
	{

		i = i + 1;

		if (i == enemyAI)
		{

			cout << "Skynet guess: " << i << endl;

			cout << "Guess is correct. It took " << i << " guesses." << endl;

			linearSearchResults = i;

			break;

		}
		else
		{

			cout << "Skynet guess: " << i << endl;

			cout << "Guess is incorrect. Guess #" << i << " is a failure" << endl;

			lastGuess = i;

			updateMap();

			for (int k = 0; k < 8; k++)
			{
				for (int j = 0; j < 8; j++)
				{

					if (j == 7)
					{

						cout << grid[k][j] << " " << endl;

					}
					else if (j < 7)
					{

						cout << grid[k][j] << " ";

					}

				}

			}

		}

	}

}

//This function searches the grid by guessing in the middle and then going in the direction of the enemy 
void bianarySearchPattern() 
{

	int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

	int m = 0;

	while (true)
	{

		m = m + 1;

		if (targetLocationPrediction == enemyAI)
		{

			cout << "Skynet guess: " << targetLocationPrediction << endl;

			cout << "Guess is correct. It took " << m << " guesses." << endl;

			bianarySearchResults = m;

			break;

		}
		else if (targetLocationPrediction > enemyAI)
		{

			cout << "Skynet guess: " << targetLocationPrediction << endl;

			cout << "Guess is incorrect. Guess #" << m << " is a failure" << endl;

			lastGuess = targetLocationPrediction;

			updateMap();

			for (int k = 0; k < 8; k++)
			{
				for (int j = 0; j < 8; j++)
				{

					if (j == 7)
					{

						cout << grid[k][j] << " " << endl;

					}
					else if (j < 7)
					{

						cout << grid[k][j] << " ";

					}

				}

			}

			targetLocationPrediction = targetLocationPrediction - 2;

			if (targetLocationPrediction < enemyAI)
			{

				targetLocationPrediction = targetLocationPrediction + 1;

			}

		}
		else if (targetLocationPrediction < enemyAI)
		{

			cout << "Skynet guess: " << targetLocationPrediction << endl;

			cout << "Guess is incorrect. Guess #" << m << " is a failure" << endl;

			lastGuess = targetLocationPrediction;

			updateMap();

			for (int k = 0; k < 8; k++)
			{
				for (int j = 0; j < 8; j++)
				{

					if (j == 7)
					{

						cout << grid[k][j] << " " << endl;

					}
					else if (j < 7)
					{

						cout << grid[k][j] << " ";

					}

				}

			}

			targetLocationPrediction = targetLocationPrediction + 2;

			if (targetLocationPrediction > enemyAI)
			{

				targetLocationPrediction = targetLocationPrediction - 1;

			}

		}

	}

}

//This is experimental, serches based on randomness
void randomSearchPattern()
{

	int n = 0;

	srand(4);

	while (true) 
	{
		n = n + 1;

		randomGuess = (rand() % 64) + 1;

		alreadyGuessed();

		if (guessed == false)
		{

			if (randomGuess = enemyAI)
			{

				cout << "Skynet guess: " << randomGuess << endl;

				cout << "Guess is correct. It took " << n << " guesses." << endl;

				randomSearchResults = n;

				break;

			}
			else if (randomGuess != enemyAI)
			{

				cout << "Skynet guess: " << randomGuess << endl;

				cout << "Guess is incorrect. Guess #" << n << " is a failure" << endl;

				lastGuess = randomGuess;

				updateMap();

				for (int k = 0; k < 8; k++)
				{
					for (int j = 0; j < 8; j++)
					{

						if (j == 7)
						{

							cout << grid[k][j] << " " << endl;

						}
						else if (j < 7)
						{

							cout << grid[k][j] << " ";

						}

					}

				}
			}

		}
		else if (guessed = true)
		{

			randomSearchPattern();

		}

	}
	
}

//This updates the map, telling the character where has been guessed
void updateMap()
{

	if (lastGuess == 1)
	{

		grid[0][0] = 0;

	}
	else if (lastGuess == 2)
	{

		grid[0][1] = 0;

	}
	else if (lastGuess == 3)
	{

		grid[0][2] = 0;

	}
	else if (lastGuess == 4)
	{

		grid[0][3] = 0;

	}
	else if (lastGuess == 5)
	{

		grid[0][4] = 0;

	}
	else if (lastGuess == 6)
	{

		grid[0][5] = 0;

	}
	else if (lastGuess == 7)
	{

		grid[0][6] = 0;

	}
	else if (lastGuess == 8)
	{

		grid[0][7] = 0;

	}
	else if (lastGuess == 9)
	{

		grid[1][0] = 0;

	}
	else if (lastGuess == 10)
	{

		grid[1][1] = 0;

	}
	else if (lastGuess == 11)
	{

		grid[1][2] = 0;

	}
	else if (lastGuess == 12)
	{

		grid[1][3] = 0;

	}
	else if (lastGuess == 13)
	{

		grid[1][4] = 0;

	}
	else if (lastGuess == 14)
	{

		grid[1][5] = 0;

	}
	else if (lastGuess == 15)
	{

		grid[1][6] = 0;

	}
	else if (lastGuess == 16)
	{

		grid[1][7] = 0;

	}
	else if (lastGuess == 17)
	{

		grid[2][0] = 0;

	}
	else if (lastGuess == 18)
	{

		grid[2][1] = 0;

	}
	else if (lastGuess == 19)
	{

		grid[2][2] = 0;

	}
	else if (lastGuess == 20)
	{

		grid[2][3] = 0;

	}
	else if (lastGuess == 21)
	{

		grid[2][4] = 0;

	}
	else if (lastGuess == 22)
	{

		grid[2][5] = 0;

	}
	else if (lastGuess == 23)
	{

		grid[2][6] = 0;

	}
	else if (lastGuess == 24)
	{

		grid[2][7] = 0;	

	}
	else if (lastGuess == 25)
	{

		grid[3][0] = 0;

	}
	else if (lastGuess == 26)
	{

		grid[3][1] = 0;

	}
	else if (lastGuess == 27)
	{

		grid[3][2] = 0;

	}
	else if (lastGuess == 28)
	{

		grid[3][3] = 0;

	}
	else if (lastGuess == 29)
	{

		grid[3][4] = 0;

	}
	else if (lastGuess == 30)
	{

		grid[3][5] = 0;

	}
	else if (lastGuess == 31)
	{

		grid[3][6] = 0;

	}
	else if (lastGuess == 32)
	{

		grid[3][7] = 0;

	}
	else if (lastGuess == 33)
	{

		grid[4][0] = 0;

	}
	else if (lastGuess == 34)
	{

		grid[4][1] = 0;

	}
	else if (lastGuess == 35)
	{

		grid[4][2] = 0;

	}
	else if (lastGuess == 36)
	{

		grid[4][3] = 0;

	}
	else if (lastGuess == 37)
	{

		grid[4][4] = 0;

	}
	else if (lastGuess == 38)
	{

		grid[4][5] = 0;

	}
	else if (lastGuess == 39)
	{

		grid[4][6] = 0;

	}
	else if (lastGuess == 40)
	{

		grid[4][7] = 0;

	}
	else if (lastGuess == 41)
	{

		grid[5][0] = 0;

	}
	else if (lastGuess == 42)
	{

		grid[5][1] = 0;

	}
	else if (lastGuess == 43)
	{

		grid[5][2] = 0;

	}
	else if (lastGuess == 44)
	{

		grid[5][3] = 0;

	}
	else if (lastGuess == 45)
	{

		grid[5][4] = 0;

	}
	else if (lastGuess == 46)
	{

		grid[5][5] = 0;

	}
	else if (lastGuess == 47)
	{

		grid[5][6] = 0;

	}
	else if (lastGuess == 48)
	{

		grid[5][7] = 0;

	}
	else if (lastGuess == 49)
	{

		grid[6][0] = 0;

	}
	else if (lastGuess == 50)
	{

		grid[6][1] = 0;

	}
	else if (lastGuess == 51)
	{

		grid[6][2] = 0;

	}
	else if (lastGuess == 52)
	{

		grid[6][3] = 0;

	}
	else if (lastGuess == 53)
	{

		grid[6][4] = 0;

	}
	else if (lastGuess == 54)
	{

		grid[6][5] = 0;

	}
	else if (lastGuess == 55)
	{

		grid[6][6] = 0;

	}
	else if (lastGuess == 56)
	{

		grid[6][7] = 0;

	}
	else if (lastGuess == 57)
	{

		grid[7][0] = 0;

	}
	else if (lastGuess == 58)
	{

		grid[7][1] = 0;

	}
	else if (lastGuess == 59)
	{

		grid[7][2] = 0;

	}
	else if (lastGuess == 60)
	{

		grid[7][3] = 0;

	}
	else if (lastGuess == 61)
	{

		grid[7][4] = 0;

	}
	else if (lastGuess == 62)
	{

		grid[7][5] = 0;

	}
	else if (lastGuess == 63)
	{

		grid[7][6] = 0;

	}
	else if (lastGuess == 64)
	{

		grid[7][7] = 0;

	}

}

//This resets the grid to the begining grid
void resetGrid()
{

	int l = 0;

	for (int k = 0; k < 8; k++)
	{

		for (int j = 0; j < 8; j++)
		{

			l = l + 1;

			grid[k][j] = l;

		}

	}

}

//This functions checks to make sure the random number hasn't already been guessed
bool alreadyGuessed()
{

	int guess1 = 0;
	int guess2 = 0;
	int guess3 = 0;
	int guess4 = 0;
	int guess5 = 0;
	int guess6 = 0;
	int guess7 = 0;
	int guess8 = 0;
	int guess9 = 0;
	int guess10 = 0;
	int guess11 = 0;
	int guess12 = 0;
	int guess13 = 0;
	int guess14 = 0;
	int guess15 = 0;
	int guess16 = 0;
	int guess17 = 0;
	int guess18 = 0;
	int guess19 = 0;
	int guess20 = 0;
	int guess21 = 0;
	int guess22 = 0;
	int guess23 = 0;
	int guess24 = 0;
	int guess25 = 0;
	int guess26 = 0;
	int guess27 = 0;
	int guess28 = 0;
	int guess29 = 0;
	int guess30 = 0;
	int guess31 = 0;
	int guess32 = 0;
	int guess33 = 0;
	int guess34 = 0;
	int guess35 = 0;
	int guess36 = 0;
	int guess37 = 0;
	int guess38 = 0;
	int guess39 = 0;
	int guess40 = 0;
	int guess41 = 0;
	int guess42 = 0;
	int guess43 = 0;
	int guess44 = 0;
	int guess45 = 0;
	int guess46 = 0;
	int guess47 = 0;
	int guess48 = 0;
	int guess49 = 0;
	int guess50 = 0;
	int guess51 = 0;
	int guess52 = 0;
	int guess53 = 0;
	int guess54 = 0;
	int guess55 = 0;
	int guess56 = 0;
	int guess57 = 0;
	int guess58 = 0;
	int guess59 = 0;
	int guess60 = 0;
	int guess61 = 0;
	int guess62 = 0;
	int guess63 = 0;
	int guess64 = 0;

	if (randomGuess == 1)
	{

		if (guess1 == 0)
		{

			guess1 = 1;

			guessed = false;

		}
		else if (guess1 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 2)
	{

		if (guess2 == 0)
		{

			guess2 = 1;

			guessed = false;

		}
		else if (guess2 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 3)
	{

		if (guess3 == 0)
		{

			guess3 = 1;

			guessed = false;

		}
		else if (guess3 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 4)
	{

		if (guess4 == 0)
		{

			guess4 = 1;

			guessed = false;

		}
		else if (guess4 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 5)
	{

		if (guess5 == 0)
		{

			guess5 = 1;

			guessed = false;

		}
		else if (guess5 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 6)
	{

		if (guess6 == 0)
		{

			guess6 = 1;

			guessed = false;

		}
		else if (guess6 == 0)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 7)
	{

		if (guess7 == 0)
		{

			guess7 = 1;

			guessed = false;

		}
		else if (guess7 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 8)
	{

		if (guess8 == 0)
		{

			guess8 = 1;

			guessed = false;

		}
		else if (guess8 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 9)
	{

		if (guess9 == 0)
		{

			guess9 = 1;

			guessed = false;

		}
		else if (guess9 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 10)
	{

		if (guess10 == 0)
		{

			guess10 = 1;

			guessed = false;

		}
		else if (guess10 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 11)
	{

		if (guess11 == 0)
		{

			guess11 = 1;

			guessed = false;

		}
		else if (guess11 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 12)
	{

		if (guess12 == 0)
		{

			guess12 = 1;

			guessed = false;

		}
		else if (guess12 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 13)
	{

		if (guess13 == 0)
		{

			guess13 = 1;

			guessed = false;

		}
		else if (guess13 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 14)
	{

		if (guess14 == 0)
		{

			guess14 = 1;

			guessed = false;

		}
		else if (guess14 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 15)
	{

		if (guess15 == 0)
		{

			guess15 = 1;

			guessed = false;

		}
		else if (guess15 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 16)
	{

		if (guess16 == 0)
		{

			guess16 = 1;

			guessed = false;

		}
		else if (guess16 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 17)
	{

		if (7 == 0)
		{

			guess17 = 1;

			guessed = false;

		}
		else if (guess17 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 18)
	{

		if (guess18 == 0)
		{

			guess18 = 1;

			guessed = false;

		}
		else if (guess18 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 19)
	{

		if (guess19 == 0)
		{

			guess19 = 1;

			guessed = false;

		}
		else if (guess19 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 20)
	{

		if (guess21 == 0)
		{

			guess21 = 1;

			guessed = false;

		}
		else if (guess21 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 22)
	{

		if (guess22 == 0)
		{

			guess22 = 1;

			guessed = false;

		}
		else if (guess22 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 23)
	{

		if (guess23 == 0)
		{

			guess23 = 1;

			guessed = false;

		}
		else if (guess23 == 1)
		{

			guessed = true;
	
		}

	}
	else if (randomGuess == 24)
	{

		if (guess24 == 0)
		{

			guess24 = 1;

			guessed = false;

		}
		else if (guess24 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 25)
	{

		if (guess25 == 0)
		{

			guess25 = 1;

			guessed = false;

		}
		else if (guess25 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 26)
	{

		if (guess26 == 0)
		{

			guess26 = 1;

			guessed = false;

		}
		else if (guess26 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 27)
	{

		if (guess27 == 0)
		{

			guess27 = 1;

			guessed = false;

		}
		else if (guess27 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 28)
	{

		if (guess28 == 0)
		{

			guess28 = 1;

			guessed = false;

		}
		else if (guess28 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 29)
	{

		if (guess29 == 0)
		{

			guess29 = 1;

			guessed = false;

		}
		else if (guess29 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 30)
	{

		if (guess30 == 0)
		{

			guess30 = 1;

			guessed = false;

		}
		else if (guess30 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 31)
	{

		if (guess31 == 0)
		{

			guess31 = 1;

			guessed = false;

		}
		else if (guess31 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 32)
	{

		if (guess32 == 0)
		{

			guess32 = 1;

			guessed = false;

		}
		else if (guess32 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 33)
	{

		if (guess33 == 0)
		{

			guess33 = 1;

			guessed = false;

		}
		else if (guess33 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 34)
	{

		if (guess34 == 0)
		{

			guess34 = 1;

			guessed = false;

		}
		else if (guess34 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 35)
	{

		if (guess35 == 0)
		{

			guess35 = 1;

			guessed = false;

		}
		else if (guess35 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 36)
	{

		if (guess36 == 0)
		{

			guess36 = 1;

			guessed = false;

		}
		else if (guess36 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 37)
	{

		if (guess37 == 0)
		{

			guess37 = 1;

			guessed = false;

		}
		else if (guess37 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 38)
	{

		if (guess38 == 0)
		{

			guess38 = 1;

			guessed = false;

		}
		else if (guess38 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 39)
	{

		if (guess39 == 0)
		{

			guess39 = 1;

			guessed = false;

		}
		else if (guess39 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 40)
	{

		if (guess40 == 0)
		{

			guess40 = 1;

			guessed = false;

		}
		else if (guess40 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 41)
	{

		if (guess41 == 0)
		{

			guess41 = 1;

			guessed = false;
	
		}
		else if (guess41 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 42)
	{

		if (guess42 == 0)
		{

			guess42 = 1;

			guessed = false;

		}
		else if (guess42 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 43)
	{

		if (guess43 == 0)
		{

			guess43 = 1;

			guessed = false;

		}
		else if (guess43 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 44)
	{

		if (guess44 == 0)
		{

			guess44 = 1;

			guessed = false;

		}
		else if (guess44 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 45)
	{

		if (guess45 == 0)
		{

			guess45 = 1;

			guessed = false;

		}
		else if (guess45 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 46)
	{

		if (guess46 == 0)
		{

			guess46 = 1;

			guessed = false;

		}
		else if (guess46 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 47)
	{

	if (guess47 == 0)
		{

			guess47 = 1;

			guessed = false;

		}
		else if (guess47 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 48)
		{

		if (guess48 == 0)
		{

			guess48 = 1;

			guessed = false;

		}
		else if (guess48 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 49)
	{

		if (guess49 == 0)
		{

			guess49 = 1;

			guessed = false;

		}
		else if (guess49 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 50)
	{

		if (guess50 == 0)
		{

			guess50 = 1;

			guessed = false;

		}
		else if (guess50 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 51)
	{

		if (guess51 == 0)
		{

			guess51 = 1;

			guessed = false;

		}
		else if (guess51 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 52)
	{

		if (guess52 == 0)
		{

			guess52 = 1;

			guessed = false;

		}
		else if (guess52 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 53)
	{

		if (guess53 == 0)
		{

			guess53 = 1;

			guessed = false;

		}
		else if (guess53 == 1)
		{

			guessed = true;
	
		}

	}
	else if (randomGuess == 54)
	{

		if (guess54 == 0)
		{

			guess54 = 1;

			guessed = false;

		}
		else if (guess54 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 55)
	{

		if (guess55 == 0)
		{

			guess55 = 1;

			guessed = false;

		}
		else if (guess55 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 56)
	{

		if (guess56 == 0)
		{

			guess56 = 1;

			guessed = false;

		}
		else if (guess56 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 57)
	{

		if (guess57 == 0)
		{

			guess57 = 1;

			guessed = false;

		}
		else if (guess57 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 58)
	{

		if (guess58 == 0)
		{

			guess58 = 1;

			guessed = false;

		}
		else if (guess58 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 59)
	{

		if (guess59 == 0)
		{

			guess59 = 1;

			guessed = false;

		}
		else if (guess59 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 60)
	{

		if (guess61 == 0)
		{

			guess61 = 1;

			guessed = false;

		}
		else if (guess61 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 62)
	{

		if (guess62 == 0)
		{

			guess62 = 1;

			guessed = false;

		}
		else if (guess62 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 63)
	{

		if (guess63 == 0)
		{

			guess63 = 1;

			guessed = false;

		}
		else if (guess63 == 1)
		{

			guessed = true;

		}

	}
	else if (randomGuess == 64)
	{

		if (guess64 == 0)
		{

			guess64 = 1;

			guessed = false;

		}
		else if (guess64 == 1)
		{

			guessed = true;

		}

	}

	return guessed;

}