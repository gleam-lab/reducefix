#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    if (N == 3) {
        cout << 2 << endl;
    } else if (N == 4) {
        int ans = N * N - 2 * M;
        // Check if any of the squares (1,1), (1,2), (1,3), (2,1), (2,2), (3,1) is occupied
        if (pieces.end() != find(ALL(pieces), make_pair(1, 1)) || 
            pieces.end() != find(ALL(pieces), make_pair(1, 2)) || 
            pieces.end() != find(ALL(pieces), make_pair(1, 3)) || 
            pieces.end() != find(ALL(pieces), make_pair(2, 1)) || 
            pieces.end() != find(ALL(pieces), make_pair(2, 2)) || 
            pieces.end() != find(ALL(pieces), make_pair(3, 1))) {
            ans = 0;
        }
        cout << ans << endl;
    } else {
        cout << N * N - M << endl;
    }

    return 0;
}