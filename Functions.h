//
// Created by MMA on 1/9/2019.
//
using namespace std;

#include <vector>
#include <string>
#include <fstream>
#include <fstream>

ifstream h("Heuristics.txt");

#ifndef RBFSNEW_FUNCTIONS_H
#define RBFSNEW_FUNCTIONS_H

vector<string> break_text_into_words(string text){//takes a string as arg,and returns a vector of strings representing words separated by space in the argument
    string word="";

    vector<string> words;
    int i=0;
    for(i=0;i<text.length();i++){
        if(text[i]!=32)word=word+text[i];

        if(text[i]==32){
            words.push_back(word);
            word.clear();
        }
        if(i==text.length()-1){
            words.push_back(word);
            word.clear();

        }
    }
    return words;

}
int findH(string city_name){
    vector<string> pair;
    string text;
    getline(h,text);

    while(true){
        pair=break_text_into_words(text);
        if(pair[0]==city_name)
        {h.clear();h.seekg(0, ios::beg);return stoi(pair[1]);}


        if(getline(h,text).eof()==true){
            pair=break_text_into_words(text);
            if(pair[0]==city_name)
            {h.clear();h.seekg(0, ios::beg);return stoi(pair[1]);}

            break;}
    }

}
#endif //RBFSNEW_FUNCTIONS_H
