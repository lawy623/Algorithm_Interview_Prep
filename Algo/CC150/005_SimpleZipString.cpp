class Zipper {
public:
    string zipString(string iniString) {
        int n = iniString.length();
        if (n==0)
            return iniString;
        string str;
        for(int i=0; i<n-1; i++) {
            int count=1;
            str += iniString[i];
            while(i<n-1 && iniString[i]==iniString[i+1]){
                count++;
                i++;
            }
            str += to_string(count);
            if (i==n-2){ //If last two char are the same, i==n-1. i==n-2 means different char at last.
                str += iniString[n-1];
                str += to_string(1);
            }
        }

        if (str.length()<iniString.length())
            return str;
        else
            return iniString;
    }
};
