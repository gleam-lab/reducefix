#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    // Sort both arrays in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int x = -1;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        // If the current toy cannot fit in the current box
        if (a[i] > b[j]) {
            // Check if we have already found a suitable box
            if (x != -1) {
                cout << -1 << endl;
                return;
            } else {
                // Mark this toy's size as the minimum required box size
                x = a[i];
                // Move to the next box since this one is too small
                ++j;
            }
        } else {
            // If the toy fits, move to the next toy
            ++i;
            // Move to the next box
            ++j;
        }
    }
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}