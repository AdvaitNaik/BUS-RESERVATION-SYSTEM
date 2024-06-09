// ReservationSystem.cpp
#include "ReservationSystem.h"
#include <iostream>

void ReservationSystem::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        executeAction(choice);
    } while (choice != 4);
}

void ReservationSystem::displayMenu() {
    std::cout << "1. Book a seat\n";
    std::cout << "2. Cancel a booking\n";
    std::cout << "3. Show bus status\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void ReservationSystem::executeAction(int choice) {
    int busNumber, seatNumber;
    std::string passengerName;
    switch (choice) {
        case 1:
            std::cout << "Enter bus number and seat number to book: ";
            std::cin >> busNumber >> seatNumber;
            std::cout << "Enter passenger name: ";
            std::cin >> passengerName;
            if (busNumber < buses.size()) {
                buses[busNumber].bookSeat(seatNumber, passengerName);
            }
            break;
        case 2:
            std::cout << "Enter bus number and seat number to cancel: ";
            std::cin >> busNumber >> seatNumber;
            if (busNumber < buses.size()) {
                buses[busNumber].cancelSeat(seatNumber);
            }
            break;
        case 3:
            std::cout << "Enter bus number to show status: ";
            std::cin >> busNumber;
            if (busNumber < buses.size()) {
                buses[busNumber].showStatus();
            }
            break;
        case 4:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid option, please try again." << std::endl;
    }
}
