#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long a[2*N], prefix[2*N];
int cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    // Compute prefix sums
    prefix[0] = 0;
    for(int i=1; i<=2*n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }
    
    long long total = 0;
    cnt[0] = 1; // Empty prefix sum
    
    // Sliding window of size n
    for(int i=1; i<=2*n; i++) {
        if(i > n) {
            long long prev_mod = (prefix[i-n] % m + m) % m;
            cnt[prev_mod]--;
        }
        
        long long curr_mod = (prefix[i] % m + m) % m;
        total += cnt[curr_mod];
        cnt[curr_mod]++;
    }
    
    cout << total << endl;
    return 0;
}