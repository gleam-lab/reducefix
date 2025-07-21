#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    ll T = 0;
    
    for (ll i = 0; i < N; i++) {
        cin >> H[i];
        // Calculate the minimum number of attacks needed for the current enemy
        ll health = H[i];
        while (health > 0) {
            if (T % 3 == 0) {
                health -= 3;
            } else {
                health -= 1;
            }
            T++;
        }
    }
    
    cout << T << endl;
    return 0;
}