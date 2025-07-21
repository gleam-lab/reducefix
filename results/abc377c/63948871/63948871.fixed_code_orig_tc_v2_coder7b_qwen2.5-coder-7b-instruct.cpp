#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m;
    cin >> n >> m;

    unordered_set<long long> attacked;
    
    for(long long i = 0; i < m; ++i){
        long long x, y;
        cin >> x >> y;
        --x, --y;
        
        // Add the current cell to the set of attacked cells
        attacked.insert(x * n + y);

        // Check all 8 directions and add the corresponding cells to the set of attacked cells
        if(x + 2 < n && y + 1 < n) attacked.insert((x + 2) * n + y + 1);
        if(x + 1 < n && y + 2 < n) attacked.insert((x + 1) * n + y + 2);
        if(x - 1 >= 0 && y + 2 < n) attacked.insert((x - 1) * n + y + 2);
        if(x - 2 >= 0 && y + 1 < n) attacked.insert((x - 2) * n + y + 1);
        if(x - 2 >= 0 && y - 1 >= 0) attacked.insert((x - 2) * n + y - 1);
        if(x - 1 >= 0 && y - 2 >= 0) attacked.insert((x - 1) * n + y - 2);
        if(x + 1 < n && y - 2 >= 0) attacked.insert((x + 1) * n + y - 2);
        if(x + 2 < n && y - 1 >= 0) attacked.insert((x + 2) * n + y - 1);
    }

    // The total number of valid cells is the total number of cells minus the number of attacked cells
    long long valid_cells = n * n - attacked.size();
    
    cout << valid_cells << endl;

    return 0;
}