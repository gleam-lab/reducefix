#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vl a(n), b(q);
    vi k(q);
    
    rep(i, n)
        cin >> a[i];
    
    rep(j, q)
        cin >> b[j] >> k[j];

    sort(a.begin(), a.end());

    rep(j, q) {
        int target_index = k[j] - 1;
        int pos = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
        
        if (pos == 0) {
            cout << abs(a[0] - b[j]) << '\n';
        } else if (pos == n) {
            cout << abs(a[n - 1] - b[j]) << '\n';
        } else {
            int left_dist = abs(a[pos - 1] - b[j]);
            int right_dist = abs(a[pos] - b[j]);
            
            if (left_dist <= right_dist) {
                cout << left_dist << '\n';
            } else {
                cout << right_dist << '\n';
            }
        }
    }

    return 0;
}