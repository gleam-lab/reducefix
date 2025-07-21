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
    
    vector<ll> sorted_A = A;
    sort(all(sorted_A));
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = K;
        ll min_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            
            int pos = upper_bound(all(sorted_A), new_votes) - sorted_A.begin();
            int needed = N - M;
            if (pos > needed) {
                min_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (min_X != -1) {
            ll total_used = min_X;
            ll remaining = K - total_used;
            if (remaining >= 0) {
                ans[i] = min_X;
            } else {
                ans[i] = -1;
            }
        } else {
            ans[i] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            // Check if already elected
            int count = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > A[i]) {
                    count++;
                }
            }
            if (count < M) {
                ans[i] = 0;
            } else {
                ans[i] = -1;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}