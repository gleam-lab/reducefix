#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    long double cost = 0;
    long double x = 0, y = 0;
    
    for(int i = 0; i < N; i++) {
        long double nx, ny;
        cin >> nx >> ny;
        
        cost += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        
        x = nx;
        y = ny;
    }
    
    cost += sqrt(x * x + y * y);
    
    cout.precision(15);
    cout << fixed << cost << endl;
    
    return 0;
}