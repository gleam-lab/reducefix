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
    
    ll i = 0, j = 0;
    ll cnt = 0;
    ll last_unmatched = -1;
    
    while (i < n && j < n - 1) {
        if (b[j] >= a[i]) {
            i++;
            j++;
        } else {
            last_unmatched = a[i];
            cnt++;
            i++;
        }
    }
    
    if (i < n) {
        cnt += (n - i);
        last_unmatched = a[n - 1];
    }
    
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        if (cnt == 0) {
            // All toys matched, need to buy a box of size at least the smallest toy not in boxes
            // Since all boxes are used, need to buy a box for one toy. The new box's x must be >= that toy's size.
            // The smallest x is the smallest toy's size, but all toys are matched, so we need a box for any toy.
            // But the problem states that each toy must be in a separate box, and boxes can't have more than one toy.
            // So in this case, the existing boxes are exactly N-1, and we have N toys. So one toy must go into the new box.
            // The minimal x is the largest toy not matched (but in this case, the new box can be any toy's size, smallest possible is the smallest unmatched toy's size, but all are matched. So perhaps the smallest toy in the list.
            // But the previous matching could have left one toy unmatched. So perhaps in this scenario, even if cnt is 0, the last_unmatched is not set, so we need to set x to the smallest toy's size.
            // Or perhaps in this case, the new box must be at least the size of the largest toy, but we need to find the minimal x.
            // The correct approach here is that if all N-1 boxes are matched to N-1 toys, then the remaining toy must go into the new box, and x must be at least its size.
            // So even if cnt is 0, the remaining toy is a[n-1] (since i would be n-1+1 after the loop).
            cout << a[n-1] << endl;
        } else {
            cout << last_unmatched << endl;
        }
    }
    
    return 0;
}