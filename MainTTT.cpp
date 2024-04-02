#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;



void fScreenCleaner()
{
	system("CLS");
}


void fGameBoard(char cBoard[3][3])
{
	int iBoardRows, iBoardColumns;
	int iCounter = 0;
	string sRows = "Rows";
	cout << "       Columns\n" << "      0   1   2\n";

		for (iBoardRows = 0; iBoardRows <= 3; iBoardRows++)
		{
			if (iCounter < 4)
			{
				cout << sRows[iCounter] << "  ";
				iCounter++;
			}
			if (iBoardRows < 3)
			{	
				if (iBoardRows == 2)
					{
						cout << "   ";
					}
				cout << iBoardRows << " ";

				for (iBoardColumns = 0; iBoardColumns < 3; iBoardColumns++)
				{
					cout << " ";
					cout << cBoard[iBoardRows][iBoardColumns];
					if (iBoardColumns < 2)
					{
						cout << " |";
					}
				}
			}
		cout << "\n";
		if (iBoardRows < 2 && iCounter < 4)
		{
			cout << sRows[iCounter] << " ";
			iCounter++;
			cout << "   ---|---|---\n";
		}
		} 
}
void fInitializingGameBoard(char cBoard[3][3])
{
	int iBoardRows, iBoardColumns;
	for (iBoardRows = 0; iBoardRows <= 3; iBoardRows++)
	{
		for (iBoardColumns = 0; iBoardColumns < 3; iBoardColumns++)
		{
			cBoard[iBoardRows][iBoardColumns] = '-';
		}
	}
}
void fGameScreen()
{
	fScreenCleaner();
	char cBoard[3][3];
	int iBoardRows, iBoardColumns;
	int iBoardRowOption, iBoardColumnOption;
	bool bGameStatus = false;
	int iPlayerTurn = 1;
	int iTurns = 0;
	string sGameFeedbackMessage = "Place a Valid Location";
	fInitializingGameBoard(cBoard);

	while (iTurns < 10 && bGameStatus == false)
	{
		fScreenCleaner();
		fGameBoard(cBoard);
		cout << iTurns << "\n";
		if (iPlayerTurn == 1)
		{
			cout << sGameFeedbackMessage << "\n";
			cout << "Player Turn: 01 \n\n";
		}
		else
		{
			cout << sGameFeedbackMessage << "\n";
			cout << "Player Turn: 02 \n\n";
		}

		cout << "Type the Row to be Marked: ";
		cin >> iBoardRowOption;
		cout << "Type the Column to be Marked: ";
		cin >> iBoardColumnOption;

		if (cBoard[iBoardRowOption][iBoardColumnOption] == 'X' || cBoard[iBoardRowOption][iBoardColumnOption] == 'O' && iBoardRowOption > 2 || iBoardColumnOption > 2)
		{
			sGameFeedbackMessage = "Location was Invalid. Try Again.";
		}
		else
		{
			sGameFeedbackMessage = "Place a Valid Location";
			if (iPlayerTurn == 1)
			{

				cBoard[iBoardRowOption][iBoardColumnOption] = 'X';
				iPlayerTurn = 2;
			}
			else
			{
				cBoard[iBoardRowOption][iBoardColumnOption] = 'O';
				iPlayerTurn = 1;
			}
			iTurns++;
		}

		/*for (iBoardRows = 0; iBoardRows < 3; iBoardRows++)
		{
			if (cBoard[iBoardRows][0] == 'X' && cBoard[iBoardRows][0] == cBoard[iBoardRows][1] && cBoard[iBoardRows][1] == cBoard[iBoardRows][2])
			{
				fScreenCleaner();
				int iOption = 0;
				while (iOption == 0)
				{
					cout << "X Won the game";
					cin >> iOption;
				}
				
			}
		}
		for (iBoardColumns = 0; iBoardColumns < 3; iBoardColumns++)
		{
			if (cBoard[0][iBoardColumns] == 'X' && cBoard[0][iBoardColumns] == cBoard[1][iBoardColumns] && cBoard[1][2] == cBoard[2][iBoardColumns])
			{
				fScreenCleaner();
				cout << "X Won the game";
			}
		}*/

	}

}


void fMainMenu()
{
	fScreenCleaner();
	int iOptions = 0;
	while (iOptions < 1 || iOptions > 3)
	{
		cout << "!!!!!WELCOME!!!!!\n";
		cout << "!!!!!!!!TO!!!!!!!\n";
		cout << "!!!TIC-TAC-TOE!!!\n\n";
		cout << "Choose an Option:\n";
		cout << "1 - Play Game\n";
		cout << "2 - About the Game\n";
		cout << "3 - Exit the Game\n";
		cin >> iOptions;

		switch (iOptions)
		{
		case 1:
			fGameScreen();
			break;
		case 2:
			cout << "About the Game";
			break;
		case 3: 
			cout << "See You Later";
			break;
		}
	}
}


int main()
{
	fMainMenu();

	return 0;
}