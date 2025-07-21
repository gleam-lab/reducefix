#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    sort(A.begin(), A.end());

    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }

    vector<long long> C(N, -1);
    for (int i = 0; i < N; ++i) {
        long long needed = -1;
        if (N - i >= M) {
            long long total_votes = prefix_sum.back() - prefix_sum[i + 1];
            long long votes_needed = K + 1 + prefix_sum[i];
            needed = votes_needed - total_votes;
        }
        C[i] = max(0LL, needed);
    }

    for (int i = 0; i < N; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}