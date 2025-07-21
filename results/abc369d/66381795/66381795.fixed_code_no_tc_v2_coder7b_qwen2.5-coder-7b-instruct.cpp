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

    // Sort the array to consider stronger monsters first
    sort(data.begin(), data.end());

    ll max_experience = 0;
    for (int i = 0; i < n; ++i) {
        // If it's an odd-indexed monster (0-based index)
        if ((i + 1) % 2 != 0) {
            max_experience += data[i];
        } else {
            // For even-indexed monsters, add twice their strength
            max_experience += 2 * data[i];
        }
    }

    cout << max_experience << endl;
    return 0;
}