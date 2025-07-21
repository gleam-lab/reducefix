#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        c[i] = b[i] + c[i-1];
    }
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        if (l > r) continue;  // Invalid range, skip it
        int left = lower_bound(a.begin() + 1, a.end(), l) - (a.begin() + 1);
        int right = upper_bound(a.begin() + 1, a.end(), r) - (a.begin() + 1);
        if (right == a.size() || left == 0) {
            cout << c[n] << endl;
        } else {
            cout << c[right - 1] - c[left - 1] << endl;
        }
    }
    return 0;
}