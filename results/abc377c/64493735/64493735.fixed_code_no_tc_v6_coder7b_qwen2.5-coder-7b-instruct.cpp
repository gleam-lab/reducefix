#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long solve(long long N, long long M, const vector<long long>& a, const vector<long long>& b) {
        set<pair<long long, long long>> pieces;
        for (long long i = 0; i < M; ++i) {
            pieces.insert(make_pair(a[i], b[i]));
        }

        long long count = 0;
        for (long long i = 1; i <= N; ++i) {
            for (long long j = 1; j <= N; ++j) {
                bool canPlace = true;
                for (auto dir : directions) {
                    long long ni = i + dir[0];
                    long long nj = j + dir[1];
                    if (ni >= 1 && ni <= N && nj >= 1 && nj <= N && pieces.count(make_pair(ni, nj))) {
                        canPlace = false;
                        break;
                    }
                }
                if (canPlace) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    static constexpr array<array<long long, 2>, 8> directions = {{
        {{2, 1}}, {{1, 2}}, {{-1, 2}}, {{-2, 1}},
        {{-2, -1}}, {{-1, -2}}, {{1, -2}}, {{2, -1}}
    }};
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