#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    int ans = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int j = N - 1 - (K - i);
        ans = min(ans, A[j] - A[i]);
    }
    cout << ans << endl;
    return 0;
}