#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search to find the closest point in O(log N)
        auto it = lower_bound(A.begin(), A.end(), b);
        vector<ll> candidates;

        // Use two pointers to collect up to k nearest elements
        int left = it - A.begin() - 1;
        int right = it - A.begin();
        vector<ll> distances;

        while (distances.size() < (size_t)k && (left >= 0 || right < N)) {
            if (left < 0) {
                distances.push_back(abs(A[right++] - b));
            } else if (right >= N) {
                distances.push_back(abs(A[left--] - b));
            } else {
                ll d_left = abs(A[left] - b);
                ll d_right = abs(A[right] - b);
                if (d_left <= d_right) {
                    distances.push_back(d_left);
                    --left;
                } else {
                    distances.push_back(d_right);
                    ++right;
                }
            }
        }

        // The distances are already collected in order of proximity
        // The k-th smallest is at index k-1 after sorting
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}