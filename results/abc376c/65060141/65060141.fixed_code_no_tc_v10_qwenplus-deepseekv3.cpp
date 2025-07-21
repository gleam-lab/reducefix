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
    
    ll unplaced = 0;
    ll max_unplaced = 0;
    ll i = n - 1, j = n - 2;
    
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            i--;
            j--;
        } else {
            unplaced++;
            max_unplaced = max(max_unplaced, a[i]);
            i--;
        }
    }
    
    while (i >= 0) {
        unplaced++;
        max_unplaced = max(max_unplaced, a[i]);
        i--;
    }
    
    if (unplaced > 1) {
        cout << -1 << endl;
    } else {
        cout << max_unplaced << endl;
    }
    
    return 0;
}