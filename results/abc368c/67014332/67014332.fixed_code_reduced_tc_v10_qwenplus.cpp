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

        // Attack the frontmost alive enemy
        H[front] -= damage;

        // Move front pointer forward if current enemy is dead
        while (front < n && H[front] <= 0) {
            front++;
        }
    }

    cout << T << endl;
    return 0;
}