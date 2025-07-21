#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to easily find min/max after removal
    sort(A.begin(), A.end());

    // The optimal strategy is to remove K smallest and largest elements
    // This minimizes the difference between max and min of the remaining elements
    ll ans = A[N-K-1] - A[K];

    cout << ans << '\n';
    return 0;
}