#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(long long N, long long M, vector<long long> &a, vector<long long> &b) {
        unordered_set<long long> occupied;
        for (long long i = 0; i < M; ++i) {
            long long pos = (a[i] - 1) * N + b[i];
            occupied.insert(pos);

            for (auto dx : {-2, -1, 1, 2}) {
                for (auto dy : {-2, -1, 1, 2}) {
                    if (abs(dx) != abs(dy)) {
                        long long nx = a[i] + dx, ny = b[i] + dy;
                        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                            long long npos = (nx - 1) * N + ny;
                            occupied.insert(npos);
                        }
                    }
                }
            }
        }

        long long totalPositions = N * N;
        long long validPositions = totalPositions - occupied.size();
        return validPositions;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;
    vector<long long> a(M), b(M);
    for (long long i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }

    Solution sol;
    cout << sol.solve(N, M, a, b) << endl;

    return 0;
}