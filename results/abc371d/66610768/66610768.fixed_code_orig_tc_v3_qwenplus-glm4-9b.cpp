#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;
int main() {
	int n, m;
	cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> b[i];
        c[i] = c[i-1] + b[i];
    }
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin(), a.end(), l);
        auto r_j = upper_bound(a.begin(), a.end(), r);
        int i = distance(a.begin(), l_i) + 1; // Adjust indexing by adding 1
        int j = distance(a.begin(), r_j) - 1; // Adjust indexing by subtracting 1
        if(r >= a[n]) {
            cout << c[n] - (i > 1 ? c[i-1] : 0) << endl;
        } else {
            cout << c[j] - (i > 1 ? c[i-1] : 0) << endl;
        }
    }
    return 0;
}