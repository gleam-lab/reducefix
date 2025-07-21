#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    rep(i, N) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    rep(_, Q) {
        int b, k;
        cin >> b >> k;
        int left = 0, right = 1e8 * 2;
        int answer = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            auto lower = lower_bound(a.begin(), a.end(), b - mid);
            auto upper = upper_bound(a.begin(), a.end(), b + mid);
            int count = upper - lower;
            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << endl;
    }
    
    return 0;
}