#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<vector<bool>> rowCaptured(N+1, vector<bool>(N+1, false));
    vector<vector<bool>> colCaptured(N+1, vector<bool>(N+1, false));
    vector<pair<long long, long long>> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }
    
    // Mark captured cells
    for (auto [a, b] : pieces) {
        rowCaptured[a][b] = true;
        colCaptured[b][a] = true;
        
        long long d1 = a + b;
        long long d2 = a - b;
        
        for (long long i = min(d1, N); i >= max(0LL, d1 - N + 1); --i) {
            rowCaptured[i][d1 - i] = colCaptured[d1 - i][i] = true;
        }
        
        for (long long i = min(d2, N); i >= max(0LL, d2 - N + 1); --i) {
            rowCaptured[i][d2 + i] = colCaptured[d2 + i][i] = true;
        }
    }
    
    // Count non-captured cells
    long long result = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            if (!rowCaptured[i][j] && !colCaptured[j][i]) {
                result++;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}