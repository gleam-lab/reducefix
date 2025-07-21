#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isValid(int i, int j, int N) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_set<long long> occupied;
    for (long long k = 0; k < M; ++k) {
        long long a, b;
        cin >> a >> b;
        occupied.insert((a - 1) * N + b);
    }

    set<long long> odd, even;
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            if ((i + j) % 2 == 0) {
                even.insert((i * N) + j);
            } else {
                odd.insert((i * N) + j);
            }
        }
    }

    for (auto pos : occupied) {
        auto [i, j] = make_tuple(pos / N, pos % N);

        // Check all 8 directions
        vector<pair<int, int>> dirs = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (const auto& [di, dj] : dirs) {
            int ni = i + di, nj = j + dj;
            if (isValid(ni, nj, N)) {
                long long neighborPos = (ni * N) + nj;
                if ((ni + nj) % 2 == 0) {
                    even.erase(neighborPos);
                } else {
                    odd.erase(neighborPos);
                }
            }
        }
    }

    cout << (even.size() + odd.size()) << endl;

    return 0;
}