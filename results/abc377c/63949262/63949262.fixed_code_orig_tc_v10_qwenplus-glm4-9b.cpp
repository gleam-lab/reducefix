#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<int, int>> occupied;
    for (long long i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        
        // Check if the piece can capture any other pieces
        if (a + 2 <= N && b + 1 <= N) occupied.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) occupied.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) occupied.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) occupied.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) occupied.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) occupied.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) occupied.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) occupied.insert({a + 2, b - 1});
    }
    
    // Calculate the number of empty cells
    long long empty_cells = N * N - occupied.size();
    cout << empty_cells << endl;
    
    return 0;
}