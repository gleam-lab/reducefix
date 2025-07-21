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
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize the minimum box size needed
    int min_box_size = -1;

    // Iterate through each toy and try to fit it into the smallest available box
    for (int i = 0; i < n; ++i) {
        // If the current toy is smaller than or equal to the largest box available, place it
        if (a[i] <= b[n - 1]) {
            min_box_size = a[i];
            break;
        } else {
            // If we can't fit this toy, increase the box size and check again
            for (int j = 0; j < n - 1; ++j) {
                if (a[i] <= b[j] + 1) {
                    min_box_size = b[j] + 1;
                    break;
                }
            }
            if (min_box_size != -1)
                break;
        }
    }

    cout << min_box_size << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}