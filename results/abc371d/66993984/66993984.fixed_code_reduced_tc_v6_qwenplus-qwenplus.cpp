#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005];
long long p[200005];
map<int, long long> sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    cin >> q;
    while(q--){
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - x;
        int d = upper_bound(x + 1, x + n + 1, R) - x;
        cout << sum[d-1] - sum[c-1] << '\n';
    }
}