#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> A(n);
    for (long long &a : A) cin >> a;
    
    // Create a vector to help us find the maximum and minimum values when K elements are removed
    vector<pair<long long, long long>> prefixMaxMin;
    for (int i = 0; i < n; ++i) {
        // Find the maximum and minimum values before the current element
        long long maxVal = 0;
        long long minVal = LLONG_MAX;
        for (int j = max(0, i - k + 1); j < i; ++j) {
            maxVal = max(maxVal, A[j]);
            minVal = min(minVal, A[j]);
        }
        prefixMaxMin.push_back({maxVal, minVal});
    }

    // Find the minimum possible value of the difference between max and min values after removing K elements
    long long minDiff = LLONG_MAX;
    for (int i = k - 1; i < n - k; ++i) {
        long long maxA = prefixMaxMin[i + k].first; // Maximum value after removing K elements from the right
        long long minB = prefixMaxMin[i].second;  // Minimum value before removing K elements on the left
        minDiff = min(minDiff, maxA - minB);
    }
    cout << minDiff << endl;

    return 0;
}