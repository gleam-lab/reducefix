#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (long long i=0;i < (n); i++)
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<long long> h(n);
    long long ans=0;

    // Calculate total damage based on each enemy's health
    rep(i,n){
        cin >> h[i];
        long long temp1 = h[i] / 3;
        long long temp2 = h[i] % 3;
        
        // Add damage considering whether the turn number is divisible by 3
        ans += temp1 * 3 + temp2;
        if(h[i] % 3 == 0 && (ans - 1) % 3 == 0){
            ans--;
        }
    }

    cout << ans << endl;
}