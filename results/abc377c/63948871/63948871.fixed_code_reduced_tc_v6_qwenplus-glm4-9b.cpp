#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX_N 1000000000

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    
    set<pair<int, int>> occupied;
    set<pair<int, int>> occupied_capture;

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        occupied.insert({pieces[i].first, pieces[i].second});
        
        int x = pieces[i].first;
        int y = pieces[i].second;
        
        // Capture positions
        occupied_capture.insert({x + 2, y + 1});
        occupied_capture.insert({x + 1, y + 2});
        occupied_capture.insert({x - 1, y + 2});
        occupied_capture.insert({x - 2, y + 1});
        occupied_capture.insert({x - 2, y - 1});
        occupied_capture.insert({x - 1, y - 2});
        occupied_capture.insert({x + 1, y - 2});
        occupied_capture.insert({x + 2, y - 1});
    }
    
    // Calculate the number of valid cells
    long long count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (occupied.find({i, j}) == occupied.end() && occupied_capture.find({i, j}) == occupied_capture.end()) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}