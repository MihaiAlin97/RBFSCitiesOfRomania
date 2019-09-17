//
// Created by MMA on 1/9/2019.
//

#ifndef RBFSNEW_RBFS_H
#define RBFSNEW_RBFS_H



#include "Node.h"
#include "Functions.h"
#include <fstream>
#include <queue>
ifstream f("Harta.txt");


class RBFS {
    public:
    string base;
    string goal;
    bool goal_reached;
    vector<Node> nodes;

    void create_map(){//put a line of Harta.txt in node,then each node in nodes
        vector<string> words;
        vector<string> names;
        vector<string> distances;
        Node node;

        string text;
        int i;

        getline(f,text);

        while(true){
            words=break_text_into_words(text);
            for(i=1;i<words.size();i++){
                if(i%2==1)names.push_back(words[i]);
                if(i%2==0)distances.push_back(words[i]);
            }
            node.setName(words[0]);
            node.setChildren(names,distances);
            node.setH(findH(words[0]));
            this->nodes.push_back(node);
            names.clear();
            distances.clear();
            words.clear();

            if(getline(f,text).eof()==true){
                words=break_text_into_words(text);

                for(i=1;i<words.size();i++){
                    if(i%2==1)names.push_back(words[i]);
                    if(i%2==0)distances.push_back(words[i]);
                }
                node.setName(words[0]);
                node.setChildren(names,distances);
                node.setH(findH(words[0]));
                this->nodes.push_back(node);
                names.clear();
                distances.clear();
                words.clear();

                break;}
        }
    }
    int findNode(string name){//return index of node in nodes;
        int i;
        for(i=0;i<this->nodes.size();i++){
            if(this->nodes[i].name==name)return i;
        }

    }
    int init(){

    }
    pair<int,int> rbfs(string parent,Node node,int f_limit,string path){
        int i,j,index;
        pair<string,int> aux;
        pair<int,int> returns;
        vector<Node> successors;
        vector<pair<string,int>> helper_children;
        queue<Node> alternatives;
        Node best;
        best=node;
        int alternative;
        int min;
        int result;
        path=path+" "+node.name;


        if(this->goal==node.name){
            cout<<"Reached the goal";
            cout<<endl<<path;
            return {1,1};
        }
        if(node.children_names.size()==1){
            cout<<"Bad path;We go back to "<<parent<<endl;
            return {0,9999};
        }

        for(i=0;i<node.children_names.size();i++){
            if(node.children_names[i]!=parent) {
                index = this->findNode(node.children_names[i]);//get index of each successor
                if (nodes[index].H + node.children_distances[i] > node.F) {
                    nodes[index].F = nodes[index].H + node.children_distances[i];
                    helper_children.push_back({nodes[index].name, nodes[index].F});
                } else {
                    nodes[index].F = node.F;
                    helper_children.push_back({nodes[index].name, nodes[index].F});
                }
            }
        }
        for(i=0;i<helper_children.size()-1;i++) {//order children by f-value
            for (j = i + 1; j < helper_children.size();j++)
                if(helper_children[i].second>helper_children[j].second){
                    aux=helper_children[i];
                    helper_children[i]=helper_children[j];
                    helper_children[j]=aux;

                };
        }
        for(i=0;i<helper_children.size();i++) {
            index=findNode(helper_children[i].first);
            alternatives.push(nodes[index]);//put updated f's in ueue
        }

        i=0;
        while(!alternatives.empty()){
            best=alternatives.front();

            cout<<"We choose "<<best.name<<"->";
            alternatives.pop();
            if(best.F>f_limit){
                cout<<best.name<<"wrong;Go back to "<<parent<<endl;
                return{0,best.F};
            }

            alternative=alternatives.front().F;
            if(alternative>f_limit)min=f_limit;
            else min=alternative;
            returns=rbfs(node.name,best,min,path);
            result=returns.first;
            best.F=returns.second;
            if(result==1)return {1,1};

        }
    }
};


#endif //RBFSNEW_RBFS_H
