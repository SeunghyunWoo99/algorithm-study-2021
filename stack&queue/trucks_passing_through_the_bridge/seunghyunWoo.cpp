#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    deque<int> deque(bridge_length, 0);

    for (int i = 0, currentTotalWeight = 0; i < truck_weights.size(); ++answer)
    {
        currentTotalWeight -= deque.front();
        deque.pop_front();

        if (currentTotalWeight + truck_weights[i] <= weight)
        {
            currentTotalWeight += truck_weights[i];
            deque.push_back(truck_weights[i++]);
        }
        else
        {
            deque.push_back(0);
        }
    }

    return answer + bridge_length;
}

int main()
{
    int bridge_length = 2, weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};

    cout << solution(bridge_length, weight, truck_weights) << endl;
    return 0;
}
