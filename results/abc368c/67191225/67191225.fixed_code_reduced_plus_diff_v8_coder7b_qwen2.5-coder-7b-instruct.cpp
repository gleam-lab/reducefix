#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<numeric>
#include <iomanip>

using namespace std;
using ll = long long;

const double PI = acos(-1.0);

int main()
{
    int N;
    cin >> N;
    vector<ll>H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    ll T = 0;
    while(true){
        bool flag = false;
        for(int i=0;i<N;i++){
            if(H[i]>0){
                flag = true;
                if(T%3==0){
                    H[i]-=3;
                }else{
                    H[i]--;
                }
                T++;
            }
        }
        if(!flag) break;
    }
    cout << T << endl;
}