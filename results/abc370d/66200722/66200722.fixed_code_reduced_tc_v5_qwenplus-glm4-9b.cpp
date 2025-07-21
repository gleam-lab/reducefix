#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 4e5 + 10;

int parent[MAX_SIZE];

int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    for (int i = 0; i < h * w; ++i) {
        parent[i] = i;
    }
    
    map<int, int> column[MAX_SIZE];
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (!column[c].count(r)) {
            column[c][r] = i;
            union_set(i, (h * w) + r);
            union_set(i, (h * w) + c);
        } else {
            int prev = column[c][r];
            union_set(i, prev);
            union_set(i, (h * w) + r);
            union_set(i, (h * w) + c);
        }
    }

    int remaining_walls = h * w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int p0 = find(i * w + j);
            int p1 = find((i + 1) * w + j);
            int p2 = find(i * w + (j + 1));
            int p3 = find((i + 1) * w + (j + 1));
            
            if (p0 == p1 || p0 == p2 || p0 == p3) {
                remaining_walls--;
            }
        }
    }
    
    cout << remaining_walls << endl;
}

int main() {
    solve();
    return 0;
}