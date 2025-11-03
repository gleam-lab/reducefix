#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    long long a;
    int idx;
}node;
node A[200000];
long long psum[200001],K;
int N,M;
bool f(long long k, int i){
    int idx = upper_bound(A+i,A+N, node{A[i].a+k,-1}, [](node a, node b){return a.a<b.a;})-A;
    int l = N-M;
    if(i>=l)l--;
    if(idx<=l) return false;
    long long req = (idx-l)*(A[i].a+k+1)-(psum[idx]-psum[l]);
    if(i>l) req -= k+1;
    if(req<=K-k) return false;
    return true;
}

int main(){
    scanf("%d %d %lld", &N, &M, &K);
    psum[0] = 0;
    for(int i=0;i<N;i++){
        scanf("%lld", &A[i].a);
        A[i].idx = i;
    }
    sort(A,A+N,[](node a, node b){return a.a<b.a;});
    for(int i=1;i<=N;i++)psum[i] = psum[i-1]+A[i-1].a;
    K -= psum[N];
    for(int i=0;i<N;i++){
        if(!f(K,i)){A[i].a=-1;continue;}
        long long lo = 0, hi=K;
        while(hi-lo>1){
            long long mid = (lo+hi)>>1;
            if(f(mid,i))hi=mid;
            else lo=mid+1;
        }
        if(hi>lo && f(hi-1,i))hi--;
        A[i].a = hi;
    }

    sort(A,A+N,[](node a, node b){return a.idx<b.idx;});
    for(int i=0;i<N;i++)printf("%lld ", A[i].a);
    printf("\n");
}