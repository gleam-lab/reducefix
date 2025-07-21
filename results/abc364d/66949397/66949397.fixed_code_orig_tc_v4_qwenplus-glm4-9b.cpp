#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int tree[MAX_N];

int query(int index) {
    int s = 0;
    for (int x = index; x > 0; x -= x & -x) {
        s = max(s, tree[x]);
    }
    return s;
}

void update(int index, int value) {
    for (int x = index; x < MAX_N; x += x & -x) {
        tree[x] = max(tree[x], value);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        int dist = abs(b - a[k - 1]);
        cout << dist << '\n';
    }
    
    return 0;
}