#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int m = n - k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // We need to find the minimum possible value of (max - min) in any subsequence of length m
    // The key mistake in the original code was sorting the entire array and trying to find
    // the minimal range in the sorted array. This is incorrect because we must preserve order.

    // To solve correctly:
    // We want to slide a window of size m over the original array and compute max-min
    // for each such window, then take the minimum among all those values.

    deque<int> maxDq;  // stores indices of elements in decreasing order (for max)
    deque<int> minDq;  // stores indices of elements in increasing order (for min)

    long long result = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain maxDq: elements are in decreasing order
        while (!maxDq.empty() && a[i] > a[maxDq.back()]) {
            maxDq.pop_back();
        }
        maxDq.push_back(i);

        // Maintain minDq: elements are in increasing order
        while (!minDq.empty() && a[i] < a[minDq.back()]) {
            minDq.pop_back();
        }
        minDq.push_back(i);

        // Remove out-of-window indices
        if (i >= m) {
            if (!maxDq.empty() && maxDq.front() <= i - m) {
                maxDq.pop_front();
            }
            if (!minDq.empty() && minDq.front() <= i - m) {
                minDq.pop_front();
            }
        }

        // Once window has size m, calculate max - min
        if (i >= m - 1) {
            result = min(result, 1LL * a[maxDq.front()] - a[minDq.front()]);
        }
    }

    cout << result << endl;

    return 0;
}