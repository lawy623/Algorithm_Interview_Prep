// use map.
class DenseLine {
public:
    vector<double> getLine(vector<Point> p, int n) {
        map<pair<double, double>, int> countLine;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++) {
                if (countLine.find(calLine(p[i],p[j]))!=countLine.end())
                    countLine[calLine(p[i],p[j])]++;
                else
                    countLine[calLine(p[i],p[j])]=1;
            }
        }
        vector<double> res;
        double max_slop = 0.0;
        double max_inter = 0.0;
        int max_count = 0;
        map<pair<double, double>, int>::iterator iter;
        for (iter=countLine.begin(); iter!=countLine.end(); iter++){
            if (iter->second > max_count){
                max_count = iter->second;
                max_slop = iter->first.first;
                max_inter = iter->first.second;
            }
        }
        res.push_back(max_slop);
        res.push_back(max_inter);
        return res;
    }

    pair<double, double> calLine(Point p1, Point p2) {
        double slop = (double)(p1.y-p2.y) / (double)(p1.x-p2.x);
        double inter = (double)p2.y - (double)p2.x * slop;
        return make_pair(slop, inter);
    }
};
