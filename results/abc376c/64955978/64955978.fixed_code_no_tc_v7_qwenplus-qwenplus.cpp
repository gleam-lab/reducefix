#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);

    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We will use a greedy approach: try to fit the smallest toy in the smallest usable box
    ll j = 0;
    ll required_box_size = -1;

    for (ll i = 0; i < N; ++i) {
        if (j < N - 1 && B[j] >= A[i]) {
            j++;
        } else {
            // This toy must go into the additional box
            required_box_size = max(required_box_size, A[i]);
        }
    }

    cout << required_box_size << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}