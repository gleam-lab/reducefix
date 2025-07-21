#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;

    // We need to find the maximum toy size
    int maxToySize = *max_element(a.begin(), a.end());

    // Check if this maximum toy size is less than or equal to any of the box sizes
    bool canFitInExistingBox = false;
    for (int i = 0; i < n - 1; ++i) {
        if (maxToySize <= b[i]) {
            canFitInExistingBox = true;
            break;
        }
    }

    // If we can fit the maximum toy in an existing box, the answer is 0
    if (canFitInExistingBox) {
        cout << 0 << endl;
    } else {
        // Otherwise, we need to buy a new box of size maxToySize
        cout << maxToySize << endl;
    }
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