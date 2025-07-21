#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];

        // Sort in descending order
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());

        ll ans = 0;
        for(int i = 0; i < k; ++i) {
            ans += a[i] * b[i];
        }

        cout << ans << '\n';
    }

    return 0;
}