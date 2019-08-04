// For double, you should allow error in 1e-16. 
class CrossLine {
public:
    bool checkCrossLine(double s1, double s2, double y1, double y2) {
        if (abs(y1-y2)<=1e-16)
            return true;
        return abs(s1-s2)>1e-16;
    }
};
