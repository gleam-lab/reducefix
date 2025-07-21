#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3 + 5;

int n, m;
vector<int> row, col, up[2], down[2];

bool exists(vector<int>& arr, int x) {
    return binary_search(arr.begin(), arr.end(), x);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        row.push_back(y);
        col.push_back(x);
        up[(x+y)%2].push_back(y-x);
        down[(x-y+1)%2].push_back(x+y);
    }
    
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    sort(up[0].begin(), up[0].end());
    sort(up[1].begin(), up[1].end());
    sort(down[0].begin(), down[0].end());
    sort(down[1].begin(), down[1].end());

    long long ans = (long long)n*n - m;
    for(int i = 0; i < m; i++) {
        int x = col[i], y = row[i];
        int u = y - x, d = x + y;
        int ru = upper_bound(row.begin(), row.end(), y-1) - lower_bound(row.begin(), row.end(), y-1);
        int cu = upper_bound(col.begin(), col.end(), x-1) - lower_bound(col.begin(), col.end(), x-1);
        int rd = upper_bound(row.begin(), row.end(), 2*x-y-1) - lower_bound(row.begin(), row.end(), 2*x-y-1);
        int cd = upper_bound(col.begin(), col.end(), 2*y-x-1) - lower_bound(col.begin(), col.end(), 2*y-x-1);
        
        if(exists(up[(x+y)%2], u)) ans--;
        else if(ru == 1 && !exists(row.begin(), y-1)) ans++;
        if(exists(up[(x+y)%2], u+1)) ans--;
        else if(cu == 1 && !exists(col.begin(), x-1)) ans++;

        if(exists(down[(x-y+1)%2], d)) ans--;
        else if(rd == 1 && !exists(row.begin(), 2*x-y-1)) ans++;
        if(exists(down[(x-y+1)%2], d+1)) ans--;
        else if(cd == 1 && !exists(col.begin(), 2*y-x-1)) ans++;
    }

    cout << ans << endl;
    return 0;
}