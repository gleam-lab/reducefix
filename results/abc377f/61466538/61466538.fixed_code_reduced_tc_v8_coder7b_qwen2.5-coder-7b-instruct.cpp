#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

long long n, m;
vector<pair<long long, long long>> positions;

// Function to check if a position is safe to place a piece
bool isSafe(long long i, long long j) {
    for (auto [x, y] : positions) {
        if (x == i || y == j || x + y == i + j || x - y == i - j) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    positions.resize(m);
    for (long long i = 0; i < m; i++) {
        cin >> positions[i].first >> positions[i].second;
    }

    long long count = 0;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            if (isSafe(i, j)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}