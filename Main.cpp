#include <bits/stdc++.h>
#include"CarClass.cpp"
using namespace std;

// global function for a new entry
void newEntry()
{
	try
	{
		// checking if more entries possible
		if(Car :: carCount == 5)
			throw (Car :: carCount);
		// entering data of a new car
		C[Car :: carCount].setCar();
		(Car :: carCount)++;
	}
	catch(int i)
	{
		cout << endl << endl;
		cout << "\t\t\t\t\t\t  Error: No More Entries Possible." << endl;
	}
}

// global function for looking a previous entry
void prevEntry()
{
	try
	{
		// checking if there is any car 
		if(Car :: carCount == 0)
			throw (Car :: carCount);
		
		int entryNum;
		cout << "\t\t\t\t\t\t  Enter Entry Number: ";
		cin >> entryNum;
		try
		{
			if(entryNum < 1 || entryNum > Car :: carCount)
				throw entryNum;
			int choice1;
			cout << endl;
			cout << "\t\t\t\t\t\t  You want to: " << endl;
			cout << "\t\t\t\t\t\t\t1. See Overall Rating Only" << endl;
			cout << "\t\t\t\t\t\t\t2. See Details of the Car" << endl;
			cout << "\t\t\t\t\t\t\t3. Modify" << endl;
			cout << "\t\t\t\t\t\t  Enter choice: ";
			cin >> choice1;
			
			switch(choice1)
			{
				case 1:	C[entryNum- 1].getCarRating();	// showing overall rating
						break;
				case 2:	{
							// showing details
							int choice2;
							cout << endl;
							cout << "\t\t\t\t\t\t  You want to see: " << endl;
							cout << "\t\t\t\t\t\t\t1. Vehicle History Details" << endl;
							cout << "\t\t\t\t\t\t\t2. Paint Quality Details" << endl;
							cout << "\t\t\t\t\t\t\t3. Frame State Details" << endl;
							cout << "\t\t\t\t\t\t\t4. Wheel Alignment Details" << endl;
							cout << "\t\t\t\t\t\t\t5. Tyre Quality Details" << endl;
							cout << "\t\t\t\t\t\t\t6. Engine Quality Details" << endl;
							cout << "\t\t\t\t\t\t\t7. Upholstery Details" << endl;
							cout << "\t\t\t\t\t\t\t8. All of these" << endl;
							cout << "\t\t\t\t\t\t  Enter choice: ";
							cin >> choice2;
						
							switch(choice2)
							{
								case 1:	getVH(C[entryNum - 1]);
										break;
									case 2:	getPQ(C[entryNum - 1]);
										break;
								case 3:	getFS(C[entryNum - 1]);
										break;
								case 4:	getWA(C[entryNum - 1]);
										break;
								case 5:	getTQ(C[entryNum - 1]);
										break;
								case 6:	getEQ(C[entryNum - 1]);
										break;
								case 7:	getU(C[entryNum - 1]);
										break;
								case 8:	C[entryNum - 1].getCar();
										break;
								default:{
											cout << endl << endl;
											cout << "\t\t\t\t\t\t  Invalid Input!!" << endl;
									}
							}
							break;
						}
				case 3: {
							int choice2;
							cout << endl;
							cout << "\t\t\t\t\t\t  You want to modify: " << endl;
							cout << "\t\t\t\t\t\t\t1. Vehicle History Details" << endl;
							cout << "\t\t\t\t\t\t\t2. Paint Quality Details" << endl;
							cout << "\t\t\t\t\t\t\t3. Frame State Details" << endl;
							cout << "\t\t\t\t\t\t\t4. Wheel Alignment Details" << endl;
							cout << "\t\t\t\t\t\t\t5. Tyre Quality Details" << endl;
							cout << "\t\t\t\t\t\t\t6. Engine Quality Details" << endl;
							cout << "\t\t\t\t\t\t\t7. Upholstery Details" << endl;
							cout << "\t\t\t\t\t\t\t8. All of these" << endl;
							cout << "\t\t\t\t\t\t  Enter choice: ";
							cin >> choice2;
							
							switch(choice2)
							{
								case 1:	setVH(C[entryNum - 1]);
										C[entryNum - 1].calculateRating();
										break;
								case 2:	setPQ(C[entryNum - 1]);
										C[entryNum - 1].calculateRating();
										break;
								case 3:	setFS(C[entryNum - 1]);
										C[entryNum - 1].calculateRating();
										break;
								case 4:	setWA(C[entryNum - 1]);
										C[entryNum - 1].calculateRating();
										break;
								case 5:	setTQ(C[entryNum - 1]);
										C[entryNum - 1].calculateRating();
										break;
								case 6:	setEQ(C[entryNum - 1]);
										C[entryNum - 1].calculateRating();
										break;
								case 7:	setU(C[entryNum - 1]);
										C[entryNum - 1].calculateRating();
										break;
								case 8:	C[entryNum - 1].setCar();
										break;
								default:{
											cout << endl << endl;
											cout << "\t\t\t\t\t\t  Invalid Input!!" << endl;
									}
								
							}
							break;
						}
				default:{
							cout << endl << endl;
							cout << "\t\t\t\t\t\t  Invalid Input!!" << endl;
					}
			}
		}
		catch(int i)
		{
			cout << endl;
			cout << "\t\t\t\t\t\t  Error: No Entry For Entry Number " << i << "." << endl;
		}
		
	}
	catch(int i)
	{
		cout << "\t\t\t\t\t\t  Error: No Previous Entries." << endl;
	}
}

// global function for showing the number of entries made
void numOfEntries()
{
	cout << "\t\t\t\t\t\t  Number of Entries: " << Car :: carCount << endl;
}

int main()
{
	int choice;
	while(1)
	{
		// menu
		cout << endl << endl;
		cout << "\t\t\t\t\t\t*******************************" << endl;
		cout << "\t\t\t\t\t\t*******************************" << endl;
    	cout << "\t\t\t\t\t\t**   CAR EVALUATION SYSTEM   **" << endl;
		cout << "\t\t\t\t\t\t*******************************" << endl;
		cout << "\t\t\t\t\t\t*******************************" << endl;
		cout << endl << endl;
		cout << "\t\t\t\t\t\t\t1. New Entry" << endl;
		cout << "\t\t\t\t\t\t\t2. Previous Entry" << endl;
		cout << "\t\t\t\t\t\t\t3. Number of Entries" << endl;
		cout << "\t\t\t\t\t\t\t4. Exit" << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t  Enter Choice: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:	cout << endl << endl;
					newEntry();
					break;
			case 2:	cout << endl << endl;
					prevEntry();
					break;
			case 3:	cout << endl << endl;
					numOfEntries();
					break;
			case 4: exit(0);
					break;
			default:{
					cout << endl << endl; 
					cout << "\t\t\t\t\t\t  Invalid Input!!" << endl;
				}
		}
	}
	return 0;
}
