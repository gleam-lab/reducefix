#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> health(n);
    ll total_time = 0;
    
    // Read the health of each enemy
    for (ll i = 0; i < n; ++i) {
        cin >> health[i];
    }
    
    // Iterate over each enemy's health
    for (ll i = 0; i < n; ++i) {
        ll current_health = health[i];
        
        // If the enemy's health is 9 or less, we can attack it until its health becomes 0
        if (current_health <= 9) {
            total_time += current_health;
        } else {
            // If the health is greater than 9, we will attack it in rounds of 3
            total_time += (current_health / 3) * 3;
            current_health %= 3;
            
            // If there is a remainder, it means we need an extra attack (either 1 or 2)
            if (current_health > 0) {
                total_time += 1;
            }
        }
    }
    
    cout << total_time;
    return 0;
}