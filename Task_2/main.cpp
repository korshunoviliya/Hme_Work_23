#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

int main (){

    std::srand(std::time(nullptr));
    std::ofstream picture ("..\\picture.txt");
    int width;
    int height;
    bool check = false;
    const int maxWidth = 50;
    const int maxHeight = 50;

    while(!check){
        std::cout << "Enter the width of the painting(from 0 to " << maxWidth << "): ";
        std::cin >> width;
        std::cout << "Enter the height of the painting(from 0 to " << maxHeight << "): ";
        std::cin >> height;

        if (width > 0 && width <= maxWidth &&
            height > 0 && height <= maxHeight)
            check = true;
        else std::cout << "Input is not correct! Try again!!!\n";
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            picture << std::rand() % 2;
        }
        picture << std::endl;
    }
    return 0;
}
