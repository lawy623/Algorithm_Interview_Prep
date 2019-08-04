class AddSubstitution {
public:
    int calc(int a, int b, int type) {
        int res = 0;
        if(type == 1){
            int tmp = 0;
            for(int i = 0; i < b; i++){
                tmp += a;
            }
            res = tmp;
        }else if(type == 0 ){
            int tmp = a;
            int count = 0;
            while(tmp > 0&& tmp >= b){
                tmp = tmp + (~b) + 1;
                count++;
            }
            res = count;
        }else{
            res = a + (~b) + 1;
        }
        return res;
    }
};
