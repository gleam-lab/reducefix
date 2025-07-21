#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked_squares;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Mark all squares attacked by the current piece
        for (long long j = 1; j <= N; ++j) {
            attacked_squares.insert({a, j}); // Same row
            attacked_squares.insert({j, b}); // Same column
            attacked_squares.insert({a + j - b, j}); // Positive diagonal
            attacked_squares.insert({a - j + b, j}); // Negative diagonal
        }
    }

    // Calculate the number of empty squares
    long long empty_squares = N * N - attacked_squares.size();

    cout << empty_squares << '\n';

    return 0;
}