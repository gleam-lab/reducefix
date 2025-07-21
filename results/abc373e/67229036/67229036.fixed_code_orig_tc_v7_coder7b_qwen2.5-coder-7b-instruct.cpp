#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long N, M, K;
    cin >> N >> M >> K;

    vector<long long> A(N);
    for (long long &a : A) {
        cin >> a;
        K -= a;
    }

    // Sort the votes in descending order
    sort(A.begin(), A.end(), greater<long long>());

    vector<long long> prefix_sum(N + 1);
    for (long long i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
    }

    vector<long long> result(N);
    for (long long i = 0; i < N; ++i) {
        long long total_votes_needed = 0;
        if (i + M < N) {
            total_votes_needed = prefix_sum[i + M + 1] - prefix_sum[i + 1];
        }
        if (total_votes_needed > K) {
            result[i] = -1;
        } else {
            result[i] = total_votes_needed - A[i];
        }
    }

    for (long long res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}