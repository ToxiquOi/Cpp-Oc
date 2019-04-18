//
// Created by tox on 17/04/2019.
//

#include "Play.h"
#include <iomanip>


Play::Play(){
}

void Play::setMissPlay(int value) {
    missPlay = value;
}

void Play::setWord(string word) {
    scWord = word;
}

bool Play::startGame(string scWord) {
    setWord(scWord);
    setMissPlay(0);
    for (int i = 0; i < scWord.size() ; ++i){
        findedChar.push_back(false);
    }
    cout << "Le PENDU" << endl;
    return true;
}

bool Play::replay(char resp){
    return (resp == 'o')? true : false;
}

void Play::getUserInput() {
    char input{' '};
    cout << "enter a letter : ";
    cin >> input;
    cout << endl;
    compareInputAndWord(toupper(input), getScWord());
}

void Play::compareInputAndWord(char input, string word) {
    int charFind{0};
    for (int i = 0; i < word.size() ; ++i) {
        if(word[i] == input){
            charFind++;
            findedChar.at(i) = true;
        }
    }
    if(charFind == 0){
        missPlay++;
    }
}

void Play::printMaskedWord(){
    cout << setfill('#') << setw(1) <<" word to find : ";
    for (int i = 0; i < getScWord().size() ; ++i) {
        if(findedChar.at(i) == true){
            cout << getScWord()[i];
        }
        else{
            cout << '*';
        }
    }
    cout << endl;
}

bool Play::gameOver() {
    if (getMissPlay() == 5){
        cout << "Game over ! 5 Error" << endl;
        findedChar.clear();
        return true;
    }
    else {
        return false;
    }
}

bool Play::win() {
    int charFind{0};
    if(getMissPlay() < 5){
        for (int i = 0; i < getScWord().size() ; ++i) {
            if(findedChar[i] == true){
                charFind++;
            }
        }
        if(charFind == getScWord().size()){
            cout << "you win !" << getScWord() << " was the good word" << endl;
            findedChar.clear();
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}