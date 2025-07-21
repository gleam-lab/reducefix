#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider all possible windows of size (n - K)
    // That is, the subsequence of N - K elements that remains after removing K
    // To minimize max - min in this window

    // Sliding window using a multiset to maintain current window elements
    multiset<int> window;
    for (int i = 0; i < n - k; ++i) {
        window.insert(A[i]);
    }

    int result = *window.rbegin() - *window.begin();

    for (int i = n - k; i < n; ++i) {
        // Remove the element going out of the window
        window.erase(window.find(A[i - (n - k)]));
        // Add the new element coming into the window
        window.insert(A[i]);
        // Update minimum difference
        int current_diff = *window.rbegin() - *window.begin();
        result = min(result, current_diff);
    }

    cout << result << endl;
    return 0;
}