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
    int i = 0;
    
    while (i < n) {
        // Skip enemies that are already defeated
        if (a[i] <= 0) {
            i++;
            continue;
        }
        
        T++;
        
        // Attack the frontmost enemy with health > 0
        if (T % 3 == 0) {
            a[i] -= 3;
        } else {
            a[i]--;
        }
        
        // If this enemy is defeated, move to next
        if (a[i] <= 0) {
            i++;
        }
    }
    
    cout << T << endl;
}