#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n, m, k, sum, cnt, a[N], b[N], d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], a[i + n] = a[i];
    
    b[0] = 1;
    for (int i = 1; i < n * 2; i++) {
        if (i < n) {
            b[d[i] % m]--;
            d[i + 1] = d[i] + a[i + 1];
            sum += b[d[i + 1] % m];
            b[d[i + 1] % m]++;
        } else if (i >= n && i < 2 * n) {
            b[d[i - n] % m]--;
            d[i + 1] = d[i] + a[i + 1];
            sum += b[d[i + 1] % m];
            b[d[i + 1] % m]++;
        }
    }
    cout << sum;
    return 0;
}