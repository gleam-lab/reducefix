#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int windowSize = n - k;
    if (windowSize == 0) {
        cout << 0 << endl;
        return 0;
    }

    deque<int> maxDq;
    deque<int> minDq;
    int result = INT_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain deque for maximums
        while (!maxDq.empty() && A[maxDq.back()] <= A[i]) {
            maxDq.pop_back();
        }
        maxDq.push_back(i);

        // Maintain deque for minimums
        while (!minDq.empty() && A[minDq.back()] >= A[i]) {
            minDq.pop_back();
        }
        minDq.push_back(i);

        // Remove elements out of the current window
        while (!maxDq.empty() && maxDq.front() <= i - windowSize) {
            maxDq.pop_front();
        }
        while (!minDq.empty() && minDq.front() <= i - windowSize) {
            minDq.pop_front();
        }

        // Once the window is full, update result
        if (i >= windowSize - 1) {
            result = min(result, A[maxDq.front()] - A[minDq.front()]);
        }
    }

    cout << result << endl;
    return 0;
}