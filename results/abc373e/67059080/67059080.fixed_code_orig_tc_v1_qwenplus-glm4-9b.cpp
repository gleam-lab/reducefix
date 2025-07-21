#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
  ll val;
  int idx;
};

int main() {
    cin >> N >> M >> K;
    vector<Node> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].val;
        a[i].idx = i + 1; // Use 1-based indexing for output
    }

    sort(a.begin(), a.end(), [](const Node &A, const Node &B) {
        return A.val < B.val;
    });

    vector<ll> pre(N);
    pre[0] = 0;
    for (int i = 1; i < N; ++i) {
        pre[i] = pre[i - 1] + a[i - 1].val;
    }

    for (int i = 0; i < N; ++i) {
        Node &current = a[i];
        ll remaining_votes = K - pre[N - 1];
        ll votes_needed = current.val + remaining_votes;
        int idx = upper_bound(a.begin(), a.begin() + i + 1, Node{votes_needed, 0}) - a.begin();
        if (idx >= M) {
            cout << 0 << " ";
        } else {
            cout << -1 << " ";
        }
    }

    return 0;
}