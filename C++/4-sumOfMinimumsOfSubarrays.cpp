// Brute force:

#include <iostream>
#include <vector>

using namespace std;

void printSumOfMinElements(const vector<int> &arr)
{
    int sum = 0; // Initialize the sum of minimum elements

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            // Find the minimum element in the current subarray
            int min_element = arr[i];
            for (int k = i + 1; k <= j; k++)
            {
                if (arr[k] < min_element)
                {
                    min_element = arr[k];
                }
            }
            sum += min_element; // Accumulate the minimum element
        }
    }

    // Print the sum of minimum elements
    cout << "Sum of minimum elements in all subarrays: " << sum << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    printSumOfMinElements(arr);
    return 0;
}
