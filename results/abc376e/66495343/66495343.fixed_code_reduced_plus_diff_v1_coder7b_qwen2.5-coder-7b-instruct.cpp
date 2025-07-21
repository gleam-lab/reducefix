#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n), b(n);

        for(int i = 0; i < n; ++i)
            cin >> a[i];

        for(int i = 0; i < n; ++i)
            cin >> b[i];

        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll ans = 0;

        // Calculate the result using the smallest K elements of B and the largest K elements of A
        for(int i = 0; i < k; ++i)
            ans += a[n - k + i] * b[i];

        cout << ans << '\n';
    }

    return 0;
}