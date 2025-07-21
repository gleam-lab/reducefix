#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
const int INF = 1001001001;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // We will consider all possible intervals of length n - k in the array
    // and compute max(B) - min(B) for each such interval.
    // The minimum among these values is our answer.

    // Use sliding window with deque to maintain min and max efficiently
    deque<int> min_deq, max_deq;
    int res = INF;

    auto clearIf = [&](deque<int>& dq, int i) {
        while (!dq.empty() && dq.front() < i)
            dq.pop_front();
    };

    auto add = [&](deque<int>& dq, int val, function<bool(int, int)> comp) {
        while (!dq.empty() && comp(val, dq.back()))
            dq.pop_back();
        dq.push_back(val);
    };

    for (int i = 0; i < n; i++) {
        // Add current element to deques
        add(min_deq, A[i], [](int a, int b) { return a <= b; });
        add(max_deq, A[i], [](int a, int b) { return a >= b; });

        // Remove elements outside the window [left, i]
        int left = i - (n - k) + 1;
        if (left > 0) {
            clearIf(min_deq, left);
            clearIf(max_deq, left);
        }

        // When window is full, update result
        if (i >= n - k - 1) {
            res = min(res, max_deq.front() - min_deq.front());
        }
    }

    cout << res << endl;
}