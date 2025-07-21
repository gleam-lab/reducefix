#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        int b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        vector<int> distances;
        priority_queue<pair<int, int>> max_heap;

        auto it = lower_bound(A.begin(), A.end(), b);
        int idx = it - A.begin();

        int l = idx - 1, r = idx;
        for (int i = 0; i < k; ++i) {
            if (l >= 0 && r < N) {
                if (abs(A[l] - b) <= abs(A[r] - b)) {
                    max_heap.push({abs(A[l] - b), l});
                    --l;
                } else {
                    max_heap.push({abs(A[r] - b), r});
                    ++r;
                }
            } else if (l >= 0) {
                max_heap.push({abs(A[l] - b), l});
                --l;
            } else if (r < N) {
                max_heap.push({abs(A[r] - b), r});
                ++r;
            }
        }

        cout << max_heap.top().first << '\n';
    }

    return 0;
}