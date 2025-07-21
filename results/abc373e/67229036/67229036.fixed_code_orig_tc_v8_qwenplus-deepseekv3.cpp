#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if(m == n) {
        for(int i = 0; i < n; ++i) {
            cout << "0 ";
        }
        cout << endl;
        return 0;
    }
    
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end(), greater<int>());
    int threshold = sorted_a[m - 1];
    
    vector<int> res(n);
    for(int i = 0; i < n; ++i) {
        if(a[i] >= threshold) {
            res[i] = 0;
        } else {
            int needed = threshold - a[i];
            if(k >= needed) {
                res[i] = needed;
                k -= needed;
            } else {
                res[i] = -1;
            }
        }
    }
    
    for(int x : res) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}