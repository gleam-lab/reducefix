#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n;
    vector<int>a(n+1,0),b(n+1,0),c(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        c[i]=c[i-1]+b[i];
    }
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        if(l == 1){
            cout << c[r] << endl;
        }else{
            cout << c[r] - c[l-1] << endl;
        }
    }
    return 0;
}