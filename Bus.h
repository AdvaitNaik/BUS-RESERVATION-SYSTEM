#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

class Bus {
private:
    std::string name;
    std::vector<bool> seats;
    std::map<int, std::string> reservations;

public:
    Bus(std::string n, int numSeats) : name(n), seats(numSeats, false) {}
    void bookSeat(int seatNumber, const std::string& passengerName);
    void cancelSeat(int seatNumber);
    void showStatus() const;
    void saveData() const;
    void loadData();
};