#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAXN 1000000007

set<pair<int, int>> occupied;

bool can_capture(int x, int y) {
    return (x+2 <= MAXN && y+1 <= MAXN) || 
           (x+1 <= MAXN && y+2 <= MAXN) || 
           (x-1 <= MAXN && y+2 <= MAXN) || 
           (x-2 <= MAXN && y+1 <= MAXN) || 
           (x-2 <= MAXN && y-1 >= 1) || 
           (x-1 <= MAXN && y-2 >= 1) || 
           (x+1 <= MAXN && y-2 >= 1) || 
           (x+2 <= MAXN && y-1 >= 1);
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        occupied.insert({x, y}); // Add the original piece
        if (can_capture(x, y)) {
            // Add all cells that can capture this piece
            if (x+2 <= N && y+1 <= N) occupied.insert({x+2, y+1});
            if (x+1 <= N && y+2 <= N) occupied.insert({x+1, y+2});
            if (x-1 >= 1 && y+2 <= N) occupied.insert({x-1, y+2});
            if (x-2 >= 1 && y+1 <= N) occupied.insert({x-2, y+1});
            if (x-2 >= 1 && y-1 >= 1) occupied.insert({x-2, y-1});
            if (x-1 >= 1 && y-2 >= 1) occupied.insert({x-1, y-2});
            if (x+1 <= N && y-2 >= 1) occupied.insert({x+1, y-2});
            if (x+2 <= N && y-1 >= 1) occupied.insert({x+2, y-1});
        }
    }

    cout << N*N - occupied.size() << endl; // Total cells minus the number of occupied cells
    return 0;
}