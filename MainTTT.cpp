#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


//Functions Header
void fMainMenu();
void fGameScreen();


//Function: Cleans Terminal
void fScreenCleaner()
{
	system("CLS");
}


//Function: Ends Terminal
void fExitGame()
{
	exit(0);
}


//Function: About the Game Screen
void fAboutScreen()
{
fScreenCleaner();
int iOption = 0;
while (iOption == 0)
{
	cout << "!!!!ABOUT!!\n";
	cout << "!!!!THE!!!!\n";
	cout << "!!!!GAME!!!\n\n";
	cout << "This is a Game of Tic-Tac-Toe in which you play against another player to score marks in a row, column or diagonaly.\n";
	cout << "By Succesfully scoring in one of those three ways, you will be declared the Winner of the Match.\n";
	cout << "This is a Game made for Studying purposes\n\n";
	cout << "Credits: Jefferson Souza aka Sarmyte\n\n";
	cout << "Input 1 to go Back to the Main Menu: \n";
	cin >> iOption;
}

fMainMenu();

}


//Function: Checks Rows, Columns and Diagonals to determine a Winner and Prints the Winner on the Screen
void fGameWinnerCheckandScreen(char cBoard[3][3],int iPlayerTurn)
{
	int iBoardRows, iBoardColumns;

	//Checking for Game Winner and Winner Screen.
	for (iBoardRows = 0; iBoardRows < 3; iBoardRows++)
	{
		if (cBoard[iBoardRows][0] != '-' && cBoard[iBoardRows][0] == cBoard[iBoardRows][1] && cBoard[iBoardRows][1] == cBoard[iBoardRows][2])
		{
			fScreenCleaner();
			int iOptions = 0;
			while (iOptions == 0)
			{
				if (cBoard[iBoardRows][0] == 'X')
				{
					cout << "!!!CONGRATULATIONS!!!\n";
					cout << "!!!!!PLAYER-ONE!!!!!!\n";
					cout << "!!!!WON THE GAME!!!!!\n\n";
				}
				else
				if (cBoard[iBoardRows][0] == 'O')
				{
					cout << "!!!CONGRATULATIONS!!!\n";
					cout << "!!!!!PLAYER-TWO!!!!!!\n";
					cout << "!!!!WON THE GAME!!!!!\n\n";
				}


				cout << "Choose an Option:\n";
				cout << "1 - Play Again\n";
				cout << "2 - Main Menu\n";
				cout << "3 - Exit the Game\n";

				cin >> iOptions;

				switch (iOptions)
				{
				case 1:
					fGameScreen();
					break;
				case 2:
					fMainMenu();
					break;
				case 3:
					cout << "See You Later";
					fExitGame();
					break;
				}
			}

		}
	}
	for (iBoardColumns = 0; iBoardColumns < 3; iBoardColumns++)
	{
		if (cBoard[0][iBoardColumns] != '-' && cBoard[0][iBoardColumns] == cBoard[1][iBoardColumns] && cBoard[1][iBoardColumns] == cBoard[2][iBoardColumns])
		{
			fScreenCleaner();
			int iOptions = 0;
			while (iOptions == 0)
			{
				if (cBoard[0][iBoardColumns] == 'X')
				{
					cout << "!!!CONGRATULATIONS!!!\n";
					cout << "!!!!!PLAYER-ONE!!!!!!\n";
					cout << "!!!!WON THE GAME!!!!!\n\n";
				}
				else
					if (cBoard[0][iBoardColumns] == 'O')
					{
						cout << "!!!CONGRATULATIONS!!!\n";
						cout << "!!!!!PLAYER-TWO!!!!!!\n";
						cout << "!!!!WON THE GAME!!!!!\n\n";
					}


				cout << "Choose an Option:\n";
				cout << "1 - Play Again\n";
				cout << "2 - Main Menu\n";
				cout << "3 - Exit the Game\n";

				cin >> iOptions;

				switch (iOptions)
				{
				case 1:
					fGameScreen();
					break;
				case 2:
					fMainMenu();
					break;
				case 3:
					cout << "See You Later";
					fExitGame();
					break;
				}
			}
		}
	}
	if (cBoard[0][0] != '-' && cBoard[0][0] == cBoard[1][1] && cBoard[1][1] == cBoard[2][2] || cBoard[0][2] != '-' && cBoard[0][2] == cBoard[1][1] && cBoard[1][1] == cBoard[2][0])
	{
		fScreenCleaner();
		int iOptions = 0;
		while (iOptions == 0)
		{
			if (cBoard[1][1] == 'X')
			{
				cout << "!!!CONGRATULATIONS!!!\n";
				cout << "!!!!!PLAYER-ONE!!!!!!\n";
				cout << "!!!!WON THE GAME!!!!!\n\n";
			}
			else
				if (cBoard[1][1] == 'O')
				{
					cout << "!!!CONGRATULATIONS!!!\n";
					cout << "!!!!!PLAYER-TWO!!!!!!\n";
					cout << "!!!!WON THE GAME!!!!!\n\n";
				}


			cout << "Choose an Option:\n";
			cout << "1 - Play Again\n";
			cout << "2 - Main Menu\n";
			cout << "3 - Exit the Game\n";

			cin >> iOptions;

			switch (iOptions)
			{
			case 1:
				fGameScreen();
				break;
			case 2:
				fMainMenu();
				break;
			case 3:
				cout << "See You Later";
				fExitGame();
				break;
			}
		}
	}
}
//Function: Displays Current player Turn and Message to check if the selected place marked is still valid to mark
void fGameSystemMessages(int iPlayerTurn, string sGameFeedbackMessage)
{
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
}
//Function: Prints the Game Board on Screen
void fGameBoard(char cBoard[3][3])
{
	int iBoardRows, iBoardColumns;
	int iCounter = 0;
	string sRows = "Rows";
	cout << "       Columns\n" << "      0   1   2\n\n";

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
//Function: Populates the Game Board with '-'
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
//Function: Main Game Screen
void fGameScreen()
{
	fScreenCleaner();
	
	char cBoard[3][3];
	int iOptions = 0;
	int iBoardRows, iBoardColumns;
	int iBoardRowOption, iBoardColumnOption;
	int iPlayerTurn = 1;
	int iTurns = 0;
	string sGameFeedbackMessage = "Place a Valid Location";

	fInitializingGameBoard(cBoard);

	while (iTurns < 9)
	{
		fScreenCleaner();
		fGameBoard(cBoard);
		cout << iTurns << "\n";
		fGameSystemMessages(iPlayerTurn, sGameFeedbackMessage);

		cout << "Type the Row to be Marked: ";
		cin >> iBoardRowOption;
		cout << "Type the Column to be Marked: ";
		cin >> iBoardColumnOption;

		//Validating player Mark Option.
		if (iBoardRowOption > 3 || iBoardRowOption < 0 || iBoardColumnOption > 3 || iBoardColumnOption < 0)
		{
			sGameFeedbackMessage = "Location was Invalid. Try Again.";
		}
		else 
		if (cBoard[iBoardRowOption][iBoardColumnOption] == '-')
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
		else
		{
			sGameFeedbackMessage = "Location was Invalid. Try Again.";
		}
		fGameWinnerCheckandScreen(cBoard, iPlayerTurn);
	}
	fScreenCleaner();

	cout << "!!!IT'S A DRAW!!!\n\n";
	cout << "Choose an Option:\n";
	cout << "1 - Play Again\n";
	cout << "2 - Main Menu\n";
	cout << "3 - Exit the Game\n";

	cin >> iOptions;

	switch (iOptions)
	{
	case 1:
		fGameScreen();
		break;
	case 2:
		fMainMenu();
		break;
	case 3:
		cout << "See You Later";
		fExitGame();
		break;
	}

}


//Function: Main Menu Screen
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
			fAboutScreen();
			break;
		case 3: 
			cout << "See You Later";
			fExitGame();
			break;
		}
	}
}


int main()
{
	fMainMenu();

	return 0;
}