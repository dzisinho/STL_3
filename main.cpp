#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Car {
    string name;
    int year;
    double engine;
    double price;

    void print() const {
        cout << name << " | " << year << " | " << engine << " L | $" << price << endl;
    }
};

class Showroom {
    vector<Car> cars;

public:
    void addCar(const string& name, int year, double engine, double price) {
        cars.push_back({ name, year, engine, price });
    }

    void removeCar(const string& name) {
        cars.erase(remove_if(cars.begin(), cars.end(), [&](const Car& c) { return c.name == name; }), cars.end());
    }

    void showCars() const {
        for (const auto& car : cars) car.print();
    }

    void sortByPrice() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) { return a.price < b.price; });
    }

    void findCar(const string& name) const {
        auto it = find_if(cars.begin(), cars.end(), [&](const Car& c) { return c.name == name; });
        if (it != cars.end()) it->print();
        else cout << "Car not found.\n";
    }
};

int main() {
    Showroom showroom;
    showroom.addCar("BMW X5", 2020, 3.0, 50000);
    showroom.addCar("Audi A6", 2018, 2.5, 30000);
    showroom.addCar("Toyota Camry", 2021, 2.0, 28000);

    cout << "All cars:\n";
    showroom.showCars();

    cout << "\nSorting by price:\n";
    showroom.sortByPrice();
    showroom.showCars();

    cout << "\nSearching for Toyota Camry:\n";
    showroom.findCar("Toyota Camry");

    cout << "\nRemoving Audi A6...\n";
    showroom.removeCar("Audi A6");
    showroom.showCars();

    return 0;
}
