#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        // Adjusting indices to be zero-based for binary search
        int c = lower_bound(x+1, x+n+1, l) - x;
        int d = upper_bound(x+1, x+n+1, r) - x;
        
        // Handling the case where r is less than the smallest element in x
        if(d == 0) d++;
        
        // Calculating the range sum using prefix sums
        long long result = sum[d-1] - sum[c-1];
        cout << result << endl;
    }
    return 0;
}