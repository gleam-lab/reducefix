#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will try all possible windows of size (N - K)
    int window_size = N - K;
    
    // To efficiently compute min and max over sliding window, use two deques
    deque<int> max_deque, min_deque;
    ll ans = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain deque for maximum
        while (!max_deque.empty() && A[i] > A[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Maintain deque for minimum
        while (!min_deque.empty() && A[i] <= A[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Remove elements out of the current window
        if (i >= window_size) {
            if (max_deque.front() <= i - window_size) {
                max_deque.pop_front();
            }
            if (min_deque.front() <= i - window_size) {
                min_deque.pop_front();
            }
        }

        // Once window is full-sized, update answer
        if (i >= window_size - 1) {
            ans = min(ans, (ll)(A[max_deque.front()] - A[min_deque.front()]));
        }
    }

    cout << ans << endl;
    return 0;
}