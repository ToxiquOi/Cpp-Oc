#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "RandWord.h"
#include "Play.h"


using namespace std;



int main() {
    RandWord rw{RandWord("dico.txt")};
    Play g = Play();
    string secretWord{""};
    char resp{' '};
    bool gameLaunch{false};


    do{
        gameLaunch = g.startGame(rw.getRandomWord());

        while(gameLaunch){

            g.printMaskedWord();
            g.getUserInput();

            if(g.win()){
                gameLaunch = false;
            }
            else if (g.gameOver()){
                gameLaunch = false;
            }
            else{
                cout << "\n\n" << endl;
            }
        }
        cout << "would you like to replay ? o/n :";
        cin >> resp;
    }while(g.replay(resp));


    return 0;
}

