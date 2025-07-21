#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll h) {
    ll cnt = 0;
    cnt += 3 * (h / 3); // 3は3回攻撃した時のダメージ
    int remind = h % 3;
    while (remind > 0) {
        cnt++;
        remind--;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t += num_attack(h);
    }

    cout << t << endl;
}