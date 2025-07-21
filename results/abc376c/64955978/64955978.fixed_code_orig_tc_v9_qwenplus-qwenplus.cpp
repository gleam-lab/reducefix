#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll N;
    cin >> N;

    vector<ll> A(N), B(N - 1);

    for (ll i = 0; i < N; ++i)
        cin >> A[i];

    for (ll i = 0; i < N - 1; ++i)
        cin >> B[i];

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    ll j = 0;
    vector<ll> unused_toys;

    for (ll i = 0; i < N; ++i) {
        if (j < N - 1 && B[j] >= A[i])
            j++;
        else
            unused_toys.push_back(A[i]);
    }

    if (unused_toys.size() <= 1)
        cout << (unused_toys.empty() ? -1 : unused_toys[0]) << endl;
    else
        cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}