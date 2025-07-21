#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<int> v[N];
int par[N], sz[N];

int find(int x) {
    if(par[x] != x) par[x] = find(par[x]);
    return par[x];
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    v[a].insert(end(v[a]), begin(v[b]), end(v[b]));
    sz[a] += sz[b];
    par[b] = a;
}

int kthLargest(vector<int>& arr, int k) {
    if(k > sz[arr]) return -1;
    nth_element(begin(arr), begin(arr) + k - 1, end(arr));
    return arr[k - 1];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
        v[i].push_back(i);
    }
    
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            unite(a, b);
        } else {
            a = find(a);
            cout << kthLargest(v[a], b) << '\n';
        }
    }

    return 0;
}