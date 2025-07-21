#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

struct Node {
    int val, idx;
};

struct Compare {
    bool operator()(Node &a, Node &b) {
        return a.val > b.val || (a.val == b.val && a.idx < b.idx);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N), B(N);
        priority_queue<Node, vector<Node>, Compare> pq;
        vector<int> prefix_sum(B.size(), 0);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
            prefix_sum[i] = (i ? prefix_sum[i - 1] : 0) + B[i];
        }

        for (int i = 0; i < K; ++i) {
            pq.push({A[i], i});
        }

        int ans = LLONG_MAX;
        int current_max = pq.top().val;
        int current_sum = prefix_sum[K - 1];

        for (int i = K; i < N; ++i) {
            pq.push({A[i], i});
            current_max = max(current_max, pq.top().val);
            current_sum = prefix_sum[i] - prefix_sum[i - K] + B[i - K];
            ans = min(ans, current_max * current_sum);
        }

        for (int i = 0; i < K; ++i) {
            pq.pop();
        }

        while (!pq.empty()) {
            pq.pop();
        }

        for (int i = 0; i < K; ++i) {
            pq.push({A[i], i});
        }

        current_max = pq.top().val;
        current_sum = prefix_sum[K - 1];

        for (int i = K; i < N; ++i) {
            pq.push({A[i], i});
            current_max = max(current_max, pq.top().val);
            current_sum = prefix_sum[i] - prefix_sum[i - K] + B[i - K];
            ans = min(ans, current_max * current_sum);
        }

        cout << ans << '\n';
    }

    return 0;
}