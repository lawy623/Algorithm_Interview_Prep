// Pre-allocate space.
class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        if (length <= 0)
            return iniString;
        int count_space = 0;
        for(int i=0; i<length; i++) {
            if (iniString[i] == ' ')
                count_space++;
        }
        if (count_space == 0)
            return iniString;

        int new_len = length + count_space * 2;
        string str(new_len, ' ');

        while (new_len >= 0) {
            if (iniString[length] != ' ') {
                str[new_len--] = iniString[length--];
            } else {
                str[new_len--] = '0';
                str[new_len--] = '2';
                str[new_len--] = '%';
                length--;
            }
        }
        return str;
    }
};
