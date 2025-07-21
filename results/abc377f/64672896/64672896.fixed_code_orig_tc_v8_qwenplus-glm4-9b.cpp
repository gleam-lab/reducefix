#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countNonCapturedSquares(int N, vector<pair<int, int>>& pieces) {
    vector<int> rowCapt(N + 1, 0);
    vector<int> colCapt(N + 1, 0);
    vector<int> diaCapt1(2 * N + 1, 0);
    vector<int> diaCapt2(2 * N + 1, 0);
    
    // Count captured squares
    for (auto& p : pieces) {
        int a = p.first;
        int b = p.second;
        rowCapt[a]++;
        colCapt[b]++;
        diaCapt1[a + b]++;
        diaCapt2[a - b]++;
    }
    
    long long nonCaptured = N * N;
    
    // Subtract captured squares
    for (int i = 1; i <= N; ++i) {
        nonCaptured -= rowCapt[i];
        nonCaptured -= colCapt[i];
        for (int j = 1; j <= 2 * N; ++j) {
            nonCaptured -= max(0LL, diaCapt1[j] - 1);
            nonCaptured -= max(0LL, diaCapt2[j] - 1);
        }
    }
    
    return nonCaptured;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    cout << countNonCapturedSquares(N, pieces) << endl;
    return 0;
}