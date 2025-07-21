#include <bits/stdc++.h>
using namespace std;

bool isValidMove(long long N, long long i, long long j, unordered_set<long long>& occupied) {
    for (int di = -2; di <= 2; ++di) {
        for (int dj = -2; dj <= 2; ++dj) {
            if (abs(di) + abs(dj) == 3 && i + di >= 1 && i + di <= N && j + dj >= 1 && j + dj <= N) {
                long long key = ((i + di - 1) * N + (j + dj - 1));
                if (!occupied.count(key)) return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    unordered_set<long long> occupied;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        long long key = ((a - 1) * N + (b - 1));
        occupied.insert(key);
    }

    long long count = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            long long key = ((i - 1) * N + (j - 1));
            if (!occupied.count(key) && isValidMove(N, i, j, occupied)) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}