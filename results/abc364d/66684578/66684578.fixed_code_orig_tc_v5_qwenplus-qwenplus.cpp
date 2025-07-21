#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define all(c) c.begin(),c.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vi a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));

    while (q--) {
        int b, k;
        cin >> b >> k;

        // Binary search on answer: the distance d such that there are at least k points within d of b
        int lo = 0, hi = 2e8 + 10;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int l = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int r = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            if (r - l >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo << '\n';
    }

    return 0;
}