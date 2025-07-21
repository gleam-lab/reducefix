#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<int, int>> occupied;
    
    for (long long i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        
        // Check all possible positions the piece can capture
        if (a + 2 <= N && b + 1 <= N) occupied.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) occupied.insert({a + 1, b + 2});
        if (a - 1 <= N && b + 2 <= N) occupied.insert({a - 1, b + 2});
        if (a - 2 <= N && b + 1 <= N) occupied.insert({a - 2, b + 1});
        if (a - 2 <= N && b - 1 <= N) occupied.insert({a - 2, b - 1});
        if (a - 1 <= N && b - 2 <= N) occupied.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 <= N) occupied.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 <= N) occupied.insert({a + 2, b - 1});
    }
    
    long long total_empty_squares = N * N;
    long long count_occupied = occupied.size();
    long long count_free_squares = total_empty_squares - count_occupied;
    
    cout << count_free_squares << endl;
    
    return 0;
}