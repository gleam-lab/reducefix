#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 7;
char S[MAX_N];

int main() {
    int N;
    cin >> N;
    scanf("%s", S);

    vector<int> dp(3, 0); // dp[r], dp[p], dp[s] represent the maximum scores for using R, P, S respectively
    vector<int> dpPrev(3, 0);
    const int mod = 1e9 + 7;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[j] = dpPrev[(j + 1) % 3]; // If we don't choose this move
            if ((j == 0 && S[i] == 'S') || (j == 1 && S[i] == 'R') || (j == 2 && S[i] == 'P')) {
                dp[j] = (dp[j] + dpPrev[j] + 1) % mod; // If we choose this move
            }
        }
        swap(dp, dpPrev);
    }

    int result = max({dp[0], dp[1], dp[2]});
    cout << result << endl;

    return 0;
}