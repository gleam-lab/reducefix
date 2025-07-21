#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], k[MAXN];

void solve() {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= q; i++) cin >> b[i] >> k[i];

    for(int i = 1; i <= q; i++) {
        int pos = lower_bound(a + 1, a + n + 1, b[i]) - a;
        int left = pos - 1, right = pos;
        int dist = INT_MAX;
        
        while(left >= 0 && right <= n) {
            int ld = abs(a[left] - b[i]), rd = abs(a[right] - b[i]);
            if(ld < rd) {
                dist = min(dist, ld);
                left--;
            } else {
                dist = min(dist, rd);
                right++;
            }
        }

        while(left >= 0) {
            dist = min(dist, abs(a[left] - b[i]));
            left--;
        }

        while(right <= n) {
            dist = min(dist, abs(a[right] - b[i]));
            right++;
        }

        cout << dist << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}