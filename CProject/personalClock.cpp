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
 * making use of the shortest path possible from the given
 * user arguments
 *
 * @author Sanika Kulkarni
 */

class clockVarient : public ProblemSolver<int> {
    
    // Initializing variables
public:
    int timeFormat;
    int initialTime;
    int currentTime;
    vector<int> increments;
    clockVarient();
    void setValues(int timeFormat,int initialTime,int currentTime, vector<int> increments);
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

int main(int argc, char* argv[]) {
    // taking command line arguments from the user
    int timeFormat = atoi(argv[1]);
    int initialTime = atoi(argv[2]);
    int currentTime = atoi(argv[3]);
    vector<int> increments;
    for(int i=4; i < argc; i++)
        increments.push_back(atoi(argv[i]));
    clockVarient clock;
    clock.setValues( timeFormat, initialTime, currentTime, increments);
    ProblemSolver<int> &solver = clock;
    solver.bfs();
    return 0;
}
//default cclnosctkrVuacrtioern
clockVarient::clockVarient() {
    
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

void clockVarient::setValues(int timeFormat, int initialTime,int currentTime, vector<int> increments) {
    this->timeFormat = timeFormat;
    this->initialTime = initialTime;
    this->currentTime = currentTime;
    this->increments = increments;
}

/**
 * getNextNodes  Describes the next all possible Configurations
 *
 * @param    nodeN  node as required
 * @return	 null
 *
 */

vector<vector<int> > clockVarient::getNextNodes(vector<int> nodeN) {
    
    vector<vector<int> > tempVector;
    for(int i=0; i<increments.size();i++)
    {
        vector<int> tempVector1;
        if(((nodeN.front()) + increments[i]) <= 0)
        tempVector1.push_back(timeFormat + ((nodeN.front()) + increments[i]));
    else if(((nodeN.front()) + increments[i]) <= timeFormat)
        tempVector1.push_back((nodeN.front()) + increments[i]);
    else if(((nodeN.front()) + increments[i]) > timeFormat)
        tempVector1.push_back(((nodeN.front()) + increments[i]) - timeFormat);
     tempVector.push_back(tempVector1);
    }
    
    return tempVector;
}

/**
 * desiredOutput       Describes all the legal outputs
 *
 * @param    vectorC   current time
 * @return	 null
 */

bool clockVarient::desiredOutput(vector<int> vectorC) {
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
void clockVarient::displayOutput(vector <int> finalOutput) {
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
vector<int> clockVarient::rootNode() {
    vector<int> rootVector;
    rootVector.push_back(initialTime);
    nodeVMap[rootVector] = rootVector;
    return rootVector;
}