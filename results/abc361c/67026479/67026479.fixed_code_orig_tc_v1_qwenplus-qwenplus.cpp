#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = n - k;
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Precompute min and max in sliding windows of size m
    deque<int> minQ, maxQ;
    long long minDiff = numeric_limits<long long>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain min queue
        while (!minQ.empty() && a[i] <= a[minQ.back()])
            minQ.pop_back();
        minQ.push_back(i);

        // Maintain max queue
        while (!maxQ.empty() && a[i] >= a[maxQ.back()])
            maxQ.pop_back();
        maxQ.push_back(i);

        // Remove elements out of window
        while (!minQ.empty() && minQ.front() <= i - m)
            minQ.pop_front();
        while (!maxQ.empty() && maxQ.front() <= i - m)
            maxQ.pop_front();

        // Update answer once window is valid
        if (i >= m - 1) {
            minDiff = min(minDiff, 1LL * a[maxQ.front()] - a[minQ.front()]);
        }
    }

    cout << minDiff << endl;
}