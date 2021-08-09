#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
#include <vector>



int main() {
    int Sectors = 13, CurrentSector = 1, viewerCount = 0, expertCount = 0;
    std::string answer;
    std::vector<int> SectorsInGame;
    do{
        CurrentSector = GetSector(CurrentSector, Sectors, SectorsInGame);
        SectorsInGame.push_back(CurrentSector);
        std::cout << "New sector is " << CurrentSector << std::endl;
        std::cout << "Question: " << std::endl;
        viewFile("../question_" + std::to_string(CurrentSector) + ".txt");
        std::cout << std::endl << "Please enter the answer: ";
        std::cin >> answer;
        if(CheckAnswer(CurrentSector, answer)) expertCount ++;
        else viewerCount++;
        std::cout << "Current score: Viewers - " << viewerCount << " Experts - " << expertCount << std::endl;
    }while (expertCount < 6 && viewerCount < 6);
    std::cout << "Game is over!" << std::endl;
    if(expertCount < 6) std::cout << "The viewers won!" << std::endl;
    else std::cout << "The experts won!" << std::endl;
    return 0;
}
