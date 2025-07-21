#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(2*n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    vector<int> cnt_map(m, 0);
    cnt_map[0] = 1; // prefix sum mod m == 0 initially
    
    ll prefix_sum = 0;
    ll result = 0;
    
    for(int i = 1; i < 2*n; ++i) {
        prefix_sum += a[i];
        int mod = ((prefix_sum % m) + m) % m;
        
        // If we're past the first n elements, decrement count from n positions back
        if(i > n) {
            int removed_mod = ((prefix_sum - a[i-n] * 2) % m + m) % m;
            cnt_map[removed_mod]--;
        }
        
        result += cnt_map[mod];
        cnt_map[mod]++;
    }
    
    cout << result;
    return 0;
}