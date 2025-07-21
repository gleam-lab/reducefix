#include <bits/stdc++.h>
using namespace std;
int n, x[200050], p[200050], q;
long long a[200050]; // Changed to long long to prevent overflow

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        a[i] = a[i-1] + p[i]; // Now using long long for accumulation
    }
    cin >> q;
    for (int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        
        // Binary search for left bound
        int l1 = 1, r1 = n;
        while (l1 < r1){
            int mid = (l1 + r1) >> 1;
            if (x[mid] >= l) r1 = mid;
            else l1 = mid + 1;
        }
        
        // Binary search for right bound
        int l2 = 1, r2 = n;
        while (l2 < r2){
            int mid = (l2 + r2 + 1) >> 1;
            if (x[mid] <= r) l2 = mid;
            else r2 = mid - 1;
        }
        
        // Output the sum between the bounds
        if (x[l1] >= l && x[l2] <= r) {
            cout << a[l2] - a[l1 - 1] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}