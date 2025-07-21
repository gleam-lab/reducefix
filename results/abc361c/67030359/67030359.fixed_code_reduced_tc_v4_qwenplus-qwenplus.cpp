#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to remove K elements such that the resulting sequence has
    // the minimum possible difference between max and min.
    // Since we must keep (N-K) elements in original order, we consider:
    // For each possible window of size (N-K), check the min and max in that window.
    // The optimal answer is the minimal (max - min) among all these windows.

    deque<int> min_deq, max_deq;
    int res = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain deque for min and max in sliding window of size W = (N-K)
        while (!min_deq.empty() && A[i] <= A[min_deq.back()]) min_deq.pop_back();
        while (!max_deq.empty() && A[i] >= A[max_deq.back()]) max_deq.pop_back();
        min_deq.push_back(i);
        max_deq.push_back(i);

        // Remove out-of-window indices
        if (min_deq.front() <= i - (N - K)) min_deq.pop_front();
        if (max_deq.front() <= i - (N - K)) max_deq.pop_front();

        // Start computing results once window is valid
        if (i >= (N - K) - 1) {
            res = min(res, A[max_deq.front()] - A[min_deq.front()]);
        }
    }

    cout << res << '\n';
}