#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
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
        // Find first element >= l
        auto l_i = lower_bound(a.begin()+1, a.end(), l);
        // Find first element > r, then subtract 1 to get last element <= r
        auto r_i = upper_bound(a.begin()+1, a.end(), r);
        
        int left_pos = l_i - a.begin();
        int right_pos = r_i - a.begin() - 1;
        
        if(left_pos > right_pos) {
            cout << 0 << endl;
        } else {
            cout << c[right_pos] - c[left_pos-1] << endl;
        }
    }
    return 0;
}