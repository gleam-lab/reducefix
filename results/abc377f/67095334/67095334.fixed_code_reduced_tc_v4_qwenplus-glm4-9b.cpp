#include <iostream>
#include <vector>
#include <set>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> captured;

    // Read and store captured pieces
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        captured.insert({a, b});
    }

    long long safe = N * N; // Start with all squares as safe

    // Subtract captured squares
    for (const auto& p : captured) {
        long long a = p.first, b = p.second;
        // Check rows and columns
        safe -= (N - abs(a - 1));
        safe -= (N - abs(b - 1));
        // Check diagonals
        safe -= (N - abs(a + b - 2));
        safe -= (N - abs(a - b + 2));
    }

    cout << safe << endl;

    return 0;
}