#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<P> a(n);
        vector<ll> b(n), sumB(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].second >> b[i];
            sumB[i + 1] = sumB[i] + b[i];
        }

        sort(a.begin(), a.end());

        ll minProduct = LLONG_MAX;
        ll maxA = 0, currentSumB = 0;

        // Iterate over the sorted pairs by B
        for (int i = 0; i < n; ++i) {
            // Update the maximum A possible with the current sum of B
            maxA = max(maxA, a[i].first);
            currentSumB = sumB[k]; // Only consider the sum of B for the current subset size

            // Calculate the product for the current subset and update the minimum product
            minProduct = min(minProduct, maxA * currentSumB);

            // Update the sum of B by removing the smallest B in the current subset
            currentSumB -= b[i];

            // Reduce the subset size
            if (--k == 0) break;
        }

        cout << minProduct << '\n';
    }

    return 0;
}