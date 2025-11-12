#include <iostream>
using namespace std;

class Auto{
public:
	int chassisID;
	string name;
	float capacity;
	float price;
	
	Auto(int i = 0, string n = "", float c = 0.0f, float p = 0.0f){
		chassisID = i;
		name = n;
		capacity = c;
		price = p;
	}
	
	void display() const{
		cout<<"ChassisID: "<<chassisID<<endl
            <<"Name: "<<name<<endl
            <<"Capacity: "<<capacity<<endl
            <<"Price: "<<price<<endl;
	}
};

void sortByPrice(Auto autos[], int count) {
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(autos[i].price<autos[j].price)
            {
                swap(autos[i],autos[j]);
            }
        }
        
    }
    
	// write your function to sort autos by price
}

void searchByID(Auto autos[], int count) {
    int temp;
    cout<<"Enter the ID: ";
    cin>>temp;
    for (int i = 0; i < count; i++)
    {
        if (autos[i].chassisID==temp)
        {
            autos[i].display();
        }
    }

    
	// write your function to search auto by ID
	// then call autos[i].display();
}

void calculateTax(Auto autos[], int count) {
    
    for (int i = 0; i < count; i++)
    {
       autos[i].price=autos[i].price+(autos[i].price*0.16);
    }
    // write your function to calculate the tax
    // then add this tax to your final price amount
}

void displayByInputPrice(Auto autos[], int count, double minPrice) {
    for (int i = 0; i < count; i++)
    {
       if (autos[i].price>= minPrice)
       {
         autos[i].display();
       }
       
    }
    // write your function to display all autos with price greater than minPrice
}

int main(){
	const int count = 6;
	Auto autos[count] = {
		Auto(1, "John Deere", 300, 15000),
		Auto(2, "Soviet Tractor", 250, 14350),
		Auto(3, "LeBron Coupe", 450, 9599),
		Auto(4, "Rover", 115, 3599),
		Auto(5, "Cero", 155, 11000),
		Auto(6, "VXR", 500, 20000)
	};
	
	int choice;
	do{
		cout << "\n===== AUTO DEALERSHIP SYSTEM =====";
        cout << "\n1. Sort Autos by Price (Ascending)";
        cout << "\n2. Search Auto by ID";
        cout << "\n3. Calculate and Add Tax";
        cout << "\n4. Display Autos with Price < Input";
        cout << "\n5. Display All Autos";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice){
        	case 1:
                sortByPrice(autos,count);
        		// call function to Sort by price
        		cout << "Autos sorted by price successfully.\n";
        		break;
        	case 2:
        		searchByID(autos,count);
        		// call function to Search by ID
				break;
        	case 3:
                calculateTax(autos,count);
        		// call function to add tax to price
        		cout << "Tax added successfully.\n";
        		break;
        	case 4:
        		double minPrice;
                cout << "Enter minimum price: ";
                cin >> minPrice;
                displayByInputPrice(autos,count,minPrice);
    
        		// call function to display autos where minPrice > input
        		cout << "\n\n";
                break;
			case 5:
                for (int i = 0; i < count; i++)
                {
                    autos[i].display();
                }
                
				// call function to display all autos
				cout << "\n\n";
				break;        		
		}
		
		
	} while(choice != 0);
	
	
	return 0;
}