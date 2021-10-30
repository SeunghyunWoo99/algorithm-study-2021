#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void print_vector(vector<int> vec)
{
    for (int v : vec)
        cout << v << " ";
    cout << endl;
}

void recursive(vector<int> numbers, int k, int current, int &answer)
{
    if (k == 0)
    {
        // cout << current << endl;
        answer += current;
        return;
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
        vector<int> temp(numbers);
        temp.erase(temp.begin() + i);
        // cout << "k = " << k << ", current = " << current << ", answer = " << answer << endl;
        // print_vector(temp);
        recursive(temp, k - 1, current * numbers[i], answer);
    }
}

int solution(vector<vector<string> > clothes)
{
    int answer = 0;
    multimap<string, string> c_map;
    for (auto c : clothes)
    {
        c_map.insert(pair<string, string>(c[1], c[0]));
    }

    vector<int> numbers = {0};
    string prev = (*c_map.begin()).first;
    for (auto it = c_map.begin(); it != c_map.end(); it++)
    {
        // cout << (*it).first << " " << (*it).second << endl;
        if (prev != (*it).first)
        {
            numbers.push_back(1);
            prev = (*it).first;
        }
        else
        {
            ++numbers.back();
        }
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
        recursive(numbers, i, 1, answer);
    }
    // recursive({3, 2, 1}, 2, 1, answer);
    cout << answer / 2 << endl;

    return answer / 2;
}

int main()
{
    vector<vector<string> > clothes = {{"yellowhat", "headgear"}, {"smoky_makeup", "face"}, {"puppy_tshirts", "top"}, {"blackpants", "pants"}, {"whiteslacks", "pants"}, {"crowmask", "face"}, {"bluesunglasses", "eyewear"}, {"kf94_mask", "face"}, {"flowerpants", "pants"}, {"blackshirts", "top"}, {"green_turban", "headgear"}, {"bluerens", "eyewear"}, {"whiteshirts", "top"}, {"redsunglasses", "eyewear"}, {"blacksunglasses", "eyewear"}, {"glasses", "eyewear"}, {"brownshirts", "top"}, {"bluejean", "pants"}};
    solution(clothes);
    return 0;
}