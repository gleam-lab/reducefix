#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    ll T = 0;
    int idx = 0;
    
    while (idx < n) {
        T++;
        // Check if current frontmost enemy (idx) is still alive
        if (a[idx] > 0) {
            if (T % 3 == 0) {
                a[idx] -= 3;
            } else {
                a[idx] -= 1;
            }
            // If this enemy is defeated, move to next
            if (a[idx] <= 0) {
                idx++;
            }
        } else {
            // This enemy already dead, move to next
            idx++;
        }
    }
    
    cout << T << endl;
}