class Solution {
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        len = digits.size();
        an = "";
        recur(0);
        return ans;
    }   

    void recur(int n) {
        if (n == len) {
            if(an.size() > 0) ans.push_back(an);
            return ;
        }
        int num = getnum(n);
        char ch = getchar(n);
        for (int i = 0; i < num; i++) {
            an.push_back(ch + i);
            recur(n + 1);
            an.pop_back();
        }
    }
    int getnum(int n) {
        if (digits[n] == '7' || digits[n] == '9') return 4; 
        return 3;
    }

    char getchar(int n) {
        if (digits[n] == '2') {
            return 'a';
        } else if(digits[n] == '3') {
            return 'd';
        } else if(digits[n] == '4') {
            return 'g';
        } else if(digits[n] == '5') {
            return 'j';
        } else if(digits[n] == '6') {
            return 'm';
        } else if(digits[n] == '7') {
            return 'p';
        } else if(digits[n] == '8') {
            return 't';
        } else {
            return 'w';
        }
    }
    vector<string> ans;
    string digits;
    string an;
    int len;
    
};