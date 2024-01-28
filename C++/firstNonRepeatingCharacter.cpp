#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count[26] = {0};
    queue<char> characters;
    if (s != "")
    {
        for (int i = 0; i < s.size(); i++)
        {
            characters.push(s[i]);
            count[s[i] - 'a']++;
            while (!characters.empty())
            {
                if (count[characters.front() - 'a'] > 1)
                {
                    characters.pop();
                }
                else
                {
                    cout << characters.front() << " ";
                    break;
                }
            }
            if (characters.empty())
            {
                cout << -1 << " ";
            }
        }
    }
    else
    {
        cout << -1;
    }
}