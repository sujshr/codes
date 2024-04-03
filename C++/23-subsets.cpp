#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &result)
{
    result.push_back(path);
    for (int i = start; i < nums.size(); ++i)
    {
        if (i > start && nums[i] == nums[i - 1]) // Avoid duplicates
            continue;
        path.push_back(nums[i]);
        backtrack(nums, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> path;
    sort(nums.begin(), nums.end()); // Sort the array to ensure lexicographic order
    backtrack(nums, 0, path, result);
    return result;
}

// this prints duplicates too
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    for (int x = 0; x < (1 << n); x++)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if ((x >> i) & 1)
                v.push_back(nums[i]);
        }
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    for (const auto &subset : result)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
