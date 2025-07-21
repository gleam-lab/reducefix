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
    
    ll toysLeft = 0;
    ll lastUnmatchedToy = -1;
    ll i = n - 1, j = n - 2;
    
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            i--;
            j--;
        } else {
            lastUnmatchedToy = a[i];
            toysLeft++;
            i--;
        }
    }
    
    while (i >= 0) {
        lastUnmatchedToy = a[i];
        toysLeft++;
        i--;
    }
    
    if (toysLeft == 1) {
        cout << lastUnmatchedToy << endl;
    } else if (toysLeft == 0) {
        // All toys are matched, but we have one extra box. So x can be any value (but problem says step 2 needs N boxes)
        // So perhaps the answer is 1, but the problem expects x to be used. So perhaps the minimal x is 1.
        // However, since all toys are matched, the new box can be of size 1 (since no toy needs it).
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}