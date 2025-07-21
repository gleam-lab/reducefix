#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_castio(false);
    cin.tie(NULL);

    long long n, m, k;
    cin >> n >> m >> k;
    
    vector<long long> a(n);
    for(long long &ai : a) cin >> ai, k -= ai;

    vector<long long> b = a;
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    vector<long long> pref(n + 1);
    for(long long i = 0; i < n; ++i) pref[i + 1] = pref[i] + b[i];

    vector<long long> ans(n, -1);
    for(long long i = 0; i < n; ++i) {
        long long need = 0;
        for(long long j = 0; j < n; ++j) {
            if(i != j) {
                need += max(0LL, b[j] - a[i] + need);
                if(j >= n - m) break;
            }
        }
        if(k >= need) ans[i] = need;
    }

    for(long long &ai : ans) cout << ai << " ";
    return 0;
}