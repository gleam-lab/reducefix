#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> health(n);
    ll T = 0;
    
    for (auto &h : health) {
        cin >> h;
        if (h > 0) { // Only proceed if the enemy has positive health
            ll rounds = h / 3; // First, use 3 attacks if possible
            h -= rounds * 3;
            T += rounds + (h % 3); // Add the rounds plus any leftover health that needs 1 attack
        }
    }
    
    cout << T << endl;
    return 0;
}