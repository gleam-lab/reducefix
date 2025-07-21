#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n, m;
int a[2*N], d[2*N];
int cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    long long sum = 0;
    cnt[0] = 1;
    
    for(int i=1; i<2*n; i++) {
        d[i] = (d[i-1] + a[i]) % m;
        if(d[i] < 0) d[i] += m; // Ensure positive modulo
        
        if(i >= n) {
            cnt[d[i-n]]--;
        }
        
        sum += cnt[d[i]];
        
        if(i < n) {
            cnt[d[i]]++;
        }
    }
    
    cout << sum << '\n';
    return 0;
}