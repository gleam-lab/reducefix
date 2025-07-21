#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    // We need to remove exactly K elements so that the difference between max and min of remaining is minimized.
    // The key observation:
    // - For any chosen subset of N-K elements, the min and max will be among some pair in the full array.
    // - If we fix a window size of (N-K), then the problem reduces to sliding this window over the array,
    //   keeping track of min and max within each window.

    int window_size = n - k;
    int min_diff = INT_MAX;

    // To efficiently compute min and max in sliding window:
    // We'll use two deques
    deque<int> min_dq;
    deque<int> max_dq;

    for (int i = 0; i < n; ++i) {
        // Maintain min deque
        while (!min_dq.empty() && A[i] <= A[min_dq.back()])
            min_dq.pop_back();
        min_dq.push_back(i);

        // Maintain max deque
        while (!max_dq.empty() && A[i] >= A[max_dq.back()])
            max_dq.pop_back();
        max_dq.push_back(i);

        // Remove out of window indices
        if (min_dq.front() <= i - window_size)
            min_dq.pop_front();
        if (max_dq.front() <= i - window_size)
            max_dq.pop_front();

        // Once window is formed
        if (i >= window_size - 1) {
            min_diff = min(min_diff, A[max_dq.front()] - A[min_dq.front()]);
        }
    }

    cout << min_diff << endl;
    return 0;
}