int main(){
    int H,W,Y; cin>>H>>W>>Y;
    vvi A(H, vi(W)), used( H, vi(W) ); cin>>A;
    pq_c<vi> pq;
    rep( i, H ){
        pq.push( { A[i][0], i, 0 } ); 
        pq.push( { A[i][W-1], i, W-1 } ); 
        used[i][0] = 1; 
        used[i][W-1] = 1;
    }
    rep3( i, 1, W-1 ){
        pq.push( { A[0][i], 0, i } ); 
        pq.push( { A[H-1][i], H-1, i } ); 
        used[0][i] = 1; 
        used[H-1][i] = 1; 
    }
    
    rep(i, Y + 1) {
        if (i > 1) {
            cout << "Year " << i - 1 << ": pq size = " << pq.size() << endl;
        }
        // ... (rest of the code to simulate the sinking process)
    }
}