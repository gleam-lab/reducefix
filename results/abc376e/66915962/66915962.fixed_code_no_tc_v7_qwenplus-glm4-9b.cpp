#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define OUT(x) cout << #x << ":" << x << endl

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> A(n), B(n);
        ll ans = LLONG_MAX;
        
        rep(i, n) cin >> A[i];
        rep(i, n) cin >> B[i];

        // We need to find the minimum value of the expression:
        // (maxAi) * (sumBi) where only K elements are considered.
        // To minimize the expression, we should consider the smallest possible
        // maxAi and the largest possible sumBi when we pick K elements.

        // We can do this by sorting B and trying to maximize the sum by picking elements from the beginning
        // of B array (since B is sorted, smaller B values are at the beginning).
        sort(B.begin(), B.end());

        // We can also consider picking the first K elements to minimize maxAi.
        ll maxA = *max_element(A.begin(), A.begin() + k);
        ll sumB = 0;
        for (ll i = 0; i < k; ++i) {
            sumB += B[i];
        }
        ans = min(ans, maxA * sumB);

        // Additionally, we can consider a scenario where we pick k-1 elements from the end of B
        // (to maximize the sum) and one element from the beginning (to minimize maxA).
        ll sumBfromEnd = 0;
        for (ll i = n - k + 1; i < n; ++i) {
            sumBfromEnd += B[i];
        }
        maxA = A[k-1]; // Take the k-th element from A to minimize maxA
        ans = min(ans, maxA * sumBfromEnd);

        cout << ans << '\n';
    }
}