#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void welcome();
char userChoice();
void getInfo(bool& senior, int& months, int& personal);
void calcCost(bool senior, int months, int personal);

// welcome function 
void welcome(){
  cout << "Portland Rock Gym Day Passes and Membership Prices:" << endl;
  cout << "\n" << endl;
  cout << "UNLIMITED MONTHLY PASS: $83.00 / month.\n" << endl;
  cout << "* *If the membership is bought and paid for 12 or more months, the discount is 10 % each month.\n" << endl;
  cout << "* *Student Discount(must show valid ID) : 30 % on unlimited monthly pass only.\n" << endl;
  cout << "            - OR -\n" << endl;
  cout << "INDIVIDUAL DAY PASSES : $21.00 / pass.\n" << endl;
  cout << "* *If 5 or more passes are bought and paid for, there will be a 20 % discount on each pass.\n" << endl;

}

char userChoice(){
	char choose;
  cout << "--------------------------------------------------------------------\n";
  cout << "\n" << endl;
	cout << "Please enter \"a\" to calculate cost, or enter \"b\" to quit the program." << endl;
  cin >> choose;
  while (choose != 'a' && choose != 'b') {
		cout << "Invalid option!\n";
    cout << "\n" << endl;
    cout << "Please enter \"a\" to calculate cost, or enter \"b\" to quit the program." << endl;
		cin >> choose;
	}

return choose;
}

void getInfo(bool& senior, int& months, int& personal){
	char daypassPurchase;
	int numClasses;
	double totaldaycost;
	const double dayUse = 21.00;
	
 
  if (!senior) {

		cout << "Would you like to purchase individual day passes? (y/n):";

		cin >> daypassPurchase;

		if (daypassPurchase == 'n') {
		cout << "Your total cost today is : $0.00" << endl;
		}
		if (daypassPurchase == 'y') {
		cout << "How many classes would you like to purchase?:";
		cin >> numClasses;
		  if (numClasses >= 5) {
			totaldaycost = numClasses * dayUse;
			totaldaycost -= ((totaldaycost * 20.00) / 100.00);
      cout << "Your total cost today is: " << fixed << setprecision(2) << totaldaycost << endl;
		  }
		  else if (numClasses < 5) {
			totaldaycost = numClasses * dayUse;
			cout << "Your total cost today is: " << fixed << setprecision(2) << totaldaycost << endl;
		  }
		}
	}

	

}
void calcCost(bool senior, int months, int personal) {
	
	double totalcost;
	const double ultmem = 83.00;
  double tenDiscount;
	double thirtyDiscount;

	if (senior) { 
		if (months >= 12 && personal == 1) {
      tenDiscount = (ultmem * 10.00) / 100.00;
      tenDiscount =  (ultmem - tenDiscount) * months;
      thirtyDiscount = tenDiscount * 30.00 / 100.00;
      totalcost = tenDiscount - thirtyDiscount;
    }
    else if (months >= 12 && personal == 0) {
      tenDiscount = (ultmem * 10.00) / 100.00;
      tenDiscount =  (ultmem - tenDiscount) * months;
      totalcost = tenDiscount;
    }
		else if (months < 12 && personal == 1) {
		  totalcost = static_cast<double>(ultmem * months);
			thirtyDiscount = (totalcost * 30.00) / 100.00;
      totalcost = totalcost - thirtyDiscount;
    }
    else if (months < 12 && personal == 0) {
      totalcost =  static_cast<double>(ultmem * months);
    }
	cout << "Your total cost today is: " << fixed << setprecision(2) << totalcost << endl;
  }
	
}

int main(){
	char unLimit;
	char choose;
	bool senior;
  int monthPurchase;
  char questStud;
  int studentInfo;
	int input1;
  int input2;

welcome();
while (choose != 'b'){
choose = userChoice();
  if (choose == 'b') {
	  cout << "Rock On!" << endl;
		exit(0);
	}
	else if (choose == 'a') {
		cout << "Would you like the unlimited month pass ? (y / n) :";
		cin >> unLimit;
		if (unLimit == 'y') {
		  senior = true;
		}
    else if (unLimit == 'n') {
		  senior = false;
      input1 = 0;
      input2 = 0;
		getInfo(senior, input1 , input2); 
    }
    if(senior == true){
        cout << "How many months would you like to purchase: ";
	      cin >> monthPurchase;
	      cout << "Are you a student? (y/n): ";
	      cin >> questStud;
        if (questStud == 'y'){
          studentInfo = 1;
        }
        if (questStud == 'n'){
          studentInfo = 0;
        }
    calcCost(senior, monthPurchase, studentInfo);
    }
  }
} 
return 0;
}
