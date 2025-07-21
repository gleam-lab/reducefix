#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int windowSize = n - k;
    deque<int> minDeque, maxDeque;
    int result = INT_MAX;

    // Initialize first window
    for (int i = 0; i < windowSize; ++i) {
        while (!minDeque.empty() && A[i] <= A[minDeque.back()])
            minDeque.pop_back();
        while (!maxDeque.empty() && A[i] >= A[maxDeque.back()])
            maxDeque.pop_back();
        minDeque.push_back(i);
        maxDeque.push_back(i);
    }

    result = A[maxDeque.front()] - A[minDeque.front()];

    // Slide the window
    for (int i = windowSize; i < n; ++i) {
        // Remove elements outside the window
        while (!minDeque.empty() && minDeque.front() <= i - windowSize)
            minDeque.pop_front();
        while (!maxDeque.empty() && maxDeque.front() <= i - windowSize)
            maxDeque.pop_front();

        // Add current element to deques
        while (!minDeque.empty() && A[i] <= A[minDeque.back()])
            minDeque.pop_back();
        while (!maxDeque.empty() && A[i] >= A[maxDeque.back()])
            maxDeque.pop_back();
        
        minDeque.push_back(i);
        maxDeque.push_back(i);

        result = min(result, A[maxDeque.front()] - A[minDeque.front()]);
    }

    cout << result << endl;
    return 0;
}