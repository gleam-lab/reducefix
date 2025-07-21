#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m;
int a[N*2], prefix[N*2];
int freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    prefix[0] = 0;
    for(int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    long long res = 0;
    freq[0] = 1;
    
    for(int i = 1; i <= 2 * n; ++i) {
        if(i > n) {
            int mod = prefix[i - n] % m;
            freq[mod]--;
        }
        res += freq[prefix[i]];
        if(i <= n) {
            freq[prefix[i]]++;
        }
    }
    
    cout << res << endl;
    return 0;
}