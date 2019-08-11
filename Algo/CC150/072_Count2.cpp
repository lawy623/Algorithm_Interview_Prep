class Count2 {
public:
    int countNumberOf2s(int n) {
        int count = 0;
        int time = 1;
        for(;n/time>0;time*=10){
            int a = (n/time+7)/10*time;
            int b = ((n/time%10)==2)?(n%time+1):0;
            count +=  (a+b);
        }
        return count;
    }
};
