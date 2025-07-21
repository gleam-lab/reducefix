#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

vector<int> parent(N + 1);
vector<int> size(N + 1);
vector<vector<int>> adjList(N + 1);
vector<int> vertexOrder;

int findLeader(int v) {
    if (parent[v] == v)
        return v;
    parent[v] = findLeader(parent[v]);
    return parent[v];
}

void unionVertices(int a, int b) {
    int rootA = findLeader(a);
    int rootB = findLeader(b);
    if (rootA == rootB)
        return;
    if (size[rootA] < size[rootB]) {
        parent[rootA] = rootB;
        size[rootB] += size[rootA];
    } else {
        parent[rootB] = rootA;
        size[rootA] += size[rootB];
    }
    mergeSort(vertexOrder);
}

void mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    mergeSort(left);
    mergeSort(right);
    merge(arr.begin(), arr.end(), left.begin(), left.end(), right.begin(), right.end());
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            unionVertices(u, v);
        } else {
            int rootV = findLeader(v);
            int index = upper_bound(vertexOrder.begin(), vertexOrder.end(), v) - vertexOrder.begin() - 1;
            if (k > size[rootV])
                cout << "-1\n";
            else
                cout << vertexOrder[index - k + 1] << "\n";
        }
    }
    return 0;
}