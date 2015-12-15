/*
 * Clock.cpp
 *
 * Version: 1.1
 *     $Id$
 *
 * Revisions:
 * Initial revision
 *
 */

#include "Solution.h"
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<cmath>
#include<cstdlib>


using namespace std;
/**
 * This program solves the clock problem that sets
 * the clock back to its actual time,since when it stopped
 * making use of the shortest path possible.
 *
 * @author Sanika Kulkarni
 * @author Yashashree Kulkarni
 */

class ClockProblem : public ProblemSolver<int> {
    
    // Initializing variables
public:
    int timeFormat;
    int initialTime;
    int currentTime;
    ClockProblem();
    void setValues(int timeFormat,int initialTime,int currentTime);
    vector< vector<int> > getNextNodes( vector<int> nodeN);
    bool desiredOutput(vector<int> vectorC);
    void displayOutput(vector<int> finalOutput);
    vector<int> rootNode();
};

/**
 * The main program.
 *
 * @param    args    command line arguments (ignored)
 *
 */

/*int main(int argc, char* argv[]) {
    // taking command line arguments from the user
    int timeFormat = atoi(argv[1]);
    int initialTime = atoi(argv[2]);
    int currentTime = atoi(argv[3]);
    ClockProblem clock;
    clock.setValues( timeFormat, initialTime, currentTime);
    ProblemSolver<int> &solver = clock;
    solver.bfs();
    return 0;
}*/
//default constructor
ClockProblem::ClockProblem () {
    
}

/**
 * setValues  Sets the required times as required by the program
 *
 * @param    timeFormat  sets the time format as the total number of hours
 in clock
 * @param    initialTime sets the time at which the clock stopped functioning
 * @param    curentTime  sets the current time
 * @return	 null
 */

void ClockProblem::setValues(int timeFormat, int initialTime,int currentTime) {
    this->timeFormat = timeFormat;
    this->initialTime = initialTime;
    this->currentTime = currentTime;
}

/**
 * getNextNodes  Describes the next all possible Configurations
 *
 * @param    nodeN  node as required
 * @return	 null
 *
 */

vector<vector<int> > ClockProblem::getNextNodes(vector<int> nodeN) {
    vector<int> tempVector1;
    vector<int> tempVector2;
    vector<vector<int> > tempVector;
    
    if(((nodeN.front()) - 1) > 0)
        tempVector1.push_back((nodeN.front()) - 1);
    else
        tempVector1.push_back(timeFormat);
    if(((nodeN.front()) + 1) <= timeFormat)
        tempVector2.push_back((nodeN.front()) + 1);
    else
        tempVector2.push_back(((nodeN.front()) + 1)% timeFormat);
    tempVector.push_back(tempVector1);
    tempVector.push_back(tempVector2);
    
    return tempVector;
}

/**
 * desiredOutput       Describes all the legal outputs
 *
 * @param    vectorC   current time
 * @return	 null
 */

bool ClockProblem::desiredOutput(vector<int> vectorC) {
    if (vectorC.front() == currentTime)
        return true;
    else
        return false;
}
/**
 * displayOutput         possible outputs
 *
 * @param    finalOutput declares the final output
 * @return	 null
 */
void ClockProblem::displayOutput(vector <int> finalOutput) {
    list<int> visitedNodeList;
    vector<int> vectorT;
    int numberOfMoves = 0;
    vectorT = nodeVMap.at(finalOutput);
    visitedNodeList.push_front(currentTime);
    int vTemp=vectorT.front();
    while(vTemp != initialTime) {
        vectorT = nodeVMap.at(vectorT);
        visitedNodeList.push_front(vTemp);
        vTemp = vectorT.front();
        numberOfMoves++;
    };
    
    visitedNodeList.push_front(vTemp);
    numberOfMoves++;
    
    int count = numberOfMoves;
    cout << "Traversing Path : ";
    
    while (!visitedNodeList.empty()) {
        cout<<visitedNodeList.front();
        if(count!=0){
            cout<<" > ";
            count--;
        }
        visitedNodeList.pop_front();
    }
    cout << "\nNo. of moves : " << numberOfMoves << endl;
}
/**
 * rootNode  Sets the nodes to initial time
 *
 *
 * @return	 null
 */
vector<int> ClockProblem::rootNode() {
    vector<int> rootVector;
    rootVector.push_back(initialTime);
    nodeVMap[rootVector] = rootVector;
    return rootVector;
}