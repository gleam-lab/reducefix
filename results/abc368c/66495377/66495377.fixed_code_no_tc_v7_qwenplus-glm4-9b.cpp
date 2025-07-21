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
    for (ll health : H) {
        if (health == 0) continue;
        
        if (T % 3 == 0) {
            T += (health + 2) / 3;
        } else {
            T += health;
        }
    }
    
    cout << T << endl;
    return 0;
}