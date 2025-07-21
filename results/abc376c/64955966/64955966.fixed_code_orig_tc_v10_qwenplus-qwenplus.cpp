#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    // Create a new vector of size N to simulate inserting a new box
    vector<ll> C(N);
    for (ll i = 0; i < N - 1; ++i) C[i] = B[i];
    // Initially assume we add the largest possible value (as placeholder)
    C[N - 1] = LLONG_MAX;

    // Try to match A to C
    bool ok = true;
    for (ll i = 0; i < N; ++i) {
        if (A[i] > C[i]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        // Binary search the minimum x
        ll low = 1, high = 1e18, ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            // Insert mid as the new box
            C[N - 1] = mid;
            sort(C.begin(), C.end(), greater<ll>());
            bool valid = true;
            for (ll i = 0; i < N; ++i) {
                if (A[i] > C[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}