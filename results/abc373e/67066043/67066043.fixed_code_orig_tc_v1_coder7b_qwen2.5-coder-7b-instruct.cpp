#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
    
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = a[ord[i]] + pref[i];
    }
    
    vector<long long> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        long long needed = 0;
        int lid = n - m - (i >= n - m ? 1 : 0);
        long long cnt = 0;
        
        auto rid = upper_bound(pref.begin(), pref.end(), pref[lid + 1] + a[ord[i]]);
        if (rid != pref.end()) {
            cnt += (rid - pref.begin() - lid - 1) * (pref[lid + 1] + a[ord[i]]) - (pref[rid - pref.begin()] - pref[lid + 1]);
        }
        if (lid <= i && i < rid - pref.begin()) {
            cnt++;
        } else {
            cnt += (k / (n - i)) + (k % (n - i) > 0);
        }
        
        if (cnt > k) {
            ans[ord[i]] = -1;
        } else {
            ans[ord[i]] = k - cnt;
        }
    }
    
    for (auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}