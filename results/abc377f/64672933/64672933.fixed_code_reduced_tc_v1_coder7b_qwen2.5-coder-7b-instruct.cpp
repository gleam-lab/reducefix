#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    i64 N, M;
    cin >> N >> M;
    
    set<pair<i64, i64>> pieces;
    vector<i64> diag1, diag2, row, col;
    unordered_map<i64, int> count_diag1, count_diag2, count_row, count_col;

    for(int i = 0; i < M; ++i){
        i64 x, y;
        cin >> x >> y;
        pieces.insert({x, y});
        diag1.push_back(x+y);
        diag2.push_back(x-y);
        row.push_back(x);
        col.push_back(y);

        count_diag1[x+y]++;
        count_diag2[x-y]++;
        count_row[x]++;
        count_col[y]++;
    }

    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    auto unique_diag1 = unique(diag1.begin(), diag1.end());
    auto unique_diag2 = unique(diag2.begin(), diag2.end());
    auto unique_row = unique(row.begin(), row.end());
    auto unique_col = unique(col.begin(), col.end());

    diag1.resize(unique_diag1 - diag1.begin());
    diag2.resize(unique_diag2 - diag2.begin());
    row.resize(unique_row - row.begin());
    col.resize(unique_col - col.begin());

    i64 ans = N*N;

    for(auto [x, y] : pieces){
        --ans;
        if(count_row[x] == 1 && count_col[y] == 1){
            continue;
        }
        if(count_diag1[x+y] == 1 && count_diag2[x-y] == 1){
            continue;
        }
        bool valid = true;
        for(i64 dx = -1; dx <= 1; ++dx){
            for(i64 dy = -1; dy <= 1; ++dy){
                if(dx != 0 || dy != 0){
                    i64 nx = x + dx, ny = y + dy;
                    if(nx > 0 && nx <= N && ny > 0 && ny <= N && !pieces.count({nx, ny})){
                        valid = false;
                        break;
                    }
                }
            }
            if(!valid) break;
        }
        if(valid) ++ans;
    }

    cout << ans << '\n';

    return 0;
}