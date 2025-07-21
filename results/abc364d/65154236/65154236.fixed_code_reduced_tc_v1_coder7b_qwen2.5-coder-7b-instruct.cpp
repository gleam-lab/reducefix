#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<long long> ans;

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    for(int i = 0; i < q; ++i) {
        int b, k; cin >> b >> k;
        auto it = lower_bound(a.begin(), a.end(), b);
        int idx = it - a.begin();
        
        if(k == 1) {
            ans.push_back(abs(b - a[idx]));
        } else if(idx == 0) {
            ans.push_back(abs(b - a[k - 1]));
        } else if(idx == n - 1) {
            ans.push_back(abs(b - a[n - k]));
        } else {
            int leftDist = abs(b - a[idx - 1]);
            int rightDist = abs(b - a[idx + k - 1]);
            ans.push_back(min(leftDist, rightDist));
        }
    }

    for(long long val : ans) {
        cout << val << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}