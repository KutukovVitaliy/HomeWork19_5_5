//
// Created by kvitadmin on 09.08.2021.
//

#ifndef HOMEWORK19_5_5_FUNCTIONS_H
#define HOMEWORK19_5_5_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>

void viewFile(const std::string& path);
int CheckSectors(std::vector<int> &SectorsInGame, int currentSector, int Sectors);
int GetSector(int currentSector, int Sectors, std::vector<int> &SectorsInGame);
bool CheckAnswer(int currentSector, const std::string& answer);
#endif //HOMEWORK19_5_5_FUNCTIONS_H
