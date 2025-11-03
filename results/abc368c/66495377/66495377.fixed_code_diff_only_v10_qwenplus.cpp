#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Simulate attacks starting from time t until enemy with health h is defeated
ll simulate_attack(ll t, ll h) {
    while (h > 0) {
        t++;
        if (t % 3 == 0) {
            h -= 3;
        } else {
            h--;
        }
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t = simulate_attack(t, h);
    }
    cout << t << endl;
    return 0;
}