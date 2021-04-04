#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void recursive(vector<int> numbers, int k, int current, int &answer)
{
    if (numbers.size() < k)
        return;
    else if (k == 0)
    {
        answer += current;
        return;
    }

    auto it = numbers.begin();
    while (!numbers.empty())
    {
        int n = *it;
        numbers.erase(it);
        recursive(numbers, k - 1, current * n, answer);
    }
}

int solution(vector<vector<string> > clothes)
{
    int answer = 0;
    multimap<string, string> c_map;
    for (auto c : clothes)
        c_map.insert(pair<string, string>(c[1], c[0]));

    vector<int> numbers = {0};
    string prev = (*c_map.begin()).first;
    for (auto it = c_map.begin(); it != c_map.end(); it++)
    {
        if (prev != (*it).first)
        {
            numbers.push_back(1);
            prev = (*it).first;
        }
        else
            ++numbers.back();
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
        vector<int> temp(numbers);
        recursive(temp, i + 1, 1, answer);
    }

    return answer;
}

int main()
{
    vector<vector<string> > clothes = {{"yellowhat", "headgear"}, {"smoky_makeup", "face"}, {"puppy_tshirts", "top"}, {"blackpants", "pants"}, {"whiteslacks", "pants"}, {"crowmask", "face"}, {"bluesunglasses", "eyewear"}, {"kf94_mask", "face"}, {"flowerpants", "pants"}, {"blackshirts", "top"}, {"green_turban", "headgear"}, {"bluerens", "eyewear"}, {"whiteshirts", "top"}, {"redsunglasses", "eyewear"}, {"blacksunglasses", "eyewear"}, {"glasses", "eyewear"}, {"brownshirts", "top"}, {"bluejean", "pants"}};
    solution(clothes);
    return 0;
}