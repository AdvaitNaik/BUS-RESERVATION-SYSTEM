#include "Bus.h"
#include <vector>

class ReservationSystem {
private:
    std::vector<Bus> buses;

public:
    void run();
    void displayMenu();
    void executeAction(int choice);
};
