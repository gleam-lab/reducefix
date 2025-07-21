#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1 << 30;

class Solution {
public:
    int solve(int N, int M, vector<int>& A, vector<int>& B) {
        unordered_set<ll> occupied;
        for (int i = 0; i < M; ++i) {
            occupied.insert((ll)(A[i] - 1) * N + (B[i] - 1));
        }

        int count = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (occupied.count((ll)(i - 1) * N + (j - 1))) continue;
                if (i + 2 <= N && j + 1 <= N && !occupied.count((ll)(i + 2 - 1) * N + (j + 1 - 1))) continue;
                if (i + 1 <= N && j + 2 <= N && !occupied.count((ll)(i + 1 - 1) * N + (j + 2 - 1))) continue;
                if (i - 1 >= 1 && j + 2 <= N && !occupied.count((ll)(i - 1 - 1) * N + (j + 2 - 1))) continue;
                if (i - 2 >= 1 && j + 1 <= N && !occupied.count((ll)(i - 2 - 1) * N + (j + 1 - 1))) continue;
                if (i - 2 >= 1 && j - 1 >= 1 && !occupied.count((ll)(i - 2 - 1) * N + (j - 1 - 1))) continue;
                if (i - 1 >= 1 && j - 2 >= 1 && !occupied.count((ll)(i - 1 - 1) * N + (j - 2 - 1))) continue;
                if (i + 1 <= N && j - 2 >= 1 && !occupied.count((ll)(i + 1 - 1) * N + (j - 2 - 1))) continue;
                if (i + 2 <= N && j - 1 >= 1 && !occupied.count((ll)(i + 2 - 1) * N + (j - 1 - 1))) continue;
                count++;
            }
        }

        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
    }

    Solution solution;
    cout << solution.solve(N, M, A, B) << endl;

    return 0;
}