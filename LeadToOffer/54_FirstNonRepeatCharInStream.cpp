class Solution
{
public:
  //Insert one char from stringstream
    char table[256]={0};
    string s;
    void Insert(char ch)
    {
        s+=ch;
        table[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len = s.length();

        for(int i=0;i<len;++i) {
            if(table[s[i]]==1)
                return s[i];
        }
        return '#';
    }

};
