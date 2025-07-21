#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int window_size = N - K;

    deque<int> min_deque;
    deque<int> max_deque;
    int result = INT_MAX;

    // Initialize first window
    for (int i = 0; i < window_size; ++i) {
        while (!min_deque.empty() && A[i] <= A[min_deque.back()]) {
            min_deque.pop_back();
        }
        while (!max_deque.empty() && A[i] >= A[max_deque.back()]) {
            max_deque.pop_back();
        }
        min_deque.push_back(i);
        max_deque.push_back(i);
    }

    result = A[max_deque.front()] - A[min_deque.front()];

    // Slide the window
    for (int i = window_size; i < N; ++i) {
        // Remove elements outside the window
        while (!min_deque.empty() && min_deque.front() <= i - window_size) {
            min_deque.pop_front();
        }
        while (!max_deque.empty() && max_deque.front() <= i - window_size) {
            max_deque.pop_front();
        }

        // Add current element to deques
        while (!min_deque.empty() && A[i] <= A[min_deque.back()]) {
            min_deque.pop_back();
        }
        while (!max_deque.empty() && A[i] >= A[max_deque.back()]) {
            max_deque.pop_back();
        }

        min_deque.push_back(i);
        max_deque.push_back(i);

        result = min(result, A[max_deque.front()] - A[min_deque.front()]);
    }

    cout << result << endl;
}