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
    int res = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int j = K - i;
        res = min(res, A[N - 1 - j] - A[i]);
    }
    cout << res << endl;
    return 0;
}