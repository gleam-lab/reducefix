#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(long long N, long long M, vector<long long> &a, vector<long long> &b) {
        set<pair<long long, long long>> pieces;
        for (long long i = 0; i < M; ++i) {
            pieces.insert(make_pair(a[i], b[i]));
        }

        long long count = 0;
        for (long long i = 1; i <= N; ++i) {
            for (long long j = 1; j <= N; ++j) {
                if (pieces.count(make_pair(i, j))) continue;
                bool can_place = true;
                for (int di = -2; di <= 2; ++di) {
                    for (int dj = -2; dj <= 2; ++dj) {
                        if (abs(di) + abs(dj) == 3 && pieces.count(make_pair(i + di, j + dj))) {
                            can_place = false;
                            break;
                        }
                    }
                    if (!can_place) break;
                }
                if (can_place) count++;
            }
        }

        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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