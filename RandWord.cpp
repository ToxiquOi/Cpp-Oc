//
// Created by tox on 17/04/2019.
//

#include "RandWord.h"

RandWord::RandWord(string pathToFile) {
    file = createStream(pathToFile);
    countLineAndGetWordFromFile();
    file.close();
}

ifstream RandWord::createStream(string pathToFile) {
    ifstream file(pathToFile);
    return file;
}

void RandWord::setWnb(int nb) {
    wNb = nb;
}


bool RandWord::countLineAndGetWordFromFile(){
    string word{""};
    int nbLine{0};

    if(file.is_open()){
        while(!file.eof()){
            file >> word;
            wordTab.push_back(word);
            nbLine++;
        }
        setWnb(nbLine);
        return true;
    }
    else{
        return false;
    }
}

int RandWord::randomLineNb(int nbLine) {
    srand(time(nullptr));
    int randNb = rand() % nbLine;
    return randNb;
}

string RandWord::selectWordInVec(int randNb, vector<string> vWord){
    cout << "selected word : " << vWord.at(randNb) << endl;
    return vWord.at(randNb);
}

string RandWord::getRandomWord() {
    return selectWordInVec(randomLineNb(getWnb()), getWordTab());
}