#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for(int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    // Sort pieces based on their positions
    sort(pieces.begin(), pieces.end());
    
    // Initialize variables to keep track of available positions
    int rowCount[N+1] = {}, colCount[N+1] = {};
    int diagonal1[N+1] = {}, diagonal2[N+1] = {};
    
    // Count occupied positions
    for(auto& p : pieces) {
        rowCount[p.first]++;
        colCount[p.second]++;
        diagonal1[p.first + p.second]++;
        diagonal2[p.first - p.second]++;
    }
    
    // Calculate available positions
    int result = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(rowCount[i] == 0 && colCount[j] == 0 && diagonal1[i+j] == 0 && diagonal2[i-j] == 0) {
                result++;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}