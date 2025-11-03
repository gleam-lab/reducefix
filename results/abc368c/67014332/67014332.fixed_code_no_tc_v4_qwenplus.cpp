#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    ll T = 0;
    int enemyIndex = 0;

    while (enemyIndex < n) {
        T++;
        // Skip enemies that are already defeated
        while (enemyIndex < n && h[enemyIndex] <= 0) {
            enemyIndex++;
        }
        
        if (enemyIndex >= n) break;
        
        // Attack the frontmost alive enemy
        if (T % 3 == 0) {
            h[enemyIndex] -= 3;
        } else {
            h[enemyIndex] -= 1;
        }
    }

    cout << T << endl;
    return 0;
}