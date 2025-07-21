#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n), prefix(2 * n + 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }

    // Duplicate the array to handle circular property
    for (int i = 0; i < n; ++i) {
        a.push_back(a[i]);
    }

    // Compute prefix sums modulo m
    prefix[0] = 0;
    for (int i = 0; i < 2 * n; ++i) {
        prefix[i + 1] = (prefix[i] + a[i]) % m;
    }

    // Use a multiset to maintain the suffix sums in sorted order
    multiset<long long> suffix_sums;
    long long result = 0;

    // Traverse from the end and build the suffix set
    for (int i = 2 * n - 1; i >= n; --i) {
        suffix_sums.insert(prefix[i + 1]);
    }

    // Slide the window
    for (int i = n; i <= 2 * n; ++i) {
        // Remove the element going out of the window
        auto it = suffix_sums.find(prefix[i]);
        if (it != suffix_sums.end()) {
            suffix_sums.erase(it);
        }

        // Add the new element coming into the window
        suffix_sums.insert(prefix[i - n]);

        // Count how many prefix[j] <= prefix[i]
        long long current = prefix[i];
        long long count = distance(suffix_sums.begin(), suffix_sums.upper_bound(current));
        result += count;
    }

    cout << result << endl;
    return 0;
}