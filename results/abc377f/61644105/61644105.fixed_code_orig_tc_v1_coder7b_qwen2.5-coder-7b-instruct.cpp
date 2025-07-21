#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> rows(n), cols(n);
    vector<vector<int>> diagonals(2*n-1), anti_diagonals(2*n-1);

    for(int i = 0; i < m; ++i){
        int r, c;
        cin >> r >> c;
        --r; --c; // Adjusting to 0-based index
        rows[r].push_back(c);
        cols[c].push_back(r);
        diagonals[r+c].push_back(c);
        anti_diagonals[n-1+r-c].push_back(c);
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    long long result = n*n;

    for(auto& vec : rows) {
        if(vec.size() > 1) {
            for(int i = 1; i < vec.size(); ++i) {
                result -= vec[i]-vec[i-1]-1;
            }
            result -= vec.back()-vec.front();
        } else if(vec.size() == 1) {
            result -= 1;
        }
    }

    for(auto& vec : cols) {
        if(vec.size() > 1) {
            for(int i = 1; i < vec.size(); ++i) {
                result -= vec[i]-vec[i-1]-1;
            }
            result -= vec.back()-vec.front();
        } else if(vec.size() == 1) {
            result -= 1;
        }
    }

    for(auto& vec : diagonals) {
        if(vec.size() > 1) {
            for(int i = 1; i < vec.size(); ++i) {
                result -= vec[i]-vec[i-1]-1;
            }
            result -= vec.back()-vec.front();
        } else if(vec.size() == 1) {
            result -= 1;
        }
    }

    for(auto& vec : anti_diagonals) {
        if(vec.size() > 1) {
            for(int i = 1; i < vec.size(); ++i) {
                result -= vec[i]-vec[i-1]-1;
            }
            result -= vec.back()-vec.front();
        } else if(vec.size() == 1) {
            result -= 1;
        }
    }

    cout << result << endl;
    return 0;
}