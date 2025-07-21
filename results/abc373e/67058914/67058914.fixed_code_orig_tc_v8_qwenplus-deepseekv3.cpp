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
    
    vector<ll> B = A;
    sort(B.begin(), B.end());
    
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i+1] = prefix[i] + B[i];
    }
    
    ll remaining = K;
    for (ll a : A) {
        remaining -= a;
    }
    
    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll ans = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = A[i] + mid;
            
            int pos = upper_bound(B.begin(), B.end(), new_val) - B.begin();
            int cnt = N - pos;
            
            if (cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (ans != -1) {
            ll new_val = A[i] + ans;
            int pos = upper_bound(B.begin(), B.end(), new_val) - B.begin();
            
            ll sum_need = 0;
            int needed = M - (N - pos) - 1;
            if (needed > 0) {
                int left = pos - 1;
                int right = left - needed + 1;
                if (right >= 0) {
                    sum_need = new_val * needed - (prefix[left+1] - prefix[right]);
                }
            }
            
            if (sum_need <= remaining - ans) {
                res[i] = ans;
            } else {
                res[i] = -1;
            }
        } else {
            res[i] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << (i+1 < N ? " " : "\n");
    }
    
    return 0;
}