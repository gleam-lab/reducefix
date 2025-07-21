#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ll long long

struct Node {
    int idx, val;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (K == 0) {
        cout << *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end());
        return 0;
    }

    // We can remove up to K elements, so we must keep at least (N-K) elements
    // Try all possible windows of (N-K) consecutive elements and compute min and max in each window
    // To do this efficiently, use two monotonic deques for sliding window min and max

    int window_size = N - K;
    deque<int> min_deq, max_deq;
    int min_result = numeric_limits<int>::max();
    int max_result = numeric_limits<int>::min();

    auto add = [&](int i) {
        while (!min_deq.empty() && A[i] <= A[min_deq.back()])
            min_deq.pop_back();
        min_deq.push_back(i);
        while (!max_deq.empty() && A[i] >= A[max_deq.back()])
            max_deq.pop_back();
        max_deq.push_back(i);
    };

    auto remove = [&](int i) {
        if (!min_deq.empty() && min_deq.front() == i)
            min_deq.pop_front();
        if (!max_deq.empty() && max_deq.front() == i)
            max_deq.pop_front();
    };

    for (int i = 0; i < N; ++i) {
        add(i);
        if (i >= window_size - 1) {
            min_result = min(min_result, A[min_deq.front()]);
            max_result = max(max_result, A[max_deq.front()]);
            remove(i - window_size + 1);
        }
    }

    cout << max_result - min_result << endl;
    return 0;
}