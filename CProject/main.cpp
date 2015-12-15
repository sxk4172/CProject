#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include "Header.h"
using namespace std;

class Clock1 : public Solver<int>{
private:
    int stopPos;
    int startPos;
    
public:
    int N;
    Clock1();
    Clock1(int,int,int);
    
    vector<int> initConfig();
    vector< vector<int> > nextConfig( vector<int> nxt);
    bool isItGoal(vector<int> chk);
    void printResult(vector<int> result);
};

Clock1::Clock1() {
}

Clock1::Clock1(int size, int stopPosition,int startPosition) {
    N = size;
    stopPos = stopPosition;
    startPos = startPosition;
}

vector<int> Clock1::initConfig(){
    vector<int> vect;
    vect.push_back(stopPos);
    visited[vect] = vect;
    
    return(vect);
}

vector<vector<int> > Clock1::nextConfig(vector<int> nxt){
    vector<vector<int> > temp;
    vector<int> t1;
    vector<int> t2;
    int element = nxt.front();
    
    if(((element + 1) % N) == 0)
    {
        t1.push_back(N);
    }
    else
    {
        t1.push_back(element + 1);
    }
    
    temp.push_back(t1);
    
    if(((element - 1) % N) == 0)
    {
        t2.push_back(N);
    }
    else
    {
        t2.push_back(element - 1);
    }
    
    temp.push_back(t2);
    
    return temp;
}

bool Clock1::isItGoal(vector<int> chk){
    int element = chk.front();
    
    if (element == startPos)
        return true;
    else
        return false;
}


void Clock1::printResult(vector <int> result){
    int noMoves = 0;
    stack<int> s;
    vector<int> temp;
    temp = visited.at(result);
    s.push(startPos);
    
    while(temp.front() != stopPos)
    {
        s.push(temp.front());
        noMoves++;
        temp = visited.at(temp);
    };
    
    if(startPos != stopPos)
    {
        s.push(stopPos);
        noMoves++;
    }
		 	
    cout << "No. of moves to move hour hand to its true position is: " << noMoves << endl;
    cout << "Sequence of movement is: ";
    
    while (!s.empty()){
        cout<<s.top();
        if(s.top() != startPos)
            cout<<" -> ";
        s.pop();
    }
}

int main(int argc, char* argv[]) {
    int siz = atoi(argv[1]);
    int stop = atoi(argv[2]);
    int proper = atoi(argv[3]);
    Clock1 c1(siz,stop,proper);
    Solver<int> &solve = c1;
    solve.solve();	
    //c1.solve();	
    //cin.get();
    return 0;
}