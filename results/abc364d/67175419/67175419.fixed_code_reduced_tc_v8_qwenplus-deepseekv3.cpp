#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        long long left = 0, right = 2e18;
        long long answer = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            auto low = lower_bound(a.begin(), a.end(), b - mid);
            auto high = upper_bound(a.begin(), a.end(), b + mid);
            int count = high - low;
            
            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << "\n";
    }
    
    return 0;
}