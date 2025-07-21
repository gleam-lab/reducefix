#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T>
void output(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll rem = K - total;

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return A[i] < A[j]; });

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        int orig_idx = idx[i];
        ll a_i = sorted_A[i];

        // Binary search on the number of votes to add
        ll low = 0, high = rem;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_score = a_i + mid;

            // Find how many candidates have strictly more votes than new_score
            int cnt_more = N - (upper_bound(sorted_A.begin(), sorted_A.end(), new_score) - sorted_A.begin());

            if (cnt_more < M) {
                ans = mid;
                high = mid - 1;
            } else {
                // Need to make sure candidate i is among top M candidates
                // We need to find how many candidates have score >= new_score
                int cnt_ge = N - (lower_bound(sorted_A.begin(), sorted_A.end(), new_score) - sorted_A.begin());
                if (cnt_ge <= M) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        res[orig_idx] = (ans == -1 ? -1 : ans);
    }

    output(res);
}