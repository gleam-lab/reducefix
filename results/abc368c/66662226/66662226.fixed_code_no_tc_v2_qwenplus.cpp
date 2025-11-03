#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll T = 0;
    int current_enemy = 0;

    while (current_enemy < n) {
        T++;
        // Attack the frontmost enemy with health > 0
        if (h[current_enemy] > 0) {
            if (T % 3 == 0) {
                h[current_enemy] -= 3;
            } else {
                h[current_enemy] -= 1;
            }
        }

        // If current enemy is defeated, move to next
        while (current_enemy < n && h[current_enemy] <= 0) {
            current_enemy++;
        }
    }

    cout << T << endl;
    return 0;
}