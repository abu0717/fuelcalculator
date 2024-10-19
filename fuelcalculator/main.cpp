#include <iostream>
using namespace std;

void settings(int &tank_size, int &kmPerLitre, int &fuel_in, int &kmpassed, int &fuel_price){
    cout << "\nPlease enter Tank size: ";
    cin >> tank_size;
    
    cout << "\nPlease enter KM per litre: ";
    cin >> kmPerLitre;
    
    cout << "\nPlease enter fuel in your car: ";
    cin >> fuel_in;
    
    cout << "\nPlease enter km that passed: ";
    cin >> kmpassed;
    
    cout << "\nPlease enter fuel price: ";
    cin >> fuel_price;
}

void buy_fuel(int &fuelBuy, double &fuelAv, int tank_size, int &totalFuelBought) {
    cout << "\nThe fuel in your tank is " << fuelAv;
    cout << "\nEnter the fuel in litres that you bought: ";
    cin >> fuelBuy;
    
    if (fuelBuy + fuelAv > tank_size) {
        cout << "\nFuel can't fit in the tank";
    } else {
        fuelAv += fuelBuy;
        totalFuelBought += fuelBuy;
        cout << "\nFuel in tank: " << fuelAv;
    }
}

void km_passed(int &kmPass, double &required_fuel, int &kmPerLitre, int &kmpassed, double &fuelAv){
    cout << "\nCurrent km passed "<< kmpassed;
    cout << "\nEnter km passed: ";
    cin >> kmPass;
    required_fuel = (double) kmPass / kmPerLitre;
    if (required_fuel > fuelAv){
        cout <<"\nFuel is not enough to cover the distance ";
    }else{
        kmpassed += kmPass;
        fuelAv -= required_fuel;
        cout << "\nUpdated km passed: " << kmpassed;
        cout << "\nFuel left in tank: " << fuelAv;
    }
}

void report(double &fuelAv, int &kmPerLitre, int &kmpassed, int &totalFuelBought, int &fuelPrice){
    cout << "~~~Report of gas usage~~~";
    cout << "\nFuel in tank (ltr): " << fuelAv;
    cout << "\nWith current fuel, approx km to pass: " << fuelAv * kmPerLitre;
    cout << "\nKm passed: " << kmpassed;
    cout << "\nTotal fuel bought: " << totalFuelBought;
    cout << "\nFuel price per litre: " << fuelPrice;
    cout << "\nTotal cost of fuel bought: " << totalFuelBought * fuelPrice;
    cout << "\n+++End of report+++" << endl;
}

int main(int argc, const char * argv[]) {
    
    bool Continue = true;
    
    int tank_size = 0, kmPerLitre = 0, fuel_in = 0, fuelPrice = 0;
    double fuelAv = 0;
    double required_fuel = 0;
    int totalFuelBought = 0, userInput, fuelBuy, kmpassed = 0, kmPass = 0;
    
    while (Continue) {
        cout << "\nMenu";
        cout << "\n(1) for settings";
        cout << "\n(2) buy fuel";
        cout << "\n(3) km passed";
        cout << "\n(4) report";
        cout << "\n(-1) to stop" << endl;
        cin >> userInput;
        
        switch (userInput) {
            case 1:
                settings(tank_size, kmPerLitre, fuel_in, kmpassed, fuelPrice);
                fuelAv = fuel_in;
                break;
                
            case 2:
                buy_fuel(fuelBuy, fuelAv, tank_size, totalFuelBought);
                break;
            case 3:
                km_passed(kmPass, required_fuel, kmPerLitre, kmpassed, fuelAv);
                break;
            case 4:
                report(fuelAv, kmPerLitre, kmpassed, totalFuelBought, fuelPrice);
                break;
            case -1:
                Continue = false;
                break;
            default:
                cout<<"Invalid input, please choose a valid option." << endl;
        }
    }
    
    return 0;
}
