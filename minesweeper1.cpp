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
int board[MAX_SIZE+1][MAX_SIZE+1];
int used[MAX_SIZE+1][MAX_SIZE+1];//тези матрици са запълнени първоначално с нули

//функция за генериране на произволни числа, използваща Линейния конгруентен метод,
//който дава поредица от псевдорандомизирани числа, изчислени с прекъснато линейно уравнение
//на части
unsigned int RandNum(unsigned int& seed, unsigned int a, unsigned int c, unsigned int m) {
    seed = (a * seed + c) % m;
    return seed;
}

unsigned int seed = 1234; // Initial seed value
unsigned int a = 22695477; // Multiplier
unsigned int c = 1; // Increment
unsigned int m = 42949; // Modulus 

//функция, която да пълни клетките спрямо броя им, подаден от потребителя
void fillBoard (int N, int& numberMines) {

    int minRange = 0; // Най-малкият възможен брой мини
    int maxRange = N; // Максималният възможен брой мини

    int mines;
    for (mines = 0; mines < numberMines; ++mines) {

        unsigned int randomNum = RandNum(seed, a, c, m); //взимаме слуайно число

        int x = (randomNum % N) ; //оправяме числото, за да пасва на рейнджа

        randomNum = RandNum(seed, a, c, m);

        int y = (randomNum % N) ;

        if(board[x][y] != N) { //пазя мините като N, тоест, ако на това място вече няма мина, слагам
            board[x][y] = N;
        }
    }
}

void print_board(int N){

    for ( int i = 0; i < N; i++) {
        for ( int j = 0; j < N; j++ ){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

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

    return 0;

}
