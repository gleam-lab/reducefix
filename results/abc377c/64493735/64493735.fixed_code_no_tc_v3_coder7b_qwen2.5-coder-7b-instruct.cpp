#include <iostream>
#include <unordered_set>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> pieces;
    for(long long i = 0; i < M; ++i){
        long long x, y;
        cin >> x >> y;
        pieces.insert((x-1)*N+y);
    }
    
    long long count = 0;
    for(long long i = 1; i <= N; ++i){
        for(long long j = 1; j <= N; ++j){
            if(!pieces.count(((i-1)*N+j))){
                long long dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
                long long dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
                bool valid = true;
                for(long long k = 0; k < 8; ++k){
                    long long nx = i + dx[k];
                    long long ny = j + dy[k];
                    if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && !pieces.count(((nx-1)*N+ny))){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    ++count;
                }
            }
        }
    }
    
    cout << count << endl;
    return 0;
}