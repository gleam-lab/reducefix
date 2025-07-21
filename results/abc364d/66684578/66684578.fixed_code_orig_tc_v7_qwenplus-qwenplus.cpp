#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort A for binary searching later
    sort(A.begin(), A.end());

    while (Q--) {
        long long b;
        int k;
        cin >> b >> k;

        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();

        int left = pos - 1;
        int right = pos;

        multiset<long long> dists;

        // Collect k nearest distances
        while ((int)dists.size() < k) {
            if (left < 0) {
                // Only move right
                dists.insert(abs(A[right++] - b));
            } else if (right >= N) {
                // Only move left
                dists.insert(abs(A[left--] - b));
            } else {
                long long d_left = abs(A[left] - b);
                long long d_right = abs(A[right] - b);

                if (d_left <= d_right) {
                    dists.insert(d_left);
                    --left;
                } else {
                    dists.insert(d_right);
                    ++right;
                }
            }
        }

        // The k-th smallest distance is the largest in the set (since it's a min-k structure)
        cout << *prev(dists.end()) << "\n";
    }

    return 0;
}