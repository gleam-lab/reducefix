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
        ll low = 0, high = remaining + A[i];
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = A[i] + mid;
            auto it = upper_bound(all(sorted_A), new_vote);
            int pos = it - sorted_A.begin();
            int over = N - pos;
            
            if (over < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                ll required = 0;
                int start_pos = pos;
                int end_pos = pos + over - (M - 1);
                if (end_pos > N) end_pos = N;
                required = (prefix[end_pos] - prefix[start_pos]) - (new_vote + 1) * (end_pos - start_pos);
                required += (new_vote + 1) * (end_pos - start_pos) - (prefix[end_pos] - prefix[start_pos]);
                required = (prefix[end_pos] - prefix[start_pos]) - (new_vote + 1) * (end_pos - start_pos);
                required = (new_vote + 1) * (end_pos - start_pos) - (prefix[end_pos] - prefix[start_pos]);
                required = 0;
                int cnt = over - (M - 1);
                if (cnt > 0) {
                    int start = N - cnt;
                    required = (new_vote + 1) * cnt - (prefix[N] - prefix[start]);
                }
                if (required <= remaining - mid) {
                    best_X = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = best_X;
    }
    
    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            // Check if already elected
            ll current = A[i];
            auto it = upper_bound(all(sorted_A), current);
            int pos = it - sorted_A.begin();
            int over = N - pos;
            if (over < M) {
                ans[i] = 0;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        if (ans[i] > remaining) ans[i] = -1;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}