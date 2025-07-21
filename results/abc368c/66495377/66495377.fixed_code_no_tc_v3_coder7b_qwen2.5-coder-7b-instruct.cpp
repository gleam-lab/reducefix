#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll t, ll h) {
    ll cnt = 0;
    cnt += h / 3; // Since we decrement by 1 or 3, every 3 units of health can be reduced by one full attack cycle
    int remind = h % 3;
    while (remind > 0) {
        t++;
        if (t % 3 == 0) {
            remind -= 3;
        } else {
            remind--;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    ll total_attacks = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        total_attacks += num_attack(total_attacks, h);
    }

    cout << total_attacks << endl;
}