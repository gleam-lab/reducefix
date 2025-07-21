#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int ll;

const int N = 2e5 + 9;

vector<int> adj[N];
set<int> vertices[N];

void findKthLargest(int v, int k, vector<int>& ans) {
    if (vertices[v].size() < k) {
        ans.clear();
        return;
    }

    auto it = vertices[v].end();
    advance(it, -k);
    ans.push_back(*it);
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    vertices[u].insert(v);
    vertices[v].insert(u);
}

int main() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if (type == 1) {
            addEdge(u, v);
        } else {
            vector<int> ans;
            findKthLargest(v, k, ans);
            for (int num : ans) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}