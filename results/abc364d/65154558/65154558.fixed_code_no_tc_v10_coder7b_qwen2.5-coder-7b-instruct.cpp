#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
vector<int> a[MAXN], b[MAXN];
vector<pair<int, int>> dists[MAXN];

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first < p2.first;
}

void solve(void) {
    int n, q; cin >> n >> q;
    
    // Collect distances for each point B_j
    for(int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        a[ai].push_back(i);
    }
    for(int i = 0; i < q; ++i) {
        int bi, ki; cin >> bi >> ki;
        b[bi].push_back(ki - 1); // Adjusting index to zero-based
    }

    // Calculate sorted distances for each point B_j
    for(int i = 0; i < 2 * 100000000 + 1; ++i) {
        sort(a[i].begin(), a[i].end());
        for(auto& idx : a[i]) {
            dists[idx].emplace_back(abs(i - idx), idx);
        }
    }
    for(int i = 0; i < 2 * 100000000 + 1; ++i) {
        sort(dists[i].begin(), dists[i].end(), comp);
    }

    // Answer each query
    for(int i = 0; i < q; ++i) {
        int bi = b[i][0];
        cout << dists[bi][bi].first << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}