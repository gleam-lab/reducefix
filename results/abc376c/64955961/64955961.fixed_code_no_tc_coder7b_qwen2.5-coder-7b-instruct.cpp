#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll maxUnfitToy = -1, boxIndex = 0;
    for (ll toyIndex = 0; toyIndex < n; ++toyIndex) {
        if (boxIndex < n - 1 && a[toyIndex] <= b[boxIndex]) {
            boxIndex++;
        } else {
            maxUnfitToy = max(maxUnfitToy, a[toyIndex]);
        }
    }
    cout << (maxUnfitToy == -1 ? -1 : maxUnfitToy) << endl;
}

int main() {
    solve();
}