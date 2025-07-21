#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

ll n, m;
vector<pii> pieces;

// Function to calculate factorial modulo MOD
ll factorial(ll x) {
    ll fact = 1;
    for (ll i = 2; i <= x; ++i) {
        fact = fact * i % MOD;
    }
    return fact;
}

// Function to calculate modular exponentiation
ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to calculate the number of ways to place a piece without capture
ll count_capture_free_squares() {
    vector<set<int>> rowCaptures(n + 1), colCaptures(n + 1), diag1Captures(2 * n + 1), diag2Captures(2 * n + 1);

    for (auto piece : pieces) {
        int x = piece.first;
        int y = piece.second;

        rowCaptures[x].insert(y);
        colCaptures[y].insert(x);
        diag1Captures[x + y].insert(x);
        diag2Captures[x - y + n].insert(x);
    }

    // Calculate the number of free squares
    ll freeSquares = factorial(n * n);
    for (int r = 1; r <= n; ++r) {
        freeSquares = freeSquares * (n - rowCaptures[r].size()) % MOD;
    }
    for (int c = 1; c <= n; ++c) {
        freeSquares = freeSquares * (n - colCaptures[c].size()) % MOD;
    }
    for (int d1 = 1; d1 <= 2 * n; ++d1) {
        freeSquares = freeSquares * (n - diag1Captures[d1].size()) % MOD;
    }
    for (int d2 = 1; d2 <= 2 * n; ++d2) {
        freeSquares = freeSquares * (n - diag2Captures[d2].size()) % MOD;
    }

    // Subtract the overcounted squares
    for (auto piece : pieces) {
        int x = piece.first;
        int y = piece.second;

        // Check for intersections in diagonals
        for (int d1 = max(1, x - y), d2 = max(1, x + y) - 2 * n; d1 <= min(2 * n, x + y - 1); ++d1) {
            freeSquares = freeSquares * (n - diag1Captures[d1].size()) % MOD;
            freeSquares = freeSquares * (n - diag2Captures[d2].size()) % MOD;
            d1++;
            d2++;
            if (d1 <= 2 * n && d2 >= 1) {
                freeSquares = freeSquares * (n - diag1Captures[d1].size()) % MOD;
                freeSquares = freeSquares * (n - diag2Captures[d2].size()) % MOD;
            }
        }
    }

    return freeSquares;
}

int main() {
    cin >> n >> m;
    pieces.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    cout << count_capture_free_squares() % MOD << endl;

    return 0;
}