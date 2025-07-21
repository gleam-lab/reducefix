#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // Extend array to simulate circular behavior
    }
    b[0] = 1;
    for(int i = 1; i < 2 * n; ++i) {
        if(i >= n) {
            b[d[i - n] % m]--; // Subtract from the count of the previous element
        }
        d[i] = d[i - 1] + a[i]; // Accumulate sum
        sum += b[d[i] % m]; // Add the count of the current sum's remainder
        if(i < n) {
            b[d[i] % m]++; // Increment the count of the current element
        }
    }
    cout << sum;
    return 0;
}