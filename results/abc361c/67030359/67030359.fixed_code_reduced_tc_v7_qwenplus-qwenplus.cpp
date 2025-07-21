#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will consider the minimum value of (max - min) in a subsequence of size N-K
    // Since we're allowed to remove K elements, we're effectively choosing a window of N-K elements

    // To minimize max - min over all possible windows of size L = N-K
    const int L = N - K;

    // We use a sliding window approach with two deques to maintain min and max in O(1) per step
    deque<int> min_deq, max_deq;
    auto add = [&](int x) {
        while (!min_deq.empty() && min_deq.back() > x)
            min_deq.pop_back();
        min_deq.push_back(x);
        while (!max_deq.empty() && max_deq.back() < x)
            max_deq.pop_back();
        max_deq.push_back(x);
    };
    auto remove = [&](int x) {
        if (!min_deq.empty() && min_deq.front() == x)
            min_deq.pop_front();
        if (!max_deq.empty() && max_deq.front() == x)
            max_deq.pop_front();
    };

    int res = numeric_limits<int>::max();
    for (int i = 0; i < N; ++i) {
        if (i >= L) {
            res = min(res, max_deq.front() - min_deq.front());
            remove(A[i - L]);
        }
        add(A[i]);
    }
    res = min(res, max_deq.front() - min_deq.front());

    cout << res << "\n";
    return 0;
}