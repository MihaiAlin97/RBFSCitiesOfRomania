//
// Created by MMA on 1/8/2019.
//
using namespace std;

#include <string>
#include <vector>
#include <map>

#ifndef RBFSNEW_NODE_H
#define RBFSNEW_NODE_H

class Node {
public:
    string name;
    int F;//evaluation function
    int G;//cost from base to current node->it's changing
    int H;//heuristic
    bool visited;
    vector<string> children_names;
    vector<int> children_distances;

    Node(){
        this->name="";
        this->F=0;
        this->G=0;
        this->H=0;
        this->visited=false;

    }
    void setChildren(vector<string> children_names,vector<string> children_distances){
        int i;
        this->children_names.clear();
        this->children_distances.clear();
        for (i=0;i<children_names.size();i++){
            this->children_names.push_back(children_names[i]);
            this->children_distances.push_back(stoi(children_distances[i]));
        }
    }

    void setF(int F){
        this->F=F;
    }
    void setG(int G){
        this->G=G;
    }
    void setH(int H){
        this->H=H;
    }
    void setName(string name){
        this->name=name;
    }
};


#endif //RBFSNEW_NODE_H