#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        
        int left = 0, right = N - 1;
        // Binary search to find the k-th closest distance
        auto check = [&](ll mid) {
            // Number of elements in a with |a_i - b| <= mid
            ll cnt = upper_bound(a.begin(), a.end(), b + mid) - lower_bound(a.begin(), a.end(), b - mid);
            return cnt >= k;
        };
        
        ll low = 0, high = 2e14;
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (check(mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }
    
    return 0;
}