#include <iostream>
#include <string>
using namespace std;

// Variables
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';

// Functions
void draw();
void input();
void switch_player();
char win();
void hvh_game();
void reset_game();
void hve_game();

void draw()
{
    system("cls");
    cout << "Tic Tac Toe Game" << endl;
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void input()
{
    string input;
    while (true)
    {
        cout << "Player " << player << "'s turn, enter Matrix Number: ";
        getline(cin, input);
        
        if (input == "1")
        {
            if (matrix[0][0] == '1')
            {
                matrix[0][0] = player;
                break;
            }
            else
            {
                cout << "Matrix is occupied, choose another matrix" << endl;
            }
        }
        else if (input == "2")
        {
            if (matrix[0][1] == '2')
            {
                matrix[0][1] = player;
                break;
            }
            else
                cout << "Matrix is occupied, choose another matrix" << endl;
        }
        else if (input == "3")
        {
            if (matrix[0][2] == '3')
            {
                matrix[0][2] = player;
                break;
            }
            else
                cout << "Matrix is occupied, choose another matrix" << endl;
        }
        else if (input == "4")
        {
            if (matrix[1][0] == '4')
            {
                matrix[1][0] = player;
                break;
            }
            else
                cout << "Matrix is occupied, choose another matrix" << endl;
        }
        else if (input == "5")
        {
            if (matrix[1][1] == '5')
            {
                matrix[1][1] = player;
                break;
            }
            else
                cout << "Matrix is occupied, choose another matrix" << endl;
        }
        else if (input == "6")
        {
            if (matrix[1][2] == '6')
            {
                matrix[1][2] = player;
                break;
            }
            else
                cout << "Matrix is occupied, choose another matrix" << endl;
        }
        else if (input == "7")
        {
            if (matrix[2][0] == '7')
            {
                matrix[2][0] = player;
                break;
            }
            else
                cout << "Matrix is occupied, choose another matrix" << endl;
        }
        else if (input == "8")
        {
            if (matrix[2][1] == '8')
            {
                matrix[2][1] = player;
                break;
            }
            else
                cout << "Matrix is occupied, choose another matrix" << endl;
        }
        else if (input == "9")
        {
            if (matrix[2][2] == '9')
            {
                matrix[2][2] = player;
                break;
            }
            else
                cout << "Matrix is occupied, choose another matrix" << endl;
        }
        else
        {
            cout << "Please enter 1 to 9 only" << endl;
        }
    }
}

void switch_player()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char win()
{
    // Player X
    // Rows
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';

    // Columns
    else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    else if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';

    // Diagonals
    else if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    else if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
        return 'X';

    // Player O
    // Rows
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';

    // Columns
    else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    else if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    else if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';

    // Diagonals
    else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    else if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
        return 'O';

    return '-';
}

void hvh_game()
{
    int turns = 0;
    draw();
    while (true)
    {
        turns++;
        input();
        draw();
        if (win() == 'X')
        {
            cout << "Player X wins!" << endl;
            reset_game();
            break;
        }
        else if (win() == 'O')
        {
            cout << "Player O wins!" << endl;
            reset_game();
            break;
        }
        else if (win() == '-' && turns == 9)
        {
            cout << "It's a draw!" << endl;
            reset_game();
            break;
        }
        switch_player();
    }
}

void reset_game()
{
    matrix[0][0] = '1';
    matrix[0][1] = '2';
    matrix[0][2] = '3';
    matrix[1][0] = '4';
    matrix[1][1] = '5';
    matrix[1][2] = '6';
    matrix[2][0] = '7';
    matrix[2][1] = '8';
    matrix[2][2] = '9';

    player = 'X';
}

void hve_game()
{
    int turns = 0;
    draw();
    while (true)
    {
        turns++;
        input();
        draw();
        if (win() == 'X')
        {
            cout << "Player X wins!" << endl;
            cout << endl;
            break;
        }
        else if (win() == 'O')
        {
            cout << "Player O wins!" << endl;
            cout << endl;
            break;
        }
        else if (win() == '-' && turns == 9)
        {
            cout << "It's a draw!" << endl;
            cout << endl;
            break;
        }
        switch_player();
    }
}

int main()
{
    string menu_command;

    while (true)
    {
    cout << "Tic Tac Toe Game" << endl;
    cout << "Press 1 for Human vs Human Tic Tac Toe" << endl;
    cout << "Press 2 for Human vs Easy AI Tic Tac Toe" << endl;
    cout << "Press 3 for Human vs Hard AI Tic Tac Toe" << endl;
    cout << "Press 0 to quit the program: ";
    getline(cin, menu_command);

    if (menu_command == "1")
        hvh_game();
    else if (menu_command == "0")
        return 0;
    else
        cout << "Command not recognized" << endl;
        cout << endl;
    }
}