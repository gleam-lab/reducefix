#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }

    ll T = 0;
    int enemyIndex = 0;

    while (enemyIndex < n) {
        T++;
        // Find the first enemy with health > 0
        while (enemyIndex < n && H[enemyIndex] <= 0) {
            enemyIndex++;
        }
        
        if (enemyIndex >= n) break;

        // Attack the frontmost alive enemy
        if (T % 3 == 0) {
            H[enemyIndex] -= 3;
        } else {
            H[enemyIndex] -= 1;
        }
    }

    cout << T << endl;
    return 0;
}