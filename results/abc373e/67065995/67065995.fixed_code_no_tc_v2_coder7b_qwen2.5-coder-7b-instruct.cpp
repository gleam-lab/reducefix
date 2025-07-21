#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the maximum number of votes any candidate can get
    ll max_votes = *max_element(a.begin(), a.end());

    // If the maximum votes are already greater than or equal to K/(n-M), no further votes are needed
    if(max_votes >= k / (n - m)) {
        for(int i = 0; i < n; ++i) cout << "0 ";
        return 0;
    }

    // Otherwise, calculate the minimum additional votes needed
    for(int i = 0; i < n; ++i) {
        if(a[i] < k / (n - m)) {
            cout << k / (n - m) - a[i] << " ";
        } else {
            cout << "-1 ";
        }
    }

    return 0;
}