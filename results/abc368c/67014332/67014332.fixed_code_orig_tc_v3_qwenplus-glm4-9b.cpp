#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, totalHealth = 0;
    cin >> n;
    vector<ll> healths(n);
    for (ll i = 0; i < n; ++i) {
        cin >> healths[i];
        totalHealth += healths[i];
    }

    ll attacks = 0;
    for (ll h : healths) {
        attacks += (h + 2) / 3; // This is equivalent to ceil(h / 3) + ceil((h % 3)) / 2
    }

    cout << totalHealth + attacks << endl; // total time is the total health plus the number of attacks
}