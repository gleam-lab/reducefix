#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    ll T = 0;
    int enemy_idx = 0;
    
    while (enemy_idx < n) {
        T++;
        // Find the first enemy with health > 0
        while (enemy_idx < n && h[enemy_idx] <= 0) {
            enemy_idx++;
        }
        
        if (enemy_idx >= n) break;
        
        // Attack the frontmost alive enemy
        if (T % 3 == 0) {
            h[enemy_idx] -= 3;
        } else {
            h[enemy_idx] -= 1;
        }
    }
    
    cout << T << endl;
    return 0;
}