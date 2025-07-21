#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<pair<long long, long long>> positions(m);
    for(long long i = 0; i < m; ++i) {
        cin >> positions[i].first >> positions[i].second;
    }
    
    // Calculate the number of cells that cannot be attacked
    long long non_attacked_cells = n*n;
    
    // Remove cells in the same row as any piece
    non_attacked_cells -= m;
    
    // Remove cells in the same column as any piece
    non_attacked_cells -= m;
    
    // Remove cells in the same diagonal as any piece
    long long diag_length = 2*n-1;
    vector<bool> diag(diag_length, false);
    for(auto& pos : positions) {
        diag[pos.first+pos.second-1] = true;
        diag[n-1+(pos.first-pos.second)] = true;
    }
    for(bool occupied : diag) {
        if(occupied) --non_attacked_cells;
    }
    
    cout << non_attacked_cells << endl;
    
    return 0;
}