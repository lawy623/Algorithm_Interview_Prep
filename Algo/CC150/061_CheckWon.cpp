class Board {
public:
    bool checkWon(vector<vector<int> > a) {
       if(a[0][0]+a[1][1]+a[2][2]==3) return true;
       if(a[0][2]+a[1][1]+a[2][0]==3) return true;
       for(int i=0;i<3;i++){
            if(a[i][0]+a[i][1]+a[i][2]==3) return true;
            if(a[0][i]+a[1][i]+a[2][i]==3) return true;
       }
       return false;
    }
};
