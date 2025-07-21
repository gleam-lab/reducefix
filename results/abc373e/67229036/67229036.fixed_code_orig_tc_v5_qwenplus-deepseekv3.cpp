#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;

signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    if(m == n) {
        // All candidates will be elected regardless
        for(int i=0; i<n; i++) cout << "0 ";
        cout << endl;
        return 0;
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    // Precompute prefix sums
    vector<int> prefix(n+1);
    for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + b[i];

    int remaining = k;
    for(int x : a) remaining -= x;

    for(int i=0; i<n; i++) {
        int x = a[i];
        int low = 0, high = remaining, ans = -1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int total = x + mid;
            
            // Find how many current votes are > total
            int pos = upper_bound(b.begin(), b.end(), total) - b.begin();
            int cnt = n - pos;
            
            if(cnt < m) {
                // Candidate is elected
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << (ans != -1 ? ans : -1) << " ";
    }
    cout << endl;
    
    return 0;
}