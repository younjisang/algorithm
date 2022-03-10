#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ansOne = {1,2,3,4,5};
vector<int> ansTwo = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> ansThree = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int correct[3] = {0,0,0};
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == ansOne[i % 5])correct[0]++;
        if(answers[i] == ansTwo[i % 8])correct[1]++;
        if(answers[i] == ansThree[i % 10])correct[2]++;
        
    }
    int maxScore = max(correct[0], max(correct[1], correct[2]));
    
    for(int i = 0; i < 3; i++)
    {
        if(maxScore == correct[i]) answer.push_back(i+1);
        
    }
    
    return answer;
}
