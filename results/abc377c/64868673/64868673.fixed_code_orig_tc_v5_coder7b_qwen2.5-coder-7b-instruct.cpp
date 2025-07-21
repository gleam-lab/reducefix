#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    unordered_set<long long> pieces;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert(((a - 1) * N + b));
    }

    long long count = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            bool safe = true;
            for (int di = -2; di <= 2; ++di) {
                for (int dj = -2; dj <= 2; ++dj) {
                    if (abs(di) + abs(dj) == 3 && di != 0 && dj != 0) {
                        long long ni = i + di, nj = j + dj;
                        if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                            if (pieces.count(((ni - 1) * N + nj))) {
                                safe = false;
                                break;
                            }
                        }
                    }
                }
                if (!safe) break;
            }
            if (safe) count++;
        }
    }

    cout << count << endl;

    return 0;
}