#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

int A[MAXN];

void solve() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> votes(N);
    for (int i = 0; i < N; i++) {
        cin >> votes[i];
        K -= votes[i];
    }

    sort(votes.begin(), votes.end());

    vector<long long> suffix_sum(N + 1);
    suffix_sum[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + votes[i];
    }

    vector<long long> C(N);
    for (int i = 0; i < N; i++) {
        if (votes[i] >= K) {
            C[i] = 0;
        } else {
            int required = 0;
            if (i + 1 >= M) {
                required = votes[i] + 1;
            } else {
                required = votes[i] + 1 + (suffix_sum[i + 1] - suffix_sum[i + M]);
            }
            C[i] = max(0LL, required - votes[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}