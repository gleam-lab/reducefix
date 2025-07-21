#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5+7;

vector<int> row[N], col[N];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int h, w, q; cin >> h >> w >> q;
    
    while(q--){
        int r, c; cin >> r >> c; 
        r--; c--;

        if(row[r].empty()){
            row[r].push_back(c);
            col[c].push_back(r);
        } else {
            int last_c = row[r].back();
            int last_r = col[c].back();

            if(last_c == c){
                row[r].push_back(c);
            } else if(last_r == r){
                col[c].push_back(r);
            }
        }
    }

    int ans = h*w;
    for(int i=0;i<h;i++){
        ans -= row[i].size();
    }
    for(int i=0;i<w;i++){
        ans -= col[i].size();
    }
    ans += h+w;
    cout << ans/2 << endl;
    
    return 0;
}