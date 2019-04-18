//
// Created by tox on 17/04/2019.
//

#ifndef UNTITLED_PLAY_H
#define UNTITLED_PLAY_H

#include <iostream>
#include <vector>
using namespace std;

class Play {
private:
    int missPlay;
    string scWord;
    vector<bool> findedChar;

    void setWord(string word);
    void compareInputAndWord(char input, string word);

public:
    void setMissPlay(int value);
    string getScWord(){return scWord;}
    int getMissPlay(){ return missPlay;}


    Play();
    bool replay(char resp);
    bool startGame(string scWord);
    void printMaskedWord();
    void getUserInput();
    bool gameOver();
    bool win();
};


#endif //UNTITLED_PLAY_H
