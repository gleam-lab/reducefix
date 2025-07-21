#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;
        priority_queue<pair<int, int>> pq; // Stores pair of (distance, index)
        
        for (int i = 0; i < N; ++i) {
            pq.push({abs(b - A[i]), i + 1});
        }

        for (int i = 0; i < k - 1; ++i) {
            pq.pop(); // We're only interested in the k-th closest
        }

        auto [dist, index] = pq.top();
        cout << dist << '\n';
    }

    return 0;
}