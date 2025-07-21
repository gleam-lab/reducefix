#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Extend array a to length 2n
    for(int i = 0; i < n; i++) {
        a[i + n] = a[i];
    }
    
    // Initialize b array
    b[0] = 1;
    for(int i = 1; i < n * 2; i++) {
        d[i] = (i > 0) ? d[i - 1] + a[i] : a[i];
        
        // Calculate the index using modulo operation considering the offset
        int index = (d[i] % m + m) % m;

        sum += b[index];
        b[index] += 2; // Since we are adding from both sides
    }
    
    cout << sum;
    return 0;
}