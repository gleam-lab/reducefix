#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to choose N - K elements in order and minimize (max - min)
    // This is equivalent to choosing a window of size (n - k) and finding the minimal (max - min)

    // Use sliding window with monotonic deque to track max and min efficiently
    deque<int> max_dq, min_dq;
    int res = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain max deque (decreasing)
        while (!max_dq.empty() && A[max_dq.back()] <= A[i]) max_dq.pop_back();
        max_dq.push_back(i);

        // Maintain min deque (increasing)
        while (!min_dq.empty() && A[min_dq.back()] >= A[i]) min_dq.pop_back();
        min_dq.push_back(i);

        // Remove elements out of window [i - window_size + 1, i]
        int window_size = n - k;
        if (i >= window_size - 1) {
            while (max_dq.front() < i - window_size + 1) max_dq.pop_front();
            while (min_dq.front() < i - window_size + 1) min_dq.pop_front();
            res = min(res, A[max_dq.front()] - A[min_dq.front()]);
        }
    }

    cout << res << endl;
}