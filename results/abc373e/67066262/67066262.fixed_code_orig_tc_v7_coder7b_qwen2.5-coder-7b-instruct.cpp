#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.rbegin(), a.rend());

    vector<long long> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<long long> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        long long need = 0;
        if(i >= n - m) {
            if(k >= (n - m - i) * a[i]) {
                ans[i] = 0;
            } else {
                need = (n - m - i) * a[i] - k;
                if(need % (n - m - i)) {
                    ans[i] = need / (n - m - i) + 1;
                } else {
                    ans[i] = need / (n - m - i);
                }
            }
        } else {
            long long rem = pref[n] - pref[i + 1];
            if(rem >= k) {
                ans[i] = 0;
            } else {
                need = k - rem;
                if(need % (n - i - 1)) {
                    ans[i] = need / (n - i - 1) + 1;
                } else {
                    ans[i] = need / (n - i - 1);
                }
            }
        }
    }

    for(long long x : ans) cout << x << " ";

    return 0;
}