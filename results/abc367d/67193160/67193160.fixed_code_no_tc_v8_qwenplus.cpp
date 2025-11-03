#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N];
long long sum;
map<int,int> cnt;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    cnt[0] = 1;
    int prefix = 0;
    
    for(int i = 1; i <= n; i++) {
        prefix = (prefix + a[i]) % m;
        if(prefix < 0) prefix += m;  // Handle negative modulo
        sum += cnt[prefix];
        cnt[prefix]++;
    }
    
    cout << sum;
    return 0;
}