class Ants {
public:
    double antsCollision(int n) {
        return 1 - pow(0.5, n-1);
    }
};
