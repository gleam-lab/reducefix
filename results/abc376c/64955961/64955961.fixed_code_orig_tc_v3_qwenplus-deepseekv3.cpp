#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);
    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll i = 0, j = 0;
    ll cnt = 0;
    ll candidate = -1;

    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            cnt++;
            candidate = A[i];
            i++;
        }
    }

    while (i < n) {
        cnt++;
        candidate = A[i];
        i++;
    }

    if (cnt > 1) {
        cout << -1 << endl;
    } else if (cnt == 1) {
        cout << candidate << endl;
    } else {
        cout << B.back() << endl;
    }
}

int main() {
    solve();
    return 0;
}