#include <iostream>
#include <cstdlib>
#include <fstream>

std::fstream cashMachine;
int arrSize = 1000;

void bankLoading(int *bank){
    cashMachine.open ("..\\cashMachine.bin", std::ios::binary | std::ios::out);
    int bill = 0;
    for (int i = 0; i < arrSize; i++ ){
        if (bank[i] == 0) {
            bill = std::rand() % 6;
            if (bill == 0) bank[i] = 100;
            else if (bill == 1) bank[i] = 200;
            else if (bill == 2) bank[i] = 500;
            else if (bill == 3) bank[i] = 1000;
            else if (bill == 4) bank[i] = 2000;
            else if (bill == 5) bank[i] = 5000;
        }
        cashMachine.write((char *) &bank[i], sizeof(bank[i]));
    }
    cashMachine.close();
}

void cashWithdrawal(int *bank){
    int cash;
    std::cout << "Enter the amount to withdraw (multiple of 100): ";
    std::cin >> cash;
    bool check = false;

    cashMachine.open ("..\\cashMachine.bin", std::ios::binary | std::ios::out);

    for (int i = 0; i < arrSize && !check; i++){

        if (cash - bank[i] > 0){
            cash -= bank[i];
            bank[i] = 0;
        }
        else if (cash - bank[i] == 0) {
            check = true;
            cash -= bank[i];
            bank[i] = 0;
        }
        else i++;

        cashMachine.write((char *) &bank[i], sizeof(bank[i]));
    }
    cashMachine.close();

    if (cash > 0) std::cout << "It is not possible to issue the required amount !!!\n";
}

int main() {
    int bank[1000] = {0};

        std::cout << "Input + add bills\n";
        std::cout << "Input - issue bills\n";
        std::cout << "What do you want to do: ";
        char userInput;
        std::cin >> userInput;

        if (userInput == '+') bankLoading(bank);
        else if (userInput == '-') cashWithdrawal(bank);
        else std::cout << "Input is not correct! Try again!!!\n";
}