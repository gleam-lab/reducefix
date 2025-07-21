#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(long long N, long long M, vector<long long> a, vector<long long> b) {
        set<pair<long long, long long>> obstacles;
        for (long long i = 0; i < M; ++i) {
            obstacles.insert({a[i], b[i]});
        }

        long long count = 0;
        for (long long i = 1; i <= N; ++i) {
            for (long long j = 1; j <= N; ++j) {
                if (!obstacles.count({i, j})) {
                    bool canPlace = true;
                    // Check all possible moves
                    vector<pair<long long, long long>> moves = {
                        {i + 2, j + 1}, {i + 1, j + 2}, {i - 1, j + 2}, {i - 2, j + 1},
                        {i - 2, j - 1}, {i - 1, j - 2}, {i + 1, j - 2}, {i + 2, j - 1}
                    };
                    for (auto& move : moves) {
                        if (move.first >= 1 && move.first <= N && move.second >= 1 && move.second <= N &&
                            obstacles.count(move)) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (canPlace) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    vector<long long> a(M), b(M);
    for (long long i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }

    Solution solution;
    cout << solution.solve(N, M, a, b) << endl;

    return 0;
}