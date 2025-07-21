#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long minDiff = numeric_limits<long long>::max();

    // Slide window of size N - K
    for (int i = 0; i + (N - K) <= N; ++i) {
        minDiff = min(minDiff, 1LL * A[i + (N - K)] - A[i]);
    }

    cout << minDiff << endl;

    return 0;
}