#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;
    int current_enemy = 0;

    while (current_enemy < n) {
        T++;
        // Attack the frontmost enemy with health > 0
        if (H[current_enemy] > 0) {
            if (T % 3 == 0) {
                H[current_enemy] -= 3;
            } else {
                H[current_enemy] -= 1;
            }
        }

        // Move to next enemy if current one is dead
        while (current_enemy < n && H[current_enemy] <= 0) {
            current_enemy++;
        }
    }

    cout << T << endl;
}