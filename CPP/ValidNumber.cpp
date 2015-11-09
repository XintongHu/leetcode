class Solution {
public:
    bool isNumber(string s) {
        int i = 0, e;
        while (s[i++] == ' ');
        s.erase(0, i - 1);
        i = s.size() - 1;
        while (s[i--] == ' ');
        s.erase(i + 2, s.size() - i - 2);
        e = s.find('e');
        if (e == -1) return isF(s);
        else return isF(s.substr(0, e)) && isI(s.substr(e + 1, s.size() - e - 1));
    }
    
    bool isF(string s) {
        int i = 0, size = s.size();
        bool flag = false, numflag = false;
        if (size == 1) return (s[i] <= '9' && s[i] >= '0');
        else if (size == 0) return false;
        else {
            if (s[0] == '-' || s[0] == '+') i++;
            for (; i < size; i++) {
                if (s[i] <= '9' && s[i] >= '0') numflag = true;
                else if (s[i] == '.' && flag == false) flag = true;
                else return false;
            }
        }
        return numflag;
    }
    
    bool isI(string s) {
        int i = 0, size = s.size();
        bool numflag = false;
        if (size == 1) return (s[i] <= '9' && s[i] >= '0');
        else if (size == 0) return false;
        else {
            if (s[0] == '-' || s[0] == '+') i++;
            for (; i < size; i++) {
                if (s[i] <= '9' && s[i] >= '0') numflag = true;
                else return false;
            }
        }
        return numflag;
    }
};