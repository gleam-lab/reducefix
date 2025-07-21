#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    // Initialize the sum of experience points
    ll max_points = 0;

    // Iterate through each monster
    for(int i = 0; i < n; ++i) {
        // If the current monster's strength is greater than twice the next monster's strength,
        // and it's an odd-indexed monster, take it.
        if((i + 1 < n && data[i] > 2 * data[i + 1]) || i % 2 == 0) {
            max_points += data[i];
        }
    }

    cout << max_points << endl;
    return 0;
}