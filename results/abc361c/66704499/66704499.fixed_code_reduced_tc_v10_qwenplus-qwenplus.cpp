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
    for (int i = 0; i + (N - K) <= N; ++i) {
        result = min(result, A[i + (N - K)] - A[i]);
    }

    cout << result << endl;

    return 0;
}