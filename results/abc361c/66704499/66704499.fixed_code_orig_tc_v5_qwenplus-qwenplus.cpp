#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will consider all windows of size (N - K) and find min(max - min)
    int window_size = N - K;
    deque<int> max_deque, min_deque;
    long long result = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain deque for max values
        while (!max_deque.empty() && A[i] > A[max_deque.back()])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Maintain deque for min values
        while (!min_deque.empty() && A[i] < A[min_deque.back()])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Remove elements out of window [i-window_size+1, i]
        if (i >= window_size - 1) {
            while (!max_deque.empty() && max_deque.front() <= i - window_size)
                max_deque.pop_front();
            while (!min_deque.empty() && min_deque.front() <= i - window_size)
                min_deque.pop_front();

            result = min(result, (long long)(A[max_deque.front()] - A[min_deque.front()]));
        }
    }

    cout << result << endl;
    return 0;
}