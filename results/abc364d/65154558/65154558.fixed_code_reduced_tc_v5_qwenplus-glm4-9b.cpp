#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        long long b, k;
        cin >> b >> k;
        long long ans = INF;

        // Calculate distances from b to each point in a
        for (int i = 0; i < n; ++i) {
            long long dist = abs(a[i] - b);
            // Sort distances and find the k-th closest
            if (k <= n) {
                ans = min(ans, dist);
            }
        }

        cout << ans << endl;
    }

    return 0;
}