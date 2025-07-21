#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m, sum, cnt, a[2*N], d[2*N], b[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    b[0] = 1;
    long long total = 0;
    
    for (int i = 1; i <= 2 * n; ++i) {
        d[i] = (d[i-1] + a[i]) % m;
        if (d[i] < 0) d[i] += m;
        
        if (i > n) {
            b[d[i - n]]--;
        }
        total += b[d[i]];
        if (i <= n) {
            b[d[i]]++;
        }
    }
    
    cout << total << endl;
    return 0;
}