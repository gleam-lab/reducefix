#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt;
int a[N],b[N],d[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    
    // Initialize b array with zeros
    for(int i = 0; i < N; i++) {
        b[i] = 0;
    }
    b[0] = 1;  // Set the initial count for modulo 0
    
    // Read the array a
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Compute prefix sums of a
    for(int i = 1; i <= 2*n; i++) {
        if(i <= n) {
            d[i] = d[i-1] + a[i];
        } else {
            d[i] = d[i-1] + a[i-n];
        }
    }

    // Calculate the sum using the b array
    for(int i = 1; i <= 2*n; i++) {
        // Update b array based on d values
        b[d[i]%m]++;
        if(i < 2*n) {
            b[d[i+1]%m]--;
        }
    }

    // Calculate the sum
    for(int i = 1; i <= m; i++) {
        sum += b[i];
    }

    cout << sum << endl;
    return 0;
}