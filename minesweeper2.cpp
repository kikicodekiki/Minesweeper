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

// правя глобална схема 11х11, за да краищата да са изпълнени с -1ци

const int MAX_SIZE = 10;
int board[MAX_SIZE+1][MAX_SIZE+1];//слагам го така, за да има някакъв контур
bool used [MAX_SIZE+1][MAX_SIZE+1];//тези матрици са запълнени първоначално с нули

int row[] = {-1, -1, -1, 0,0, 1, 1, 1,};
int col[] = {-1, 0, 1, -1, 1,-1, 0, 1,};

//функция, която да пълни клетките спрямо броя им, подаден от потребителя
void fillBoard (int N, int& numberMines) {

    for ( int i = 0; i < N+1 ; i++ ) {
        board[0][i] = -1;
        board[i][0] = -1;
        board[N+1][i] = -1;
        board[i][N+1] = -1; //идеята е да стане рамка
    }

    int mines = 0;

    while (mines < numberMines){
        int x = rand() % N + 1;
        int y = rand() % N + 1;

        if(board[x][y] != 9) { //пазя мините като 9, тоест, ако на това място вече няма мина, слагам девятка
            board[x][y] = 9;

            //обхождаме съседите
            for(int i = 0; i < 8; ++i) {

                if(board[x + row[i]][y + col[i]] != -1 && board[x + row[i]][y + col[i]] != 9){
                    // ако не е граница го увеличаваме с единица
                    board[x + row[i]][y + col[i]]++;
                }

            }

            mines++;
        }



    }

}

void print_board(int N){

    for ( int i = 1; i <= N; i++) {
        for ( int j = 1; j <= N; j++ ){
            if (used[i][j]) {
                cout << board[i][j] << ' ';
            }
            else {
                cout << 'x' << ' ';
            }
        }
        cout << endl;
    }

}

void game (int N) {

    cout << "Enter your move (row[ 1 - " << N << "] column[ 1 - " << N << "]) : ";
    int curRow;
    int curCol;
    cin >> curRow >> curCol;

}


int main() {

    int N, numberMines;

    do {
        cout << "Enter the dimension of the board on which you wish to play: ";
        cin >> N;
    } while ( N < 3 || N > MAX_SIZE );

    do {
        cout << "Enter the number of mines that you wish to open: ";
        cin >> numberMines;
    } while ( numberMines < 1 || numberMines > 3*N );

    fillBoard(N, numberMines);
    print_board(N);
    game(N);

    return 0;

}
