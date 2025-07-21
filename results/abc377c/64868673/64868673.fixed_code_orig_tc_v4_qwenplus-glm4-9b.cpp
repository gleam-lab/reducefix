#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> pieces(m);
    set<pair<long long, long long>> capturedSpots;
    
    // Read the positions of the existing pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        
        // Check the spots that can be captured
        long long dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        long long dy[] = {1, -1, 1, -1, 2, -2, -2, 2};
        
        for (long long j = 0; j < 8; ++j) {
            long long nx = pieces[i].first + dx[j];
            long long ny = pieces[i].second + dy[j];
            
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                capturedSpots.insert({nx, ny});
            }
        }
    }
    
    // Calculate the number of available spots
    long long totalSpots = n * n;
    long long capturedCount = capturedSpots.size();
    long long availableSpots = totalSpots - capturedCount;
    
    // Output the result
    cout << availableSpots << endl;
    
    return 0;
}