#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b
ll query(ll b, int k) {
    // Find the insertion point of b in A
    int pos = lower_bound(A.begin(), A.end(), b) - A.begin();

    int left = pos - 1;
    int right = pos;

    // Use two pointers to find the k-th closest
    // We use a min-heap to keep track of distances we have considered
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    // Initialize with nearest elements around 'b'
    if (left >= 0) {
        pq.push({abs(A[left] - b), left});
    }
    if (right < A.size()) {
        pq.push({abs(A[right] - b), right});
    }

    // Mark visited indices
    vector<bool> visited(A.size(), false);
    if (left >= 0) visited[left] = true;
    if (right < A.size()) visited[right] = true;

    ll result = 0;
    for (int i = 0; i < k; ++i) {
        auto [dist, idx] = pq.top();
        pq.pop();
        result = dist;

        // Move left
        if (idx > 0 && !visited[idx - 1]) {
            visited[idx - 1] = true;
            pq.push({abs(A[idx - 1] - b), idx - 1});
        }
        // Move right
        if (idx < A.size() - 1 && !visited[idx + 1]) {
            visited[idx + 1] = true;
            pq.push({abs(A[idx + 1] - b), idx + 1});
        }
    }

    return result;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        cout << query(b, k) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}