// Reverse. O(n) time. For really C-style, the last char should be '\0'.
class Reverse {
public:
    string reverseString(string iniString) {
        int n = iniString.length();
        if (n==0)
            return "";
        for(int i=0;i<n/2; i++)
            swap(iniString[i], iniString[n-1-i]);
        return iniString;
    }
};
