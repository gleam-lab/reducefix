#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1); // Using vectors for better memory management and bounds safety
    map<int, int> prefixSum;

    // Read x values (0-indexed for easier range management, though we only use 1 to n)
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    // Read p values and compute prefix sums using a map for sparse updates
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefixSum[x[i]] += p[i];
    }

    // Since prefix sums are stored based on x values directly, we need to maintain a cumulative sum
    map<int, int> cumulativeSum;
    int cumSum = 0;
    for (const auto& pair : prefixSum) {
        cumSum += pair.second;
        cumulativeSum[pair.first] = cumSum;
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Use lower_bound and upper_bound on the x values (since they are sorted implicitly by their insertion order in map keys)
        auto itL = cumulativeSum.lower_bound(L);
        auto itR = cumulativeSum.upper_bound(R);

        // If itL points to a key greater than R, it means there are no elements in the range [L, R]
        if (itL == cumulativeSum.end() || itL->first > R) {
            cout << 0 << endl;
        } else {
            int sumL = (itL == cumulativeSum.begin()) ? 0 : (--itL)->second;
            int sumR = (itR != cumulativeSum.end()) ? itR->second : cumulativeSum.rbegin()->second;
            cout << sumR - sumL << endl;
        }
    }

    return 0;
}