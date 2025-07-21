#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

void solve() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);
    
    while(m--) {
        int x, y, k;
        cin >> x >> k;
        
        // Binary search for the k-th closest point
        int left = 0, right = 1e8;
        while(left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            
            for(int i = 1; i <= n; ++i) {
                if(abs(x - a[i]) <= mid)
                    ++count;
                
                if(count >= k)
                    break;
            }
            
            if(count >= k)
                right = mid;
            else
                left = mid + 1;
        }
        
        cout << left << '\n';
    }
}

int main() {
    solve();
    return 0;
}