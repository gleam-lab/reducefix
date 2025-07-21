#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ll total = accumulate(all(A), 0LL);
    ll remaining = K - total;
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0;
        ll high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = A[i] + mid;
            int pos = upper_bound(all(sorted_A), new_vote) - sorted_A.begin();
            if (idx < pos) pos--;
            int higher = N - pos;
            if (higher < M) {
                best = mid;
                high = mid - 1;
            } else {
                int needed_pos = N - M;
                ll min_required = sorted_A[needed_pos];
                if (new_vote <= min_required) {
                    ll sum_needed = 0;
                    if (needed_pos < N - 1) {
                        sum_needed = (new_vote + 1) * (N - 1 - needed_pos) - (prefix[N] - prefix[needed_pos + 1]);
                    }
                    if (sum_needed <= remaining - mid) {
                        best = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    ll sum_needed = 0;
                    if (needed_pos < idx) {
                        sum_needed = (new_vote + 1) * (needed_pos + 1 - (idx + 1)) - (prefix[needed_pos + 1] - prefix[idx + 1]);
                    }
                    sum_needed += max(0LL, (new_vote - sorted_A[idx]));
                    if (sum_needed <= remaining - mid) {
                        best = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        ans[i] = best;
    }
    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            ll new_vote = A[i] + remaining;
            int pos = upper_bound(all(sorted_A), new_vote) - sorted_A.begin();
            if (N - pos < M) {
                ans[i] = remaining;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            int pos = upper_bound(all(sorted_A), A[i]) - sorted_A.begin();
            if (N - pos < M) {
                ans[i] = 0;
            }
        }
    }
    for (ll &x : ans) {
        if (x == -1) {
            cout << -1 << ' ';
        } else {
            cout << x << ' ';
        }
    }
    cout << endl;
    return 0;
}