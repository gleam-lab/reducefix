#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;

    vector<int> x(n + 1), p(n + 1); // Use vector for better bounds handling
    map<int, vector<int>> indexMap; // To store indices of x values

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        indexMap[x[i]].push_back(i); // Store indices where x[i] occurs
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        long long sumP = 0; // Use long long to avoid overflow

        // Iterate over all indices where x values fall in the range [L, R]
        auto itL = indexMap.lower_bound(L);
        auto itR = indexMap.upper_bound(R);

        for (auto it = itL; it != itR; ++it) {
            for (int idx : it->second) {
                if (x[idx] >= L && x[idx] <= R) { // Double-check the range (though unnecessary if input is correct)
                    sumP += p[idx];
                }
            }
        }

        cout << sumP << endl;
    }

    return 0;
}