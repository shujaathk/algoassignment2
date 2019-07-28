/*
    Author: Nouman Arshad
    Github: @nouman0320
    License: MIT license
*/

/// O(nlogn)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] > tail[length - 1])
            tail[length++] = v[i];
        else {
            // TO check whether the element is not present before hand
            auto it = find(tail.begin(), tail.begin() + length, v[i]);
            if (it != tail.begin() + length) {
                continue;
            }
            // If not present change the tail element to v[i]
            it = upper_bound(tail.begin(), tail.begin() + length, v[i]);
            *it = v[i];
        }
    }

    return length;
}

int main()
{
    vector<int> v{1, 5, 6, 4, 7, 3, 2, 4, 8, 9};
    cout << "Length of Longest Increasing Subsequence is "
              << LongestIncreasingSubsequenceLength(v);
    return 0;
}
