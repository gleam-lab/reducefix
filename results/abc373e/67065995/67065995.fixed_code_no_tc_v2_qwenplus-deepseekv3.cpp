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
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;
    
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sortedA = A;
    sort(all(sortedA));
    
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll best_X = remaining + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll current_votes = A[i] + mid;
            
            // Find the number of elements > current_votes
            auto it = upper_bound(all(sortedA), current_votes);
            int cnt_greater = sortedA.end() - it;
            
            if (A[i] + mid == current_votes) {
                // Need to adjust if current_votes equals some other candidate's votes
                auto it_eq = lower_bound(all(sortedA), current_votes);
                int cnt_eq = upper_bound(all(sortedA), current_votes) - it_eq;
                if (it_eq - sortedA.begin() <= idx && idx < it_eq - sortedA.begin() + cnt_eq) {
                    cnt_greater += cnt_eq - 1;
                } else {
                    cnt_greater += cnt_eq;
                }
            }
            
            if (cnt_greater < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best_X <= remaining) {
            ans[i] = best_X;
        } else {
            ans[i] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}