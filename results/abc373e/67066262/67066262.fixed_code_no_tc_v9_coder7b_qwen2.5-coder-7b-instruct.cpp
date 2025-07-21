#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    vector<pair<ll, int>> sorted_a;
    for(int i = 0; i < n; ++i) {
        sorted_a.emplace_back(a[i], i);
    }
    sort(sorted_a.rbegin(), sorted_a.rend());
    
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + sorted_a[i].first;
    }
    
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll target = sorted_a[i].second;
        ll need = 0;
        
        // Calculate the minimum additional votes needed for candidate i to win
        for(int j = i + 1; j < n; ++j) {
            if(sorted_a[j].first > sorted_a[i].first) {
                need += max(0LL, sorted_a[j].first - sorted_a[i].first);
            }
        }
        
        // Check if we can achieve the needed votes within the remaining votes
        if(k >= need) {
            ans[target] = need;
        }
    }
    
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}