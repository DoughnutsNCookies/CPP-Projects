#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

// Vaccine Class
class Vaccine
{
public:
    string vaccine_id, vaccine_batch, vaccine_name, vaccine_expiry_date;
    double price_per_vial;
    int number_of_vials_purchased;

    // Class Initializer Method
    Vaccine(string _vaccine_id, string _vaccine_batch, string _vaccine_name, string _vaccine_expiry_date, double _price_per_vial, int _number_of_vials_purchased)
    {
        vaccine_id = _vaccine_id;
        vaccine_batch = _vaccine_batch;
        vaccine_name = _vaccine_name;
        vaccine_expiry_date = _vaccine_expiry_date;
        price_per_vial = _price_per_vial;
        number_of_vials_purchased = _number_of_vials_purchased;
    }

    // Setter Methods
    void setter_vaccine_id(string set_vaccine_id)
    {
        vaccine_id = set_vaccine_id;
    }
    void setter_vaccine_batch(string set_vaccine_batch)
    {
        vaccine_batch = set_vaccine_batch;
    }
    void setter_vaccine_name(string set_vaccine_name)
    {
        vaccine_name = set_vaccine_name;
    }
    void setter_vaccine_expiry_date(string set_vaccine_expiry_date)
    {
        vaccine_expiry_date = set_vaccine_expiry_date;
    }
    void setter_price_per_vial(double set_price_per_vial)
    {
        price_per_vial = set_price_per_vial;
    }
    void setter_number_of_vials_purchased(int set_number_of_vials_purchased)
    {
        number_of_vials_purchased = set_number_of_vials_purchased;
    }

    // Getter Methods
    string getter_vaccine_id()
    {
        return vaccine_id;
    }
    string getter_vaccine_batch()
    {
        return vaccine_batch;
    }
    string getter_vaccine_name()
    {
        return vaccine_name;
    }
    string getter_vaccine_expiry_date()
    {
        return vaccine_expiry_date;
    }
    double getter_price_per_vial()
    {
        return price_per_vial;
    }
    int getter_number_of_vials_purchased()
    {
        return number_of_vials_purchased;
    }
    double total_price()
    {
        return price_per_vial * number_of_vials_purchased;
    }
    int num_of_vaccines_administered()
    {
        return number_of_vials_purchased;
    }
};

// Vaccine List
struct vaccine_data_list
{
    string vaccine_id, vaccine_batch, vaccine_name, vaccine_expiry_date;
    double price_per_vial;
    int number_of_vials_purchased;

    vaccine_data_list(string _vaccine_id, string _vaccine_batch, string _vaccine_name, string _vaccine_expiry_date, double _price_per_vial, int _number_of_vials_purchased)
    {
        vaccine_id = _vaccine_id;
        vaccine_batch = _vaccine_batch;
        vaccine_name = _vaccine_name;
        vaccine_expiry_date = _vaccine_expiry_date;
        price_per_vial = _price_per_vial;
        number_of_vials_purchased = _number_of_vials_purchased;
    }
};

// Functions
void menu();
unordered_multimap<string, vaccine_data_list> register_vaccine(unordered_multimap<string, vaccine_data_list> vaccine_data);
unordered_multimap<string, vaccine_data_list> display_vaccine(unordered_multimap<string, vaccine_data_list> vaccine_data);

// Menu
void menu()
{
    string lowest_id, highest_id;
    int lowest_price = 0;
    int highest_price = 0;
    bool running = true;
    unordered_multimap<string, vaccine_data_list> vaccine_data;
    while (running)
    {
        int command;

        // Displays Menu and User Input
        cout << "Introduction to Class" << endl;
        cout << "Press 1 to register vaccine" << endl;
        cout << "Press 2 to display vaccine list and make configurations to vaccine data" << endl;
        cout << "Press 3 for lowest priced vaccine" << endl;
        cout << "Press 4 for highest priced vaccine" << endl;
        cout << "Press 0 to exit program: ";

        if(!(cin >> command))
        {
            cout << "Invalid command: Enter numbers above only" << endl;
            cin.clear();
            cin.ignore();
            cout << endl;
        }
        //Instructions based on User Input
        else
        {
            switch (command)
            {
            case 0:
                running = false;
                break;
            case 1:
                cin.ignore();
                cout << endl;
                vaccine_data = register_vaccine(vaccine_data);
                break;
            case 2:
                cin.ignore();
                vaccine_data = display_vaccine(vaccine_data);
                break;
            case 3:
                for (auto itr = vaccine_data.begin(); itr != vaccine_data.end(); itr++)
                {
                    if (lowest_price == 0)
                {
                    lowest_id = (*itr).first;
                    lowest_price = (*itr).second.price_per_vial;
                }
                    else if (lowest_price != 0 && (*itr).second.price_per_vial < lowest_price)
                    {
                        lowest_id = (*itr).first;
                        lowest_price = (*itr).second.price_per_vial;
                    }
                }
                cout << "The lowest priced vaccine ID is: " << lowest_id << endl;
                cout << endl;
                break;
            case 4:
                for (auto itr = vaccine_data.begin(); itr != vaccine_data.end(); itr++)
                {
                    if (highest_price == 0)
                {
                    highest_id = (*itr).first;
                    highest_price = (*itr).second.price_per_vial;
                }
                    else if (highest_price != 0 && (*itr).second.price_per_vial > highest_price)
                    {
                        highest_id = (*itr).first;
                        highest_price = (*itr).second.price_per_vial;
                    }
                }
                cout << "The highest priced vaccine ID is: " << highest_id << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid command: Enter numbers only" << endl;
                cout << endl;
                break;
            }
        }
    }
}

// Register Vaccine
unordered_multimap<string, vaccine_data_list> register_vaccine(unordered_multimap<string, vaccine_data_list> vaccine_data)
{
    while (true)
    {
        string vaccine_id;

        // User Input Command
        cout << "Enter the vaccine ID or press <ENTER> to return back: ";
        getline(cin, vaccine_id);

        if (vaccine_id == "")
        {
            // To return
            cout << endl;
            return vaccine_data;
        }
        else
        {
            string vaccine_batch, vaccine_name, vaccine_expiry_date, test;
            double price_per_vial;
            int number_of_vials_purchased;

            // User Input
            cout << "Vaccine ID: " << vaccine_id << endl;
            cout << "Vaccine Batch: ";
            getline(cin, vaccine_batch);
            cout << "Vaccine Name: ";
            getline(cin, vaccine_name);
            cout << "Vaccine Expiry Date: ";
            getline(cin, vaccine_expiry_date);

            while (true)
            {
                cout << "Price per vial: $";
                cin >> price_per_vial;
                if (cin.fail() || price_per_vial < 0)
                {
                    cout << "Enter positive number only" << endl;
                    cin.clear();
                    cin.ignore(2048, '\n');
                }
                else
                {
                    cin.ignore();
                    break;
                }
            }

            while (true)
            {
                cout << "Number of vials purchased: ";
                cin >> number_of_vials_purchased;
                if (cin.fail() || number_of_vials_purchased < 0)
                {
                    cout << "Enter positive number only" << endl;
                    cin.clear();
                    cin.ignore(2048, '\n');
                }
                else
                {
                    cin.ignore();
                    break;
                }
            }

            // Storing Data
            vaccine_data.insert(pair<string, vaccine_data_list>(vaccine_id, vaccine_data_list(vaccine_id, vaccine_batch, vaccine_name, vaccine_expiry_date, price_per_vial, number_of_vials_purchased)));

            cout << "Vaccine has been registerd, returning to main menu" << endl;
            cout << endl;
            return vaccine_data;
        }
    }
}

// Display Vaccine List
unordered_multimap<string, vaccine_data_list> display_vaccine(unordered_multimap<string, vaccine_data_list> vaccine_data)
{
    string vaccine_entered;
    bool vaccine_found = false;
    while (true)
    {
        cout << "Available vaccines are: " << endl;
        for (auto itr = vaccine_data.begin(); itr != vaccine_data.end(); itr++)
        {
            cout << (*itr).first << endl;
        }

        cout << endl;
        cout << "Enter Vaccine ID above or press <ENTER> to return back: ";
        getline(cin, vaccine_entered);

        for (auto itr = vaccine_data.begin(); itr != vaccine_data.end(); itr++)
        {
            if ((*itr).first == vaccine_entered)
            {
                vaccine_found = true;

                // Initialize Class in this function (Setter)
                Vaccine vaccine_selected((*itr).second.vaccine_id, (*itr).second.vaccine_batch, (*itr).second.vaccine_name, (*itr).second.vaccine_expiry_date, (*itr).second.price_per_vial, (*itr).second.number_of_vials_purchased);

                while (true)
                {
                    string command, new_input;
                    int configuration_command, int_input;
                    double double_input;

                    // Display Vaccine
                    cout << "1. Vaccine ID: " << vaccine_selected.getter_vaccine_id() << endl;
                    cout << "2. Vaccine Batch: " << vaccine_selected.getter_vaccine_batch() << endl;
                    cout << "3. Vaccine Name: " << vaccine_selected.getter_vaccine_name() << endl;
                    cout << "4. Vaccine Expiry Date: " << vaccine_selected.getter_vaccine_expiry_date() << endl;
                    cout << "5. Price Per Vial: $" << vaccine_selected.getter_price_per_vial() << endl;
                    cout << "6. Number Of Vials Purchased: " << vaccine_selected.getter_number_of_vials_purchased() << endl;
                    cout << endl;
                    cout << "Press 1 to make configuration or press <ENTER> to back: ";

                    getline(cin, command);

                    if (command == "1")
                    {
                        cout << "Type out which variable you would like to make changes to (1-6) or press <ENTER> to back: ";
                        cin >> configuration_command;
                        cin.ignore();

                        switch (configuration_command)
                        {
                            case 1:
                            {
                            cout << "1. Vaccine ID: " << vaccine_selected.getter_vaccine_id() << endl;
                            cout << "Enter new Vaccine ID: ";
                            getline(cin, new_input);
                            vaccine_selected.setter_vaccine_id(new_input);
                            break;
                            }

                            case 2:
                            {
                            cout << "2. Vaccine Batch: " << vaccine_selected.getter_vaccine_batch() << endl;
                            cout << "Enter new Vaccine Batch: ";
                            getline(cin, new_input);
                            vaccine_selected.setter_vaccine_batch(new_input);
                            break;
                            }

                            case 3:
                            {
                            cout << "3. Vaccine Name: " << vaccine_selected.getter_vaccine_name() << endl;
                            cout << "Enter new Vaccine Name: ";
                            getline(cin, new_input);
                            vaccine_selected.setter_vaccine_name(new_input);
                            break;
                            }

                            case 4:
                            {
                            cout << "4. Vaccine Expiry Date: " << vaccine_selected.getter_vaccine_expiry_date() << endl;
                            cout << "Enter new Vaccine Expiry Date: ";
                            getline(cin, new_input);
                            vaccine_selected.setter_vaccine_expiry_date(new_input);
                            break;
                            }

                            case 5:
                            {
                            cout << "5. Price Per Vial: $" << vaccine_selected.getter_price_per_vial() << endl;
                            while (true)
                            {
                                cout << "Enter new Price Per Vial: $";
                                cin >> double_input;
                                if (cin.fail() || double_input < 0)
                                {
                                    cout << "Enter positive number only" << endl;
                                    cin.clear();
                                    cin.ignore(2048, '\n');
                                }
                                else
                                {
                                    cin.ignore();
                                    break;
                                }
                            }
                            vaccine_selected.setter_price_per_vial(double_input);
                            break;
                            }

                            case 6:
                            {
                            cout << "6. Number Of Vials Purchased: " << vaccine_selected.getter_number_of_vials_purchased() << endl;
                            while (true)
                            {
                                cout << "Enter new number of vials purchased: ";
                                cin >> int_input;
                                if (cin.fail() || int_input < 0)
                                {
                                    cout << "Enter positive number only" << endl;
                                    cin.clear();
                                    cin.ignore(2048, '\n');
                                }
                                else
                                {
                                    cin.ignore();
                                    break;
                                }
                            }
                            vaccine_selected.setter_number_of_vials_purchased(int_input);
                            break;
                            }

                            default:
                            {
                            cout << "Vaccine variable not available" << endl;
                            break;
                            }

                            cout << endl;
                        }

                    vaccine_data.erase(vaccine_entered);
                    vaccine_data.insert(pair<string, vaccine_data_list>(vaccine_selected.getter_vaccine_id(), vaccine_data_list(vaccine_selected.getter_vaccine_id(), vaccine_selected.getter_vaccine_batch(), vaccine_selected.getter_vaccine_name(), vaccine_selected.getter_vaccine_expiry_date(), vaccine_selected.getter_price_per_vial(), vaccine_selected.getter_number_of_vials_purchased())));

                    }
                    else if (command == "")
                    {
                        break;
                    }
                    else
                    {
                        cout << "Command not recognized, please type out numbers from 1 to 6 or press <ENTER> only" << endl;
                    }
                }
            }
        }
        if (vaccine_entered == "")
        {
            cout << "Returning to main menu" << endl;
            cout << endl;
            return vaccine_data;
        }
        else if (vaccine_found == false)
        {
            cout << "Vaccine ID not found" << endl;
            cout << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}