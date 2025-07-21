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

    // We need to choose N-K elements in order and minimize (max - min)
    // Since N is up to 2e5, we need an O(N log N) solution or better

    // Sliding window approach: For every window of size L = N-K, compute max and min
    // Use monotonic deque to maintain sliding window max and min in O(N)

    int L = n - k;
    vector<int> min_window, max_window;
    deque<int> min_dq, max_dq;

    // Initialize first window
    for (int i = 0; i < L; ++i) {
        while (!min_dq.empty() && A[i] <= A[min_dq.back()]) min_dq.pop_back();
        while (!max_dq.empty() && A[i] >= A[max_dq.back()]) max_dq.pop_back();
        min_dq.push_back(i);
        max_dq.push_back(i);
    }

    int res = A[max_dq.front()] - A[min_dq.front()];

    // Slide the window
    for (int i = L; i < n; ++i) {
        // Remove elements out of window
        if (min_dq.front() == i - L) min_dq.pop_front();
        if (max_dq.front() == i - L) max_dq.pop_front();

        // Add new element
        while (!min_dq.empty() && A[i] <= A[min_dq.back()]) min_dq.pop_back();
        while (!max_dq.empty() && A[i] >= A[max_dq.back()]) max_dq.pop_back();
        min_dq.push_back(i);
        max_dq.push_back(i);

        // Update result
        res = min(res, A[max_dq.front()] - A[min_dq.front()]);
    }

    cout << res << endl;
}