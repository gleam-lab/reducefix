#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long min_diff = LLONG_MAX;

    for (int i = 0; i <= K; ++i) {
        int j = N - K + i - 1;
        if (j >= i) {
            min_diff = min(min_diff, A[j] - A[i]);
        }
    }

    cout << min_diff << endl;

    return 0;
}