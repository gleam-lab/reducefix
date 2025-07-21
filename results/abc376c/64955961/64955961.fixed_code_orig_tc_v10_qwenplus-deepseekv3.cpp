#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll i = n-1, j = n-2;
    ll cnt = 0;
    ll ans = -1;
    
    while (i >= 0 && j >= 0) {
        if (a[i] <= b[j]) {
            i--;
            j--;
        } else {
            cnt++;
            ans = a[i];
            i--;
        }
        if (cnt > 1) {
            cout << -1 << endl;
            return;
        }
    }
    
    if (cnt == 1) {
        cout << ans << endl;
    } else {
        if (i >= 0) {
            cout << a[0] << endl;
        } else {
            // All toys are placed, but we still need to choose x
            // The new box can be any size >= the smallest toy, but since all toys are placed,
            // the answer is the smallest toy (but need to see if all boxes are used)
            // Wait, in this case, all N-1 boxes are used and we have one toy left, which would be the smallest.
            // So the new box must be at least the smallest toy's size.
            // But wait, if all toys are placed, then we have N toys and N boxes (including the new one). So the new box must be at least the smallest toy's size.
            // But in the case where all toys are placed, the smallest toy is placed in the smallest box, but since we have N boxes (N-1 existing + 1 new), but only N-1 existing boxes. So perhaps the smallest toy is placed in the smallest box, and the new box is not needed? No, because we have N toys and N boxes.
            // Wait, the initial condition is that we have N toys and N-1 boxes, so after purchasing one new box, we have N boxes. So if all N-1 boxes are used, the remaining toy must go into the new box.
            // So in the case where all existing boxes are used (i.e., no toys left after matching all N-1 boxes), then the new box is not needed, but the problem says we must purchase one box. So in this case, the answer should be the smallest toy's size, since we can place any toy in the new box (but to minimize x, we choose the smallest toy).
            // But in the code's logic, if all toys are placed in existing boxes (i < 0), we might have to choose x as the smallest possible (which could be 1, but since toy sizes can be up to 1e9, we need the smallest toy's size).
            // But the problem says we must purchase one box, even if all toys can be placed in existing boxes, which would mean we have to choose x as the size of the smallest toy (since it's the minimal possible).
            // But the sample input suggests that when all toys can be placed in existing boxes, the answer is the smallest toy's size.
            // However, in the problem statement, it's given that we must purchase one box, and then place each toy into one box. So the new box must be used, and the minimal x would be the size of the smallest toy not placed in existing boxes, or if all are placed, the smallest toy's size (since we can place it in the new box).
            cout << a[0] << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}