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
    // Sliding window over all windows of size (n - k)
    int window_size = n - k;
    deque<int> min_deque;
    deque<int> max_deque;
    int res = INT_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain min_deque: increasing order
        while (!min_deque.empty() && A[i] < A[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Maintain max_deque: decreasing order
        while (!max_deque.empty() && A[i] > A[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Remove elements out of window
        while (!min_deque.empty() && min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }
        while (!max_deque.empty() && max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }

        if (i >= window_size - 1) {
            res = min(res, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << res << endl;
}