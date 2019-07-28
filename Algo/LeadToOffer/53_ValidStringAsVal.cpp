class Solution {
public:
    bool isNum(char* c) {
        if (int(*c-'0')>=0 && int(*c-'0')<=9)
            return true;
        return false;
    }
    bool checkLastPart(char* string) {
        if (*string=='\0')
            return false;
        if (*string=='+' || *string=='-')
            string++;
        if (*string=='\0')
            return false;
        while(*string!='\0') {
            if (isNum(string))
                string++;
            else
                return false;
        }
        return true;
    }
    bool isNumeric(char* string)
    {
        if (*string=='\0')
            return false;
        if (*string=='+' || *string=='-')
            string++;
        if (*string=='\0' || *string=='e' || *string=='E')
            return false;

        bool has_dot = false;
        while(*string!='\0') {
            if (*string=='e' || *string=='E') {
                return checkLastPart(string+1);
            }
            if (*string=='.') {
                if (has_dot)
                    return false;
                has_dot = true;
                string++;
                continue;
            }
            if (isNum(string))
                string++;
            else
                return false;
        }
        return true;
    }
};
