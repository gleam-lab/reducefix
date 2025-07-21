#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int i,j,x,y,z,t;
    cin >> n >> m;

    // Extend array 'a' ensuring no out-of-bounds access.
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i + n < N) {
            a[i + n] = a[i];
        }
    }

    // Initialize array 'b' to use it as a frequency counter mod m.
    fill(b, b + m, 0);
    b[0] = 1; // Set initial value for some correct calculation.
    for (i = 1; i <= n; ++i) {
        d[i] = (d[i - 1] + a[i]) % m;
        b[d[i]]++;
    }

    // Calculate the sum using the frequency array.
    for (i = 1; i <= n; ++i) {
        sum += b[d[i]];
    }

    cout << sum;
    return 0;
}