#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<long long> x(n+1), p(n+1), sum(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }

    // Sort x array (assuming it wasn't sorted before)
    vector<pair<long long, int>> indexedX(n);
    for (int i = 1; i <= n; i++) {
        indexedX[i-1] = {x[i], i};
    }
    sort(indexedX.begin(), indexedX.end());

    // Rebuild x array as sorted values (not strictly necessary, just for clarity)
    // and create a mapping from sorted indices back to original indices
    vector<int> originalIndex(n+1);
    for (int i = 0; i < n; i++) {
        originalIndex[indexedX[i].second] = i + 1; // +1 to match 1-based indexing logic
    }

    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        
        // Find the correct indices in the sorted x
        auto itL = lower_bound(indexedX.begin(), indexedX.end(), make_pair(l, 0)) - indexedX.begin();
        auto itR = upper_bound(indexedX.begin(), indexedX.end(), make_pair(r, n+1)) - indexedX.begin();
        
        // Map back to original indices (1-based) and adjust for 0-based array access
        int idxL = originalIndex[itL];
        int idxR = (itR == n ? n : originalIndex[itR]); // Handle case where r is larger than all values

        // Print the result, ensuring no out-of-bounds access
        cout << (idxR > idxL ? sum[idxR-1] - sum[idxL-1] : 0) << endl;
    }

    return 0;
}