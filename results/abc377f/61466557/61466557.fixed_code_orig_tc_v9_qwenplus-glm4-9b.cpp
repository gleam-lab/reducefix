#include <iostream>
using namespace std;

int main() {
    long long n, m, total_squares, occupied_squares;

    // Read the number of rows, columns, and the number of pieces
    cin >> n >> m;

    // Calculate the total number of squares in the grid
    total_squares = n * n;

    // Calculate the number of squares that will be occupied by the existing pieces
    occupied_squares = 3 * m - 3;

    // The answer is the total number of squares minus the number of occupied squares
    cout << total_squares - occupied_squares << endl;

    return 0;
}