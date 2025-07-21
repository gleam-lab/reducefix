#include <iostream>
#include <vector>
#include <algorithm>
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

    // We will use a sliding window approach to find the minimum difference
    // between max and min in all windows of size (n - K) in A

    deque<int> minDeque, maxDeque;
    int result = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        // Maintain deque for min and max in current window
        while (!minDeque.empty() && A[minDeque.back()] >= A[i]) minDeque.pop_back();
        while (!maxDeque.empty() && A[maxDeque.back()] <= A[i]) maxDeque.pop_back();
        
        minDeque.push_back(i);
        maxDeque.push_back(i);

        // Remove elements out of window
        while (!minDeque.empty() && minDeque.front() <= i - (n - K)) minDeque.pop_front();
        while (!maxDeque.empty() && maxDeque.front() <= i - (n - K)) maxDeque.pop_front();

        // When window size is reached, calculate difference
        if (i >= (n - K - 1)) {
            result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
        }
    }

    cout << result << endl;
}