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
    
    // Sort the arrays in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    int maxBoxSize = -1;
    int i = 0, j = 0;

    // Iterate through both arrays to find the minimum box size needed
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
        } else {
            if (maxBoxSize == -1 || a[i] < maxBoxSize) {
                maxBoxSize = a[i];
            } else {
                cout << -1 << endl;
                return;
            }
            j++;
        }
    }

    // If we still need to place a toy, check if the last toy can fit
    if (i < n) {
        if (maxBoxSize == -1 || a[i] < maxBoxSize) {
            maxBoxSize = a[i];
        } else {
            cout << -1 << endl;
            return;
        }
    }

    cout << maxBoxSize << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // Uncomment the line below to read multiple test cases
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}