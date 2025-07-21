#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    rep(i, Q) {
        int b, k;
        cin >> b >> k;
        
        int left = 0, right = 1e8 * 2 + 1;
        int answer = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            auto lower = lower_bound(A.begin(), A.end(), b - mid);
            auto upper = upper_bound(A.begin(), A.end(), b + mid);
            int count = upper - lower;
            
            if (count >= k) {
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