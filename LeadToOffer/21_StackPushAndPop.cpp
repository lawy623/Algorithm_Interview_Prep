class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size())
            return false;
        if (pushV.size()==0 && popV.size()==0)
            return false;

        stack<int> temp;
        int i = 0;
        int j = 0;
        while (i<pushV.size()) {
            temp.push(pushV[i]);
            i++;
            while (!temp.empty() && popV[j]==temp.top()) {
                temp.pop();
                j++;
            }
        }

        return temp.empty();
    }
};
