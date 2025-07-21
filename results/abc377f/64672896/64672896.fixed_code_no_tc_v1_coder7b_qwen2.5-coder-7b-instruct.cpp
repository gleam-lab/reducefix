#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> pieces;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    i64 count = 0;

    for (i64 i = 1; i <= N; i++) {
        unordered_set<i64> cols, diags1, diags2;
        
        for (i64 j = 1; j <= N; j++) {
            auto it = pieces.find({i, j});
            
            if (it != pieces.end()) {
                cols.insert(j);
                diags1.insert(i + j);
                diags2.insert(i - j);
            } else {
                bool valid = true;
                if (cols.empty() && diags1.empty() && diags2.empty())
                    valid = false;
                
                for (auto col : cols)
                    if (col == j || abs(col - j) <= 1)
                        valid = false;
                
                for (auto diag1 : diags1)
                    if (diag1 == i + j || abs(diag1 - (i + j)) <= 1)
                        valid = false;
                
                for (auto diag2 : diags2)
                    if (diag2 == i - j || abs(diag2 - (i - j)) <= 1)
                        valid = false;
                
                if (valid)
                    count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}