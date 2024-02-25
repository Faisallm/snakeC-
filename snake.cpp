#include <iostream>
#include <conio.h>  // console input/output
using namespace std;

// declaration of variables
// let us on and off the game
bool gameOver;

// 20 units of width and height of game area
// ...over which the snake will move.
const int width = 20;
const int height = 20;

// the x, y are used to locate the snake head position.
// fruitX, fruitY stores location of the fruit.
// we store our score in the score variable.
int x, y, fruitX, fruitY, score;

// we have to store the direction
// an enum is a datatype that consist of named values.
// is this similar to a python dictionary?
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    // initial setup at the beginning of the game


    // initially gameOver is False
    gameOver = false;

    // stop movement
    dir = STOP;
    
    // initial position of the head will be at the middle
    x = width / 2;
    y = height / 2;
    
    // this will create a random number from 0 to (width - 1). 
    // along the horizontal axes
    // do we not import this rand() value
    fruitX = rand() % width;

    // this will create a random number from 0 to (height - 1).
    // along the vertical axes 
    fruitY = rand() % height;

    // setting the score
    score = 0;
}

void Draw() {
    // we need to clear the screen
    system("cls");

    // printing the top wall
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    // printing the left and right side walls...
    // and the snakes head and the fruit.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            else if (j == width - 1)
                cout << "#";
            else
                if (i == y && j == x) {
                    // we will print the head of the snake
                    cout << "O";
                }
                else if (i == fruitY && j == fruitX) {
                    // here we will print the fruit
                    cout << "F";
                }
                else {
                    // or else, we will print space.
                    cout << " ";
                }
        }
        cout << endl;
    }


    // bottom wall
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input() {
    // the code below will handle the control
    // _kbhit() will return true when the keyboard is pressed.
    if (_kbhit()) {
        // _getch() will return character value that was pressed.
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            // this will terminate the game
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    // we are going to switch the direction, dir
    switch (dir) {
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

    if (x > width || x < 0 || y  > height || y < 0) {
        gameOver = true;
    }
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }

}


int main()
{
    // call the setup function at the beginning
    Setup();

    // run this loop when gameOver is false
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        // we will also add a sleep function here.
    }

    return 0;
}
