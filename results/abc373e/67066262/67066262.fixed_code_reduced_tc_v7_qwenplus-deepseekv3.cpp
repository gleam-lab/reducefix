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
    
    vector<ll> sortedA = A;
    sort(all(sortedA));
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = K - (prefix[N] - prefix[0]);
        ll minX = -1;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll total = current + mid;
            
            // Find the number of candidates with votes > total
            auto it = upper_bound(all(sortedA), total);
            ll cnt = sortedA.end() - it;
            
            if (A[i] + mid > total) {
                cnt--;
            }
            
            if (cnt < M) {
                minX = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (minX != -1) {
            ans[i] = minX;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}