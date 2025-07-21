#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
int a[MAXN];

void solve(void) {
    int n, q; cin >> n >> q;
    vector<int> coords(n);
    for(int i = 0; i < n; i++) {
        cin >> coords[i];
    }
    sort(coords.begin(), coords.end());

    for(int i = 0; i < q; i++){
        int x, k; cin >> x >> k;
        auto it = lower_bound(coords.begin(), coords.end(), x);
        int index = it - coords.begin();

        if(index == k - 1) {
            cout << 0 << endl;
        } else if(index < k - 1) {
            cout << coords[k - 1] - x << endl;
        } else {
            cout << x - coords[index - k] << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}