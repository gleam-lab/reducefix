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

    // We need to find the minimum possible value of (max - min)
    // over all subsequences of length m when removing K elements.

    // Sliding window approach: keep track of min and max in windows of size m
    // We use deques to maintain indices of candidates for min and max

    deque<int> min_deq, max_deq;
    long long min_result = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain min deque: increasing order
        while (!min_deq.empty() && a[i] <= a[min_deq.back()]) {
            min_deq.pop_back();
        }
        min_deq.push_back(i);

        // Maintain max deque: decreasing order
        while (!max_deq.empty() && a[i] >= a[max_deq.back()]) {
            max_deq.pop_back();
        }
        max_deq.push_back(i);

        // Remove out of window indices
        if (i >= m - 1) {
            while (min_deq.front() < i - m + 1) {
                min_deq.pop_front();
            }
            while (max_deq.front() < i - m + 1) {
                max_deq.pop_front();
            }
            min_result = min(min_result, (long long)a[max_deq.front()] - (long long)a[min_deq.front()]);
        }
    }

    cout << min_result << endl;
}