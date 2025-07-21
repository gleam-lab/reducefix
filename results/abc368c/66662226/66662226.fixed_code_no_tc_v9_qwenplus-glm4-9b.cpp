#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    ll ans = 0;
    rep(i, n) cin >> health[i];

    for (int health_i : health) {
        if (health_i % 3 == 0) {
            ans += health_i / 3;
        } else {
            ans += health_i / 3 + 1;
        }
    }

    cout << ans << endl;
}