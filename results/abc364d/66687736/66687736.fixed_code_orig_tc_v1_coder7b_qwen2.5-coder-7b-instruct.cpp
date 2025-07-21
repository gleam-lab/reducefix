#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
int A[MAX], B[MAX];

struct Query {
    int index, x, k;
};

bool cmp(Query a, Query b) {
    return a.x < b.x;
}

vector<int> solve(vector<Query> queries, int n, int q) {
    sort(queries.begin(), queries.end(), cmp);
    
    vector<int> result(q);
    int i = 0;
    multiset<int> dist;
    for (int j = 0; j < q; ++j) {
        while (i < n && A[i] <= queries[j].x) {
            dist.insert(abs(A[i] - queries[j].x));
            i++;
        }
        
        auto it = next(dist.begin(), queries[j].k - 1);
        result[queries[j].index] = *it;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    vector<Query> queries;
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries.push_back({i, b, k});
    }
    
    vector<int> result = solve(queries, n, q);
    
    for (int res : result) {
        cout << res << '\n';
    }
    
    return 0;
}