class Finder {
public:
    int findString(vector<string> str, int n, string x) {
        int size = str.size();
        if(size == 0 || n <= 0){
            return -1;
        }
        int start = 0,end = size - 1;
        int mid;
        while(start <= end){
            mid = (end - start) / 2 + start;
            if(str[mid] == ""){
                int index = mid;
                while(index >= start && str[index] == "")
                    --index;
                if(index < start)
                    start = mid + 1;
                else if(str[index] == x)
                    return index;
                else if(str[index] > x)
                    end = index - 1;
                else
                    start = mid + 1;
            }
            else{
                if(str[mid] == x)
                    return mid;
                else if(str[mid] > x)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return -1;
    }
};
