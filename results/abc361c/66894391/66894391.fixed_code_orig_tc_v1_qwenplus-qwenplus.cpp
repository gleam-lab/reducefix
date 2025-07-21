#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int W = N - K;

    deque<int> max_deque;
    deque<int> min_deque;
    int min_diff = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain max_deque: elements are in decreasing order
        while (!max_deque.empty() && A[max_deque.back()] <= A[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Maintain min_deque: elements are in increasing order
        while (!min_deque.empty() && A[min_deque.back()] >= A[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Remove elements out of window
        while (!max_deque.empty() && max_deque.front() <= i - W) {
            max_deque.pop_front();
        }
        while (!min_deque.empty() && min_deque.front() <= i - W) {
            min_deque.pop_front();
        }

        // Update answer when window is valid
        if (i >= W - 1) {
            min_diff = min(min_diff, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << min_diff << endl;
}