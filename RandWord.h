//
// Created by tox on 17/04/2019.
//

#ifndef PENDU_RANDWORD_H
#define PENDU_RANDWORD_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class RandWord {

private:
        ifstream file{nullptr};
        int wNb;
        vector<string> wordTab;


        static ifstream createStream(string pathToFile);

        void setWnb(int nb);

        int getWnb(){return wNb;}

        vector<string> getWordTab(){return wordTab;}

        bool countLineAndGetWordFromFile();

        static int randomLineNb(int nbLine);

        static string selectWordInVec(int randNb, vector<string> vWord);

public:
        RandWord(string pathToFile);

        string getRandomWord();

};



#endif //PENDU_RANDWORD_H
