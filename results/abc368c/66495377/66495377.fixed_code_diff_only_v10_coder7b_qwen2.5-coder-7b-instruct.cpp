#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll h) {
    ll cnt = 0;
    cnt += h / 3; // 3 is the damage per attack
    int remind = h % 3;
    while (remind > 0) {
        remind--;
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    ll total_t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        total_t += num_attack(h);
    }

    cout << total_t << endl;
}