#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    vector<ll> b(Q), k(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    for (int j = 0; j < Q; ++j) {
        ll bj = b[j];
        ll kj = k[j];
        
        // Binary search to find the smallest distance 'd' such that there are at least 'kj' elements <= d
        ll left = 0;
        ll right = 2e14; // Sufficiently large upper bound
        
        while (left < right) {
            ll mid = left + (right - left) / 2;
            
            // Count the number of elements in 'a' with |a_i - bj| <= mid
            auto it_lower = lower_bound(a.begin(), a.end(), bj - mid);
            auto it_upper = upper_bound(a.begin(), a.end(), bj + mid);
            ll count = it_upper - it_lower;
            
            if (count >= kj) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << endl;
    }
    
    return 0;
}