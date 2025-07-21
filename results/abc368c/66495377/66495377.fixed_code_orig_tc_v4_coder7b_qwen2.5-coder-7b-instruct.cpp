#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the number of attacks needed for an enemy
ll num_attack(ll t, ll h) {
    ll cnt = 0;
    while (h > 0) {
        t++;
        if (t % 3 == 0) {
            h -= 3;
        } else {
            h -= 1;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
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