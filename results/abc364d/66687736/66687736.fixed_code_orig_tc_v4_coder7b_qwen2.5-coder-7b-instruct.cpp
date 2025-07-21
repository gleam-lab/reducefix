#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vl a(n), b(q);
    vl k(q);
    
    rep(i, n) cin >> a[i];
    rep(j, q) cin >> b[j] >> k[j];
    
    sort(a.begin(), a.end());
    
    for (int j = 0; j < q; ++j) {
        ll lb = -1e9, rb = 1e9 + 10;
        while (rb - lb > 1) {
            ll mid = (lb + rb) / 2;
            int cnt = 0;
            for (const auto& ai : a) {
                cnt += lower_bound(a.begin(), a.end(), b[j] + mid) - upper_bound(a.begin(), a.end(), b[j] - mid);
            }
            if (cnt >= k[j]) rb = mid;
            else lb = mid;
        }
        cout << rb << '\n';
    }
    
    return 0;
}