#include <bits/stdc++.h>
using namespace std;

long long minMaxDifference(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int n = A.size();
    long long res = LONG_MAX;
    for (int i = 0; i <= K; ++i) {
        res = min(res, static_cast<long long>(A[n - 1 - i] - A[i]));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << minMaxDifference(A, K) << endl;

    return 0;
}