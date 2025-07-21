#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, cnt, a[N], b[N], d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i]; // Extend the array
    }
    
    // Initialize remainder counts for the range 1 to m
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n * 2; i++) {
        // Use the last n elements as part of the extended array
        if (i > n) {
            b[d[i - n] % m]--;
        }
        
        // Update the sum of the array
        d[i] = d[i - 1] + a[i];
        
        // Update the sum based on the count of remainders
        sum += cnt * (d[i] % m);
        
        if (i <= n) {
            b[d[i] % m]++;
        }
        
        // Update the count of remainders for d[i]
        cnt = 0;
        for (int j = 1; j <= m; j++) {
            cnt += b[j];
        }
    }
    
    cout << sum;
    return 0;
}