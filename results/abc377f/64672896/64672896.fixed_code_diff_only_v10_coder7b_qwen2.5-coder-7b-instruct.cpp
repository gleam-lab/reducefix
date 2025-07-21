#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> pieces;
    for(int i=0; i<M; ++i){
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    i64 ans = 0;
    for(i64 i=1; i<=N; ++i){
        for(i64 j=1; j<=N; ++j){
            bool safe = true;
            for(i64 a=i+1; a<=N; ++a){
                if(pieces.find({a, j}) != pieces.end()){
                    safe = false;
                    break;
                }
            }
            if(!safe) continue;

            safe = true;
            for(i64 a=i-1; a>=1; --a){
                if(pieces.find({a, j}) != pieces.end()){
                    safe = false;
                    break;
                }
            }
            if(!safe) continue;

            safe = true;
            for(i64 b=j+1; b<=N; ++b){
                if(pieces.find({i, b}) != pieces.end()){
                    safe = false;
                    break;
                }
            }
            if(!safe) continue;

            safe = true;
            for(i64 b=j-1; b>=1; --b){
                if(pieces.find({i, b}) != pieces.end()){
                    safe = false;
                    break;
                }
            }
            if(!safe) continue;

            safe = true;
            for(i64 a=i+1, b=j+1; a<=N && b<=N; ++a, ++b){
                if(pieces.find({a, b}) != pieces.end()){
                    safe = false;
                    break;
                }
            }
            if(!safe) continue;

            safe = true;
            for(i64 a=i-1, b=j-1; a>=1 && b>=1; --a, --b){
                if(pieces.find({a, b}) != pieces.end()){
                    safe = false;
                    break;
                }
            }
            if(!safe) continue;

            safe = true;
            for(i64 a=i+1, b=j-1; a<=N && b>=1; ++a, --b){
                if(pieces.find({a, b}) != pieces.end()){
                    safe = false;
                    break;
                }
            }
            if(!safe) continue;

            safe = true;
            for(i64 a=i-1, b=j+1; a>=1 && b<=N; --a, ++b){
                if(pieces.find({a, b}) != pieces.end()){
                    safe = false;
                    break;
                }
            }
            if(safe) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}