#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    for(long long i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        occupied.insert(make_pair(a, b));
    }

    long long count = 0;
    for(long long i = 1; i <= N; i++) {
        for(long long j = 1; j <= N; j++) {
            if(occupied.find(make_pair(i, j)) == occupied.end()) {
                // Check all possible moves
                vector<pair<long long, long long>> moves = {{i+2, j+1}, {i+1, j+2}, {i-1, j+2}, {i-2, j+1},
                                                         {i-2, j-1}, {i-1, j-2}, {i+1, j-2}, {i+2, j-1}};
                bool safe = true;
                for(auto move : moves) {
                    if(move.first >= 1 && move.first <= N && move.second >= 1 && move.second <= N &&
                       occupied.find(move) != occupied.end()) {
                        safe = false;
                        break;
                    }
                }
                if(safe) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}