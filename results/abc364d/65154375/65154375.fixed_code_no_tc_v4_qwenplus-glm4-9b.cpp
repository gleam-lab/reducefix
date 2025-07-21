#include<bits/stdc++.h>
#include<array>
#define endl "\n"
using namespace std;

const int INF = 1e9 + 7;
const int N = 2e5 + 5;
int a[N];

int main() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = abs(x);
    }
    sort(a, a + n);  // Sort the absolute values of a_i in ascending order

    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        int index = upper_bound(a, a + n, abs(x)) - a - 1;  // Find the index of the k-th closest point
        if (index < n) {
            if (k == 1) {
                index = 0;
            }
            index -= (k - 1);
            if (index < 0) index = 0;
        }
        cout << a[index] << endl;  // Output the distance to the k-th closest point
    }
    
    return 0;
}