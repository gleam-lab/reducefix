#include<bits/stdc++.h>
using namespace std;

vector<int> a;

bool check(vector<int>& distances, int k) {
    sort(distances.begin(), distances.end());
    return distances[k-1];
}

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<vector<int>> queries(q, vector<int>(2));
    for(int i = 0; i < q; i++) cin >> queries[i][0] >> queries[i][1];
    
    for(auto& query : queries) {
        int b = query[0], k = query[1];
        vector<int> distances;
        for(int i = 0; i < n; i++) {
            distances.push_back(abs(a[i] - b));
        }
        if(k == 1) cout << *min_element(distances.begin(), distances.end()) << '\n';
        else if(k == n) cout << *max_element(distances.begin(), distances.end()) << '\n';
        else cout << check(distances, k) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}