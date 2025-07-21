#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define all(x) x.begin(), x.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        int low = 0, high = 2e8;
        int answer = 0;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            auto left = lower_bound(all(a), b - mid);
            auto right = upper_bound(all(a), b + mid);
            int count = right - left;
            
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }
    
    return 0;
}