#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> a[MAXN], b;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x].push_back(i);
    }
    for(int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y;
        b.push_back(y);
        for(auto j : a[x]) pq.emplace(j, abs(j - x));
    }
    for(int i = 0; i < q; ++i) {
        int k = b[i];
        while(pq.top().first != a[b[i]][k - 1]) pq.pop();
        auto [j, dist] = pq.top();
        cout << dist << '\n';
    }
    return 0;
}