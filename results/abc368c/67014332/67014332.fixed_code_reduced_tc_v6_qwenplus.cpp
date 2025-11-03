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
    int front = 0; // index of the first enemy with health > 0

    while (front < n) {
        T++;
        // Determine damage: 3 if T is multiple of 3, else 1
        ll damage = (T % 3 == 0) ? 3 : 1;

        // Attack the frontmost enemy with health > 0
        H[front] -= damage;

        // If this enemy's health drops to 0 or below, move to next
        if (H[front] <= 0) {
            front++;
        }
    }

    cout << T << endl;
    return 0;
}