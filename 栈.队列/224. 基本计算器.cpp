class Solution {
public:
    int calculate(string s) {
        vector<string> tokens;
        long long sum = 0;
        bool numflag = false;
        bool zero_flag = true;
        stack<char> op;
        for (auto it : s) {
            if (it >= '0' && it <= '9') {
                numflag = true;
                sum = sum * 10 + it - '0';
                continue;
            } else {
                if (numflag == true) {
                    tokens.push_back(to_string(sum));
                    sum = 0;
                    numflag = false;
                    zero_flag = false;
                }
            }
            if (it == ' ') continue;
            if (it == '(') {
                op.push(it);
                zero_flag = true;
            } else if (it == ')') {
                while (op.top() != '(') {
                    tokens.push_back(string(1, op.top()));
                    op.pop();
                }
                op.pop();
                zero_flag = false;
            } else { //符号运算符
                while (!op.empty() && get(op.top()) >= get(it)) {
                    tokens.push_back(string(1, op.top()));
                    op.pop();
                }
                if (zero_flag) tokens.push_back(to_string(0));
                op.push(it); 
            } 
        }
        if (numflag) tokens.push_back(to_string(sum));
        while (!op.empty()) {
            tokens.push_back(string(1, op.top()));
            op.pop();
        }
        // for (auto it :tokens) {
        //     cout << it << endl;
        // }
        return evalRPN(tokens);
    }

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
    
    int get(char a) {
        if (a == '*' || a == '/') return 2;
        if (a == '+' || a == '-') return 1;
        return 0;
    }
};