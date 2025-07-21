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

    // We will use a sliding window of size (n - k)
    int window_size = n - k;
    int min_diff = numeric_limits<int>::max();

    // To efficiently get min and max in the window, use two deques
    deque<int> max_deq;
    deque<int> min_deq;

    for (int i = 0; i < n; ++i) {
        // Maintain deque for max
        while (!max_deq.empty() && A[max_deq.back()] <= A[i]) {
            max_deq.pop_back();
        }
        max_deq.push_back(i);

        // Maintain deque for min
        while (!min_deq.empty() && A[min_deq.back()] >= A[i]) {
            min_deq.pop_back();
        }
        min_deq.push_back(i);

        // Remove elements out of window
        if (max_deq.front() <= i - window_size) {
            max_deq.pop_front();
        }
        if (min_deq.front() <= i - window_size) {
            min_deq.pop_front();
        }

        // When window is filled, calculate difference
        if (i >= window_size - 1) {
            chmin(min_diff, A[max_deq.front()] - A[min_deq.front()]);
        }
    }

    cout << min_diff << endl;
}