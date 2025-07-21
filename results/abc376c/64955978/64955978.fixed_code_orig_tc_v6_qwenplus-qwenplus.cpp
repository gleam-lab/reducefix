#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll N;
    cin >> N;

    vector<ll> A(N), B(N - 1);

    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.rbegin(), A.rend());  // Descending
    sort(B.rbegin(), B.rend());

    ll extra_box_size = -1;
    ll j = 0;

    for (ll i = 0; i < N; ++i) {
        if (j < N - 1 && A[i] <= B[j]) {
            ++j;  // Use one of the available boxes
        } else {
            if (extra_box_size == -1) {
                extra_box_size = A[i];  // Use the new box for this toy
            } else {
                cout << -1 << endl;  // Already used extra box
                return;
            }
        }
    }

    cout << extra_box_size << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}