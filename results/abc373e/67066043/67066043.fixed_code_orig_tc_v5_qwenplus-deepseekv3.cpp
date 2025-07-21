#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return A[i] > A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        int original_pos = ord[i];
        ll current_votes = sorted_A[i];
        ll low = 0, high = K;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<ll>()) - sorted_A.begin();
            if (pos <= M - 1) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1) {
            ll total_needed = 0;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), current_votes + best, greater<ll>()) - sorted_A.begin();
            if (pos < M) {
                total_needed = best;
            } else {
                ll sum = prefix[pos] - prefix[M - 1];
                ll required = (current_votes + best) * (pos - (M - 1)) - sum;
                total_needed = best + max(0LL, required - (K - best));
            }
            if (total_needed <= K) {
                ans[original_pos] = best;
            }
        } else {
            ans[original_pos] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            ll current_votes = A[i];
            int pos_in_sorted = lower_bound(sorted_A.begin(), sorted_A.end(), current_votes, greater<ll>()) - sorted_A.begin();
            if (pos_in_sorted < M) {
                ans[i] = 0;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}