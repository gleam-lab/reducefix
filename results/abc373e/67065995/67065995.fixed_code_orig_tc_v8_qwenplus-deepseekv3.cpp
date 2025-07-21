#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll total_votes = accumulate(all(a), 0LL);
    ll remaining = k - total_votes;
    
    vector<ll> sorted_a = a;
    sort(all(sorted_a), greater<ll>());
    
    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }
    
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        ll current = a[i];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            
            // Find the number of candidates with votes > new_votes
            auto it = upper_bound(all(sorted_a), new_votes, greater<ll>());
            int cnt = it - sorted_a.begin();
            
            if (cnt < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = best;
    }
    
    for (int i = 0; i < n; i++) {
        cout << (ans[i] == -1 ? -1 : max(0LL, ans[i])) << ' ';
    }
    cout << '\n';
    return 0;
}