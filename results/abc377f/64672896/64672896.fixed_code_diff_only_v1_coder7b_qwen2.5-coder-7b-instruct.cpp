#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    vector<array<int,2>> pieces(M);
    set<pair<int, int>> occupied;
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        occupied.insert({a, b});
    }

    auto valid_position = [&](int x, int y) -> bool{
        if(x <= 0 || x > N || y <= 0 || y > N) return false;
        if(occupied.find({x, y}) != occupied.end()) return false;
        
        // Check all directions
        for(int dx = -1; dx <= 1; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
                if(dx == 0 && dy == 0) continue;
                int cx = x, cy = y;
                while(true){
                    cx += dx;
                    cy += dy;
                    if(cx <= 0 || cx > N || cy <= 0 || cy > N) break;
                    if(occupied.find({cx, cy}) != occupied.end()){
                        if((abs(dx) + abs(dy)) == 1) return true;
                        else break;
                    }
                }
            }
        }
        return false;
    };

    i64 count = 0;
    for(i64 x = 1; x <= N; ++x){
        for(i64 y = 1; y <= N; ++y){
            if(valid_position(x, y)) count++;
        }
    }

    cout << count << '\n';

    return 0;
}