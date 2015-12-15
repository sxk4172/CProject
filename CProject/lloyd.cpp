/*
 * lloyd.cpp
 *
 * Version: 3.1
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
#include<fstream>

using namespace std;
/**
 * This program solves lloyd problem and displays the output
 * int the required form
 *
 * @author Sanika Kulkarni
 * @author Yashashree Kulkarni
 */

class lloyd : public ProblemSolver<char> {
    
    public:
    //Initializing Variables
    int noOfRows;
    int noOfColumns;
    ostream *o;
    vector<char> inputMatrix;
    vector<char> outputMatrix;
    lloyd();
    lloyd(int, int, ostream &os);
    void setInputMatrix(vector<char> inputMatrix);
    void setOutputMatrix(vector<char> outputMatrix);
    vector<vector<char> > getNextNodes( vector<char> nextNode);
    bool desiredOutput(vector<char> checkVector);
    void displayOutput(vector<char> finalOutput);
    vector<char> rootNode();
    bool checkIfRoot(vector<char> start);
};
//Default Constructor
lloyd::lloyd(){
}

lloyd::lloyd(int r, int c , ostream &os)
{
    noOfRows = r;
    noOfColumns = c;
    o=&os;
}

void lloyd::setInputMatrix(vector<char> inputMatrix) {
    this->inputMatrix= inputMatrix;
}

void lloyd::setOutputMatrix(vector<char> outputMatrix) {
    this->outputMatrix= outputMatrix;
}
/**
 * rootNode  Sets the nodes to initial quantity
 *
 *
 * @return	 null
 */

vector<char> lloyd::rootNode() {
    vector<char> rootVector;
    rootVector = inputMatrix;
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

vector<vector<char> > lloyd::getNextNodes( vector<char> nextNode) {
    vector<vector<char> > tempVector;
    vector<char> tempVector1;
    int  i, j;
    char tempchar;
    
    for(i=0; i<noOfRows; i++)
    {
        for(j=0; j<noOfColumns; j++)
        {
            if(nextNode[i*noOfColumns+j] == '.')
            {
                if (i>0){
                    tempVector1 = nextNode;
                    tempchar = (i - 1) * noOfColumns + j;
                    tempVector1[i*noOfColumns + j] = tempVector1[tempchar];
                    tempVector1[tempchar] = '.';
                    tempVector.push_back(tempVector1);
                }
                if (i < (noOfRows-1)) {
                    tempVector1 = nextNode;
                    tempchar = (i + 1) * noOfColumns + j;
                    tempVector1[i*noOfColumns + j] = tempVector1[tempchar];
                    tempVector1[tempchar] = '.';
                    tempVector.push_back(tempVector1);
                }
                if (j >0){
                    tempVector1 = nextNode;
                    tempchar = i * noOfColumns + (j - 1);
                    tempVector1[i*noOfColumns + j] = tempVector1[tempchar];
                    tempVector1[tempchar] = '.';
                    tempVector.push_back(tempVector1);
                }
                
                if (j <(noOfColumns-1)){
                    tempVector1 = nextNode;
                    tempchar = i * noOfColumns + (j + 1);
                    tempVector1[i*noOfColumns + j] = tempVector1[tempchar];
                    tempVector1[tempchar] = '.';
                    tempVector.push_back(tempVector1);
                }
        }
    }
    
    }
    return tempVector;
}
/**
 * desiredOutput       checks if the required amount of
 *                     water is achieved
 *
 * @param    checkvector  to check of the desired water level
 * @return	 null
 */

bool lloyd::desiredOutput(vector<char> checkvector){
    bool resultT=true;
    for(int i=0;i<checkvector.size();i++) {
        if(checkvector[i]!=outputMatrix[i]){
            resultT=false;
            break;
        }
    }
    if(resultT)
        return true;
    else
        return false;
}

bool lloyd::checkIfRoot(vector<char> start){
    bool test=true;
    for(int i=0;i<start.size();i++) {
        if(start[i]!=inputMatrix[i]){
            test=false;
            break;
        }
    }
    if(test)
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

void lloyd::displayOutput(vector<char> finalOutput){
    stack<vector<char> > s;
    vector<char> temp;
    temp = nodeVMap.at(finalOutput);
    s.push(finalOutput);
    while(!checkIfRoot(temp))
    {
        s.push(temp);
        temp = nodeVMap.at(temp);
    };
    
    s.push(temp);
		 	
    *o << "Sequence of movement is: \n";
    
    while (!s.empty()){
        vector<char> t;
        t = s.top();
        s.pop();
        for(int i=0; i< noOfRows; i++)
        {
            for(int j=0; j<noOfColumns; j++)
            {
                *o<<t[i*noOfColumns+j]<< " ";
            }
            *o<<"\n";
        }
        *o<<"\n\n";
    }
}
/**
 * The main program.
 *
 * @param    args    command line arguments (ignored)
 *
 */
/*int main(int argc, char* argv[]) {
    if (argc != 3){
        cout << "2 args only" << endl;
    }
    else{
        istream *isp;
        ifstream ifs;
        ostream *osp;
        ofstream ofs;
        
        if (argv[1][0] == '-' && argv[1][1] == '\0'){
            isp = &cin;
        }
        else{
            ifs.open(argv[1]);
            isp = &ifs;
        }
        istream &is = *isp;
        
        if (argv[2][0] == '-' && argv[2][1] == '\0'){
            osp = &cout;
        }
        else{
            ofs.open(argv[2]);
            osp = &ofs;
        }
        ostream &os = *osp;
        int ro,col;
    vector<char> vectorI;
    vector<char> vectorO;
    int i,j;
        char temp;
        is>>ro>>col;
    
    for(i=0; i < ro; i++)
    {
        for(j=0; j<col; j++)
            
        {
            is >> temp;
            vectorI.push_back(temp);
        }
    }
        for(i=0; i < ro; i++)
        {
            for(j=0; j<col; j++)
                
            {
                is >> temp;
                vectorO.push_back(temp);
            }
        }
    lloyd l(ro,col,os);
    l.setInputMatrix(vectorI);
    l.setOutputMatrix(vectorO);
    l.bfs();
    return 0;
    }}*/