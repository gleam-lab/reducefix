#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // Maps to track captured rows, columns, and diagonals
    map<int, bool> capturedRows, capturedCols;
    map<pair<int, int>, bool> capturedDiags; // stored as {d1, d2}

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // convert to 0-based index

        // Check capture conditions and update maps
        // ...
    }

    // Calculate the number of free squares
    int freeSquares = N * N;
    // ...

    cout << freeSquares << endl;

    return 0;
}