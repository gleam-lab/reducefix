#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll t = 0;
    int i = 0;
    
    while (i < n) {
        t++;
        // Attack the frontmost enemy with health > 0
        if (h[i] > 0) {
            if (t % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i]--;
            }
            // If this enemy is defeated, move to next
            if (h[i] <= 0) {
                i++;
            }
        }
        // If current enemy has 0 or negative health, move to next
        while (i < n && h[i] <= 0) {
            i++;
        }
    }
    
    cout << t << endl;
}