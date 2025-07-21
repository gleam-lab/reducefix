#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> a, b, k;

bool compare(int& x, int& y){
    return abs(a[x] - b[j]) < abs(a[y] - b[j]);
}

int findKthClosest(int idx, int k){
    int n = a.size();
    vector<int> dist(n);
    for(int i = 0; i < n; i++){
        dist[i] = abs(a[i] - b[idx]);
    }
    nth_element(dist.begin(), dist.begin() + k - 1, dist.end());
    return dist[k - 1];
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        b.push_back(x);
        k.push_back(y);
    }

    sort(b.begin(), b.end());
    for(int i = 0; i < q; i++){
        int idx = lower_bound(b.begin(), b.end(), b[i]) - b.begin();
        int ans = findKthClosest(idx, k[i]);
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}