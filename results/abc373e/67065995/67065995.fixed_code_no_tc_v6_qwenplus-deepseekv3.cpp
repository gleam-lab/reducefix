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
    ll sum_A = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }
    ll remaining = K - sum_A;

    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = sorted_A[i] + prefix[i];
    }

    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0;
        ll high = remaining + A[i];
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = A[i] + mid;
            int pos = upper_bound(all(sorted_A), new_vote) - sorted_A.begin();
            int needed = N - M;
            if (pos > needed) {
                ll total = prefix[pos] - prefix[needed] - (ll)(new_vote + 1) * (pos - needed);
                if (total + mid <= remaining) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                best = mid;
                high = mid - 1;
            }
        }
        if (best != -1 && best <= remaining) {
            ans[i] = best;
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            // Check if already elected
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > A[i]) {
                    cnt++;
                }
            }
            if (cnt < M) {
                ans[i] = 0;
            }
        }
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}