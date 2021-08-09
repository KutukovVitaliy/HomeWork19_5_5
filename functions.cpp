//
// Created by kvitadmin on 09.08.2021.
//
#include "functions.h"

void viewFile(const std::string& path){
    std::ifstream txtFile;
    char buf[256];

    txtFile.open(path, std::ios::binary);
    if(!txtFile.is_open()){
        std::cout << "Bad file name!" << std::endl;
        return;
    }
    while (!txtFile.eof()) {
        txtFile.read(buf, 255);
        buf[txtFile.gcount()] = 0;
        std::cout << buf;
    }
    txtFile.close();

}

int CheckSectors(std::vector<int> &SectorsInGame, int currentSector, int Sectors){
    bool findEl = false;
    for(int el : SectorsInGame){
        if(currentSector == el){
            findEl = true;
        }
    }
    if(!findEl) return currentSector;
    currentSector++;
    currentSector %= Sectors;
    if(currentSector == 0) currentSector++;
    CheckSectors(SectorsInGame,currentSector,Sectors);
}

int GetSector(int currentSector, int Sectors, std::vector<int> &SectorsInGame){
    bool Input;
    int Offset;
    std::string InputValue;

    do{
        Input = true;
        std::cout << "Please, enter the offset from 1 to 1000: ";
        std::cin >> InputValue;
        for(char element : InputValue){
            if(element < '0' || element > '9'){
                Input = false;
                break;
            }

        }
        if(Input){
            Offset = stoi(InputValue);
            if(Offset < 1 || Offset > 1000) {
                Input = false;
            }
        }
        if(!Input) std::cout << "Offset is incorrect!" << std::endl;
    }while(!Input);
    currentSector += Offset;
    currentSector %= Sectors;
    if(currentSector == 0) currentSector++;
    currentSector = CheckSectors(SectorsInGame, currentSector, Sectors);
    return currentSector;
}

bool CheckAnswer(int currentSector, const std::string& answer){
    std::ifstream answerFile;
    std::string answerFromFile;
    answerFile.open("../answer_" + std::to_string(currentSector) + ".txt");
    if(answerFile.is_open()){
        answerFile >> answerFromFile;
        answerFile.close();
    }
    else std::cout << "Can't open answer file!" << std::endl;
    if(answer == answerFromFile){
        std::cout << "Your answer is correct!" << std::endl;
        return true;
    }
    else {
        std::cout << "Your answer is wrong!" << std::endl;
        std::cout << "Correct answer is: " << answerFromFile << std::endl;
        return false;
    }
}