#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        while (h[i] > 0) {
            t++;
            if (t % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i]--;
            }
        }
    }

    cout << t << endl;
}