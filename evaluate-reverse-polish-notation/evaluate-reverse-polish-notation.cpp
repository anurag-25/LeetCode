class Solution {
private:
    int solve (const int &a, const int&b, const char &oper) {
        if (oper == '+') return a+b;
        else if (oper == '-') return a-b;
        else if (oper == '*') return a*b;
        else return a/b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i].size()>1 || (tokens[i][0] >='0' && tokens[i][0] <='9')) s.push (stoi(tokens[i]));
            else {
                char oper = tokens[i][0];
                int a, b;
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(solve(a, b, oper));
            }
        }
        return s.top();
    }
};