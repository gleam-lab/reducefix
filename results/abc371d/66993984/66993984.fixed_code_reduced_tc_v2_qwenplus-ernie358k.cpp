#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1); // Using long long to handle large numbers
    map<long long, long long> prefixSum; // Using long long for sum values
    prefixSum[0] = 0; // Initialize prefix sum for index 0

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefixSum[x[i]] += p[i]; // Sum p[i] at position x[i] in the map
    }

    // Since x[i] can be non-contiguous, we need to maintain a cumulative prefix sum
    map<long long, long long> cumulativeSum;
    long long cumSum = 0;
    for (const auto& [key, value] : prefixSum) {
        cumSum += value;
        cumulativeSum[key] = cumSum;
    }

    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;

        // Find the closest elements in x that are <= L and < R
        auto itL = cumulativeSum.lower_bound(L);
        if (itL == cumulativeSum.end()) {
            // If L is greater than all elements in x
            cout << 0 << endl;
            continue;
        }
        --itL; // lower_bound gives the first element >= L, so decrement to get <= L

        auto itR = cumulativeSum.upper_bound(R);
        if (itR == cumulativeSum.begin()) {
            // If R is less than all elements in x
            cout << 0 << endl;
            continue;
        }
        --itR; // To get the last element < R, use the previous element
        // Since itR is now the last element < R, we need to exclude it in the sum

        // Calculate the sum: from the element <= L to just before the element < R
        long long result = (itR == cumulativeSum.begin()) ? cumulativeSum[itL->first] 
                         : cumulativeSum[itR->first] - cumulativeSum[prev(itR)->first];

        cout << result << endl;
    }

    return 0;
}