#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> health[i];
        // Calculate the full health decreases
        int full_decreases = health[i] / 5;
        health[i] -= full_decreases * 5;
        // Calculate the hits needed for remaining health
        int hits = health[i]; // This is already the minimum number of hits needed
        ans += full_decreases + hits;
    }
    cout << ans << endl;
    return 0;
}