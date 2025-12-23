#define _CRT_SECURE_NO_WARNINGS
#include "time_utility.h"
#include "train.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
bool IsEmptyFile(std::ifstream& in) {
    return in.peek() == EOF;
}
void PrintInformationAboutTrain(const Train& train) {
    std::cout << "Train: " << train.GetId()<< " Type: " << static_cast<int>(train.GetType())<< " Destination: " << train.GetDestination()<< "| Dispatch: ";
    PrintTime(train.GetDispatchTime());
    std::cout << "Travelling time: ";
    PrintTime(train.GetTravellingTime());
    std::cout << std::endl;
}
std::vector<Train> ReadTrains(std::ifstream& fin) {
    using namespace time_utility;
    std::vector<Train> trains;
    std::string line;

    while (std::getline(fin, line)) {
        if (line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        TrainId id;
        int type;
        std::string dest;
        size_t disp_hour, disp_minute, trav_hour, trav_minute;
        if (!(iss >> id >> type >> dest >> disp_hour >> disp_minute >> trav_hour >> trav_minute)) {
            std::cerr << "Invalid information in input file" << std::endl;
            continue;
        }
        try {
            std::time_t dispatch_time = SetTime(disp_hour, disp_minute);
            std::time_t travelling_time = SetTime(trav_hour, trav_minute);
            trains.emplace_back(id, static_cast<TrainType>(type), dest, dispatch_time, travelling_time);
        }
        catch (const std::out_of_range& error) {
            std::cerr << error.what() << std::endl;
            continue;
        }
    }
    return trains;
}
void SortedOnDispatch(std::vector<Train>& trains) {
    std::sort(trains.begin(), trains.end());
    for (const Train& train : trains) {
        PrintInformationAboutTrain(train);
    }
}
void PrintFromTimeToTime(const std::vector<Train>& trains,const std::time_t t1,const std::time_t t2) {
    for (const Train& train : trains) {
        if (train.GetDispatchTime() >= t1 && train.GetDispatchTime() <= t2) {
            PrintInformationAboutTrain(train);
        }
    }
}
void PrintFromDestToDest(const std::vector<Train>& trains, const std::string& dest) {
    for (const Train& train : trains) {
        if (train.GetDestination() == dest) {
            PrintInformationAboutTrain(train);
        }
    }
}
void PrintOnCurrentTypeAndDest(const std::vector<Train>& trains, int type_, const std::string& dest) {
    bool flag_inf_exist = false;
  
    for (const Train& train : trains) {
        if (train.GetType() == TrainType(type_) && train.GetDestination() == dest) {
            PrintInformationAboutTrain(train);
            flag_inf_exist = true;
        }
    }
    if (!(flag_inf_exist)) {
        std::cout << "There is no such a train with your id and type" << std::endl;
   }
}
void PrintTheFastestToCurrentDest(const std::vector<Train>& trains, const std::string& dest) {
    bool flag_for_dest = false;
        const Train* fastest_train = nullptr;
        for (const auto& train : trains) {
            if (train.GetDestination() == dest) {
                flag_for_dest = true;
                if (!fastest_train || train.GetTravellingTime() < fastest_train->GetTravellingTime()) {
                    fastest_train = &train;
                }
            }
        }
        if (flag_for_dest) {
            PrintInformationAboutTrain(*fastest_train);
        }
        else if (!flag_for_dest) {
            std::cout << "There are no trains to " << dest << std::endl;
        }
    }
int main() {
    try {
        using namespace time_utility;
        std::ifstream in("input.txt");
        if (!in.is_open()) {
            in.close();
            throw "Can not open input";
        }
        if (IsEmptyFile(in)) {
            in.close();
            throw "input is empty";
        }
        std::vector<Train> trains = ReadTrains(in);
        std::cout << "All the information about trains:" << std::endl;
        for (const auto& i : trains) {
            PrintInformationAboutTrain(i);
        }
        std::cout << "Sorted on dispatch: " << std::endl;
        SortedOnDispatch(trains);
        
        std::random_device rd;
        std::mt19937 generator(rd());

        std::time_t t1 = SetTime(12, 23);
        try {
            t1 = SetTime(12, 56);
        }
        catch (const std::out_of_range& err) {
            std::cerr << err.what() << std::endl;
        }

        std::time_t t2 = GenerateRandomTime(generator);

        std::cout << "t1: ";
        PrintTime(t1);

        std::cout << "t2: ";
        PrintTime(t2);

        std::cout << "t1 < t2: " << std::boolalpha << (t1 < t2) << '\n';
        std::cout << "t2 < t1: " << std::boolalpha << (t2 < t1) << '\n';
        std::cout << "All the trains between: " << std::endl; 
        PrintTime(t1);
        std::cout << "and" << std::endl;
        PrintTime(t2);
        std::cout << "are: " << std::endl;
        PrintFromTimeToTime(trains, t1, t2);
        std::string dest1{ "Minsk" };
        std::cout << "All the trains on destination: " << dest1 << std::endl;
        PrintFromDestToDest(trains, dest1);
        int type = 9;
        std::string dest2{ "Warsaw" };
        std::cout << "Train for type: " << type << " and dist " << dest2 << " are: " << std::endl;
        PrintOnCurrentTypeAndDest(trains, type, dest2);

        std::cout << "The fastest to dest " << dest2 << " is: " << std::endl;
        PrintTheFastestToCurrentDest(trains, dest2);

        return EXIT_SUCCESS;
    }
    catch (const char* msg) {
        std::cerr << msg;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return 1;
    }
}
