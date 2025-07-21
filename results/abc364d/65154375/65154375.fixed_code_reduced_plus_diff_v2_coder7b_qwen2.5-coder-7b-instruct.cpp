#include <bits/stdc++.h>

using namespace std;

vector<int> A;
vector<pair<int,int>> queries;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        A.push_back(ai);
    }

    for(int i = 0; i < q; ++i) {
        int bi, ki; cin >> bi >> ki;
        queries.push_back({bi, ki});
    }

    sort(A.begin(), A.end());

    for(auto& [bi, ki]: queries) {
        auto it = lower_bound(A.begin(), A.end(), bi);
        int dist = min(abs(bi - *it), abs(bi - *(--it)));
        ans.push_back(dist * dist);
    }

    for(auto a: ans) cout << a << '\n';

    return 0;
}