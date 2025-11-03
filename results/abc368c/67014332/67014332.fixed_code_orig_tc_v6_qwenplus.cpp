#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll T = 0;
    ll tri = 0; // count of attacks, mod 3
    
    for(int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        
        while (h > 0) {
            T++;
            tri++;
            
            if (tri % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
        
        // Reset tri counter only when moving to next enemy
        // But note: T continues and tri is global across enemies
        // The pattern repeats every 3 attacks: 1,1,3,1,1,3,...
        // We need to maintain the global attack sequence
        // So we don't reset tri - it continues across enemies
    }
    
    cout << T;
}