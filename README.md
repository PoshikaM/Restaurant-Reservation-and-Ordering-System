# Restaurant Reservation and Ordering System (`code.app`)

## 📋 Project Overview

This is a **Restaurant Reservation and Ordering System** developed in C++ using **Object-Oriented Programming (OOP)** principles. The system supports different types of customers (Dine-In and Takeout) and different types of food items (Appetizer, Entree, Dessert). It allows customers to place orders and handle reservations based on customer type.

---

## ⚙️ Setup Instructions

1. **Clone the Repository or Download Files**
   - Make sure you have the `code.app` file saved locally.

2. **Open the Project in VS Code**
   - Make sure the file `code.app` is opened in Visual Studio Code.

3. **Install C++ Extension (if not already installed)**
   - Go to Extensions (Ctrl+Shift+X) and install **"C/C++" by Microsoft**.

4. **Run the Program**
   - Click the ▶️ **Run** button at the top right corner of the VS Code window.

## 🧱 System Architecture

### Classes Used

- FoodItem (abstract base class)

  - Derived by: Appetizer, Entree, Dessert

- Customer (abstract base class)

  - Derived by: DineInCustomer, TakeoutCustomer

- Order

  - Contains customer and a list of food items.
