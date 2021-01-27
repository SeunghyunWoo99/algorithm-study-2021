#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    multimap<string, int> map_participant;

    for (auto elem : participant) {
        map_participant.insert(pair<string, int>(elem, 0));
    }


    for (auto elem : completion) {
        multimap<string, int>::iterator it = map_participant.find(elem);
        if (it != map_participant.end()) {
            map_participant.erase(it);
        }
        else return it->first;
    }

    return map_participant.begin()->first;
}