#include <iostream>
#include <set>
#include <cmath>
using namespace std;

long long solve(long long N, long long M, vector<long long> &a, vector<long long> &b) {
    set<pair<long long, long long>> occupied;
    for (int i = 0; i < M; ++i) {
        occupied.insert(make_pair(a[i], b[i]));
    }

    long long count = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            if (!occupied.count(make_pair(i, j))) {
                bool safe = true;
                for (int di = -2; di <= 2; ++di) {
                    for (int dj = -2; dj <= 2; ++dj) {
                        if (abs(di) + abs(dj) == 3 && i + di >= 1 && i + di <= N && j + dj >= 1 && j + dj <= N) {
                            if (occupied.count(make_pair(i + di, j + dj))) {
                                safe = false;
                                break;
                            }
                        }
                    }
                    if (!safe) break;
                }
                if (safe) ++count;
            }
        }
    }

    return count;
}

int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> a(M), b(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }

    cout << solve(N, M, a, b) << endl;

    return 0;
}