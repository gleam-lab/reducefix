#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return A[i] > A[j];
    });

    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[idx[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> res(N, -1);
    ll remaining = K - prefix[N];

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = sorted_A[i] + mid;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_vote, greater<ll>());
            int pos = it - sorted_A.begin();
            
            if (pos < M) {
                best = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                if (pos > M) {
                    needed = new_vote * (pos - M) - (prefix[pos] - prefix[M]);
                }
                if (needed <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        res[idx[i]] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}