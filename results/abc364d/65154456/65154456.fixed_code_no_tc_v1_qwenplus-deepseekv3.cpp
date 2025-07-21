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
        ll b, k;
        cin >> b >> k;
        k--; // convert to 0-based index
        
        // Binary search for the k-th closest distance
        ll left = 0, right = 2e14;
        ll answer = 0;
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count the number of elements <= b + mid
            ll upper = b + mid;
            auto it_upper = upper_bound(a.begin(), a.end(), upper);
            ll cnt_upper = it_upper - a.begin();
            
            // Count the number of elements < b - mid
            ll lower = b - mid;
            auto it_lower = lower_bound(a.begin(), a.end(), lower);
            ll cnt_lower = it_lower - a.begin();
            
            // Total elements in [b - mid, b + mid]
            ll total = cnt_upper - cnt_lower;
            
            if (total <= k) {
                left = mid + 1;
            } else {
                answer = mid;
                right = mid - 1;
            }
        }
        
        // Now find the exact k-th distance
        vector<ll> distances;
        for (int i = 0; i < N; ++i) {
            distances.push_back(abs(a[i] - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k] << '\n';
    }
    
    return 0;
}