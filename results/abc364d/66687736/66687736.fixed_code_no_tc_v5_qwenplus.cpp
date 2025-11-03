#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vi a(N);
    rep(i, N) cin >> a[i];

    // Sort the A points for binary search and distance calculation
    sort(a.begin(), a.end());

    rep(qi, Q) {
        int b, k;
        cin >> b >> k;
        k--; // convert to 0-indexed

        // Binary search on the answer (distance)
        ll low = -1;
        ll high = 200000000; // max possible distance is 2e8

        while (high - low > 1) {
            ll mid = (low + high) / 2;

            // Count how many points in A are within distance 'mid' from B
            ll left_bound = b - mid;
            ll right_bound = b + mid;

            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);

            int count = it2 - it1;

            if (count <= k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        cout << high << '\n';
    }
}