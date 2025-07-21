#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    vector<pair<i64, i64>> pieces(M);
    set<pair<i64, i64>> positions;

    for(i64 i = 0; i < M; ++i){
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        positions.insert({a, b});
    }

    unordered_set<i64> sum_lines, diff_lines, row_lines, col_lines;

    for(auto &piece : pieces){
        sum_lines.insert(piece.first + piece.second);
        diff_lines.insert(piece.first - piece.second);
        row_lines.insert(piece.first);
        col_lines.insert(piece.second);
    }

    i64 count = 0;

    for(i64 i = 1; i <= N; ++i){
        for(i64 j = 1; j <= N; ++j){
            if(positions.find({i, j}) != positions.end())
                continue;

            bool can_place = true;

            if(row_lines.find(i) != row_lines.end())
                can_place = false;
            
            if(col_lines.find(j) != col_lines.end())
                can_place = false;

            if(sum_lines.find(i + j) != sum_lines.end())
                can_place = false;

            if(diff_lines.find(i - j) != diff_lines.end())
                can_place = false;

            if(can_place)
                ++count;
        }
    }

    cout << count << '\n';

    return 0;
}