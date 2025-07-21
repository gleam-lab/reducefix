#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        int pos = lower_bound(a.begin(), a.end(), b) - a.begin();
        
        int l = pos - 1, r = pos;
        vector<ll> distances;
        while (distances.size() < k && (l >= 0 || r < N)) {
            ll dl = (l >= 0) ? abs(b - a[l]) : LLONG_MAX;
            ll dr = (r < N) ? abs(b - a[r]) : LLONG_MAX;
            if (dl <= dr) {
                distances.push_back(dl);
                l--;
            } else {
                distances.push_back(dr);
                r++;
            }
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}