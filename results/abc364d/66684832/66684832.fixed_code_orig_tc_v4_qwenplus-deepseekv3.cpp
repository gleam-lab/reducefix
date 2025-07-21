#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        
        int left = 0, right = 2e14;
        int answer = 2e14;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int cnt = upper_bound(a, a + n, b + mid) - lower_bound(a, a + n, b - mid);
            
            if (cnt >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}