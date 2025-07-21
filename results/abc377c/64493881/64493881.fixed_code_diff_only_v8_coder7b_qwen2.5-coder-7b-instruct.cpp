#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(long long N, long long M, vector<long long> a, vector<long long> b) {
        set<pair<long long, long long>> pieces;
        for (long long i = 0; i < M; ++i) {
            pieces.insert(make_pair(a[i], b[i]));
        }

        long long count = 0;
        for (long long i = 1; i <= N; ++i) {
            for (long long j = 1; j <= N; ++j) {
                if (!pieces.count(make_pair(i, j))) {
                    // Check all possible moves
                    if (!pieces.count(make_pair(i + 2, j + 1)) &&
                        !pieces.count(make_pair(i + 1, j + 2)) &&
                        !pieces.count(make_pair(i - 1, j + 2)) &&
                        !pieces.count(make_pair(i - 2, j + 1)) &&
                        !pieces.count(make_pair(i - 2, j - 1)) &&
                        !pieces.count(make_pair(i - 1, j - 2)) &&
                        !pieces.count(make_pair(i + 1, j - 2)) &&
                        !pieces.count(make_pair(i + 2, j - 1))) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

int main() {
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