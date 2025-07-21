#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    ll a[N], b[N-1];
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < N-1; i++) {
        cin >> b[i];
    }

    // To ensure each toy can be placed in a box
    sort(a, a + N);
    // To only consider necessary boxes
    sort(b, b + N-1, greater<ll>());

    // If the largest toy cannot be placed in the smallest box
    if (a[0] > b[N-2]) {
        cout << -1 << endl;
        return;
    }

    // To find the minimum size of the box needed
    for (ll i = 0; i < N-1; i++) {
        if (a[i] <= b[i]) continue;
        if (a[i+1] <= b[i]) {
            cout << b[i] << endl;
            return;
        }
    }

    // If all toys can fit in existing boxes
    cout << a[N-1] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}