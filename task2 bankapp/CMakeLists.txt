cmake_minimum_required(VERSION 3.23)
project(task2_bankapp)

set(CMAKE_CXX_STANDARD 14)

add_executable(task2_bankapp main.cpp savinBank.cpp savinBank.h Client.cpp Client.h BankAAcount.cpp BankAccount.h BankAccount.cpp BankApplication.cpp BankAccountt.h BankApplication.h)
