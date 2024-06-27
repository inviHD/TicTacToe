#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

std::string header = "Tic Tac Toe!\n------------------------------------------------\n";

char player1pice = 'X';
char player2pice = 'O';

std::string player1name = "Player 1";
std::string player2name = "Player 2";
void renderField(char field[])
{
	std::cout << header;
	std::cout << " --1---2---3--\n";
	std::cout << " | " << field[0] << " | " << field[1] << " | " << field[2] << " | " << "\n";
	std::cout << " --4---5---6--\n";
	std::cout << " | " << field[3] << " | " << field[4] << " | " << field[5] << " | " << "\n";
	std::cout << " --7---8---9--\n";
	std::cout << " | " << field[6] << " | " << field[7] << " | " << field[8] << " | " << "\n";
}

void playGame()
{
	char field[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	bool gameOver = false;

	int actPlayer = 1;
	char actPice = player1pice;
	std::string actPlayerName = player1name;

	while (!gameOver)
	{
		// Gaming
		std::system("cls");

		renderField(field);
		std::cout << "It's " << actPlayerName << "'s turn. Choose a field: ";
		bool moveInvalid = true;
		while (moveInvalid)
		{
			int fieldChoice;
			std::cin >> fieldChoice;
			if (field[fieldChoice - 1] == ' ') {
				field[fieldChoice - 1] = actPice;
				moveInvalid = false;
			}
			else
			{
				std::cout << "Invalid field!";
				continue;
			}
		}

		// Check for win
		if (field[0] == actPice && field[1] == actPice && field[2] == actPice)
		{
			gameOver = true;
		}
		else if (field[3] == actPice && field[4] == actPice && field[5] == actPice)
		{
			gameOver = true;
		}
		else if (field[6] == actPice && field[7] == actPice && field[8] == actPice)
		{
			gameOver = true;
		}
		else if (field[0] == actPice && field[3] == actPice && field[6] == actPice)
		{
			gameOver = true;
		}
		else if (field[1] == actPice && field[4] == actPice && field[7] == actPice)
		{
			gameOver = true;
		}
		else if (field[2] == actPice && field[5] == actPice && field[8] == actPice)
		{
			gameOver = true;
		}
		else if (field[0] == actPice && field[4] == actPice && field[8] == actPice)
		{
			gameOver = true;
		}
		else if (field[2] == actPice && field[4] == actPice && field[6] == actPice)
		{
			gameOver = true;
		}


		if (!gameOver)
		{
			// Change player
			if (actPlayer == 1)
			{
				actPlayer = 2;
				actPice = player2pice;
				actPlayerName = player2name;
			}
			else
			{
				actPlayer = 1;
				actPice = player1pice;
				actPlayerName = player1name;
			}
		}
	}

	std::system("cls");
	// End of game
	renderField(field);
	std::cout << "Congratulations " << actPlayerName << "! You won!\n";
	std::cout << "Do you want to play again? (y/n)\nPress 's' to save the game in a .txt file! (Save in the same dir as the .exe)\n";
	char playAgain;
	std::cin >> playAgain;
	if (playAgain == 'y')
	{
		playGame();
	}
	else if (playAgain == 's')
	{
		std::cout << "Saving game...";
		// The render game field will be saved in a .txt file
		std::ofstream file;
		file.open("TicTacToeSave.txt");
		file << "Tic Tac Toe Save\n";
		file << "-----------------\n";
		file << "Player 1: " << player1name << "\n";
		file << "Player 2: " << player2name << "\n";
		file << "-----------------\n";
		file << "Player 1 pice: " << player1pice << "\n";
		file << "Player 2 pice: " << player2pice << "\n";
		file << "-----------------\n";
		file << " --1---2---3--\n";
		file << " | " << field[0] << " | " << field[1] << " | " << field[2] << " | " << "\n";
		file << " --4---5---6--\n";
		file << " | " << field[3] << " | " << field[4] << " | " << field[5] << " | " << "\n";
		file << " --7---8---9--\n";
		file << " | " << field[6] << " | " << field[7] << " | " << field[8] << " | " << "\n";
		file.close();
		std::cout << "Game saved in the same dir as the .exe!";

	}
	else
	{
		std::cout << "Thanks for playing!";
	}
	std::cin;
}

int main()
{
	std::cout << header;
	std::cout << "Welcome to Tic Tac Toe!\n";
	std::cout << "Press q and enter for QuickPlay with default settings.\n";
	std::cout << "Press c and enter for CustomPlay with custom settings.\n";
	std::cout << ">>> ";
	char playMode;
	std::cin >> playMode;
	if (playMode == 'q')
	{
		playGame();
	}
	else if (playMode == 'c')
	{
		bool namesInvaild = true;
		while(namesInvaild)
		{
			std::cout << "Enter the name of player 1: ";
			std::cin >> player1name;
			std::cout << "Enter the name of player 2: ";
			std::cin >> player2name;

			if (player1name == player2name)
			{
				std::cout << "Names can't be the same! Please choose different ones!";
			}
			else
			{
				namesInvaild = false;
			}
		}

		bool picesInvaild = true;
		while (picesInvaild)
		{
			std::cout << "Enter the pice for player 1: ";
			std::cin >> player1pice;
			std::cout << "Enter the pice for player 2: ";
			std::cin >> player2pice;

			if (player1pice == player2pice)
			{
				std::cout << "Pices can't be the same! Please choose different ones!";
			}
			else
			{
				picesInvaild = false;
			}
		}



		playGame();
	}
	else
	{
		std::cout << "Invalid input!";
	}	
}
