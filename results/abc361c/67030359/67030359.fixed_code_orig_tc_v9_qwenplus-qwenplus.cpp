#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int L = N - K;
    deque<int> max_deque, min_deque;
    long long ans = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain max_deque for current window
        while (!max_deque.empty() && A[max_deque.back()] <= A[i])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Maintain min_deque for current window
        while (!min_deque.empty() && A[min_deque.back()] >= A[i])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Remove elements out of the window
        if (i >= L - 1) {
            while (!max_deque.empty() && max_deque.front() <= i - L)
                max_deque.pop_front();
            while (!min_deque.empty() && min_deque.front() <= i - L)
                min_deque.pop_front();

            ans = min(ans, (long long)(A[max_deque.front()] - A[min_deque.front()]));
        }
    }

    cout << ans << endl;
    return 0;
}