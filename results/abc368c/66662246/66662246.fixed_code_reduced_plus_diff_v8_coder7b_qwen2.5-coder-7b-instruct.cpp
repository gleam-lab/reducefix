#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

ll solve(vector<ll>& a) {
    ll sum = accumulate(a.begin(), a.end(), 0LL), ans = 0;
    while(sum > 0) {
        bool changed = false;
        rep(i, a.size()) {
            if(a[i] <= 0) continue;
            changed = true;
            if((ans + 1) % 3 == 0) {
                a[i] -= 3;
            } else {
                a[i]--;
            }
            sum -= (a[i] < 0 ? 0 : 1);
            ans++;
            if(!sum) break;
        }
        if(!changed) return -1; // In case of an infinite loop
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    ll res = solve(a);
    if(res == -1) cout << "Infinite Loop Detected" << endl;
    else cout << res << endl;
    
    return 0;
}