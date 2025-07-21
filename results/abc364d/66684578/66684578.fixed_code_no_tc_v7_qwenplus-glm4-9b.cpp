#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to use binary search later
    sort(a.begin(), a.end());

    // Process each query
    for (int i = 0; i < q; ++i) {
        long long b, k;
        cin >> b >> k;

        // Calculate the index of the k-th closest point
        auto it = lower_bound(a.begin(), a.end(), b) - a.begin();
        long long kth_closest = a[it + k - 1]; // k-th closest point

        // Output the distance to the k-th closest point
        cout << abs(kth_closest - b) << endl;
    }

    return 0;
}