#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<pair<int, int>> occupied;
    for (const auto& p : pieces) {
        occupied.insert(p);
        // Calculate the set of positions that this piece can capture
        // and insert them into the occupied set
    }
    
    int total_positions = N * N;
    int occupied_positions = occupied.size();
    int valid_positions = total_positions - occupied_positions;
    
    cout << valid_positions << endl;
    
    return 0;
}