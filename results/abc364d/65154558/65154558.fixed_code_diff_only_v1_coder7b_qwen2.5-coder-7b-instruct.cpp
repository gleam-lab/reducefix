#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
vector<int> a[MAXN], b;

void solve(void) {
    int n, q; cin >> n >> q;
    
    // Store coordinates of points A_i
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x].push_back(i + 1);
    }

    // Store coordinates of points B_j and their corresponding k_j values
    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        b.push_back(x * q + k); // Unique identifier to sort by distance
    }

    // Sort points B_j based on their distances
    sort(b.begin(), b.end());

    // Process each point B_j
    for(auto it = b.begin(); it != b.end(); ++it) {
        int x = *it / q, k = *it % q; // Extract original x and k values
        if(k == 1) {
            cout << a[x].front() << endl; // Closest point is the first one
        } else {
            auto pos = lower_bound(a[x].begin(), a[x].end(), k); // Find position of k_th closest point
            if(pos != a[x].end()) {
                cout << *pos << endl;
            } else {
                cout << a[x].back() << endl; // If k exceeds the size, the farthest point is the last one
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}