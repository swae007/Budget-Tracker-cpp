#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
 	cout<< "-----Welcome to MyBudget app-----\n\n";
	
	//gets user's name for file creation'
	 string username;
     cout << "Enter your name: ";
     cin >> username; 
     string filename = username + ".txt";

   
     //this is to check if the file being created already exists
     ifstream checkFile(filename);
     if (checkFile.good()) {
         cout << "Welcome back " << username << "!\n";
     } else {
         cout << "Welcome " << username << ", your file has been created!\n";
     }
     checkFile.close();
     
 	char again = 'y';
	 while (again == 'y' || again == 'Y'){
	    cout<< "\nEnter your monthly income in Naira: ";
	
	//income scope
	    double income;
	    cin>>income;
	    
	    //creates a vector array for categories and expenses
	    vector<string> categories;
	    vector<double> expenses;
	    
	    char addMore = 'y';
	    
	    while (addMore == 'y' || addMore == 'Y'){
	    	cout << "\n What category would you like to add money to: ";
	    	string category;
	    	cin >> category;
	    	
	    	cout << " How much are you adding to the category: ";
	    	double amount;
	    	cin >> amount;
	    	
	    	//stores the input in the array created in order
	    	categories.push_back(category);
	    	expenses.push_back(amount);
	    	
	    	cout << "\nDo you wish to add more categories? (y/n): ";
            cin >> addMore;
	    }
	
	
	//addition of total expenses
	    double total {};
	    for (double e : expenses) {
            total += e;
        }
	    
	    
	    double balance = income - total;
	    
	    cout << "\n--- Expense Summary ---\n";
	    
	    //loop to print out the arrays(vectors)
	    for (int i = 0; i < categories.size(); i++) {
               cout << categories[i] << ": ₦" << expenses[i] << "\n";
        }
        
        cout << "Total spent: ₦" << total << "\n";
	    
	    //a condition that decides the output if the balance is less than 0
	    if (balance <= 0) {
               cout<<"You have exceeded your income! \n";
        } else {
               cout<<"Your remaining balance is: ₦" << balance << "\n";
        }
        
        
        //timestamp expressions for when the file is created
        time_t now = time(0);
        string timestamp = ctime(&now);
        
         
         //filehandling for saving the file pn the device
        ofstream file(filename, ios::app);


         //this is the way the outputs will be saved inside the file
        file << "\n--- Budget Summary ---\n";
        file << "Date: " << timestamp;
        file << "Income: ₦" << income << "\n";
        for (int i = 0; i < categories.size(); i++) {
            file << categories[i] << ": ₦" << expenses[i] << "\n";
        }
        file << "Total spent: ₦" << total << "\n";
        file << "Remaining balance: ₦" << balance << "\n";
        file.close();
	    
	    
	    
	    cout << "\nDo you wish to continue? (y/n): ";
        cin >> again;
	 }
	
	cout << "Thank you, Goodbye! \n";
	return 0;
}