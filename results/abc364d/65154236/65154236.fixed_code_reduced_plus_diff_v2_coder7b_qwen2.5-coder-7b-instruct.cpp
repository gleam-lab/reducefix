#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long ll;

vector<ll> A, B;

bool cmp(ll a, ll b) {
    return abs(a) < abs(b);
}

int find_closest_distance(vector<ll>& points, ll target, int k) {
    sort(all(points));
    int n = points.size();
    int left = 0, right = n - 1;
    while(left < right) {
        int mid = (left + right) >> 1;
        if(abs(points[mid]) >= abs(target - points[k])) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return points[left];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    A.resize(n);
    B.resize(q);
    
    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < q; ++i) {
        cin >> B[i] >> A[i]; // Read both b_i and k_j
        A.push_back(B[i]); // Add b_i to A for sorting
    }

    sort(A.begin(), A.end());
    A.erase(unique(all(A)), A.end()); // Remove duplicates

    for(int i = 0; i < q; ++i) {
        int idx = lower_bound(all(A), B[i]) - A.begin(); // Find index of b_i in sorted array
        int k = A.size() - idx; // Calculate k_j
        int dist = find_closest_distance(A, B[i], k); // Find the k-th closest distance
        cout << abs(dist - B[i]) << endl; // Print the result
    }

    return 0;
}