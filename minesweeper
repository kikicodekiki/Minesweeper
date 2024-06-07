#include <iostream>
using namespace std;
/**
*
* Solution to course project # 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Ekaterina Ivanova Stoyanova
* @idnumber 2MI0600285
* @compiler CLion
*
* <file with game>
*
*/

const int MAX_SIZE = 10; // even though I know that using global variables is not a good practice,
int board[MAX_SIZE + 2][MAX_SIZE + 2]; // I used them in my project so as to make the code more easily
bool used[MAX_SIZE + 2][MAX_SIZE + 2]; // understandable
bool markedMines[MAX_SIZE + 2][MAX_SIZE + 2];

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // directions for the neighbouring cells
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int opened; // a counter for the number of opened cells
int totalMines; // a counter for the total number of mines

void createBorder(int N) {
    for (int i = 0; i < N + 1; i++) {
        board[0][i] = -1; // I am creating a border of -1 so that the directions work properly
        board[i][0] = -1;
        board[N + 1][i] = -1;
        board[i][N + 1] = -1;
    }
}

void createBoard() {
    for (int j = 0; j < MAX_SIZE + 2; j++) {
        for (int f = 0; f < MAX_SIZE + 2; f++) {
            board[j][f] = 0; // filling the main board with zeros
            used[j][f] = false; // a bool board that shows me whether or not a cell has been used
            markedMines[j][f] = false; // a bool matrix that shows which mines have been marked
        }
    }
}

void fillBoardWithMines(int N, int numberMines) {
    createBoard();

    opened = 0;
    totalMines = numberMines;

    createBorder(N);

    int mines = 0;
    srand(time(0)); // this function randomizes the position of mines
    while (mines < numberMines) {
        int x = rand() % N + 1; // the +1 is in order for the coordinates to not match with the border
        int y = rand() % N + 1;

        if (board[x][y] != 9) {
            board[x][y] = 9; // I am keeping the mines as '9'

            for (int i = 0; i < 8; ++i) {
                if (board[x + row[i]][y + col[i]] != -1 && board[x + row[i]][y + col[i]] != 9) {
                    board[x + row[i]][y + col[i]]++; // if it is not a border nor a mine : +1
                }
            }
            mines++;
        }
    }
}

void printBoard(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (used[i][j]) {
                if (markedMines[i][j]) {
                    cout << "@" << ' '; // if it has been marked
                } else if (board[i][j] == 9) {
                    cout << "*" << ' '; // if it's a mine
                } else if (board[i][j] != 9 && (!markedMines[i][j])) {
                    cout << board[i][j] << ' '; // if the cell is a number and it has been opened
                }
            } else {
                cout << 'x' << ' '; // unknown cells
            }
        }
        cout << endl;
    }
}

int myStrcmp(const char* first, const char* second) {
    if (!first || !second)
        return 0;
    while ((*first) && (*second) && ((*first) == (*second))) {
        first++;
        second++;
    }
    return (*first - *second);
}

bool validMove(int curRow, int curCol, int N) {
    if (curRow > N || curRow < 1 || curCol > N || curCol < 1 ) {
        return false;
    } else {
        return true;
    }
}

bool validCommand(const char* command) {
    return (myStrcmp(command, "open") == 0 || myStrcmp(command, "mark") == 0 ||
    myStrcmp(command, "unmark") == 0);
}

void recursionNeighbours(int moveRow, int moveCol) {
    used[moveRow][moveCol] = true;
    opened++;
    for (int i = 0; i < 8; ++i) {
        int newRow = moveRow + row[i];
        int newCol = moveCol + col[i];
        // the function goes around and opens the neighboring cells
        if (newRow >= 1 && newRow <= MAX_SIZE && newCol >= 1 && newCol <= MAX_SIZE && !used[newRow][newCol]) {
            if (board[newRow][newCol] > 0 && board[newRow][newCol] < 9) {
                used[newRow][newCol] = true;
                opened++;
            } else if (board[newRow][newCol] == 0) {
                recursionNeighbours(newRow, newCol);
            }
        }
    }
}

void mark(int curRow, int curCol, int N) {
    used[curRow][curCol] = true;
    markedMines[curRow][curCol] = true; // saves the info that the cell has been marked
    if (board[curRow][curCol] == 9) {
        totalMines--;
    } else {
        opened++;
    }
}

void unmark(int curRow, int curCol) {
    if (markedMines[curRow][curCol] && used[curRow][curCol] && board[curRow][curCol] == 9) {
        totalMines++; // if the cell was indeed a mine, the number of mines increases
    }
    used[curRow][curCol] = false;
    markedMines[curRow][curCol] = false;
}

void winner() {
    cout << " ********* ~ CONGRATULATIONS! ~ ********* " << endl;
    cout << " YOU WON " << endl;
}

int game(int N, int numberMines) {
    bool valid = false;
    int curRow;
    int curCol;

    const size_t command_length = 6;
    char command[command_length];

    while (!valid) {
        cout << "Enter your move (command: open/mark/unmark), (row[ 1 - " << N << "]), (column[ 1 - " << N << "]) : ";
        cin >> command >> curRow >> curCol;

        if ((!(validCommand(command))) || (!(validMove(curRow, curCol, N)))) {
            cout << "Invalid move. Try again" << endl;
        } else {
            valid = true;
        }
    }

    if (myStrcmp(command, "open") == 0) {
        if (board[curRow][curCol] == 9) {
            cout << "You lost! Game over!" << endl; // if the player has stepped on a mine
            printBoard(N);
            return -1;
        } else if (board[curRow][curCol] == 0) {
            used[curRow][curCol] = true;
            opened++;
            recursionNeighbours(curRow, curCol); // goes around the neighbouring cells
        } else {
            used[curRow][curCol] = true;
            opened++; // opens the cell with a number
        }
    } else if (myStrcmp(command, "mark") == 0) {
        mark(curRow, curCol, N);
        if (totalMines == 0) {
            winner();
            return 0;
        }
    } else if (myStrcmp(command, "unmark") == 0) {
        unmark(curRow, curCol);
    }

    printBoard(N);

    if (opened == (N * N - numberMines)) {
        winner(); // the game is won, if all cells have been opened
        return -1;
    } else {
        return game(N, numberMines);
    }
}

int main() {
    cout << "(_)                                                  \n"
            " _ __ ___  _ _ __   ___  _____      _____  ___ _ __   ___ _ __ \n"
            "| '_ ` _ \\| | '_ \\ / _ \\/ __\\ \\ /\\ / / _ \\/ _ \\ '_ \\ / _ \\ '__|\n"
            "| | | | | | | | | |  __/\\__\\\\ V  V /  __/  __/ |_) |  __/ |   \n"
            "|_| |_| |_|_|_| |_|\\___||___/ \\_/\\_/ \\___|\\___| .__/ \\___|_|   \n"
            "                                              | |              \n"
            "                                              |_|              " << endl;
    cout << endl
         << endl
         << endl;

    int N, numberMines;

    do {
        cout << "Enter the dimension of the board on which you wish to play: ";
        cin >> N;
    } while (N < 3 || N > MAX_SIZE);

    do {
        cout << "Enter the number of mines that you wish to open: ";
        cin >> numberMines;
    } while (numberMines < 1 || numberMines > 3 * N);

    cout << "_____________________________________________" << endl;
    cout << "              NEW GAME BEGINS                " << endl;
    cout << "_____________________________________________" << endl;

    fillBoardWithMines(N, numberMines);
    printBoard(N);
    game(N, numberMines);

    return 0;
}
