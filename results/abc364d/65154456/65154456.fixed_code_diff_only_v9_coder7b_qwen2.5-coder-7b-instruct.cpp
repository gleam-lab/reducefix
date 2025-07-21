#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;
vector<ll> a(MAXN * 2), b(MAXN * 2);

int main() {
    int n, q;
    cin >> n >> q;
    
    // Read the coordinates of points A_i
    for(int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        a[ai + MAXN]++;
    }

    // Calculate prefix sums for array 'a'
    for(int i = 1; i <= 2 * MAXN; i++) {
        a[i] += a[i - 1];
    }

    // Process each query for points B_j
    for(int i = 1; i <= q; i++) {
        int bj, kj;
        cin >> bj >> kj;
        
        // Find the k_j-th smallest distance
        int l = 0, r = 2 * MAXN;
        while(l < r) {
            int m = (l + r) / 2;
            if(a[m + MAXN] - a[bj + m - MAXN] >= kj) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        // Output the result
        cout << l - bj << endl;
    }

    return 0;
}