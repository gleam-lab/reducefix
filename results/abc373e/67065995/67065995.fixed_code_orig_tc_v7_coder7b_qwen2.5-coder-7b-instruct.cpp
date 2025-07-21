#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll, int>> candidates;

bool can_win(int idx, ll x, int M) {
    // Calculate the total votes needed to surpass the M-th candidate
    ll needed = candidates[M].first + x + 1;
    
    // Sum up votes for all candidates except the current one
    ll sum = 0;
    for (int i = 0; i < candidates.size(); ++i) {
        if (i != idx) {
            sum += candidates[i].first;
        }
    }
    
    return sum < needed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Store candidates' votes and their original indices
    for (int i = 0; i < n; ++i) {
        candidates.push_back({a[i], i});
    }
    
    // Sort candidates by votes
    sort(candidates.begin(), candidates.end());
    
    vector<int> ans(n, -1);
    
    for (int i = 0; i < n; ++i) {
        int left = 0, right = k + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (can_win(i, mid, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if (left == k + 1) {
            ans[candidates[i].second] = -1;
        } else {
            ans[candidates[i].second] = left;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}