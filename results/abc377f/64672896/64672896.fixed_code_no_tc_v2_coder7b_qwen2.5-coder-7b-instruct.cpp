#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isValid(int N, int x, int y, set<pair<int, int>>& pieces){
    for(auto& [px, py]: pieces){
        if(x == px || y == py || x+y==px+py || x-y==px-py){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    set<pair<int, int>> pieces;
    for(int i=0; i<M; ++i){
        int x, y;
        cin >> x >> y;
        pieces.insert({x, y});
    }

    int result = 0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            if(isValid(N, i, j, pieces)){
                ++result;
            }
        }
    }

    cout << result << '\n';

    return 0;
}