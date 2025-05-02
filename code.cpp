#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Abstract base class - Abstraction & Polymorphism
class FoodItem {
protected:
    string name;
    double price;
public:
    FoodItem(string n, double p) : name(n), price(p) {}
    virtual void display() const = 0; // Pure virtual function
    virtual ~FoodItem() {}
    double getPrice() const { return price; }
};

// Inheritance - Derived food items
class Appetizer : public FoodItem {
public:
    Appetizer(string n, double p) : FoodItem(n, p) {}
    void display() const override {
        cout << "Appetizer: " << name << " - $" << price << endl;
    }
};

class Entree : public FoodItem {
public:
    Entree(string n, double p) : FoodItem(n, p) {}
    void display() const override {
        cout << "Entree: " << name << " - $" << price << endl;
    }
};

class Dessert : public FoodItem {
public:
    Dessert(string n, double p) : FoodItem(n, p) {}
    void display() const override {
        cout << "Dessert: " << name << " - $" << price << endl;
    }
};

// Abstract base class - Customer
class Customer {
protected:
    string name;
public:
    Customer(string n) : name(n) {}
    virtual void reserveTable() const = 0;
    virtual void displayType() const = 0;
    virtual ~Customer() {}
};

// Inheritance + Polymorphism - Dine-in and Takeout
class DineInCustomer : public Customer {
public:
    DineInCustomer(string n) : Customer(n) {}
    void reserveTable() const override {
        cout << "Table reserved for dine-in customer: " << name << endl;
    }
    void displayType() const override {
        cout << name << " is a Dine-In Customer.\n";
    }
};

class TakeoutCustomer : public Customer {
public:
    TakeoutCustomer(string n) : Customer(n) {}
    void reserveTable() const override {
        cout << "No table needed for takeout customer: " << name << endl;
    }
    void displayType() const override {
        cout << name << " is a Takeout Customer.\n";
    }
};

// Encapsulation - Order class
class Order {
private:
    vector<shared_ptr<FoodItem>> items;
    Customer* customer;
public:
    Order(Customer* c) : customer(c) {}

    void addItem(shared_ptr<FoodItem> item) {
        items.push_back(item);
    }

    void showOrder() {
        cout << "\nOrder Summary:\n";
        double total = 0;
        for (auto& item : items) {
            item->display();
            total += item->getPrice();
        }
        cout << "Total: $" << total << endl;
    }

    void processReservation() {
        customer->reserveTable();
    }

    void showCustomerType() {
        customer->displayType();
    }
};

// Main function to test
int main() {
    // Creating customers
    DineInCustomer dineIn("Alice");
    TakeoutCustomer takeout("Bob");

    // Create food items
    auto springRolls = make_shared<Appetizer>("Spring Rolls", 5.99);
    auto steak = make_shared<Entree>("Grilled Steak", 18.50);
    auto iceCream = make_shared<Dessert>("Vanilla Ice Cream", 4.25);

    // Creating orders
    Order order1(&dineIn);
    order1.addItem(springRolls);
    order1.addItem(steak);
    order1.addItem(iceCream);

    order1.processReservation();
    order1.showCustomerType();
    order1.showOrder();

    cout << "\n------------------------\n";

    Order order2(&takeout);
    order2.addItem(steak);
    order2.addItem(iceCream);

    order2.processReservation();
    order2.showCustomerType();
    order2.showOrder();

    return 0;
}