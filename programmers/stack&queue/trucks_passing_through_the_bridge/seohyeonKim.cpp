#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    vector<int> cross(truck_weights.size(), 0);
    int bridge_weight = 0;
    int crossing_front = 0, crossing_back = 0;

    for (int i = 0; *(cross.end() - 1) < bridge_length; answer++) {

        if (i < truck_weights.size() && bridge_weight + truck_weights[i] <= weight) { //버틸 수 있는 무게면
            bridge_weight += truck_weights[i];
            crossing_back = i++;
        }
        for (int j = crossing_front; j <= crossing_back; j++) {
            cross[j]++;
            if (cross[j] >= bridge_length) {
                bridge_weight -= truck_weights[j];
                crossing_front = j + 1;
            }
        }
    }

    return answer;
}
