#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Find the k-th smallest distance from B_j to any A_i
        // We will use binary search on the answer (distance)
        ll left = 0;
        ll right = 2e8 + 10;
        
        while (left < right) {
            ll mid = (left + right) / 2;
            
            // Count how many points A_i are within distance 'mid' from b
            ll low_bound = b - mid;
            ll high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            int count = it2 - it1;
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}