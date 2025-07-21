#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Number of elements to keep
    int m = n - k;

    // Sliding window approach
    // We need to find the minimum possible (max - min) among all windows of size m
    deque<int> min_deque, max_deque;
    int min_diff = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain min_deque
        while (!min_deque.empty() && a[i] <= a[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Maintain max_deque
        while (!max_deque.empty() && a[i] >= a[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove elements out of window
        while (!min_deque.empty() && min_deque.front() <= i - m) {
            min_deque.pop_front();
        }
        while (!max_deque.empty() && max_deque.front() <= i - m) {
            max_deque.pop_front();
        }

        // Calculate if we have a valid window
        if (i >= m - 1) {
            min_diff = min(min_diff, a[max_deque.front()] - a[min_deque.front()]);
        }
    }

    cout << min_diff << endl;
}