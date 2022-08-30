#include <iostream>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <time.h>
using namespace std;

void setPos(int N, int pos[]) 
{
	for (int i = 0; i < N; i++) 
	{
		pos[i] = -1;
	}
}

void setBoard(char board[][4], char name[][4], int pos[], int size, int N) 
{
	for(int i = 0; i < size * size; i++) 
	{
		memcpy(board[i], "   ", 4);
	}
	
	for(int i = 0; i < N; i++) 
	{
		if(pos[i] != -1)
		{
			memcpy(board[pos[i]], name[i], 4);
		}
	}
}

void printHorizontalLine(int size) 
{
	for(int i = 0; i < size; i++)
	{
		cout << " -------";
	}
	cout << endl;
}

void printVerticalLine(int size) 
{
	for(int i = 0; i < size; i++)
	{
		cout << "       |";
	}
	cout << endl;
}

void printBoard3x3(char board[][4], int map3x3[][3], int size) 
{
	for(int i = 0; i < size; i++)
	{
		printHorizontalLine(size);
		cout << "|";
		printVerticalLine(size);
		cout << "|";
		for(int j = 0; j < size; j++)
		{
			cout << "  " << board[map3x3[i][j]] << "  |";
		}
		cout << endl << "|";
		printVerticalLine(size);
	}
	printHorizontalLine(size);
}

void printBoard5x5(char board[][4], int map5x5[][5], int size) 
{
	for(int i = 0; i < size; i++)
	{
		printHorizontalLine(size);
		cout << "|";
		printVerticalLine(size);
		cout << "|";
		for(int j = 0; j < size; j++)
		{
			cout << "  " << board[map5x5[i][j]] << "  |";
		}
		cout << endl << "|";
		printVerticalLine(size);
	}
	printHorizontalLine(size);
}

void printBoard7x7(char board[][4], int map7x7[][7], int size) 
{
	for(int i = 0; i < size; i++) 
	{
		printHorizontalLine(size);
		cout << "|";
		printVerticalLine(size);
		cout << "|";
		for(int j = 0; j < size; j++)
		{
			cout << "  " << board[map7x7[i][j]] << "  |";
		}
		cout << endl << "|";
		printVerticalLine(size);
	}
	printHorizontalLine(size);
}

void gameplayMap3x3(char board[][4], char name[][4], int pos[], int map3x3[][3], int size, int N) 
{
	int move;
	int gamefinish = -1;
	while(gamefinish == -1) 
	{
		for(int i = 0; i < N; i++) 
		{
			move = rand() % 4 + 1;
			cout << name[i] << " rolled into " << move << endl;
			if(pos[i] + move > size * size - 1)
			{
				cout << name[i] << " cannot move forward" << endl;
			}
			else
			{
				pos[i] = pos[i] + move;
				cout << name[i] << " moved forward " << move << " steps" << endl; 
				if(pos[i] == size * size - 1)
				{
					gamefinish = i;
					
					break;
				}
				for(int j = 0; j < N; j++)
				{
					if(pos[i] == pos[j] && i != j)
					{
						pos[j] = -1;
						cout << endl << name[i] << " kicked " << name[j] << endl;
						break;
					}
				}
			}
			setBoard(board, name, pos, size, N);
			printBoard3x3(board, map3x3, size);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << endl <<  "--------------------------------------------" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			getch();
		}
	}
	setBoard(board, name, pos, size, N);
	printBoard3x3(board, map3x3, size);
	cout << endl << name[gamefinish] << " is the winner!!!" << endl << endl; 
}

void gameplayMap5x5(char board[][4], char name[][4], int pos[], int map5x5[][5], int size, int N)
{
	int move;
	int gamefinish = -1;
	while(gamefinish == -1)
	{
		for(int i = 0; i < N; i++)
		{
			move = rand() % 4 + 1;
			cout << name[i] << " rolled into " << move << endl;
			if(pos[i] + move > size * size - 1)
			{
				cout << name[i] << " cannot move forward" << endl;
			}
			else
			{
				pos[i] = pos[i] + move;
				cout << name[i] << " moved forward " << move << " steps" << endl; 
				if(pos[i] == size * size - 1)
				{
					gamefinish = i;
					
					break;
				}
				for(int j = 0; j < N; j++)
				{
					if(pos[i] == pos[j] && i != j)
					{
						pos[j] = -1;
						cout << endl << name[i] << " kicked " << name[j] << endl;
						break;
					}
				}
			}
			setBoard(board, name, pos, size, N);
			printBoard5x5(board, map5x5, size);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << endl <<  "--------------------------------------------" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			getch();
		}
		
	}
	setBoard(board, name, pos, size, N);
	printBoard5x5(board, map5x5, size);
	cout << endl << name[gamefinish] << " is the winner!!!" << endl << endl; 
}

void gameplayMap7x7(char board[][4], char name[][4], int pos[], int map7x7[][7], int size, int N)
{
	int move;
	int gamefinish = -1;
	while(gamefinish == -1)
	{
		for(int i = 0; i < N; i++)
		{
			move = rand() % 4 + 1;
			cout << name[i] << " rolled into " << move << endl;
			if(pos[i] + move > size * size - 1)
			{
				cout << name[i] << " cannot move forward" << endl;
			}
			else
			{
				pos[i] = pos[i] + move;
				cout << name[i] << " moved forward " << move << " steps" << endl; 
				if(pos[i] == size * size - 1)
				{
					gamefinish = i;
				
					break;
				}
				for(int j = 0; j < N; j++)
				{
					if(pos[i] == pos[j] && i != j)
					{
						pos[j] = -1;
						cout << name[i] << " kicked " << name[j] << endl;
						break;
					}
				}
			}
			setBoard(board, name, pos, size, N);
			printBoard7x7(board, map7x7, size);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << endl <<  "----------------------------------------------------------" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			getch();
		}
		
	}
	setBoard(board, name, pos, size, N);
	printBoard7x7(board, map7x7, size);
	cout << endl << name[gamefinish] << " is the winner!!!" << endl << endl;
}

int main(){
	srand(time(0));
	int numofgame, size, N, pos[N];
	char r, name[N][4];
	
	// Initial
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "WELCOME TO THE GAME!!!" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "----------------------" << endl;
	cout << "Push 3 for 3x3 map" << endl;
	cout << "Push 5 for 5x5 map" << endl;
	cout << "Push 7 for 7x7 map" << endl;
	cout << "----------------------" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	
	// choose map
	cout << "Choose the map: ";
	cin>> size;
	
	// input validiation for number of player
	while (size < 3 || size == 4 || size == 6 || size > 7)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "----------------------" << endl;
		cout << "Push 3 for 3x3 map" << endl;
		cout << "Push 5 for 5x5 map" << endl;
		cout << "Push 7 for 7x7 map" << endl;
		cout << "----------------------" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "Choose the map again: ";
		cin >> size;
	}
	
	// enter the number of player
	cout << endl << "Number of player: ";
	cin >> N;
	
	// input validiation for number of player
	while (N <= 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << endl << "----------------------" << endl;
		cout << "Number of players has to be higher than 1!!!" << endl;
		cout << "----------------------" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "Enter number of player again: ";
		cin >> N;
	}
	
	// Note for the input of player
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << endl << "----------------------" << endl;
	cout << "Enter the name of " << N << " players."<< endl;
	cout << "Name must have only 3 characters." << endl;
	cout << "----------------------" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	
	// Enter the names of players
	for(int i = 0 ; i < N; i++)
	{
		cout << "Player" << i + 1 << "'s name: "; 
		cin >> name[i];
	}
	
	cout << endl << "----------------------" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	
	// Reset all the values to -1
	setPos(N, pos);
	
	// Initialization 3 kinds of maps: 3x3, 4x4, 5x5.
	char board[size*size][4]; 
	int map3x3[3][3] = {{0, 5, 6}, {1, 4, 7}, {2, 3, 8}};
	int map5x5[5][5] = {{0, 1, 2, 3, 4}, {15, 16, 17, 18, 5}, {14, 23, 24, 19, 6}, {13, 22, 21, 20, 7}, {12, 11, 10, 9, 8}};
	int map7x7[7][7] = {{0, 1, 2, 3, 4, 5, 6}, {23, 24, 25, 26, 27, 28, 7}, {22, 39, 40, 41, 42, 29, 8}, {21, 38, 47, 48, 43, 30, 9}, {20, 37, 46, 45, 44, 31, 10}, {19, 36, 35, 34, 33, 32, 11}, {18, 17, 16, 15, 14, 13, 12}};
	
	// Ending for 3 maps
	// Map 3x3
	if (size == 3)
	{
		do
		{
			setPos(N, pos);
			gameplayMap3x3(board , name, pos , map3x3, size , N);
			numofgame++;
			cout << "Do you want to play again? ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << endl << "----------------------" << endl;
			cout << "Push y for yes" << endl;
			cout << "Push n for no"  << endl;
			cout << "----------------------" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cin >> r;
		}
		while(r == 'y');
	}
	
	// Map 5x5
	if (size == 5)
	{
		do
		{
			setPos(N, pos);
			gameplayMap5x5(board , name, pos , map5x5, size , N);
			numofgame++;
			cout << "Do you want to play again? ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << endl << "----------------------" << endl;
			cout << "Push y for yes" << endl;
			cout << "Push n for no"  << endl;
			cout << "----------------------" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cin >> r;
		}
		while(r == 'y');
	}
	
	// Map 7x7
	if(size == 7)
	{
		do 
		{ 
			setPos(N, pos);
			gameplayMap7x7(board , name, pos , map7x7, size , N);
			numofgame++;
			cout << "Do you want to play again? ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << endl << "----------------------" << endl;
			cout << "Push y for yes" << endl;
			cout << "Push n for no"  << endl;
			cout << "----------------------" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		    cin >> r;
		} 
		while(r == 'y');
	}
	return 0;
}









