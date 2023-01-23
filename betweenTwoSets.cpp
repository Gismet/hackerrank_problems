#include <iostream>
#include <vector>
#include <algorithm>

bool areAllFactorsOfNum(std::vector<int> a, int num)
{
    int i = 0;
    while (i < a.size())
    {
        if (num % a[i] != 0)
            return false;
        i++;
    }
    return true;
}

bool isNumFactorOfAllNums(std::vector<int> b, int num)
{
    int i = 0;
    while (i < b.size())
    {
        if (b[i] % num != 0)
            return false;
        i++;
    }
    return true;
}

int getTotalX(std::vector<int> a, std::vector<int> b)
{
    int count = 0;
    int lower = *std::max_element(a.begin(), a.end());
    int upper = *std::min_element(b.begin(), b.end());

    int num = lower;
    while (num <= upper)
    {
        if (areAllFactorsOfNum(a, num) && isNumFactorOfAllNums(b, num))
        {
            count++;
        }
        num++;
    }
    return count;
}

int main()
{
    std::vector<int> a = {2, 4};
    std::vector<int> b = {16, 32, 96};

    // 4 --- 16
    std::cout << getTotalX(a, b);

    return 0;
}