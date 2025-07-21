#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq[200005];
int fa[200005];
int n,q;

void init() {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
        while(!pq[i].empty()) pq[i].pop();
        pq[i].push(-1); // Initialize with -1 to handle case when k > number of connections
    }
}

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) {
        if(pq[y].size() > pq[x].size()) swap(x, y);
        while(!pq[y].empty()) {
            pq[x].push(pq[y].top());
            pq[y].pop();
        }
        fa[y] = x;
    }
}

int getKthLargest(int x, int k) {
    x = find(x);
    if(k > pq[x].size() || pq[x].top() == -1) return -1;
    priority_queue<int> temp;
    for(int i = 0; i < k; ++i) {
        temp.push(pq[x].top());
        pq[x].pop();
    }
    int res = temp.top();
    while(!temp.empty()) {
        pq[x].push(temp.top());
        temp.pop();
    }
    return res;
}

int main() {
    cin >> n >> q;
    init();
    for(int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) merge(u, v);
        else cout << getKthLargest(v, k) << endl;
    }
    return 0;
}