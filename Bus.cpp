#include "Bus.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Bus::bookSeat(int seatNumber, const std::string& passengerName) {
    if (seatNumber < 0 || seatNumber >= seats.size()) {
        std::cout << "Invalid seat number." << std::endl;
        return;
    }
    if (seats[seatNumber]) {
        std::cout << "Seat " << seatNumber << " is already booked." << std::endl;
        return;
    }
    seats[seatNumber] = true;
    reservations[seatNumber] = passengerName;
    std::cout << "Seat " << seatNumber << " booked successfully for " << passengerName << "." << std::endl;
}

void Bus::cancelSeat(int seatNumber) {
    if (seatNumber < 0 || seatNumber >= seats.size() || !seats[seatNumber]) {
        std::cout << "Invalid operation or seat is not booked." << std::endl;
        return;
    }
    seats[seatNumber] = false;
    reservations.erase(seatNumber);
    std::cout << "Reservation canceled for seat " << seatNumber << "." << std::endl;
}

void Bus::showStatus() const {
    for (int i = 0; i < seats.size(); ++i) {
        std::cout << "Seat " << i << ": " << (seats[i] ? "Booked by " + reservations.at(i) : "Available") << std::endl;
    }
}

void Bus::saveData() const {
    std::ofstream file((name + "_data.txt").c_str());
    for (int i = 0; i < seats.size(); ++i) {
        if (seats[i]) {
            file << i << " " << reservations.at(i) << "\n";
        }
    }
    file.close();
}

void Bus::loadData() {
    std::ifstream file((name + "_data.txt").c_str());
    std::string line, name;
    int seatNumber;
    while (getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> seatNumber >> name)) { break; }
        if (seatNumber >= 0 && seatNumber < seats.size()) {
            seats[seatNumber] = true;
            reservations[seatNumber] = name;
        }
    }
    file.close();
}
