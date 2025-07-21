#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> rows(h + 2);
    vector<set<int>> cols(w + 2);
    
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        
        if (!rows[r].count(c)) {
            // Place a bomb
            for (auto& s : rows) s.erase(c);
            for (auto& s : cols) s.erase(r);
        } else {
            // Destroy the wall at (r, c)
            rows[r].erase(c);
            cols[c].erase(r);
        }
    }
    
    int remaining_walls = 0;
    for (const auto& s : rows) remaining_walls += s.size();
    for (const auto& s : cols) remaining_walls += s.size();
    
    cout << remaining_walls / 2 << endl;
    
    return 0;
}