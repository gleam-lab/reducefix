#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

bool canDefeatEnemies(int T, const vector<ll>& h) {
    ll totalAttacks = 0;
    for (const auto& health : h) {
        ll attacks = (health + 2) / 3;  // Because (health - 1) / 3 will always be the floor
        if (attacks % 3 == 0) totalAttacks += attacks / 3;
        else {
            if (attacks >= 3) totalAttacks += attacks / 3 + 1;
            else totalAttacks += attacks; // This will handle the case when attacks < 3
        }
        if (totalAttacks > T) return false;
    }
    return totalAttacks <= T;
}

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (ll& health : h) cin >> health;

    int low = 0, high = 2e9;  // We can set the upper limit to 2e9 because the number of attacks can't be larger than the total health of all enemies.
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (canDefeatEnemies(mid, h)) high = mid;
        else low = mid;
    }
    cout << high << endl;
    return 0;
}