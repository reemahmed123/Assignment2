#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<deque>
using namespace std;
struct dominoT {
    int leftDots;
    int rightDots;
};
bool FormsDominoChain(vector<dominoT>& dominos, deque<dominoT>& Answer, vector<bool>& used) {
    if (Answer.size() == dominos.size()) {
        return true;
    } else {
        for (int i = 0; i < dominos.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (Answer.empty() || dominos[i].leftDots == Answer.back().rightDots) {
                Answer.push_back(dominos[i]);
                used[i] = true;
                if(FormsDominoChain(dominos, Answer, used)){   //call function recursively
                    return true;
                }
                used[i] = false;   //backtracking
                Answer.pop_back();  //backtracking
            } else if (dominos[i].rightDots == Answer.front().leftDots) {
                Answer.push_front(dominos[i]);
                used[i] = true;
                if(FormsDominoChain(dominos, Answer, used)){  //call function recursively
                    return true;
                }
                used[i] = false;   //backtracking
                Answer.pop_front();   //backtracking
            }
        }
        return false;
    }
}


int main() {
    cout << "Please enter the number of dominos: " << endl;
    int number;
    cin >> number;

    deque<dominoT> Answer;
    vector<dominoT> dominos(number);
    vector<bool> used(number, false);

    cout << "Please enter your dominos: " << endl;
    for (int i = 0; i < number; i++) {
        cin >> dominos[i].leftDots >> dominos[i].rightDots;
    }

    if (FormsDominoChain(dominos, Answer, used)) {
        for (int i = 0; i < Answer.size(); i++) {
            if(i==Answer.size()-1){
                cout << Answer[i].leftDots << "|" << Answer[i].rightDots;
                continue;
            }
            cout << Answer[i].leftDots << "|" << Answer[i].rightDots << " - ";
        }
    }
    else{
        cout<<"sorry we couldnt make a chain with these dominoes!!";
    }

    return 0;
}
