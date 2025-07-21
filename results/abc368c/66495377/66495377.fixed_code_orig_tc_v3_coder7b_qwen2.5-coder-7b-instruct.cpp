#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll t, ll h) {
    ll cnt = 0;
    cnt += 3 * (h / 3); // Correctly calculate the number of full attacks of 3
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t += num_attack(t, h);
    }

    cout << t << endl;
}