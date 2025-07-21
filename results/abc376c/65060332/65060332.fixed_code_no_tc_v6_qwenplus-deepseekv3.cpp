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
    
    ll toy_ptr = 0;
    ll box_ptr = 0;
    ll cnt = 0;
    ll max_unmatched = 0;
    
    while (toy_ptr < n && box_ptr < n-1) {
        if (b[box_ptr] >= a[toy_ptr]) {
            box_ptr++;
            toy_ptr++;
        } else {
            cnt++;
            max_unmatched = max(max_unmatched, a[toy_ptr]);
            toy_ptr++;
        }
    }
    
    while (toy_ptr < n) {
        cnt++;
        max_unmatched = max(max_unmatched, a[toy_ptr]);
        toy_ptr++;
    }
    
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << max_unmatched << endl;
    }
    
    return 0;
}