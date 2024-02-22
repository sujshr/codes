#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
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