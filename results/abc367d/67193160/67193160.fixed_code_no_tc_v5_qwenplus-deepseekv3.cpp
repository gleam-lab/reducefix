#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long a[N], prefix[N];
int freq[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i+n] = a[i]; // Create circular array
    }
    
    prefix[0] = 0;
    freq[0] = 1; // Initialize for prefix sum 0
    
    long long res = 0;
    for(int i=1;i<=2*n;i++) {
        prefix[i] = prefix[i-1] + a[i];
        if(i > n) {
            // Remove the element that's now outside our window of size n
            freq[prefix[i-n] % m]--;
        }
        res += freq[prefix[i] % m];
        if(i <= n) {
            // Only add to frequency for first n elements
            freq[prefix[i] % m]++;
        }
    }
    cout << res;
    return 0;
}