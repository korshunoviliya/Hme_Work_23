#include <iostream>
#include <fstream>
#include <string>

std::string volidationDate(std::string date){
    while (true) {
        date.clear();
        std::cout << "Input payment date(DD.MM.YYYY): ";
        std::cin >> date;
        bool check = true;
        for (int i = 0; i < date.length() && check; i++){
            if (i == 2 || i == 5){
                date[i] = '.';
                i++;
            }
            if (date[i] >= '0' && date[i] <= '9') check = true;
            else check = false;
        }
        if (check) {
            int day = std::stoi(date.substr(0, 2));
            int month = std::stoi(date.substr(3, 2));
            int year = std::stoi(date.substr(6, 4));

            if (date.length() == 10 && (day > 0 && day <= 31) &&
                (month > 0 && month <= 12) &&
                (year > 1900 && year <= 2021)) return date;
        }
        std::cout << "Input is not correct! Try again!!!\n";
    }
}

std::string volidationSum (std::string sum){
    while (true) {
        sum.clear();
        bool check = true;
        int counterPoint = 0;
        std::cout << "Input payment amount: ";
        std::cin >> sum;
        for (int i = 0; i < sum.length() && check; i++){
            if ((sum[i] >= '0' && sum[i] <= '9') || (sum[i] == '.' && counterPoint < 1)) check = true;
            else check = false;
            if (sum[i] == '.') counterPoint++;
        }
        if (check) return sum;
        std::cout << "Input is not correct! Try again!!!\n";
    }
}

void inputData(std::string name, std::string family, std::string paymentDate, std::string sum){

    std::ofstream bill;

    std::cout << "Input name: ";
    std::cin >> name;
    std::cout << "Input family: ";
    std::cin >> family;
    paymentDate = volidationDate(paymentDate);
    sum = volidationSum(sum);

    bill.open ("..\\bill.txt", std::ios::app);
    bill << name << " " << family << " " << paymentDate << " " << sum << "\n";

    bill.close();
}

void printBill (std::string name, std::string family, std::string paymentDate, std::string sum){

    std::ifstream bill;

    bill.open("..\\bill.txt");

    if (bill.is_open()) {
        while (true){
            bill >> name >> family >> paymentDate >> sum;
            if (bill.eof()) break;
            std::cout << name << "\t" << family << "\t" << paymentDate << "\t" << sum << "\n";
        }
    }
    else std::cout << "Error! File is not open!!!\n";

    bill.close();
}

int main() {
    int answer;
    std::string name;
    std::string family;
    std::string paymentDate;
    std::string sum;

    while(true) {
        std::cout << "1 - enter new data into the list,\n"
                     "2 - display the list on the screen,\n"
                     "0 - terminate the program\n"
                     "What do you want to do?: \n";
        std::cin >> answer;

        if (answer == 1) inputData(name, family, paymentDate, sum);
        else if (answer == 2) printBill(name, family, paymentDate, sum);
        else if (answer == 0)
        {
            std::cout << "See you later\n";
            return 0;
        }
        else std::cout << "Input is not correct. Try again!!!\n";
    }
}
