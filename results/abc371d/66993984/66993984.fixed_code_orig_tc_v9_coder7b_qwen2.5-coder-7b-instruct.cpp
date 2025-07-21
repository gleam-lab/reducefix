#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
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
        int L, R;
        cin >> L >> R;
        
        // Adjusting indices as array is 1-indexed
        --L;
        --R;
        
        // Calculating the required sum using prefix sums
        long long result = sum[R] - sum[L];
        cout << result << '\n';
    }
    
    return 0;
}