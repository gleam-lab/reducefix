#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toys and boxes in descending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    // Try to fit the largest toys into the largest available boxes
    ll extra_toy = -1;

    ll b_idx = 0;
    for (ll a_idx = 0; a_idx < N; ++a_idx) {
        if (b_idx < N - 1 && B[b_idx] >= A[a_idx]) {
            b_idx++;
        } else {
            if (extra_toy == -1) {
                extra_toy = A[a_idx];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    if (extra_toy == -1) {
        // All toys fit in existing boxes, so we can choose x = 0 or minimal possible unused size
        // But per problem statement, x must be positive
        cout << "1" << endl;
    } else {
        cout << extra_toy << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}