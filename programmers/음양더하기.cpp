#include <string>
#include <vector>

#include <unordered_map>//해쉬맵 사용

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hash;
    
    for(string name : participant) {
        hash[name]++;
    }
    
    for (string name : completion)
    {
        hash[name]--;
    }
    
    for(auto tmp : hash) {
        if(tmp.second > 0) 
        {
            answer = tmp.first;
            break;
        }
    }
    return answer;
}
