// must pass the centers of two retangle.
class Bipartition {
public:
    vector<double> get_center(vector<Point> A){
        double x = (A[0].x + A[1].x) / 2.0;
        double y = (A[2].y + A[1].y) / 2.0;
        vector<double> res;
        res.push_back(x);
        res.push_back(y);
        return res;
    }
    vector<double> getBipartition(vector<Point> A, vector<Point> B) {
        vector<double> c1 = get_center(A);
        vector<double> c2 = get_center(B);
        double slop = (c2[1]-c1[1]) / (c2[0]-c1[0]);
        double intercept = c2[1] - slop*c2[0];
        vector<double> res;
        res.push_back(slop);
        res.push_back(intercept);
        return res;
    }
};
