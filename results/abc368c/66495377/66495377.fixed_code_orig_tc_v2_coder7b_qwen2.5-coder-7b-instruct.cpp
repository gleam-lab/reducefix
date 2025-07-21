#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll simulateAttack(int &T, ll h) {
    ll cnt = 0;
    while (h > 0) {
        T++;
        if (T % 3 == 0) {
            h -= 3;
        } else {
            h -= 1;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t += simulateAttack(t, h);
    }

    cout << t << endl;

    return 0;
}