#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // We remove K elements, so we maintain a window of size N-K.
    // We start with a deque that will store indices of the elements.
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        // Remove indices from the deque that are out of this window.
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Maintain deque such that the values at the back are in decreasing order.
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add current element index.
        dq.push_back(i);

        // Once we've filled our window, we start processing.
        if (i >= k - 1) {
            // The element with the smallest value in the current window has the index at the front of the deque.
            // The element with the largest value in the current window is at the back of the deque, but
            // one index back because we look from the smallest to the largest.
            cout << nums[dq.front()] - nums[(dq.back() - 1) / 2] << endl;
        }
    }

    return 0;
}