#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> health(n);
    
    // Read each enemy's health
    for (ll i = 0; i < n; ++i) {
        cin >> health[i];
    }
    
    ll total_attacks = 0;
    
    // Iterate from the last enemy to the first
    for (ll i = n - 1; i >= 0; --i) {
        // Calculate full cycles of 3 attacks
        total_attacks += (health[i] + 2) / 3;
        
        // Remaining health after full cycles
        health[i] -= ((health[i] + 2) / 3) * 3;
        
        // If there is any remaining health, it means the next attack is not a multiple of 3
        if (health[i] > 0) {
            total_attacks++;
        }
    }
    
    cout << total_attacks << endl;
}