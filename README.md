🏦 Banking System Project (C++)
=====================================
📌 Project Overview
------------------------

This project is a Simple Banking System developed in C++ that demonstrates Object-Oriented Programming (OOP) concepts such as:

Encapsulation
---------------

Inheritance
-------------
Polymorphism
-----------------
Abstraction
-------------------------
The system allows users to create different types of bank accounts and perform basic banking operations like deposit, withdrawal, balance checking, and interest calculation.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
🎯 Features
=====================
Create different types of bank accounts:
---------------------------------------------

Savings Account
---------------------------------------------
Checking Account
-----------------------------------------
Fixed Deposit Account
------------------------------------------
Deposit money
---------------------------------------------
Withdraw money (with overdraft facility for Checking Account)
-------------------------------------------------------------------------
Check current balance
----------------------------------------
Display account details
----------------------------------------------------
Calculate interest based on account type
-------------------------------------------------
Menu-driven console application
-----------------------------------
🧩 OOP Concepts Used
===============================
1. Encapsulation
----------------------
Account balance is kept private
------------------------------------
Accessed and modified using public methods
----------------------------------------
2. Inheritance
------------------------
SavingsAccount, CheckingAccount, and FixedDepositAccount inherit from BankAccount

3. Polymorphism
----------------------
Function overriding using virtual functions

withdraw() and calculateInterest() behave differently for each account type

4. Abstraction
-----------------------------
Base class BankAccount provides a common interface for all account types

🏗️ Account Types
==============================
🔹 Savings Account
-----------------------------------
Allows deposit and withdrawal

Calculates interest based on user-defined interest rate

🔹 Checking Account
---------------------------------------
Allows overdraft facility

Withdrawal is allowed even if balance is insufficient (within overdraft limit)

🔹 Fixed Deposit Account
------------------------------------------------
Fixed term deposit

Interest calculated based on term period

Withdrawal is restricted

⚙️ Technologies Used
===========================
Language: C++
------------------------------------------------------------------

📋 Sample Menu
======================
--- Banking Menu ---
1. Deposit
   ------------------
3. Withdraw
   ---------------------
5. Check Balance
   ------------------------
7. Display Account Info
   ----------------------------
9. Calculate Interest
    -------------------------
0. Exit
-----------------------------
🧪 Sample Operations
==============================
Deposit money into account

Withdraw money (with overdraft check)

Calculate interest for Savings and Fixed Deposit accounts

Display complete account information

📝 Assumptions
=============================
Only one account is handled at a time

Input values are assumed to be valid

Fixed Deposit withdrawals are restricted

📚 Learning Outcome
====================================
Clear understanding of OOP principles

Practical implementation of polymorphism and inheritance

Improved C++ programming skills

👨‍💻 Author
========================
Name:Charmee paneliya
-------------------------------
Project Type: Academic / Practice Project
--------------------------------
Language: C++
----------------------------

Concepts: OOP (Object-Oriented Programming)
------------------------------------------------

Compiler: Any standard C++ compiler (GCC, Turbo C++, etc.)
