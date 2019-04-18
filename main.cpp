#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class DicoReader
{
private:
    ifstream file;
    int nbWord;
    string randWord;
    vector<string> vWord;

    static ifstream createStream(string path){
        ifstream File(path);
        return File;
    }

    void setRandWord(string word){
        randWord = word;
    }

    void setNbWord(int nb){
        nbWord = nb;
    }

    void addWordandCountFromDico(){
        string word{""};
        int nb{0};

        if(file.is_open()){
            while(!file.eof()){
                file >> word;
                vWord.push_back(word);
                nb++;
            }

            setNbWord(nb);
        }
    }

    void selectRandWord(){
        srand(time(nullptr));
        int randNb{rand()% nbWord};
        setRandWord(vWord.at(randNb));
    }

public:
    DicoReader(string path){
        file = createStream(path);
        addWordandCountFromDico();
        file.close();
    }

    string getRandWord(){
        return randWord;
    }


};

bool replay(char resp){
   return (resp == 'o')? true : false;
}

int main()
{
    char response{' '};
    DicoReader dr("dico.txt");

    do
    {
        cout << dr.getRandWord() << endl;


        cout << "voulez vous rejouer ? o/n";
        cin >> response;
    }while(replay(response));

    return 0;
}

