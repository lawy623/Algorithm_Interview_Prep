vector<string> digits = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
vector<string> teens = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
vector<string> tens = { "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
vector<string> bigs = { "", "Thousand", "Million" };

class ToString {
public:
    string numToString100(int number)
    {
        string str = "";

        /*转换百位数的地方*/
        if (number >= 100){
            str += digits[number / 100 - 1] + " Hundred ";
            number %= 100;
        }

        //转换十位数的地方
        if (number >= 11 && number <= 19)
        {
            return str += teens[number - 11]+" ";
        }
        else if (number == 10 || number >= 20)
        {
            str += tens[number / 10 - 1] + " ";
            number %= 10;
        }

        //转换个位的地方
        if (number >= 1 && number <= 9)
        {
            str += digits[number - 1]+" ";
        }
        return str;

    }

    void removeLastSpace(string &str)
    {
        if(str[str.length()-1]==' ')
            str.erase(str.length()-1,str.length());
    }
    string toString(int x) {
        // write code here
        if (x == 0)
            return "zero";
        else if (x < 0)
            return "Negative" + toString(abs(x));

        int count = 0;
        string str = "";

        while (x > 0)
        {
            if (x % 1000 != 0)
            {
                if (str != "")
                    str = numToString100(x % 1000) + bigs[count] + "," + str;
                else
                    str = numToString100(x % 1000)+ bigs[count];
            }
            x /= 1000;
            count++;
        }
            removeLastSpace(str);
        return str;
    }
};
