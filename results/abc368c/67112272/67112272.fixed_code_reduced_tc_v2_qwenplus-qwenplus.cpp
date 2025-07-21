#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // We will simulate the process using a queue
    queue<ll> q;
    rep(i, n) q.push(H[i]);

    ll attack_count = 0;

    // While there are enemies left
    while (!q.empty()) {
        ll h = q.front();
        q.pop();
        
        attack_count++;
        T++;

        if (attack_count % 3 == 0) {
            h -= 3;
        } else {
            h -= 1;
        }

        if (h > 0) {
            // Put the enemy back in the queue to be attacked again
            q.push(h);
        }
    }

    cout << T << endl;

    return 0;
}