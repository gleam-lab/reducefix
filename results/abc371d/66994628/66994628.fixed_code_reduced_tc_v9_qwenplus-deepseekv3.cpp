#include<bits/stdc++.h>
using namespace std;
int n, q;
long long x[200005], p[200005];
long long sum[200005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    cin >> q;
    while(q--) {
        long long l_query, r_query;
        cin >> l_query >> r_query;
        int l = lower_bound(x + 1, x + n + 1, l_query) - x;
        int r = upper_bound(x + 1, x + n + 1, r_query) - x;
        cout << sum[r-1] - sum[l-1] << endl;
    }
    return 0;
}