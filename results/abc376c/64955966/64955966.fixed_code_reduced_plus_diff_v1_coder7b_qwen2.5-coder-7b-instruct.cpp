#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (ll i = 0; i < N; ++i) cin >> a[i];
    for (ll i = 0; i < N - 1; ++i) cin >> b[i];

    // Sort toys and boxes in descending order
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    // Check if we can place all toys
    bool possible = true;
    for (ll i = 0; i < N; ++i) {
        if (i == N - 1) { // For the last toy, it must fit into the new box
            if (a[i] > b.back()) {
                possible = false;
                break;
            }
        } else {
            // Check if any existing box can hold the current toy
            bool found = false;
            for (ll j = 0; j < N - 1; ++j) {
                if (a[i] <= b[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                possible = false;
                break;
            }
        }
    }

    if (possible) yes;
    else no;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}