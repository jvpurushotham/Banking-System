# Bank System

A simple C++ console-based bank system that allows users to create bank accounts, deposit and withdraw money, and display account details. This project is intended for educational purposes to demonstrate basic object-oriented programming concepts and dynamic memory management using C++.

## Features

- **Create Account**: Add a new bank account with an account holder's name, account number, and initial balance.
- **Deposit**: Deposit a specified amount into an existing bank account.
- **Withdraw**: Withdraw a specified amount from an existing bank account, with a check for sufficient balance.
- **Display Account Details**: View the details of a bank account, including the account holder's name, account number, and current balance.
- **Menu-Driven Interface**: Provides a simple text-based menu for user interaction.

## Project Structure

- **BankAccount Class**: Manages individual bank accounts with private data members for the account holder's name, account number, and balance. Contains member functions for depositing, withdrawing, and displaying account details.
- **Bank Class**: Manages multiple `BankAccount` objects using a vector. Provides functions to create accounts, find an account by its number, and perform bank operations.

## Getting Started

### Prerequisites

- C++ compiler (such as g++)

### Compilation and Execution

1. Clone this repository or download the source files.
2. Open a terminal or command prompt.
3. Compile the program using:
   ```
   g++ -o bank_system bank_system.cpp
   ```
4. Run the executable:
   ```
   ./bank_system
   ```
