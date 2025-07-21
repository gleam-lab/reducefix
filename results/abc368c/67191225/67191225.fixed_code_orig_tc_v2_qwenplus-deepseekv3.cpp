#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    ll T = 0;
    for (int i = 0; i < N; ++i) {
        ll h = H[i];
        // The attacks on this enemy start at time T + 1
        // Each attack can be either 1 or 3 damage, depending on (T + k) % 3 == 0
        // We need to find the number of attacks k such that sum of damages >= h
        // The damage pattern is cyclic every 3 attacks: 1, 1, 3
        // So, the sum of damage per 3 attacks is 1 + 1 + 3 = 5
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        ll k = 0;
        ll damage = 0;
        if (remaining > 0) {
            if ((T + 1) % 3 == 0) {
                damage = 3;
                if (remaining > damage) {
                    k = 1;
                    remaining -= damage;
                    if ((T + 2) % 3 == 0) {
                        damage = 3;
                    } else {
                        damage = 1;
                    }
                    if (remaining > damage) {
                        k++;
                        remaining -= damage;
                    } else {
                        k++;
                        remaining = 0;
                    }
                } else {
                    k = 1;
                    remaining = 0;
                }
            } else {
                damage = 1;
                k = 1;
                remaining -= damage;
                if (remaining > 0) {
                    if ((T + 2) % 3 == 0) {
                        damage = 3;
                    } else {
                        damage = 1;
                    }
                    if (remaining > damage) {
                        k++;
                        remaining -= damage;
                    } else {
                        k++;
                        remaining = 0;
                    }
                }
            }
        }
        k += full_cycles * 3;
        T += k;
    }
    cout << T << endl;
    return 0;
}