#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to choose N-K elements to keep in order, minimizing max(B) - min(B)
    // Try all sliding windows of size N-K and compute min and max in each window

    deque<int> min_deque, max_deque;
    int window_size = n - k;
    ll ans = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        // Maintain max_deque: elements are in decreasing order
        while (!max_deque.empty() && A[i] > A[max_deque.back()]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        // Maintain min_deque: elements are in increasing order
        while (!min_deque.empty() && A[i] < A[min_deque.back()]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        // Remove out of window indices
        if (i >= window_size) {
            while (!max_deque.empty() && max_deque.front() <= i - window_size) {
                max_deque.pop_front();
            }
            while (!min_deque.empty() && min_deque.front() <= i - window_size) {
                min_deque.pop_front();
            }
        }

        if (i >= window_size - 1) {
            chmin(ans, (ll)(A[max_deque.front()] - A[min_deque.front()]));
        }
    }

    cout << ans << endl;
}