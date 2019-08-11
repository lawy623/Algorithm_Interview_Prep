// 1. O(n) search
class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        int min_dis = INT_MAX;
        int pos_x=-1;
        int pos_y=-1;
        for(int i=0; i<n; i++) {
            if (article[i]==x || article[i]==y) {
                if (article[i]==x) pos_x = i;
                if (article[i]==y) pos_y = i;
                if (pos_x!=-1 && pos_y!=-1 && abs(pos_x-pos_y)<min_dis)
                    min_dis = abs(pos_x-pos_y);
            }
        }
        return min_dis;
    }
};

// 2. If we want search time to be O(1), we can calculate all first in O(n^2)
class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        map<pair<string,string>,int> min_dis;
        string a = "", b = "", temp = "";
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                a = article[i];
                b = article[j];
                if (a>b) {
                    temp = a;
                    a = b;
                    b = temp;
                }
                if (min_dis.find(make_pair(a,b))==min_dis.end())
                    min_dis[make_pair(a,b)] = abs(i-j);
                else {
                    if (min_dis[make_pair(a,b)]>abs(i-j))
                        min_dis[make_pair(a,b)]=abs(i-j);
                }
            }
        }
        return x<y?min_dis[make_pair(x,y)]:min_dis[make_pair(y,x)];
    }
};
