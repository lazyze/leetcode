class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int a, b, res;
        for (const auto &it : tokens) {
            if (it.size() != 1 || (it[0] != '+' && it[0] != '-' && it[0] != '*' && it[0] != '/')) {
                num.push(stoi(it));
            } else {
                b = num.top();
                num.pop();
                a = num.top();
                num.pop();
                res = cal(a, b, it[0]);
                num.push(res);
            }
        }
        return num.top();
    }

    int cal(int a, int b, char c) {
        if (c == '+') {
            return a + b;
        } else if (c == '-') {
            return a - b;
        } else if (c == '*') {
            return a * b;
        } else {
            return a / b;
        }
    }
    
};