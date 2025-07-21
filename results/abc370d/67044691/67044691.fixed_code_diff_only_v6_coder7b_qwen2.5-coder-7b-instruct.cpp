#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

int main(){
    ll h,w,q;cin >> h >> w >> q;
    vl row(h, w), col(w, h);

    rep(i,q){
        ll r,c;cin >> r >> c;
        r--;c--;

        if(row[r][c] == 1){ // Wall found at position (r, c)
            row[r][c] = 0; // Remove the wall
            continue;
        }

        // Search upwards
        for(int i=r-1; i>=0; i--){
            if(row[i][c] == 1){
                row[i][c] = 0; // Remove the wall
                break;
            }
        }

        // Search downwards
        for(int i=r+1; i<h; i++){
            if(row[i][c] == 1){
                row[i][c] = 0; // Remove the wall
                break;
            }
        }

        // Search leftwards
        for(int j=c-1; j>=0; j--){
            if(col[j][r] == 1){
                col[j][r] = 0; // Remove the wall
                break;
            }
        }

        // Search rightwards
        for(int j=c+1; j<w; j++){
            if(col[j][r] == 1){
                col[j][r] = 0; // Remove the wall
                break;
            }
        }
    }

    ll ans = 0;
    rep(i,h) rep(j,w) ans += (row[i][j] + col[j][i]);

    cout << ans << endl;
}