#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        ans += full_cycles * 3;
        if (remaining > 0) {
            if (remaining <= 2) {
                ans += remaining;
            } else {
                ans += 3;
            }
        }
    }
    cout << ans;
}