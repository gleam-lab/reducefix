#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int res = A[N-1] - A[0]; // Initial difference is between max and min of entire array
    for (int i = 0; i <= K; ++i) {
        int j = N - 1 - (K - i);
        if (j >= i) {
            res = min(res, A[j] - A[i]);
        }
    }
    cout << res << endl;
    return 0;
}