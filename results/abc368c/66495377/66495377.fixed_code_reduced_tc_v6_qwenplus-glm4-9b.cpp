#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll solve(int n, const vector<ll>& healths) {
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        // Calculate the number of attacks needed to reduce health to zero or less
        // If health is already 0 or less, no attack is needed for this enemy
        while (healths[i] > 0) {
            if (t % 3 == 0) {
                healths[i] -= 3;
            } else {
                healths[i] -= 1;
            }
            t++;
        }
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<ll> healths(n);
    for (int i = 0; i < n; ++i) {
        cin >> healths[i];
    }
    
    cout << solve(n, healths) << endl;
    return 0;
}