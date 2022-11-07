#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    ifstream account("Balance.txt"); //read the text files
    ifstream transaction("Transaction.txt");
    if (account.is_open() && transaction.is_open()) //check whether the file is opened
    {
    	//************************************balance.txt************************************
    	
    	vector<string> container_one, container_two, container_three; /*containers are vectors to store dates, account numbers, opening balances 
																	    in balance.txt file sequencely*/
        string line;
        string date, account_number, account_balance;
        
        
        
        while(getline(account, line) ) //read the balance.txt file and put each word into particular vector
        {
            stringstream ss(line);
            
            getline(ss,date,',');    
            container_one.push_back(date);
            getline(ss,account_number,','); 
            container_two.push_back(account_number);
            getline(ss,account_balance,','); 
			container_three.push_back(account_balance);
        }
        
        
        
        ofstream bank_vault("bank vault.txt");//convert the opening balances from string vector to integer vector 
        float bank_total = 0;
        stringstream object;
        int num;
        vector<int> int_container_three;
        for(int i=0; i<10; i++)
        {
        	num = stoi(container_three[i]);
        	//cout << num << endl;
			int_container_three.push_back(num);
			bank_total = bank_total + int_container_three[i];			
		}
		bank_vault << "Opening balance: " << fixed << setprecision(2) << bank_total << endl;
		
		
		
		//************************************transaction.txt************************************
        
		vector<string> t_container_one, t_container_two, t_container_three, t_container_four; /*t_containers are vectors to store 
									dates, account numbers, transaction type, transaction amounts in transacion.txt file sequencely*/
        string t_line;
        string t_date, t_account_number, transaction_type, amount;
               
        while(getline(transaction, t_line) ) //read the transaction.txt file and put each word into particular vector
        {
            stringstream t_ss(t_line);
            
            getline(t_ss,t_date,',');    
            t_container_one.push_back(t_date);
            getline(t_ss,t_account_number,','); 
            t_container_two.push_back(t_account_number);
            getline(t_ss,transaction_type,','); 
			t_container_three.push_back(transaction_type);
			getline(t_ss,amount,','); 
			t_container_four.push_back(amount);
        }
		
		
		
		stringstream t_object; //convert the transaction values from string vector to integer vector 
        float t_num;
        vector<float> t_float_container_four;
        for(int i=0; i<180; i++)
        {
        	t_num = stoi(t_container_four[i]);
			t_float_container_four.push_back(t_num);			
		}
		
		
		
		for(int i=0; i<180; i++) //update the bank vault.txt according to the transactions
        {
			if(t_container_three[i] == "1")
			{
				bank_total += t_float_container_four[i];				
				bank_vault << "Date:" << t_container_one[i] << "  Account:" << t_container_two[i] << "  TransactionType:" << t_container_three[i] << "  Amount:" << t_container_four[i] << "  Balance:" << fixed << setprecision(2) << bank_total << endl;
			}
			else
			{
				bank_total -= t_float_container_four[i];
				bank_vault << "Date:" << t_container_one[i] << "  Account:" << t_container_two[i] << "  TransactionType:" << t_container_three[i] << "  Amount:" << t_container_four[i] << "  Balance:" << fixed << setprecision(2) << bank_total << endl;
			}
		}
		bank_vault << "End of the day balance: " << fixed << setprecision(2) << bank_total << endl;
		
		
		
		float given_interests, got_charges;
		string number, balance;
        for(int i=0; i<10; i++) //create individual accounts as .txt files and include the opening balance of each account
        {
        	number = container_two[i];
        	balance = container_three[i];
			ofstream account(number);
			account << "Opening balance: " << balance << endl;
			float float_balance = stoi(balance);
			
			int j;
			for(j=0; j<180; j++)
			{
				if(number == t_container_two[j]) //identify and validate the account number
				{
					if(t_container_three[j] == "1") //identify and validate the transaction type
					{
						float_balance += t_float_container_four[j];
						account << "Date:" << t_container_one[j] << "  Account:" << t_container_two[j] << "  TransactionType:" << t_container_three[j] << "  Amount:" << t_container_four[j] << "  Balance:" << fixed << setprecision(2) << float_balance << endl;	
					}
					else
					{
						float_balance -= t_float_container_four[j];
						account << "Date:" << t_container_one[j] << "  Account:" << t_container_two[j] << "  TransactionType:" << t_container_three[j] << "  Amount:" << t_container_four[j] << "  Balance:" << fixed << setprecision(2) << float_balance << endl;					
					}						
				}			
			}
			account << "Closing balance: " << fixed << setprecision(2) << float_balance << endl;
			
			
			
			float day_charge = 0;
			float day_interest = 0;	
			float day_float_balance = int_container_three[i];		
			
			for(int k=0; k<180; k++) //generate report details accordning to the date user input
			{
				string each_day = t_container_one[k];						
			
				if(number == t_container_two[k]) //validating the account number
				{
					if(each_day == "20210101") //validate the date
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210102") //validate the date
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210103")
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210104")
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210105")
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210106")
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210107")
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210108")
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210109")
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
					
					else if(each_day == "20210110")
					{
						if(t_container_three[k] == "1")
							day_float_balance += t_float_container_four[k];
						else
							day_float_balance -= t_float_container_four[k];										
					}
										
				}
				
				if(day_float_balance < 1000 && day_float_balance>0) //update if any interests or charges in each account
					day_charge += 10.0;
				else if(day_float_balance < 0) 
					day_charge += 50.0;
				else if(day_float_balance > 0)
					day_interest += day_float_balance*0.0002;				
			}  
					
									
			given_interests	+= day_interest; //update if any interests or charges in bank vault
			got_charges += day_charge;
			
			account << "Charge: " << fixed << setprecision(2) << day_charge << endl;    
			account << "Interest: " << fixed << setprecision(2) << day_interest << endl; 
						
    	}
    	
    	bank_vault << "Got Charge: " << fixed << setprecision(2) << got_charges << endl; 
    	bank_vault << "Given Interests: " << fixed << setprecision(2) << given_interests << endl;
    	
    	
    	
    	//***************************user interface***************************
    	
    	cout << "\n\t*****************Book Keeping System*****************\n\n";
		cout << "Menu:\n";
		cout << "\t0 - Check Balance\t\t1 - Exit\n";
		int input1, input2;
		string input3, input4;
		cout << "Choose:";
		cin >> input1;
		
		switch (input1)
		{
			case 0: 
			{
				cout << "\n\t0 - Bank Vault balance\t\t1 - User Account balance\t2 - By Date\n";
				cout << "Choose:";
				cin >> input2;
				switch (input2)
					{
					case 0:
						{
							//getting full detail report of bank vault
							cout << "Balance: " << fixed << setprecision(2) << bank_total << endl;
							cout << "Got Charges: " << got_charges << endl;
							cout << "Given Interests: " << given_interests << endl;
							break;
						}
					case 1:
						{
							//getting full detail report of any user selected account
							cout << "Enter account number: ";
							cin >> input3;
							cout << endl;
							
							string _line;
							ifstream details(input3);
							while (getline(details, _line)) 
							{
	    						cout << _line << "\n";
	  						}
	  						break;
						}
					case 2:
						{
							//getting full detail report of any user selected date
							cout << "Enter the date: ";
							cin >> input4;
							
							for(int m=0; m<180; m++)
							{
								if(input4 == t_container_one[m])
								{
									cout << "  Account:" << t_container_two[m] << "  TransactionType:" << t_container_three[m] << "  Amount:" << fixed << setprecision(2) << t_container_four[m] << endl;			
								}
							}							
						}
					}
				break;
			}
			
			case 1: 
				return 0;

		}
				
	}
	
	return 0;

}






