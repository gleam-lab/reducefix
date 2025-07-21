#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
#define endl '\n'

const int N = 1e5 + 5;

int n, q;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;
        
        // Binary search bounds
        int low = 0, high = 2e8 + 10;
        while (low < high) {
            int mid = (low + high) / 2;
            
            // Find the range of elements within distance `mid` from b
            int left = lower_bound(a, a + n, b - mid) - a;
            int right = upper_bound(a, a + n, b + mid) - a;
            int count = right - left;
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        cout << low << endl;
    }

    return 0;
}