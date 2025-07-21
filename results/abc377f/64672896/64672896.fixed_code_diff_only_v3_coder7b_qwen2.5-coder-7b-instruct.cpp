#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    vector<array<int, 2>> pieces(M);
    for(int i = 0; i < M; ++i){
        cin >> pieces[i][0] >> pieces[i][1];
    }

    set<pair<int, int>> occupied;
    for(auto &piece : pieces){
        occupied.insert({piece[0], piece[1]});
        occupied.insert({piece[0] + piece[1], piece[0] - piece[1]});
        occupied.insert({piece[0], piece[1] + N});
        occupied.insert({piece[0], piece[1] - N});
    }

    i64 count = 0;
    for(i64 i = 1; i <= N; ++i){
        for(i64 j = 1; j <= N; ++j){
            if(!occupied.count({i, j}) && !occupied.count({i + j, i - j})){
                count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}