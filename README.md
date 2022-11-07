
<h1 align="center">
  <br>
  Simple Console Based Book Keeping System in C++ 
  <br>
</h1>

<h4 align="center">This is a console based application to represents the basic operations of a Book Keeping System.</h4>

<p align="center">
  <a href="https://"><img src="https://img.shields.io/badge/language-C++-2ea44f?logo=java" alt="language - C++"></a>
  <a href="https://"><img src="https://img.shields.io/badge/Simple Console application-localhost-orange?logo=IDE" alt="Console application"></a>
  <a href="https://"><img src="https://img.shields.io/badge/inputdata_structure-text_file-yellow?logo=IDE" alt="text"></a>
  <br>
  <a href="#description">Description</a> 
</p>


## Description

- First, read the balance.txt and create text file for each account under account number with opening balance as indicated in the balance.txt. 
- Second, perform the transactions on the accounts as indicated in the transaction.txt. E. g. : If a customer deposit money, it should be indicated in both customer and bank vault account as well. 
- Thirdly, implement the following two operations on the accounts:
1. If the balance is less than Rs 1000.00, a Rs10.00 charge will be added to the customer’s account and add that charge to the bank vault at the end of each day. 
2. If the balance is negative, Rs50.00 will be charged from the customer’s account as overdraft charge at the end of the day. 
3. A daily interest of 0.02% will be added to all the customers’ accounts at the beginning of the day if the balance is positive. Round the interest value up to 2nd decimal place (eg. 0 to 0.005 rounded to .00 and 0.0051to 0.0099 to 0.01) before adding it to account balance. 

<br>
When the program starts, delete all the customer account files and rewrite them freshly. The UI should give options to view bank vault balance and current balance of all the customer accounts. User can enter the date and see the starting balance (before applying interest) and end of the day balance of
