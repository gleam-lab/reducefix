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
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end());

    rep(qi, Q) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-indexed

        // Binary search on the distance
        ll left = -1;
        ll right = 2e8 + 10;

        while (right - left > 1) {
            ll mid = (left + right) / 2;
            ll low = b - mid;
            ll high = b + mid;

            // Count how many points in A are in [low, high]
            auto it1 = lower_bound(a.begin(), a.end(), low);
            auto it2 = upper_bound(a.begin(), a.end(), high);
            ll count = it2 - it1;

            if (count <= k) {
                left = mid;
            } else {
                right = mid;
            }
        }

        cout << right << '\n';
    }
}