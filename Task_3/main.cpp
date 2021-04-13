#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string catchFish;
    std::cout << "What kind of fish do you want to catch?: ";
    std::cin >> catchFish;

    std::ifstream river;
    std::string fishRiver;

    std::fstream basket;
    int catchCounter = 0;

    river.open ("..\\river.txt");

    if (river.is_open()){
        while (!river.eof()){
            river >> fishRiver;
            if (catchFish == fishRiver){
                basket.open ("..\\basket.txt", std::ios::app | std::ios::out);
                if (!basket.is_open()) {
                    std::cerr << "File is not open!!!";
                    exit(1);
                }
                basket << fishRiver << "\n";
                basket.close();
                catchCounter++;
            }
        }
    }
    else{
        std::cerr << "File is not open\n";
        return 1;
    }
    river.close();

    std::cout << "This time you caught fish: " << catchCounter << std::endl;
    catchCounter = 0;

    basket.open ("..\\basket.txt", std::ios::in);

    while (basket.is_open()){
        basket >> catchFish;
        if (basket.eof()) {
            basket.close();
            std::cout << "You caught fish in total: " << catchCounter << std::endl;
            return 0;
        }
        std::cout << catchFish << std::endl;
        catchCounter++;
    }
}
