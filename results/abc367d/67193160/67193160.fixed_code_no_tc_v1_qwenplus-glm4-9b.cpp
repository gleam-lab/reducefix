#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, cnt;
int a[N], b[N], d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    // Extend the array 'a' for the circular nature of the problem
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    
    // Initialize the prefix sums array 'd' with zeros
    memset(d, 0, sizeof(d));
    
    // Initialize the frequency array 'b' for the remainder modulo 'm'
    for (int i = 0; i < m; i++) {
        b[i] = 0;
    }
    
    // Calculate the prefix sums and use a sliding window technique with a frequency array
    for (int i = 0; i < 2 * n; i++) {
        d[i] = d[i - 1] + a[i];
        sum += b[d[i] % m];
        if (i < n) {
            b[d[i] % m]++;
        } else {
            b[d[i - n] % m]--;
            b[d[i] % m]++;
        }
    }
    
    cout << sum;
    return 0;
}