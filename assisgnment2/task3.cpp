#include <iostream>
using namespace std;
class fruit
{
public:
    string name;
    float rating;
    fruit *next;
    fruit(string name, float rating)
    {
        this->name = name;
        this->rating = rating;
        next = NULL;
    }
};
class FruitTypes
{
public:
    string type;
    FruitTypes *next;
    fruit *fnext;
    fruit *ftail;
    FruitTypes(string type)
    {
        this->type = type;
    }
};
class Store
{
private:
    FruitTypes *head = NULL;
    FruitTypes *tail = NULL;

public:
    void addFruitType(string name)
    {
        FruitTypes *temp = new FruitTypes(name);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    FruitTypes *find(string name)
    {
        FruitTypes *current = head;
        while (current != NULL)
        {
            if (current->type == name)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
    void AddFruit(string type, string name, float rating)
    {
        FruitTypes *Fruit_type = find(type);
        if (Fruit_type == NULL)
        {
            cout << "Error: Type '" << type << "' not found. Cannot add fruit." << endl;
            return;
        }
        fruit *FruitName = new fruit(name, rating);
        // FruitName->next = Fruit_type->fnext;
        // Fruit_type->fnext = FruitName;
        if (Fruit_type->fnext == NULL)
        {
            Fruit_type->fnext = FruitName;
            Fruit_type->ftail = FruitName;
        }
        else
        {
            Fruit_type->ftail->next = FruitName;
            Fruit_type->ftail = FruitName;
        }
    }

    void deleteFruit(string type, string name)
    {
        FruitTypes *Fruit_type = find(type);
        // to check if the type and fruit list are in the structure or not
        if (Fruit_type == NULL)
        {
            cout << "Error: Type '" << type << "' not found. Cannot delete." << endl;
            return;
        }
        if (Fruit_type->fnext == NULL)
        {
            cout << "Error: Fruit list for '" << type << "' is empty. Cannot delete." << endl;
            return;
        }

        fruit *current = Fruit_type->fnext;
        fruit *prev = NULL;

        while (current != NULL)
        {
            if (current->name == name)
            {
                // if the wanted delete fruit is the head
                if (prev == NULL)
                {
                    Fruit_type->fnext = current->next;
                }
                else
                {
                    prev->next = current->next;
                }

                if (current == Fruit_type->ftail)
                {
                    Fruit_type->ftail = prev;
                }

                cout << "Deleted: " << current->name << " from " << Fruit_type->type << endl;
                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }
        cout << "Error: Fruit '" << name << "' not found in type '" << type << "'." << endl;
    }
    void editFruit(string type, string name, float newRating)
    {

        FruitTypes *Fruit_type = find(type);
        if (Fruit_type == NULL)
        {
            cout << "Error: Type '" << type << "' not found. Cannot edit." << endl;
            return;
        }

        fruit *current = Fruit_type->fnext;
        while (current != NULL)
        {
            if (current->name == name)
            {
                current->rating = newRating;
                cout << "Updated rating for " << name << " to " << newRating << "." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Error: Fruit '" << name << "' not found in type '" << type << "'." << endl;
    }
    void findHighestRating()
    {
        fruit *highestFruit = NULL;
        string highestType;
        FruitTypes *currentType = head;
        while (currentType != NULL)
        {

            fruit *currentFruit = currentType->fnext;
            while (currentFruit != NULL)
            {

                if (highestFruit == NULL)
                {
                    highestFruit = currentFruit;
                    highestType = currentType->type;
                }
                else if (currentFruit->rating > highestFruit->rating)
                {
                    highestFruit = currentFruit;
                    highestType = currentType->type;
                }

                currentFruit = currentFruit->next;
            }
            currentType = currentType->next;
        }

        cout << "--- Highest Rated Fruit ---" << endl;
        cout << "Type:   " << highestType << endl;
        cout << "Name:   " << highestFruit->name << endl;
        cout << "Rating: " << highestFruit->rating << endl;
    }
    void displayAll()
    {

        FruitTypes *currentType = head;
        while (currentType != NULL)
        {
            cout << "\n--- " << currentType->type << " ---" << endl;

            fruit *currentFruit = currentType->fnext;
            while (currentFruit != NULL)
            {
                cout << "  - " << currentFruit->name
                     << " (Rating: " << currentFruit->rating << ")" << endl;
                currentFruit = currentFruit->next;
            }
            currentType = currentType->next;
        }
    }
};

int main()
{
    Store myStore;
    int choice;

    myStore.addFruitType("DryFruit");
    myStore.addFruitType("CitrusFruit");
    myStore.addFruitType("StoneFruit");

    myStore.AddFruit("DryFruit", "Almond", 4.5);
    myStore.AddFruit("DryFruit", "Walnut", 4.2);
    myStore.AddFruit("CitrusFruit", "Orange", 4.0);
    myStore.AddFruit("StoneFruit", "Peach", 4.8);

    cout << "Welcome to the Fruit Store Management System!" << endl;

    while (true)
    {
        cout << "\n----------------------------------------" << endl;
        cout << "                 MAIN MENU                " << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Add a new Fruit Type" << endl;
        cout << "2. Add a new Fruit" << endl;
        cout << "3. Delete a Fruit" << endl;
        cout << "4. Edit a Fruit's Rating" << endl;
        cout << "5. Find Highest Rated Fruit" << endl;
        cout << "6. Display All Fruits by Type" << endl;
        cout << "7. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice (1-7): ";

        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            string typeName;
            cout << "Enter new fruit type name: ";
            cin >> typeName;
            myStore.addFruitType(typeName);
            cout << "Successfully added type: " << typeName << endl;
            break;
        }
        case 2:
        {
            string type, name;
            float rating;
            cout << "Enter type (e.g., DryFruit): ";
            cin >> type;
            cout << "Enter fruit name: ";
            cin >> name;
            cout << "Enter rating (e.g., 4.5): ";
            cin >> rating;
            myStore.AddFruit(type, name, rating);
            break;
        }
        case 3:
        {
            string type, name;
            cout << "Enter type: ";
            cin >> type;
            cout << "Enter fruit name to delete: ";
            cin >> name;
            myStore.deleteFruit(type, name);
            break;
        }
        case 4:
        {
            string type, name;
            float newRating;
            cout << "Enter type: ";
            cin >> type;
            cout << "Enter fruit name to edit: ";
            cin >> name;
            cout << "Enter new rating: ";
            cin >> newRating;
            myStore.editFruit(type, name, newRating);
            break;
        }
        case 5:
        {
            myStore.findHighestRating();
            break;
        }
        case 6:
        {
            myStore.displayAll();
            break;
        }
        case 7:
        {
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
            break;
        }
        }
    }

    return 0;
}