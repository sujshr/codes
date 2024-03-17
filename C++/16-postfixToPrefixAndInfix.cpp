#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

vector<string> postToPre(vector<string> post_exp)
{
    stack<string> s;
    int n = post_exp.size();

    for (int i = 0; i < n; i++)
    {

        if (isOperator(post_exp[i][0]))
        {

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = post_exp[i] + " " + op2 + " " + op1;

            s.push(temp);
        }

        else
        {
            s.push(post_exp[i]);
        }
    }

    vector<string> ans;
    ans.push_back(s.top());
    return ans;
}

string postfixToInfix(const string &postfix)
{
    stack<string> operands;

    // Traverse the postfix expression from left to right
    for (char c : postfix)
    {
        if (isOperator(c))
        {
            // Pop two operands and concatenate them with the operator
            string operand2 = operands.top();
            operands.pop();
            string operand1 = operands.top();
            operands.pop();
            string expression = "(" + operand1 + c + operand2 + ")";
            operands.push(expression);
        }
        else if (isalnum(c))
        {
            // If operand, push it onto the stack
            operands.push(string(1, c));
        }
    }

    // The result is at the top of the stack
    return operands.top();
}

// Driver Code
int main()
{
    string post_exp = "ABC/-AK/L-*";
    getline(cin, post_exp);

    vector<string> words;
    string word;

    stringstream ss(post_exp);

    while (ss >> word)
    {
        words.push_back(word);
    }

    vector<string> ans = postToPre(words);
    for (auto i : ans)
    {
        cout << i;
    }
    return 0;
}