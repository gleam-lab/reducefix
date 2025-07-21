#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    ll current = 0; // This will accumulate the total cost
    
    for (ll i = 0; i < n; ++i) {
        ll health = H[i];
        if (current % 3 == 2) { // If current attack is the third one
            // We can attack this enemy with T=3, T=4, or T=5
            // This means we don't need to increment T, we can use the next T=6 attack
            current += health;
        } else if (current % 3 == 1) { // If current attack is the second one
            // We need to increment T by 2 to be able to attack this enemy
            T += 2;
            current += health;
        } else { // If current attack is the first one
            T += 1;
            current += health;
        }
    }
    
    cout << T << endl;
    
    return 0;
}