#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<pair<long long, long long>> pieces(M);
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }
    
    vector<long long> row capturedRows(N + 1, 0);
    vector<long long> col capturedCols(N + 1, 0);
    vector<long long> diag1(N + 1, 0); // i + j
    vector<long long> diag2(N + 1, 0); // i - j
    
    for (long long i = 0; i < M; ++i) {
        long long a = pieces[i].first;
        long long b = pieces[i].second;
        
        capturedRows[a]++;
        capturedCols[b]++;
        diag1[a + b]++;
        diag2[a - b]++;
    }
    
    long long totalEmpty = N * N;
    
    // Subtract rows, columns, diagonals, and intersections
    for (long long i = 1; i <= N; ++i) {
        totalEmpty -= capturedRows[i];
        totalEmpty -= capturedCols[i];
        totalEmpty -= diag1[i];
        totalEmpty -= diag2[i];
    }
    
    // Subtract intersections
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            if (diag1[i + j] > 1 || diag2[i - j] > 1) {
                totalEmpty--;
            }
        }
    }
    
    // Add the intersections that were subtracted twice
    for (long long i = 1; i <= N; ++i) {
        if (diag1[i + 1] > 1 && diag2[i] > 1) {
            totalEmpty++;
        }
    }
    
    cout << totalEmpty << endl;
    
    return 0;
}