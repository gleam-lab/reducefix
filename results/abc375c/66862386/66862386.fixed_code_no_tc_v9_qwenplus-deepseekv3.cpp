#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    long double total_cost = 0.0;
    long long nowX = 0, nowY = 0;
    
    for (int i = 0; i < N; ++i) {
        long long nextX, nextY;
        cin >> nextX >> nextY;
        
        long long dx = nextX - nowX;
        long long dy = nextY - nowY;
        total_cost += sqrtl(dx * dx + dy * dy);
        
        nowX = nextX;
        nowY = nextY;
    }
    
    long long dx = -nowX;
    long long dy = -nowY;
    total_cost += sqrtl(dx * dx + dy * dy);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    
    return 0;
}