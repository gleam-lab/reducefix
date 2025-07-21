#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n - 1);
    
    ll toys_left = 0;
    ll max_unmatched = 0;
    ll i = n - 1, j = n - 2;
    
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            i--;
            j--;
        } else {
            max_unmatched = max(max_unmatched, a[i]);
            toys_left++;
            i--;
        }
    }
    while (i >= 0) {
        max_unmatched = max(max_unmatched, a[i]);
        toys_left++;
        i--;
    }
    
    if (toys_left > 1) {
        cout << -1 << endl;
    } else {
        cout << max_unmatched << endl;
    }
    return 0;
}