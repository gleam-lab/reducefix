#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = n - k;
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Create a sliding window minimum and maximum structure
    deque<int> min_deq, max_deq;
    auto add = [&](int i) {
        while (!min_deq.empty() && a[min_deq.back()] >= a[i]) min_deq.pop_back();
        min_deq.push_back(i);
        while (!max_deq.empty() && a[max_deq.back()] <= a[i]) max_deq.pop_back();
        max_deq.push_back(i);
    };

    auto remove = [&](int i) {
        if (!min_deq.empty() && min_deq.front() == i) min_deq.pop_front();
        if (!max_deq.empty() && max_deq.front() == i) max_deq.pop_front();
    };

    long long min_diff = numeric_limits<long long>::max();

    for (int i = 0; i < n; ++i) {
        add(i);
        if (i >= m - 1) {
            min_diff = min(min_diff, (long long)a[max_deq.front()] - (long long)a[min_deq.front()]);
            remove(i - (m - 1));
        }
    }

    cout << min_diff << endl;
    return 0;
}