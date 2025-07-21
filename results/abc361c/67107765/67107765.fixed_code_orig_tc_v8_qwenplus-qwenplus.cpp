#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to choose N-K elements to keep in order, minimizing max - min of that subsequence
    // Sliding window over all possible windows of size L = N - K
    int L = n - k;
    vector<int> window_min, window_max;
    deque<int> min_deque, max_deque;
    ll res = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain min deque (increasing)
        while (!min_deque.empty() && A[i] <= A[min_deque.back()])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Maintain max deque (decreasing)
        while (!max_deque.empty() && A[i] >= A[max_deque.back()])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Remove out of window indices
        if (i >= L - 1) {
            while (min_deque.front() <= i - L)
                min_deque.pop_front();
            while (max_deque.front() <= i - L)
                max_deque.pop_front();

            res = min(res, 1LL * (A[max_deque.front()] - A[min_deque.front()]));
        }
    }

    cout << res << endl;
}