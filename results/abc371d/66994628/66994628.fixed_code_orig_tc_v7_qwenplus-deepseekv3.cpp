#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
long long x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    
    int q;
    cin >> q;
    while(q--) {
        long long l, r;
        cin >> l >> r;
        int left_idx = lower_bound(x+1, x+n+1, l) - x;
        int right_idx = upper_bound(x+1, x+n+1, r) - x;
        cout << sum[right_idx-1] - sum[left_idx-1] << '\n';
    }
    return 0;
}