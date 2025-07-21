#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll t = 0;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    for (ll health : h) {
        // Reduce health in chunks of 3 when possible to minimize the number of steps
        t += (health + 2) / 3;
        // If there's a remainder, reduce it by 1
        if (health % 3 != 0) {
            t++;
        }
    }

    cout << t << endl;
}