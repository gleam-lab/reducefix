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

    // We will use a sliding window approach
    // The idea is to find the minimum possible (max - min) over all subsequences of length n-k

    // Since we are allowed to remove K elements, we want to find a contiguous subsequence of length N-K
    // that has the minimal difference between its maximum and minimum values.

    // To do this efficiently, we slide a window of size n-k over the array and maintain
    // both minimum and maximum values in the window using two deques:
    // - One deque for max (decreasing order)
    // - One deque for min (increasing order)

    int window_size = n - k;
    vector<int> min_deque, max_deque;
    long long res = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain min deque: keep elements in increasing order
        while (!min_deque.empty() && A[i] <= A[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Maintain max deque: keep elements in decreasing order
        while (!max_deque.empty() && A[i] >= A[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove out-of-window elements from both deques
        if (min_deque[0] <= i - window_size) {
            min_deque.erase(min_deque.begin());
        }
        if (max_deque[0] <= i - window_size) {
            max_deque.erase(max_deque.begin());
        }

        // Once the window is full, update result
        if (i >= window_size - 1) {
            res = min(res, 1LL * A[max_deque[0]] - A[min_deque[0]]);
        }
    }

    cout << res << endl;
}