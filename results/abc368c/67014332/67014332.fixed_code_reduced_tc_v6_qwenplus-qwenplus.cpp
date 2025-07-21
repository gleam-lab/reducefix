#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0, tri = 1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        
        // Process full cycles of 3 attacks: 1 normal attack + 1 normal attack + 1 triple damage attack
        // Each cycle reduces health by 5 (1 + 1 + 3)
        ll full_cycles = h / 5;
        ans += full_cycles * 3;  // Each cycle takes 3 time units
        h %= 5;  // Remaining health after full cycles
        
        // Handle remaining health from 1 to 5
        while(h > 0) {
            if (tri == 3) {
                h -= 3;
                tri = 1;
            } else {
                h -= 1;
                tri++;
            }
            ans++;
        }
        
        // If we ended on a triple attack, reset the counter for next enemy
        if (tri == 3) {
            tri = 1;
        }
    }
    
    cout << ans;
}