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
    int enemy_idx = 0;
    
    while (enemy_idx < n) {
        T++;
        // Attack the frontmost enemy with health > 0
        if (a[enemy_idx] > 0) {
            if (T % 3 == 0) {
                a[enemy_idx] -= 3;
            } else {
                a[enemy_idx]--;
            }
            
            // If current enemy's health becomes 0 or less, move to next enemy
            if (a[enemy_idx] <= 0) {
                enemy_idx++;
            }
        }
        // If current enemy has 0 or negative health, skip to next enemy
        else {
            enemy_idx++;
        }
    }
    
    cout << T << endl;
}