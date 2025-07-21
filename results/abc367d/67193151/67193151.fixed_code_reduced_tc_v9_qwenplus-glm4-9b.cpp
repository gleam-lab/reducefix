#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // Initialize b with zeros and set b[0] to 1 because it corresponds to the initial state
    for (int i = 0; i < m; i++) {
        b[i] = 0;
    }
    b[0] = 1;
    
    // Process the array a by considering its repeated elements
    for (int i = 1; i <= n * 2; i++) {
        if (i > n) {
            // Decrease the count of the current remainder
            b[d[i - n] % m]--;
        }
        
        // Calculate the new value of d[i] and update the sum
        d[i] = d[i - 1] + a[i % n]; // Use modulo to wrap around the array
        if (i <= n) {
            // Increase the count of the new remainder for the first n elements
            b[d[i] % m]++;
        }
        
        // If i is greater than n, we need to add the current remainder count to sum
        if (i > n) {
            sum += b[d[i] % m];
        }
    }
    
    cout << sum;
    return 0;
}