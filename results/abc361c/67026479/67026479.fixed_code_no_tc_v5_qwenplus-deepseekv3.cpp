#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int window_size = N - K;
    if (window_size == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    deque<int> min_deque, max_deque;
    int min_diff = INT_MAX;
    
    for (int i = 0; i < N; ++i) {
        // Remove elements not in the current window from the front
        while (!min_deque.empty() && min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }
        while (!max_deque.empty() && max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }
        
        // Maintain the deque for minimum values
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);
        
        // Maintain the deque for maximum values
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);
        
        // Check if the window is of the required size
        if (i >= window_size - 1) {
            int current_diff = A[max_deque.front()] - A[min_deque.front()];
            min_diff = min(min_diff, current_diff);
        }
    }
    
    cout << min_diff << endl;
    return 0;
}