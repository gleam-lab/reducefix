#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

// Binary Indexed Tree (Fenwick Tree) implementation
struct BIT {
    int size;
    ll tree[MAXN];

    void init(int sz) {
        size = sz;
        memset(tree, 0, (size + 2) * sizeof(ll));
    }

    // Add val to position idx
    void update(int idx, ll val) {
        while (idx <= size) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    // Query prefix sum up to idx
    ll query(int idx) {
        ll res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    // Find smallest idx such that prefix sum >= k
    int find_kth(int k) {
        int curr = 0, sum = 0;
        for (int i = 1 << 17; i >= 0; i--) {
            curr += (1 << i);
            if (curr >= size || sum + tree[curr] < k) continue;
            curr -= (1 << i);
            sum += tree[curr];
        }
        return curr + 1;
    }
} bit;

// Coordinate compression utilities
vector<ll> all_coords;
unordered_map<ll, int> coord_id;

int get_id(ll x) {
    return lower_bound(all_coords.begin(), all_coords.end(), x) - all_coords.begin() + 1;
}

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        all_coords.push_back(A[i]);
    }

    vector<pair<ll, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        all_coords.push_back(queries[i].first);
    }

    // For coordinate compression
    sort(all_coords.begin(), all_coords.end());
    all_coords.resize(unique(all_coords.begin(), all_coords.end()) - all_coords.begin());

    // Initialize BIT
    bit.init(all_coords.size() + 2);

    // Insert all A points into BIT
    for (ll a : A) {
        int id = get_id(a);
        bit.update(id, 1);
    }

    // Process each query
    for (auto [b, k] : queries) {
        int left = 0, right = 0;
        int b_id = get_id(b);
        
        // Current radius
        int radius = 0;
        
        // We perform exponential search to find an upper bound
        while (bit.query(get_id(b + radius)) - bit.query(get_id(b - radius - 1)) < k) {
            radius = radius == 0 ? 1 : radius * 2;
        }
        
        // Binary search to find the exact k-th smallest distance
        int low = 0, high = radius;
        while (low < high) {
            int mid = (low + high) / 2;
            int l = get_id(b - mid);
            int r = get_id(b + mid);
            if (bit.query(r) - bit.query(l - 1) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        // Now we know the distance is 'low', but need to find exact point
        // First pass: count how many points are within 'low'-1 distance
        int l_prev = get_id(b - (low - 1));
        int r_prev = get_id(b + (low - 1));
        int cnt_before = bit.query(r_prev) - bit.query(l_prev - 1);
        
        int remaining = k - cnt_before;
        
        // Second pass: find the k-th point within 'low' distance
        int l_curr = get_id(b - low);
        int r_curr = get_id(b + low);
        
        // Find the k-th point using binary search on the BIT
        int kth_id = bit.find_kth(bit.query(r_curr) - (remaining - 1));
        
        // Calculate the distance
        ll closest_val = all_coords[kth_id - 1];
        cout << abs(closest_val - b) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    
    return 0;
}