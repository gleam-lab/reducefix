#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,a[1003],b[1003];
vector<bool>row(1005),col(1005),diag1(2005),diag2(2005);

int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%lld%lld",&a[i],&b[i]);
        row[a[i]] = col[b[i]] = diag1[a[i] + b[i]] = diag2[a[i] - b[i] + 1000] = true;
    }
    ll ans = (n - count(row.begin(), row.end(), false)) * (n - count(col.begin(), col.end(), false));
    for(int i=1;i<=n;++i){
        if(!row[i]){
            for(int j=1;j<=n;++j){
                if(!col[j] && !diag1[i + j] && !diag2[i - j + 1000])
                    ++ans;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}