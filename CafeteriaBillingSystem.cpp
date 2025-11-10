#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const double DISCOUNT_RATE = 0.10;
const double DISCOUNT_THRESHOLD = 100.00;
const double COFFEE_PRICE = 15.00;
const double SANDWICH_PRICE = 30.00;
const double SALAD_PRICE = 25.00;
const double JUICE_PRICE = 10.00;
const double MUFFIN_PRICE = 20.00;
const double PIZZA_PRICE = 35.00;
const double SOUP_PRICE = 18.00;
const double BURGER_PRICE = 40.00;

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Coffee - R" << COFFEE_PRICE << endl;
    cout << "2. Sandwich - R" << SANDWICH_PRICE << endl;
    cout << "3. Salad - R" << SALAD_PRICE << endl;
    cout << "4. Juice - R" << JUICE_PRICE << endl;
    cout << "5. Muffin - R" << MUFFIN_PRICE << endl;
    cout << "6. Pizza Slice - R" << PIZZA_PRICE << endl;
    cout << "7. Soup - R" << SOUP_PRICE << endl;
    cout << "8. Burger - R" << BURGER_PRICE << endl;
}

double getItemPrice(int item) {
    switch (item) {
    case 1: return COFFEE_PRICE;
    case 2: return SANDWICH_PRICE;
    case 3: return SALAD_PRICE;
    case 4: return JUICE_PRICE;
    case 5: return MUFFIN_PRICE;
    case 6: return PIZZA_PRICE;
    case 7: return SOUP_PRICE;
    case 8: return BURGER_PRICE;
    default: return 0.0;
    }
}

int main() {
    string name, surname;
    int numItems, item;
    double totalBill = 0.0, discount = 0.0, finalBill = 0.0;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your surname: ";
    cin >> surname;

    displayMenu();
    cout << "Enter the number of items you want to order (up to 8): ";
    cin >> numItems;

    if (numItems < 1 || numItems > 8) {
        cout << "Invalid number of items. Exiting program.\n";
        return 1;
    }

    for (int i = 0; i < numItems; i++) {
        cout << "Enter item number " << (i + 1) << ": ";
        cin >> item;
        double price = getItemPrice(item);

        if (price == 0.0) {
            cout << "Invalid item. Skipping...\n";
            continue;
        }

        totalBill += price;
    }

    if (totalBill > DISCOUNT_THRESHOLD) {
        discount = totalBill * DISCOUNT_RATE;
    }

    finalBill = totalBill - discount;

    cout << fixed << setprecision(2);
    cout << "\nCustomer: " << name << " " << surname << endl;
    cout << "Total Bill: R" << totalBill << endl;
    cout << "Discount: R" << discount << endl;
    cout << "Final Bill: R" << finalBill << endl;

    ofstream file("CafeteriaBill.txt", ios::app);
    if (file.is_open()) {
        file << "Customer: " << name << " " << surname << endl;
        file << "Total Bill: R" << totalBill << endl;
        file << "Discount: R" << discount << endl;
        file << "Final Bill: R" << finalBill << endl;
        file << "----------------------------\n";
        file.close();
        cout << "Bill saved to CafeteriaBill.txt\n";
    }
    else {
        cout << "Error opening file for writing.\n";
    }

    return 0;
}
