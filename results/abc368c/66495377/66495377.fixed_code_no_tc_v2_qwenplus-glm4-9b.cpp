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
        // For each enemy, calculate the minimum number of attacks required
        t += (h[i] + 2) / 3; // (h[i] + 2) / 3 ensures that we round up to the nearest multiple of 3
    }

    cout << t << endl;
}