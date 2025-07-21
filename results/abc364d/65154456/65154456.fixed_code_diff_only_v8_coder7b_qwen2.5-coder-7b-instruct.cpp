#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int a[200005], b[200005];

void solve(void) {
    int n, q; cin >> n >> q;
    vector<int> dist(n);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    for(int i = 1; i <= q; i++) {
        cin >> b[i] >> dist[i];
    }
    
    for(int i = 1; i <= q; i++) {
        int left = 0, right = n - 1;
        
        while(left < right) {
            int mid = (left + right) / 2;
            
            if(a[mid + 1] - b[i] < dist[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        cout << a[left + 1] - b[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}