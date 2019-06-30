// cpp version. Loop to count the space first. Then fill backward.
void replaceSpace(char *str,int length) {
    if (length <= 0 || str == NULL)
        return;
    int count_space = 0;
    int len = 0;
    for(; str[len] != '\0'; len++) {
        if (str[len] == ' ')
            count_space++;
    }
    if (count_space == 0)
        return;

    int new_len = len + count_space * 2;
    if (new_len > length)
        return;

    while (new_len >= 0) {
        if (str[len] != ' ') {
            str[new_len--] = str[len--];
        } else {
            str[new_len--] = '0';
            str[new_len--] = '2';
            str[new_len--] = '%';
            len--;
        }

    }
}
