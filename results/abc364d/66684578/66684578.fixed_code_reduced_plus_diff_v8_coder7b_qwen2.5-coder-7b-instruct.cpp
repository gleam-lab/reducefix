#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    
    vi a(n);
    rep(i, n) cin >> a[i];
    
    vi b(q);
    vi k(q);
    rep(i, q) cin >> b[i] >> k[i];

    // Sort points A and B
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Create prefix sum arrays
    vl prefix_a(n + 1, 0);
    rep(i, n) prefix_a[i + 1] = prefix_a[i] + (a[i] <= b[0]);

    for (int j = 1; j < q; ++j) {
        prefix_a[j] += prefix_a[j - 1];
    }

    // Answer each query
    for (int j = 0; j < q; ++j) {
        int target_k = k[j] - 1; // Convert to zero-based index
        auto it = upper_bound(b.begin(), b.end(), b[j]);
        int pos = it - b.begin();
        
        if (pos == 0) {
            cout << prefix_a[n - 1] << endl;
        } else {
            int lower_count = prefix_a[pos - 1];
            int remaining = target_k - lower_count;
            
            if (remaining >= n - pos) {
                cout << prefix_a[n - 1] - prefix_a[pos - 1] << endl;
            } else {
                int idx = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
                int rank = idx + remaining;
                
                if (rank < n && abs(a[rank] - b[j]) < abs(a[idx] - b[j])) {
                    cout << prefix_a[n - 1] - prefix_a[pos - 1] << endl;
                } else {
                    cout << prefix_a[pos] - prefix_a[pos - 1] << endl;
                }
            }
        }
    }

    return 0;
}