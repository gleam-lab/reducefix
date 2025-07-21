#include <iostream>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<int, int>> blockedSquares;

    for (long long i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        // Add the square where the piece is placed
        blockedSquares.insert({a, b});
        // Add all squares in the row and column
        for (long long j = 1; j <= n; ++j) {
            blockedSquares.insert({a, j});
            blockedSquares.insert({j, b});
        }
        // Add diagonal squares
        for (long long j = 1; j <= n; ++j) {
            blockedSquares.insert({a + j, b + j});
            blockedSquares.insert({a - j, b - j});
        }
    }

    // Calculate the number of unblocked squares
    long long totalSquares = n * n;
    long long unblockedSquares = totalSquares - blockedSquares.size();
    cout << unblockedSquares << endl;
    return 0;
}