#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll t, ll h) {
    ll cnt = 0;
    cnt += 3 * (h / 3); // 3 is the damage per attack
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t += num_attack(t, h);
    }

    cout << t << endl;

    return 0;
}