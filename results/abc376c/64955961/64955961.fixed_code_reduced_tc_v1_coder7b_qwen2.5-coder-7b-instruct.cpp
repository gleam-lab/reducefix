#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll min_box_size = -1;
    for (ll i = 0, j = n - 2; i < n; ++i) {
        if (j >= 0 && a[i] <= b[j]) {
            --j;
        } else {
            if (min_box_size == -1 || a[i] > min_box_size) {
                min_box_size = a[i];
            }
        }
    }

    cout << min_box_size << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}