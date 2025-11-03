#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        // Calculate how many attacks needed for current enemy
        while (h[i] > 0) {
            t++;
            if (t % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i]--;
            }
            
            // If this enemy is defeated, move to next
            if (h[i] <= 0) break;
            
            // Check if we need to attack previous enemies that became positive again
            // But according to problem, we always attack frontmost enemy with health > 0
            // So we just continue attacking current enemy until it's dead
        }
    }

    cout << t << endl;
}