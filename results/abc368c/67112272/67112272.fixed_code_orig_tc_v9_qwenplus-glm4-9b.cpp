#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
    ll n; cin >> n;
    ll T = 0;
    ll health;
    rep(i, n) {
        cin >> health;
        if (health > 3 * (T % 3)) {
            T += (health - 3 * (T % 3)) / (3 * (T % 3)) * 3;
        } else {
            T += health;
        }
    }
    cout << T << endl;
}