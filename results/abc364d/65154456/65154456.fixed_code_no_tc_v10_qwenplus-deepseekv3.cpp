#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b_j, k_j;
        cin >> b_j >> k_j;
        
        ll left = 0, right = 2e14; // Sufficiently large upper bound
        ll answer = 0;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            auto lower = lower_bound(a.begin(), a.end(), b_j - mid);
            auto upper = upper_bound(a.begin(), a.end(), b_j + mid);
            ll count = upper - lower;
            
            if (count >= k_j) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}