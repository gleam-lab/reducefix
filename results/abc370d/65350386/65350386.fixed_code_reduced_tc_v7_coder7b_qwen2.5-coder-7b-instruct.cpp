#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<deque<pair<int,int>>> tate(w),yoko(h);
    rep(i,h) rep(j,w) {
        tate[j].push_back({i,j});
        yoko[i].push_back({j,i});
    }

    while(q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if(!tate[c][0].first || tate[c][0].second != r){
            while(!tate[c].empty() && tate[c].front().first <= r){
                int i = tate[c].front().first;
                int j = tate[c].front().second;
                tate[c].pop_front();
                yoko[i].pop_back();
            }
            if(!tate[c].empty()){
                int i = tate[c].front().first;
                int j = tate[c].front().second;
                tate[c].pop_front();
                yoko[i].pop_back();
            }
        }else{
            tate[c].pop_front();
            yoko[r].pop_back();
        }

        if(!yoko[r][0].second || yoko[r][0].first != c){
            while(!yoko[r].empty() && yoko[r].front().second <= c){
                int i = yoko[r].front().first;
                int j = yoko[r].front().second;
                yoko[r].pop_front();
                tate[j].pop_back();
            }
            if(!yoko[r].empty()){
                int i = yoko[r].front().first;
                int j = yoko[r].front().second;
                yoko[r].pop_front();
                tate[j].pop_back();
            }
        }else{
            yoko[r].pop_front();
            tate[c].pop_back();
        }
    }

    int ans = 0;
    rep(i,w) {
        ans += tate[i].size();
    }
    cout << ans << "\n";

    return 0;
}