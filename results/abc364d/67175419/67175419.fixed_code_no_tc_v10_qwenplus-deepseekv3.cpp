#include<bits/stdc++.h>
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
        
        int low = 0, high = 2e8;
        int answer = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            auto left = lower_bound(a.begin(), a.end(), b - mid);
            auto right = upper_bound(a.begin(), a.end(), b + mid);
            int count = right - left;
            
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << "\n";
    }
    
    return 0;
}