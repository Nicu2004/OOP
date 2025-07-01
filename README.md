# 🧾 Inventory and Employee Management System (C++)

This project is a simple **console-based application** written in **C++**, designed to manage employees and inventory (products) using **object-oriented programming (OOP)** concepts.

## 🚀 Features

- **Employee Management**:
  - Add, view, search, and delete employees
  - Store attributes like name, age, role, salary, and ID

- **Inventory Management**:
  - Add, display, update, and delete products
  - Each product stores name, quantity, and price

- **File Handling**:
  - Load and save employee/product data from and to text files
  - Ensures data persistence between sessions

- **OOP Principles Used**:
  - Classes and Objects
  - Inheritance (`Person` → `Angajat`)
  - Polymorphism (via virtual functions)
  - Encapsulation
  - Modular design

## 🧠 Technologies Used

- C++ (STL: `vector`, `string`, `fstream`)
- File I/O (`ifstream`, `ofstream`)
- Console-based user interaction

## 📂 Project Structure

📁 /project-root
│
├── main.cpp # Main application logic and menu
├── classes/
│ ├── Person.h / .cpp # Base class for common attributes
│ └── Angajat.h / .cpp # Derived class for employee logic
├── produse/
│ ├── Produs.h / .cpp # Product class and operations
│
├── Angajati.txt # Stores employee data
├── Produse.txt # Stores product data
└── README.md # This file

shell
Copy
Edit

## 🧪 Example Run

=========== MENIU PRINCIPAL ===========

Gestionare Angajati

Gestionare Produse
-1. Iesire
Alege optiunea: 1

--- Meniu Angajati ---

Adauga Angajat

Afiseaza Angajati

Sterge Angajat

Cauta Angajat

Revenire la meniul principal

markdown
Copy
Edit

## 📌 Future Improvements

- Add authentication for admin access
- Implement search filters (by salary range, name, etc.)
- Add file encryption for sensitive data
- Switch from `.txt` to `.json` or `.csv` format

## 📚 Author

- 👨‍💻 **Nicu Mămăligă**
- 📘 Computer Science Student at UPT
- 💼 Interested in software development, OOP, and secure systems
