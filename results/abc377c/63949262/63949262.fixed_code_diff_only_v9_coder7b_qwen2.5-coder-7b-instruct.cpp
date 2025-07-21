#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

long long count_valid_positions(long long N, long long M, vector<pair<long long, long long>>& pieces) {
    unordered_set<long long> attacked_positions;

    for (const auto& piece : pieces) {
        long long x = piece.first, y = piece.second;
        
        // Check all possible knight moves
        if (x + 2 <= N && y + 1 <= N) attacked_positions.insert(((x + 2) * N) + (y + 1));
        if (x + 1 <= N && y + 2 <= N) attacked_positions.insert(((x + 1) * N) + (y + 2));
        if (x - 1 >= 1 && y + 2 <= N) attacked_positions.insert(((x - 1) * N) + (y + 2));
        if (x - 2 >= 1 && y + 1 <= N) attacked_positions.insert(((x - 2) * N) + (y + 1));
        if (x - 2 >= 1 && y - 1 >= 1) attacked_positions.insert(((x - 2) * N) + (y - 1));
        if (x - 1 >= 1 && y - 2 >= 1) attacked_positions.insert(((x - 1) * N) + (y - 2));
        if (x + 1 <= N && y - 2 >= 1) attacked_positions.insert(((x + 1) * N) + (y - 2));
        if (x + 2 <= N && y - 1 >= 1) attacked_positions.insert(((x + 2) * N) + (y - 1));
    }

    return N * N - attacked_positions.size();
}

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<pair<long long, long long>> pieces(M);
    for (auto& piece : pieces) {
        cin >> piece.first >> piece.second;
    }

    cout << count_valid_positions(N, M, pieces) << endl;
    return 0;
}