#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 2e5 + 5;

vector<int> parent(N + 1);
vector<int> size(N + 1, 1);

// Find with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union by size
void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Initialize parent and size arrays
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        
        if (t == 1) {
            // Union operation
            union_sets(a, b);
        } else {
            // Find the representative and count the size of the set
            int root = find(b);
            int count = size[root];
            
            // Process the second type of query
            cout << (count < b ? -1 : count - b + 1) << '\n';
        }
    }

    return 0;
}