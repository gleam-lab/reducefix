#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int i,j,x,y,z,t;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i];
    
    long long total = 0;
    map<int,int> freq;
    freq[0] = 1;
    int prefix_sum = 0;
    
    for(i=1;i<=2*n;i++) {
        prefix_sum = (prefix_sum + a[i]) % m;
        if(i > n) {
            int old_prefix = (prefix_sum - d[i-n] + m) % m;
            freq[old_prefix]--;
        }
        total += freq[prefix_sum];
        if(i <= n) {
            d[i] = prefix_sum;
        }
        freq[prefix_sum]++;
    }
    
    cout<<total;
    return 0;
}