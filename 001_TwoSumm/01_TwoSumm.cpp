// 01_TwoSumm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int, int> chisla;

        for (int i = 0; i < nums.size(); ++i)
        {
            chisla.insert({ nums[i], i });
        }

        for (int num : nums)
        {
            int searsh_num = target - num;
            
            if (searsh_num == num)// && chisla.count(num) >=2)
            {
                auto range = chisla.equal_range(num);
                auto dis = distance(range.first, range.second);

                if (dis >= 2)
                {
                    int first_index = range.first->second;
                    range.first++;

                    return { first_index, range.first->second };
                }

            }
            else
            {
                const auto find_it = chisla.find(searsh_num);
                if (find_it != chisla.end())
                {
                    return { chisla.find(num)->second , find_it->second };
                }
            }
        }
        return { 0, 0 };
    }
};


int main()
{
    Solution sol;
    vector<int> nums = { 2, 7, 11, 15 };
    auto res = sol.twoSum(nums, 9);
    cout << "[" << res[0] << ", " << res[1] << "]\n";
//Output : [0, 1]

    nums = { 3, 2, 4 };
    res = sol.twoSum(nums, 6);
    cout << "[" << res[0] << ", " << res[1] << "]\n";
    //    Output : [1, 2]
    
    nums = { 3, 3 };
    res = sol.twoSum(nums, 6);
    cout << "[" << res[0] << ", " << res[1] << "]\n";
    //Output : [0, 1]

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
