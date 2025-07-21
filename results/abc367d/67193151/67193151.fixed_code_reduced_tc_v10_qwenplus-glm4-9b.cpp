#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    // Initialize the array `a` with 0
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Initialize the array `b` to count the frequency of remainders
    for(int i = 0; i < m; i++) {
        b[i] = 0;
    }

    // Calculate the prefix sums and update count of remainders
    for(int i = 1; i <= n; i++) {
        d[i] = (i <= n ? a[i] : 0) + d[i-1]; // Ensure d[i] is defined correctly
        int remainder = d[i] % m;
        b[remainder]++;
        sum += b[remainder];
    }

    cout << sum;
    return 0;
}