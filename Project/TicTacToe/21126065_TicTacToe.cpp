#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int history[2] = {0, 0};
char player1, player2;

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void role() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "  > to go right " << endl;
    cout << "  < to go left " << endl;
    cout << "  /\\ to go up " << endl;
    cout << "  \\/ to go down " << endl;
    cout << " Enter to choose." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << " Three identical characters in a row, column or diagnol is win." << endl;
}

void role7x7() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "  > to go right " << endl;
    cout << "  < to go left " << endl;
    cout << "  /\\ to go up " << endl;
    cout << "  \\/ to go down " << endl;
    cout << " Enter to choose." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << " Four identical characters in a row, column or diagnol is win." << endl;
}

int move() {
    char c = _getch();
    if ((int)c == -32)
    {
        c = _getch();
    }
    switch ((int)c) {
    case 80:// DOWN
        return 1;
    case 72:// UP
        return 2;
    case 77:// RIGHT
        return 3;
    case 75:// LEFT
        return 4;
    case 27:// ESC
        return 8;
    case 13:// ENTER
        return 5;
    case 32://SPACE
        return 6;
    default://!!INVALID!!
        return 0;
    }
}

void setBoard(char board[][7], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = ' ';
}


void printHorizontalLine(int size) {
    for (int i = 0; i < size; i++) {
        cout << " -----";
    }
    cout << endl;
}

void printVerticalLine(int size) {
    for (int i = 0; i < size; i++) {
        cout << "     |";
    }
    cout << endl;
}

void printBoard(char board[][7], int size) {
    for (int i = 0; i < size; i++)
    {
        printHorizontalLine(size);
        cout << "|";
        printVerticalLine(size);
        cout << "|";
        for (int j = 0; j < size; j++)
            cout << "  " << board[i][j] << "  |";
        cout << endl << "|";
        printVerticalLine(size);
    }
    printHorizontalLine(size);
}

bool checkWinner3x3(char board[][7], int size) {
    bool check = false;
    for (int i = 0; i < size; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            check = true;
            break;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            check = true;
            break;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        check = true;
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
        check = true;
    return check;
}

bool checkWinner5x5(char board[][7], int size) {
    bool check = false;
    for (int i = 0; i < size; i++) {
    	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
    		check = true;
    		break;
    	}
		if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][1] != ' ') {
    		check = true;
    		break;
    	}	
    	if (board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][2] != ' ') {
    		check = true;
    		break;
    	}
    	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
    		check = true;
    		break;
    	}
    	if (board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[1][i] != ' ') {
    		check = true;
    		break;
    	}
    	if (board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[2][i] != ' ') {
    		check = true;
    		break;
    	}
    	if (i < 3 && board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && board[i][i] != ' ') {
    	 	check = true;
    	 	break;
    	}
	}
	if (board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[0][4] != ' ') 
    	check = true;
    if (board[3][1] == board[1][3] && board[1][3] == board[2][2] && board[3][1] != ' ') 
    	check = true;
    if (board[2][2] == board[3][1] && board[3][1] == board[4][0] && board[2][2] != ' ') 
    	check = true;
	if (board[0][2] == board[1][3] && board[1][3] == board[3][4] && board[0][2] != ' ') 
    	check = true;
    if (board[2][0] == board[3][1] && board[3][1] == board[4][3] && board[2][0] != ' ') 
    	check = true;	
    if (board[0][1] == board[1][2] && board[1][2] == board[2][3] && board[0][1] != ' ') 
    	check = true;
    if (board[3][4] == board[1][2] && board[1][2] == board[2][3] && board[3][4] != ' ') 
    	check = true;
    if (board[1][0] == board[2][1] && board[2][1] == board[3][2] && board[1][0] != ' ') 
    	check = true;
    if (board[4][3] == board[2][1] && board[2][1] == board[3][2] && board[4][3] != ' ') 
    	check = true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') 
    	check = true;
    if (board[2][4] == board[3][3] && board[3][3] == board[4][2] && board[2][4] != ' ') 
    	check = true;
    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[0][3] != ' ') 
    	check = true;
    if (board[3][0] == board[1][2] && board[1][2] == board[2][1] && board[3][0] != ' ') 
    	check = true;
    if (board[1][4] == board[2][3] && board[2][3] == board[3][2] && board[1][4] != ' ') 
    	check = true;
    if (board[4][1] == board[2][3] && board[2][3] == board[3][2] && board[4][1] != ' ') 
    	check = true;
    return check;
}

bool checkWinner7x7(char board[][7], int size) {
    bool check = false;
    for (int i = 0; i < size; i++) {
    	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][0] != ' ') {
    		check = true;
    		break;
    	}
		if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][1] != ' ') {
    		check = true;
    		break;
    	}	
    	if (board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][4] == board[i][5] && board[i][2] != ' ') {
    		check = true;
    		break;
    	}
    	if (board[i][3] == board[i][4] && board[i][4] == board[i][5] && board[i][5] == board[i][6] && board[i][3] != ' ') {
    		check = true;
    		break;
    	}
    	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[0][i] != ' ') {
    		check = true;
    		break;
    	}
    	if (board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[1][i] != ' ') {
    		check = true;
    		break;
    	}
    	if (board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[4][i] == board[5][i] && board[2][i] != ' ') {
    		check = true;
    		break;
    	}
    	if (board[3][i] == board[4][i] && board[4][i] == board[5][i] && board[5][i] == board[6][i] && board[3][i] != ' ') {
    		check = true;
    		break;
    	}
    	if (i < 4 && board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && board[i + 3][i + 3] == board[i + 2][i + 2] && board[i][i] != ' ') {
    	 	check = true;
    	 	break;
    	}
	}
	if (board[3][0] == board[4][1] && board[4][1] == board[5][2] && board[5][2] == board[6][3] && board[3][0] != ' ') 
    	check = true;
    if (board[0][3] == board[1][4] && board[1][4] == board[2][5] && board[2][5] == board[3][6] && board[0][3] != ' ') 
    	check = true;
    if (board[2][0] == board[3][1] && board[3][1] == board[4][2] && board[4][2] == board[5][3] && board[2][0] != ' ') 
    	check = true;
    if (board[6][4] == board[3][1] && board[3][1] == board[4][2] && board[4][2] == board[5][3] && board[6][4] != ' ') 
    	check = true;
    if (board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[2][4] == board[3][5] && board[0][2] != ' ') 
    	check = true;
    if (board[4][6] == board[1][3] && board[1][3] == board[2][4] && board[2][4] == board[3][5] && board[4][6] != ' ') 
    	check = true;
    if (board[0][1] == board[1][2] && board[1][2] == board[2][3] && board[2][3] == board[3][4] && board[0][1] != ' ') 
    	check = true;
    if (board[4][5] == board[1][2] && board[1][2] == board[2][3] && board[2][3] == board[3][4] && board[4][5] != ' ') 
    	check = true;
    if (board[4][5] == board[5][6] && board[5][6] == board[2][3] && board[2][3] == board[3][4] && board[4][5] != ' ') 
    	check = true;
    if (board[1][0] == board[2][1] && board[2][1] == board[3][2] && board[4][3] == board[3][2] && board[1][0] != ' ') 
    	check = true;
    if (board[5][4] == board[2][1] && board[2][1] == board[3][2] && board[4][3] == board[3][2] && board[5][4] != ' ') 
    	check = true;
    if (board[5][4] == board[6][5] && board[6][5] == board[3][2] && board[4][3] == board[3][2] && board[5][4] != ' ') 
    	check = true;	
    if (board[0][6] == board[1][5] && board[1][5] == board[2][4] && board[2][4] == board[3][3] && board[0][6] != ' ') 
    	check = true;
    if (board[4][2] == board[1][5] && board[1][5] == board[2][4] && board[2][4] == board[3][3] && board[4][2] != ' ') 
    	check = true;
    if (board[4][2] == board[5][1] && board[5][1] == board[2][4] && board[2][4] == board[3][3] && board[4][2] != ' ') 
    	check = true;
    if (board[4][2] == board[5][1] && board[5][1] == board[6][0] && board[6][0] == board[3][3] && board[4][2] != ' ') 
    	check = true;
    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[0][3] != ' ') 
    	check = true;
    if (board[3][6] == board[4][5] && board[4][5] == board[5][4] && board[5][4] == board[6][4] && board[3][6] != ' ') 
    	check = true;
    if (board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[0][4] != ' ') 
    	check = true;
    if (board[4][0] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[4][0] != ' ') 
    	check = true;
    if (board[2][6] == board[3][5] && board[3][5] == board[4][4] && board[4][4] == board[5][3] && board[2][6] != ' ') 
    	check = true;
    if (board[6][2] == board[3][5] && board[3][5] == board[4][4] && board[4][4] == board[5][3] && board[6][2] != ' ') 
    	check = true;
    if (board[0][5] == board[1][4] && board[1][4] == board[2][3] && board[2][3] == board[3][2] && board[0][5] != ' ') 
    	check = true;
    if (board[4][1] == board[1][4] && board[1][4] == board[2][3] && board[2][3] == board[3][2] && board[4][1] != ' ') 
    	check = true;
    if (board[4][1] == board[5][0] && board[5][0] == board[2][3] && board[2][3] == board[3][2] && board[4][1] != ' ') 
    	check = true;
    if (board[1][6] == board[2][5] && board[2][5] == board[3][4] && board[3][4] == board[4][3] && board[1][6] != ' ') 
    	check = true;
    if (board[5][2] == board[2][5] && board[2][5] == board[3][4] && board[3][4] == board[4][3] && board[5][2] != ' ') 
    	check = true;
    if (board[5][2] == board[6][1] && board[6][1] == board[3][4] && board[3][4] == board[4][3] && board[5][2] != ' ') 
    	check = true;
    return check;
}

bool checkFull(char board[][7], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void setBoard(char board[][7], int size);
void menu(char board[][7]);
void gameplay3x3(char board[][7], int size);
void gameplay5x5(char board[][7], int size);
void gameplay7x7(char board[][7], int size);

void decision(char board[][7], int size) {
    int x;
    bool thoat = false;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "*****************" << endl;
    cout << "enter to menu" << endl;
    cout << "space to play again" << endl;
    cout << "esc to out" << endl;
    cout << "*****************" << endl;
    gotoxy(0, 25);
    while (!thoat) {
        if (_kbhit()) {
            x = move();
            if (x == 5) {
                system("cls");
                menu(board);
            }
            else if (x == 6) {
                system("cls");
                setBoard(board, size);
                if (size == 3)
                    gameplay3x3(board, size);
                if (size == 5)
                    gameplay5x5(board, size);
                if (size == 7)
                	gameplay7x7(board, size);
            }
            else if (x == 8) {
                system("cls");
            }
        }
    }
}

void decisionHistory(char board[][7]) {
    int x;
    bool thoat = false;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "*****************" << endl;
    cout << "enter to menu" << endl;
    cout << "esc to out" << endl;
    cout << "*****************" << endl;
    gotoxy(0, 25);
    while (!thoat) {
        if (_kbhit()) {
            x = move();
            if (x == 5) {
                system("cls");
                menu(board);
            }
            else if (x == 8) {
                system("cls");
            }
        }
    }
}

void historyP(int player) {
	if (player % 2 == 0) {
        history[0]++;
    }
    else {
        history[1]++;
    }
}

void iconP() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	char check;
	char x = 'x', o = 'o';
    cout << "Do you want to get a new icon(y/n): ";
    cin >> check;
    cout << endl;
    if (check == 'y') {
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    	cout << "********************************************" << endl;
    	cout << "* Icon must contain only 1 character!!!    *" << endl;
    	cout << "********************************************" << endl;
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    	cout << endl << "Enter the icon for player 1: ";
    	cin >> player1; 
    	cout << "Enter the icon for player 2: ";
    	cin >> player2;
	} else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "Player 1 choose character (x/o): ";
	    cin >> player1;
	    if (player1 == x) {
	        player2 = o;
	    }
	    else {
	        player2 = x;
	    } 
	}
}

void gameplay3x3(char board[][7], int size) {
    int a = 0;
    int b = 0;
    int x2;
    int count = 0;
    int column2 = 3;
    int line2 = 7;
    iconP();
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "**************************" << endl;
    cout << "*    Player 1 is " << player1 << "       *" << endl;
    cout << "*    Player 2 is " << player2 << "       *" << endl;
    cout << "**************************" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    gotoxy(0, 5);
    printBoard(board, size);
    role();
    gotoxy(3, 7);
    while (checkWinner3x3(board, size) == false && checkFull(board, size) == false) {
        if (_kbhit()) {
            x2 = move();
            switch (x2) {
            case 1: // DOWN 
            {
                line2 = line2 + 4;
                if (line2 >= 17) {
                    a -= 3;
                    line2 = 7;
                }
                a++;
                break;
            }
            case 3: // RIGHT
            {
                column2 = column2 + 6;

                if (column2 >= 18) {
                    b -= 3;
                    column2 = 3;
                }
                b++;
                break;
            }

            case 2: // UP
            {
                line2 = line2 - 4;
                if (line2 < 6) {
                    line2 = 15;
                    a += 3;
                }
                a--;
                break;
            }
            case 4: // LEFT
            {
                column2 = column2 - 6;
                if (column2 < 0) {
                    column2 = 15;
                    b += 3;
                }
                b--;
                break;
            }
            case 5: // ENTER
            {
                if (board[a][b] == ' ') {
                    if (count % 2 == 0) {
                        board[a][b] = player1;
                        cout << board[a][b];
                        count++;
                    }
                    else {
                        board[a][b] = player2;
                        cout << board[a][b];
                        count++;
                    }
                }
                break;
            }
            case 8: // ESC
            {
                system("cls");
                break;
            }
            }
            gotoxy(column2, line2);
        }
    }
    if (checkWinner3x3(board, size) == true) {

        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        printBoard(board, size);
        count--;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        if (count % 2 == 0) {
            cout << "Player 1 win!" << endl;
            historyP(count);
        }
        else {
            cout << "Player 2 win!" << endl;
            historyP(count);
        }
        decision(board, size);
    }
    else {
        system("cls");
        gotoxy(0, 0);
        cout << "DRAW!" << endl;
        decision(board, size);
    }
}

void gameplay5x5(char board[][7], int size) {
    int a = 0;
    int b = 0;
    int x2;
    int count = 0;
    int column2 = 3;
    int line2 = 7;
    iconP();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "**************************" << endl;
    cout << "*    Player 1 is " << player1 << "       *" << endl;
    cout << "*    Player 2 is " << player2 << "       *" << endl;
    cout << "**************************" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    gotoxy(0, 5);
    printBoard(board, size);
    role();
    gotoxy(3, 7);
    while (checkWinner5x5(board, size) == false && checkFull(board, size) == false) {
        if (_kbhit()) {

            x2 = move();
            switch (x2) {
            case 1: // DOWN 
            {
                line2 = line2 + 4;
                if (line2 >= 26) {
                    a -= 5;
                    line2 = 7;
                }
                a++;
                break;
            }
            case 3: // RIGHT
            {
                column2 = column2 + 6;

                if (column2 >= 32) {
                    b -= 5;
                    column2 = 3;
                }
                b++;
                break;
            }

            case 2: // UP
            {
                line2 = line2 - 4;
                if (line2 < 6) {
                    line2 = 23;
                    a += 5;
                }
                a--;
                break;
            }
            case 4: // LEFT
            {
                column2 = column2 - 6;
                if (column2 < 0) {
                    column2 = 27;
                    b += 5;
                }
                b--;
                break;
            }
            case 5: // ENTER
            {
                if (board[a][b] == ' ') {
                    if (count % 2 == 0) {
                        board[a][b] = player1;
                        cout << board[a][b];
                        count++;
                    }
                    else {
                        board[a][b] = player2;
                        cout << board[a][b];
                        count++;
                    }
                }
                break;
            }
            case 8: // ESC
            {
                system("cls");
                break;
            }
            }
            gotoxy(column2, line2);
        }
    }
    if (checkWinner5x5(board, size) == true) {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        printBoard(board, size);
        count--;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        if (count % 2 == 0) {
            cout << "Player 1 win!" << endl;
            historyP(count);
        }
        else {
            cout << "Player 2 win!" << endl;
            historyP(count);
        }
        decision(board, size);
    }
    else {
        system("cls");
        gotoxy(0, 0);
        cout << "DRAW!" << endl;
        decision(board, size);
    }
}

void gameplay7x7(char board[][7], int size) {
    char x = 'x', o = 'o';
    int a = 0;
    int b = 0;
    int x2;
    int count = 0;
    int column2 = 3;
    int line2 = 7;
    iconP();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "**************************" << endl;
    cout << "*    Player 1 is " << player1 << "       *" << endl;
    cout << "*    Player 2 is " << player2 << "       *" << endl;
    cout << "**************************" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    gotoxy(0, 5);
    printBoard(board, size);
    role7x7();
    gotoxy(3, 7);
    while (checkWinner7x7(board, size) == false && checkFull(board, size) == false) {
        if (_kbhit()) {
            x2 = move();
            switch (x2) {
	            case 1: // DOWN 
	            {
	                line2 = line2 + 4;
	                if (line2 >= 34) {
	                    a -= 7;
	                    line2 = 7;
	                }
	                a++;
	                break;
	            }
	            case 3: // RIGHT
	            {
	                column2 = column2 + 6;
	
	                if (column2 >= 44) {
	                    b -= 7;
	                    column2 = 3;
	                }
	                b++;
	                break;
	            }
	
	            case 2: // UP
	            {
	                line2 = line2 - 4;
	                if (line2 < 6) {
	                    line2 = 31;
	                    a += 7;
	                }
	                a--;
	                break;
	            }
	            case 4: // LEFT
	            {
	                column2 = column2 - 6;
	                if (column2 < 0) {
	                    column2 = 39;
	                    b += 7;
	                }
	                b--;
	                break;
	            }
	            case 5: // ENTER
	            {
	                if (board[a][b] == ' ') {
	                    if (count % 2 == 0) {
	                        board[a][b] = player1;
	                        cout << board[a][b];
	                        count++;
	                    }
	                    else {
	                        board[a][b] = player2;
	                        cout << board[a][b];
	                        count++;
	                    }
	                }
	                break;
	            }
            }
            gotoxy(column2, line2);
        }
    }
    if (checkWinner7x7(board, size) == true) {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        printBoard(board, size);
        count--;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        if (count % 2 == 0) {
            cout << "Player 1 win!" << endl;
            historyP(count);
        }
        else {
            cout << "Player 2 win!" << endl;
            historyP(count);
        }
        decision(board, size);
    }
    else {
        system("cls");
        gotoxy(0, 0);
        cout << "DRAW!" << endl;
        decision(board, size);
    }
}

void displayHistory() {
	cout << "Player 1 has won " << history[0] << " !!!" << endl;
	cout << "Player 2 has won " << history[1] << " !!!" << endl << endl;
}

int chooseMap(int& size) {
    if (size == 1) size = 3;
    else if (size == 2) size = 5;
    else if (size == 3) size = 7;
    else size = 4;
    return size;
}

void pickMap(int& size) {
    cin >> size;
    chooseMap(size);
}

void menu(char board[][7]) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout << "**************************" << endl;
    cout << "*       1. Map 3x3       *" << endl;
    cout << "*       2. Map 5x5       *" << endl;
    cout << "*       3. Map 7x7       *" << endl;
    cout << "*       4. History       *" << endl;
    cout << "**************************" << endl;

    int size;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << endl << "Choose map: ";
    pickMap(size);

    system("cls");
    if (size == 3) {
        setBoard(board, size);
        gameplay3x3(board, size);
    }

    if (size == 5) {
        setBoard(board, size);
        gameplay5x5(board, size);
    }

    if (size == 7) {
        setBoard(board, size);
        gameplay7x7(board, size);
    }
    
    if (size == 4) {
    	system("cls");
    	displayHistory();
    	decisionHistory(board);
	}
}

int main() {
    char board[7][7];
    menu(board);
    return 0;
}
