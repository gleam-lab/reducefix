#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_damage(int h) {
    ll damage = 0;
    while (h > 0) {
        if (damage % 3 == 0) {
            h -= 3;
        } else {
            h--;
        }
        damage++;
    }
    return damage;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll total_damage = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        total_damage += calculate_damage(h);
    }

    cout << total_damage << endl;

    return 0;
}