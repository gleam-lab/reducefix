#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int x = -1; // Minimum box size x not yet determined

    for (int i = 0; i < n; ++i) { // Iterate over all toys
        bool isPlaced = false; // Flag to check if the current toy is placed
        for (int j = 0; j < n - 1; ++j) { // Check all boxes
            if (a[i] <= b[j]) { // If box can hold the toy
                isPlaced = true; // Place the toy in this box
                x = max(x, b[j]); // Update x to the size of the box we used
                break; // This toy is now placed, move to the next toy
            }
        }

        if (!isPlaced) { // If the toy wasn't placed, it's impossible to fit it
            cout << -1 << endl;
            return;
        }
    }

    cout << x << endl; // If we've placed all toys, output x
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}