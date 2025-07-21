#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m;
vector<int> rows, cols, diag1, diag2;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        rows.push_back(x);
        cols.push_back(y);
        diag1.push_back(x + y);
        diag2.push_back(x - y);
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());

    long long totalSquares = n * n;
    long long capturedSquares = 0;

    // Count squares captured by rows and columns
    capturedSquares += rows.size();
    capturedSquares += cols.size();

    // Count squares captured by diagonals
    for (int i = 1; i < diag1.size(); i++) {
        capturedSquares += (diag1[i] - diag1[i - 1]) - 1;
    }
    for (int i = 1; i < diag2.size(); i++) {
        capturedSquares += (diag2[i] - diag2[i - 1]) - 1;
    }

    // Calculate the number of available squares
    long long availableSquares = totalSquares - capturedSquares;
    cout << availableSquares << endl;

    return 0;
}