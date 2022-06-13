#include <iostream>
#include <conio.h>
#include <windows.h> // For Sleep()
#include <time.h>    // For Seeding in rand()
using namespace std;

// Global Variables
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruit_x, fruit_y, score, tail_x[100], tail_y[100], tail_length;

// enum is used to give a name to certain values
// eDirection is used as a type, like int, bool, double, This is used to declare multiple values
// Stop is 0, Left is 1, Right is 2 and so on
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection direction;

void setup()
{
    gameover = false;
    direction = STOP;
    x = width / 2;
    y = height / 2;
    fruit_x = rand() % width;
    fruit_y = rand() % height;
    score = 0;
}

void draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // for every column (height), i is each pixel and i is y-axis
    for (int i = 0; i < height; i++)
    {
        // for every row (width), j is each row pixel and j is x-axis
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruit_y && j == fruit_x)
                cout << "X";
            else
            {
                bool print = false;
                // for loop for the length of the tail
                for (int k = 0; k < tail_length; k++)
                {
                    // if tail x and tail y are in the pixel, print the tail
                    if (tail_x[k] == j && tail_y[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                // Cannot use else because if there is no tail length, empty spaces will not be printed out
                if (!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void input()
{
    // Recognized if a keyboard button is hit
    if (_kbhit())
    {
        //_getch() means which keyboard button is hit
        switch (_getch())
        {
        case 'a':
            direction = LEFT;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'w':
            direction = UP;
            break;
        case 's':
            direction = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}

void logic()
{
    int prev_x = tail_x[0];
    int prev_y = tail_y[0];
    int prev_2x, prev_2y;
    tail_x[0] = x;
    tail_y[0] = y;

    // To figure out where does the tail go
    for (int i = 1; i < tail_length; i++)
    {
        prev_2x = tail_x[i];
        prev_2y = tail_y[i];
        tail_x[i] = prev_x;
        tail_y[i] = prev_y;
        prev_x = prev_2x;
        prev_y = prev_2y;
    }

    switch (direction)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    // if (x > width || x < 0 || y > height || y < 0)
    // gameover = true;
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;
    if (y >= width)
        y = 0;
    else if (y < 0)
        y = height - 1;

    // if any of the tail is equal to the head, means game over as the snake bit itself
    for (int i = 0; i < tail_length; i++)
        if (tail_x[i] == x && tail_y[i] == y)
            gameover = true;

    // if the head is equal to the fruit, means the snake ate the fruit
    if (x == fruit_x && y == fruit_y)
    {
        score += 10;
        fruit_x = rand() % width;
        fruit_y = rand() % width;
        tail_length++;
    }
}

int main()
{
    srand(time(0));
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
        // Sleep is used here to slow down the game
        Sleep(50);
    }
    return 0;
}