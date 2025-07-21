#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for(int i=0;i<N;i++)cin>>H[i];
    long long T = 0;
    for(int i=0;i<N;i++){
        if(H[i]>0){
            T+=(H[i]+2)/3; // Ceiling division to account for remaining health after reducing by multiples of 3
        }
    }
    cout<<T<<endl;
    return 0;
}