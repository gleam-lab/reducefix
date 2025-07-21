#include<bits/stdc++.h>
using namespace std;

int n,q,x[200005],p[200005];
long long sum[200005];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i]; // Store prefix sums instead of cumulative sums
    }
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        int c = lower_bound(x + 1, x + n + 1, l) - x;
        int d = upper_bound(x + 1, x + n + 1, r) - x;
        if(c > 0 && d <= n) { // Check if indices are within bounds
            cout << sum[d-1] - sum[c-1] << endl;  
        } else {
            cout << "Invalid Query" << endl; // Handle invalid queries
        }
    }
    return 0;
}