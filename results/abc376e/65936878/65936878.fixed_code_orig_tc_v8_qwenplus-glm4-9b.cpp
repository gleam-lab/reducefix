#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 5;
int T, N, K;
vector<int> A, B;

struct MinHeap {
    priority_queue<int, vector<int>, greater<int>> pq;
    int val[MAXN];

    void push(int x) {
        if (pq.size() < N - K) {
            pq.push(x);
            val[pq.size()] = x;
        } else if (x > pq.top()) {
            pq.pop();
            pq.push(x);
            val[pq.size()] = x;
        }
    }

    int getMax() {
        // Find the maximum value in the top N-K elements
        int ind = upper_bound(val + 1, val + N - K + 1, pq.top()) - val;
        return val[ind];
    }
};

int solve() {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    MinHeap heap;
    int ans = LLONG_MAX;

    for (int i = 0; i < N; ++i) {
        heap.push(B[i]);
        if (i >= K) {
            ans = min(ans, heap.getMax() * A[i]);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> K;
        A.resize(N), B.resize(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];
        cout << solve() << '\n';
    }

    return 0;
}