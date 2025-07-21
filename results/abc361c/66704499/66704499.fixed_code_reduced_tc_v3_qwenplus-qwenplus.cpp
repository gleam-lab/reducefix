#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long result = LLONG_MAX;
    int window_size = N - K;

    // Slide window of size N-K over the sorted array
    for (int i = 0; i + window_size <= N; ++i) {
        result = min(result, A[i + window_size - 1] - A[i]);
    }

    cout << result << endl;
    return 0;
}