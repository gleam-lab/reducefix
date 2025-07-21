#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vi A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));
    
    rep(_, Q) {
        int b, k;
        cin >> b >> k;
        // The k-th smallest |A_i - b| is desired
        // Binary search the answer: the distance d
        // Count how many A_i have |A_i - b| <= d
        // If count >= k, possible to have d smaller
        // Else, need larger d
        ll left = 0, right = 2e14;
        ll answer = right;
        while (left <= right) {
            ll mid = (left + right) / 2;
            // Number of A_i <= b + mid
            int upper = upper_bound(all(A), b + mid) - A.begin();
            // Number of A_i >= b - mid
            int lower = lower_bound(all(A), b - mid) - A.begin();
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