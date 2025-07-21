#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 200000

vector<int> parent(MAX_N + 1);
vector<vector<int>> group(MAX_N + 1);
vector<vector<int>> component;

int find_set(int a) {
    if (parent[a] == a) return a;
    parent[a] = find_set(parent[a]);
    return parent[a];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        merge(component[a], component[b], back_inserter(component[a]));
        sort(component[a].rbegin(), component[a].rend());
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        group[i].push_back(i);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            // Union the sets containing a and b
            union_sets(a, b);
        } else if (t == 2) {
            a = find_set(a);
            if (find_set(b) != a) {
                cout << -1 << endl;
            } else {
                cout << component[a][b - 1] << endl;
            }
        }
    }

    return 0;
}