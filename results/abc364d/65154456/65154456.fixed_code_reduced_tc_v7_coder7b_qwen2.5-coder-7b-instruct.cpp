#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

vector<int> A[MAXN], B[MAXN];

void preprocess() {
    for(int i = 0; i < MAXN; i++) sort(all(A[i]));
    for(int i = 0; i < MAXN; i++) sort(all(B[i]));
}

int query(vector<int>& arr, int k) {
    int n = arr.size();
    int lo = 0, hi = n - 1;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(arr[mid] >= k) hi = mid;
        else lo = mid + 1;
    }
    return arr[lo];
}

void solve() {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[abs(x)].push_back(abs(x));
    }
    for(int i = 1; i <= q; i++) {
        int x, k; cin >> x >> k;
        B[abs(x)].push_back(k);
    }
    preprocess();
    for(int i = 1; i < MAXN; i++) {
        for(auto& k : B[i]) {
            if(A[i].size() < k) cout << "0" << endl;
            else cout << query(A[i], k) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}