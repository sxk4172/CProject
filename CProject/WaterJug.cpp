/*
 * WaterJug.cpp
 *
 * Version: 2.1
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
#include<stack>
#include<algorithm>

using namespace std;
/**
 * This program solves the Waterjug problem that
 * uses the capacity of one jug to transfer the 
 * said quantity to another.
 *
 * @author Sanika Kulkarni
 * @author Yashashree Kulkarni
 */

class WaterJug : public ProblemSolver<int> {
    public:
    int capacityJug1;
    int requiredAmount;
    int capacityJug2;
    WaterJug();
    vector< vector<int> > getNextNodes( vector<int> nodeN);
    bool desiredOutput(vector<int> vectorC);
    void displayOutput(vector<int> finalOutput);
    vector<int> rootNode();
    WaterJug(int requiredAmount, int capacityJug1, int capacityJug2);
};

/**
 * The main program.
 *
 * @param    args    command line arguments (ignored)
 *
 */
/*int main(int argc, char* argv[]) {
 // taking command line arguments from the user
 int requiredAmount = atoi(argv[1]);
 int capacityJug1 = atoi(argv[2]);
 int capacityJug2 = atoi(argv[3]);
 WaterJug jug(requiredAmount,capacityJug1,capacityJug2);
 ProblemSolver<int> &solver = jug;
 solver.bfs();
 return 0;
 }*/

/**
 * WaterJug  Describes the next all possible Configurations
 *
 * @param    requiredAmount  the required total amount of water
 * @param    capacityJug1    the capacity of jug 1
 * @param    capacityJug2    the capacity of jug 2
 * @return	 null
 *
 */

WaterJug::WaterJug(int requiredAmount, int capacityJug1, int capacityJug2) {
    this->capacityJug1 = capacityJug1;
    this->capacityJug2 = capacityJug2;
    this->requiredAmount = requiredAmount;
    
}

WaterJug::WaterJug() {
}
/**
 * rootNode  Sets the nodes to initial quantity
 *
 *
 * @return	 null
 */

vector<int> WaterJug::rootNode() {
    vector<int> rootVector;
    rootVector.push_back(0);
    rootVector.push_back(0);
    nodeVMap[rootVector] = rootVector;
    return rootVector;
}
/**
 * getNextNodes  Describes the next all possible quantity
                 combination
 
 * @param    nodeN  node as required
 * @return	 null
 *
 */

vector<vector<int> > WaterJug::getNextNodes(vector<int> nodeN) {
    vector<vector<int> > vectorT;
    vector<int> vTemp;

    if(nodeN[0]!=capacityJug1) {
        vTemp=nodeN;
        vTemp[0]=capacityJug1;
        vectorT.push_back(vTemp);
    }
    
    if(nodeN[0]!=0) {
        vTemp=nodeN;
        vTemp[0]=0;
        vectorT.push_back(vTemp);
    }
    
    vTemp = nodeN;
    vTemp[1] = vTemp[1] - (min(nodeN[1],(capacityJug1 - nodeN[0])));
    vTemp[0] = vTemp[0] + (min(nodeN[1],(capacityJug1 - nodeN[0])));
    vectorT.push_back(vTemp);

    
    vTemp = nodeN;
    vTemp[0] = vTemp[0] - (min(nodeN[0],(capacityJug2 - nodeN[1])));
    vTemp[1] = vTemp[1] + (min(nodeN[0],(capacityJug2 - nodeN[1])));
    vectorT.push_back(vTemp);

    
    if(nodeN[1]!=capacityJug2) {
        vTemp=nodeN;
        vTemp[1]=capacityJug2;
        vectorT.push_back(vTemp);
    }
    
    if(nodeN[1]!=0) {
        vTemp=nodeN;
        vTemp[1]=0;
        vectorT.push_back(vTemp);
    }
    
    return vectorT;
}
/**
 * desiredOutput       checks if the required amount of
 *                     water is achieved
 *
 * @param    checkvector  to check of the desired water level
 * @return	 null
 */

bool WaterJug::desiredOutput(vector<int> checkVector) {
    if(checkVector[0] ==requiredAmount || checkVector[1] == requiredAmount)
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

void WaterJug::displayOutput(vector <int> finalOutput) {
    vector<int> tempVector = nodeVMap.at(finalOutput);
    list<vector<int> > visitedNodeList;
    visitedNodeList.push_front(finalOutput);
    while(tempVector[0]!=0 || tempVector[1]!=0) {
        visitedNodeList.push_front(tempVector);
        tempVector = nodeVMap.at(tempVector);
    };
    visitedNodeList.push_front(tempVector);
    cout << "Steps to follow : \n";
    while (!visitedNodeList.empty()) {
        vector<int> vTemp;
        vTemp = visitedNodeList.front();
        visitedNodeList.pop_front();
        cout<<vTemp[0]<<"  "<<vTemp[1]<<endl;
    }
}	

