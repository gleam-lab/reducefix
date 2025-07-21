#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
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

    // We will consider all possible windows of size (n - K)
    int window_size = n - k;
    int res = numeric_limits<int>::max();

    // To efficiently find min and max in sliding window, use deques
    deque<int> min_deq;
    deque<int> max_deq;

    auto remove_out_of_window = [&](int i) {
        if (!min_deq.empty() && min_deq[0] == i) min_deq.pop_front();
        if (!max_deq.empty() && max_deq[0] == i) max_deq.pop_front();
    };

    auto add_to_deques = [&](int i) {
        while (!min_deq.empty() && A[min_deq.back()] >= A[i]) min_deq.pop_back();
        while (!max_deq.empty() && A[max_deq.back()] <= A[i]) max_deq.pop_back();
        min_deq.push_back(i);
        max_deq.push_back(i);
    };

    // Initialize the first window
    for (int i = 0; i < window_size; ++i) {
        add_to_deques(i);
    }
    chmin(res, A[max_deq.front()] - A[min_deq.front()]);

    // Slide the window
    for (int i = window_size; i < n; ++i) {
        remove_out_of_window(i - window_size);
        add_to_deques(i);
        chmin(res, A[max_deq.front()] - A[min_deq.front()]);
    }

    cout << res << endl;
}