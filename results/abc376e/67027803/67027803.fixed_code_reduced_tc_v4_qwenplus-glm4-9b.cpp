#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        // We need to find the minimum of the expression (max_{i in S} A_i) * (sum_{i in S} B_i)
        // To achieve this, we need to consider the elements that will be in the subset S of size K
        // which give us the minimum product of the max element and the sum of the subset.

        // First, sort the pairs (A[i], B[i]) by the ratio B[i]/A[i] in descending order
        // This helps in selecting the largest ratio first, which is beneficial because we want
        // to minimize the maximum value in the subset and maximize the sum of the subset.
        vector<pair<ll, ll>> ab(N); // ab[i] = (A[i], B[i])
        for (int i = 0; i < N; i++) ab[i] = {A[i], B[i]};
        sort(ab.begin(), ab.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return (b.second * b.first < a.second * a.first);
        });

        // Calculate the sum and max of the first K elements
        ll sumK = 0;
        ll maxA = 0;
        for (int i = 0; i < K; i++) {
            sumK += ab[i].second;
            maxA = max(maxA, ab[i].first);
        }

        // Initialize the answer with the result from the first K elements
        ll ans = maxA * sumK;

        // Now, iterate from the (K+1)th element to the end of the array
        // and try to replace the smallest elements in the sumK that have the smallest ratios
        // with the current element from the array (which has a potentially better ratio).
        for (int i = K; i < N; i++) {
            // Calculate the potential new sum if we replace the smallest element in current sumK with ab[i].second
            ll newSumK = sumK - ab[i - K].second + ab[i].second;
            ll newMaxA = max(ab[i].first, maxA);

            ans = min(ans, newMaxA * newSumK);
        }

        cout << ans << '\n';
    }

    return 0;
}