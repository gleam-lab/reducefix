#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        while (H[i] > 0) {
            t++;
            if (t % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i]--;
            }
        }
    }

    cout << t << endl;
    return 0;
}