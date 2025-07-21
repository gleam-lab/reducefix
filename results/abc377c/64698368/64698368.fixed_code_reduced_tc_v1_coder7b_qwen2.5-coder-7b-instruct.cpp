#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define ALL_(a) (a),(a)+size(a)
#define IF_T if(Is_test)

#define ll long long
using namespace std;

int N, M;
vector<pair<int, int>> moves = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    cin >> N >> M;
    
    // If there are no pieces, all squares are valid
    if (M == 0) {
        cout << N * N << endl;
        return 0;
    }
    
    // Set to store positions of non-capturable squares
    unordered_set<ll> nonCapturable;
    
    // Add all positions that are within 2 steps horizontally or vertically
    for (auto& move : moves) {
        repi(x, 0, N) {
            repi(y, 0, N) {
                if (isValid(x + move.first, y + move.second)) {
                    nonCapturable.insert((ll)x * N + y + move.first * N + move.second);
                }
            }
        }
    }
    
    // Calculate the number of valid squares
    ll totalSquares = N * N;
    ll invalidSquares = nonCapturable.size();
    
    // Remove duplicates (if any)
    for (auto& move : moves) {
        repi(x, 0, N) {
            repi(y, 0, N) {
                if (isValid(x + move.first, y + move.second) && isValid(x + move.second, y + move.first)) {
                    nonCapturable.erase((ll)x * N + y + move.first * N + move.second);
                    nonCapturable.erase((ll)x * N + y + move.second * N + move.first);
                }
            }
        }
    }
    
    invalidSquares = nonCapturable.size();
    
    cout << totalSquares - invalidSquares << endl;
}