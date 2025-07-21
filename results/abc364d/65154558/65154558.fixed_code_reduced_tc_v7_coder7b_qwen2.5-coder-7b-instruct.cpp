#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lowbit(x) (x & (-x))

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

struct Node {
    int sum, lazy;
};

Node segTree[MAXN * 4];

void pushDown(int node, int left, int right) {
    if (segTree[node].lazy == 0) return;
    int mid = (left + right) / 2;
    segTree[node * 2].sum += segTree[node].lazy * (mid - left + 1);
    segTree[node * 2 + 1].sum += segTree[node].lazy * (right - mid);
    
    segTree[node * 2].lazy += segTree[node].lazy;
    segTree[node * 2 + 1].lazy += segTree[node].lazy;
    
    segTree[node].lazy = 0;
}

void updateRange(int node, int left, int right, int start, int end, int val) {
    if (start <= left && right <= end) {
        segTree[node].sum += val * (right - left + 1);
        segTree[node].lazy += val;
        return;
    }
    
    pushDown(node, left, right);
    
    int mid = (left + right) / 2;
    if (start <= mid) updateRange(node * 2, left, mid, start, end, val);
    if (end > mid) updateRange(node * 2 + 1, mid + 1, right, start, end, val);
    
    segTree[node].sum = segTree[node * 2].sum + segTree[node * 2 + 1].sum;
}

int queryRange(int node, int left, int right, int pos) {
    if (left == right) return segTree[node].sum;
    
    pushDown(node, left, right);
    
    int mid = (left + right) / 2;
    if (pos <= mid) return queryRange(node * 2, left, mid, pos);
    else return queryRange(node * 2 + 1, mid + 1, right, pos);
}

void buildSegmentTree(int node, int left, int right, vector<int>& arr) {
    if (left == right) {
        segTree[node].sum = arr[left];
        return;
    }
    
    int mid = (left + right) / 2;
    buildSegmentTree(node * 2, left, mid, arr);
    buildSegmentTree(node * 2 + 1, mid + 1, right, arr);
    
    segTree[node].sum = segTree[node * 2].sum + segTree[node * 2 + 1].sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, q; cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    vector<int> rank(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        if (!mp.count(a[i])) {
            mp[a[i]] = mp.size() + 1;
        }
        rank[i] = mp[a[i]];
    }
    
    buildSegmentTree(1, 1, n, rank);
    
    for (int i = 0; i < q; ++i) {
        int b, k; cin >> b >> k;
        --k; // Adjusting for zero-based indexing
        
        int idx = lower_bound(a.begin(), a.end(), b) - a.begin() + 1;
        
        updateRange(1, 1, n, idx, idx, 1);
        int result = queryRange(1, 1, n, k + 1);
        updateRange(1, 1, n, idx, idx, -1);
        
        cout << a[result - 1] - b << endl;
    }
    
    return 0;
}