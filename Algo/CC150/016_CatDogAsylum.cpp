class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {
        queue<int> dog; // +1
        queue<int> cat; // -1
        vector<int> res;
        for(int i=0; i<ope.size(); i++) {
            if (ope[i][0]==1) {
                if (ope[i][1]>0) {
                    dog.push(i);
                    dog.push(ope[i][1]);
                }
                else if (ope[i][1]<0) {
                    cat.push(i);
                    cat.push(ope[i][1]);
                }
            }
            else if (ope[i][0]==2) {
                if (ope[i][1]==0) {
                    if (cat.empty() && dog.empty())
                        continue;
                    else if (cat.empty()) {
                        dog.pop();
                        res.push_back(dog.front());
                        dog.pop();
                    } else if (dog.empty()) {
                        cat.pop();
                        res.push_back(cat.front());
                        cat.pop();
                    } else {
                        if (cat.front()<dog.front()) {
                            cat.pop();
                            res.push_back(cat.front());
                            cat.pop();
                        } else {
                            dog.pop();
                            res.push_back(dog.front());
                            dog.pop();
                        }
                    }
                } else if (ope[i][1]==1) {
                    if (!dog.empty()) {
                        dog.pop();
                        res.push_back(dog.front());
                        dog.pop();
                    }
                } else if (ope[i][1]==-1) {
                    if (!cat.empty()) {
                        cat.pop();
                        res.push_back(cat.front());
                        cat.pop();
                    }
                }
            }
        }
        return res;
    }
};
