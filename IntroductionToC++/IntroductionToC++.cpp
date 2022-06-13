#include <iostream>      // Main
#include <string>        // For getline()
#include <map>           // For Maps
#include <algorithm>     // For transform (.upper())
#include <unordered_map> // For unordered_multimap
using namespace std;

// Vaccine List
struct vaccine_data_list
{
    string vaccine_name, batch_id, date_of_purchase, manufacturer, origin_country;
    double price_per_vial, total_price;
    int number_of_vials;

    vaccine_data_list(string _vaccine_name, int _number_of_vials, string _batch_id, string _date_of_purchase, string _manufacturer, string _origin_country, double _price_per_vial, double _total_price)
    {
        vaccine_name = _vaccine_name;
        number_of_vials = _number_of_vials;
        batch_id = _batch_id;
        date_of_purchase = _date_of_purchase;
        manufacturer = _manufacturer;
        origin_country = _origin_country;
        price_per_vial = _price_per_vial;
        total_price = _total_price;
    }
};

// Patient List
struct patient_data_list
{
    string patient_name, vac_name, appoint_date, appoint_time;
    double fee;

    patient_data_list(string _patient_name, string _vac_name, double _fee, string _appoint_date, string _appoint_time)
    {
        patient_name = _patient_name;
        vac_name = _vac_name;
        fee = _fee;
        appoint_date = _appoint_date;
        appoint_time = _appoint_time;
    }
};

// Functions
void welcome_message();
unordered_multimap<string, vaccine_data_list> get_batch_data(unordered_multimap<string, vaccine_data_list> batch_data);
void display_invoice(string batch_id, string date_of_purchase, string manufacturer, string vaccine_name, string origin_country, double price_per_vial, int number_of_vials, double total_price);
void display_vaccine(unordered_multimap<string, vaccine_data_list> batch_data);
unordered_multimap<string, patient_data_list> get_appointment(unordered_multimap<string, vaccine_data_list> batch_data, unordered_multimap<string, patient_data_list> patient_data);
void display_appointment(unordered_multimap<string, patient_data_list> patient_data);

// Displays Welcome Message and Menu
void welcome_message()
{
    unordered_multimap<string, vaccine_data_list> batch_data;
    unordered_multimap<string, patient_data_list> patient_data;
    while (true)
    {
        string num;

        // Displays Menu and User Input
        cout << "Welcome to the vaccine interface" << endl;
        cout << "Press 1 to record vaccine batch data" << endl;
        cout << "Press 2 to display vaccine details" << endl;
        cout << "Press 3 to enter appointment details" << endl;
        cout << "Press 4 to display appointment details" << endl;
        cout << "Press 5 to quit the program: ";
        getline(cin, num);
        cout << endl;

        // Instructions based on User Input
        if (num == "1")
        {
            batch_data = get_batch_data(batch_data);
        }
        else if (num == "2")
        {
            display_vaccine(batch_data);
        }
        else if (num == "3")
        {
            patient_data = get_appointment(batch_data, patient_data);
        }
        else if (num == "4")
        {
            display_appointment(patient_data);
        }
        else if (num == "5")
        {
            cout << "Program End" << endl;
            return;
        }
        else
        {
            cout << "Invalid Command: Please only enter 1, 2, 3, 4, or 5" << endl;
            cout << endl;
        }
    }
}

// User Input for Batch Data
unordered_multimap<string, vaccine_data_list> get_batch_data(unordered_multimap<string, vaccine_data_list> batch_data)
{
    double total_price, all_total_price = 0;
    while (true)
    {
        string batch_id;

        // User Input Command
        cout << "Enter the Batch ID or press <ENTER> to display total accumulative purchase price from all batches: ";
        getline(cin, batch_id);

        if (batch_id == "")
        {
            // To return
            cout << "The total price is $" << all_total_price << endl;
            cout << endl;
            return batch_data;
        }
        else
        {
            string date_of_purchase, manufacturer, vaccine_name, origin_country;
            double price_per_vial;
            int number_of_vials;

            // User Input
            cout << "Batch ID: " << batch_id << endl;
            cout << "Date of purchase: ";
            getline(cin, date_of_purchase);
            cout << "Name of the manufacturer: ";
            getline(cin, manufacturer);
            cout << "Name of the Vaccine: ";
            getline(cin, vaccine_name);
            transform(vaccine_name.begin(), vaccine_name.end(), vaccine_name.begin(), ::toupper);
            cout << "Vaccine's country of origin: ";
            getline(cin, origin_country);

            while (true)
            {
                cout << "Price per vial of vaccine: $";
                cin >> price_per_vial;
                if (cin.fail() || price_per_vial < 0)
                {
                    cout << "Enter positive numbers only" << endl;
                    cin.clear();
                    cin.ignore(2048, '\n');
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "Number of vials: ";
                cin >> number_of_vials;
                if (cin.fail() || number_of_vials < 0)
                {
                    cout << "Enter positive numbers only" << endl;
                    cin.clear();
                    cin.ignore(2048, '\n');
                }
                else
                {
                    break;
                }
            }
            cout << endl;

            // Basic Calculation
            total_price = price_per_vial * number_of_vials;
            all_total_price += total_price;

            // Storing Data
            batch_data.insert(pair<string, vaccine_data_list>(vaccine_name, vaccine_data_list(vaccine_name, number_of_vials, batch_id, date_of_purchase, manufacturer, origin_country, price_per_vial, total_price)));

            // Prints Invoice
            display_invoice(batch_id, date_of_purchase, manufacturer, vaccine_name, origin_country, price_per_vial, number_of_vials, total_price);

            cout << endl;
        }
    }
}

// Invoice Printing after Batch Data
void display_invoice(string batch_id, string date_of_purchase, string manufacturer, string vaccine_name, string origin_country, double price_per_vial, int number_of_vials, double total_price)
{
    cout << "Invoice for " << batch_id << "\t\tDate: " << date_of_purchase << endl;
    cout << "__________________________________________________________" << endl;
    cout << "Vaccine details: " << endl;
    cout << "Producer: " << manufacturer << endl;
    cout << "Country: " << origin_country << endl;
    cout << "Vaccine Name: " << vaccine_name << endl;
    cout << "__________________________________________________________" << endl;
    cout << "Price per vail: $" << price_per_vial << endl;
    cout << "Number of vail purchased: " << number_of_vials << endl;
    cout << "Total price: $" << total_price << endl;
    cin.ignore();
    return;
}

// Display Vaccines, learn library
void display_vaccine(unordered_multimap<string, vaccine_data_list> batch_data)
{
    cout << "Available vaccines are:" << endl;
    for (auto itr = batch_data.begin(); itr != batch_data.end(); itr++)
    {
        cout << (*itr).first << endl;
    }
    while (true)
    {
        string vac_name;
        bool vaccine_found = false;

        // User input to access vaccine data
        cout << endl;
        cout << "Enter one of the vaccines name above or type <back> to return: ";
        getline(cin, vac_name);
        transform(vac_name.begin(), vac_name.end(), vac_name.begin(), ::toupper);

        // Acess data from struct in map
        for (auto itr = batch_data.begin(); itr != batch_data.end(); itr++)
        {
            if ((*itr).first == vac_name)
            {
                cout << "Vaccines available," << endl;
                cout << "Vaccine Name: " << (*itr).first << endl;
                cout << "Vaccine vials left: " << (*itr).second.number_of_vials << endl;
                cout << "Available Health Centres are: Sunway Health Centre (SHC), Fungus Hospital (FH), Take-away Child Centre (TCC)" << endl;
                cout << "Available time to make appointments: 8:00AM - 6:00PM everyday except Sundays" << endl;
                vaccine_found = true;
                break;
            }
        }

        // Return back
        if (vac_name == "BACK")
        {
            cout << endl;
            break;
        }
        // Else Statement
        else if (vaccine_found == false)
        {
            cout << "Enter the available vaccines only or <back> to return" << endl;
        }
    }
    return;
}

unordered_multimap<string, patient_data_list> get_appointment(unordered_multimap<string, vaccine_data_list> batch_data, unordered_multimap<string, patient_data_list> patient_data)
{
    string patient_id, patient_name, vac_name, appoint_date, appoint_time;
    double fee;
    bool vaccine_found = false;
    cout << "Enter patient's ID: ";
    getline(cin, patient_id);
    cout << "Enter patient's Name: ";
    getline(cin, patient_name);
    cout << "Enter vaccine name: ";
    getline(cin, vac_name);
    for (auto itr = batch_data.begin(); itr != batch_data.end(); itr++)
    {
        if ((*itr).second.vaccine_name == vac_name)
        {
            vaccine_found = true;
            break;
        }
    }
    if (vaccine_found)
    {
        while (true)
            {
                cout << "Enter fee amount: $";
                cin >> fee;
                if (cin.fail() || fee < 0)
                {
                    cout << "Enter numbers only" << endl;
                    cin.clear();
                    cin.ignore(2048, '\n');
                }
                else
                {
                    break;
                }
            }
        cin.ignore();
        cout << "Enter appointment date: ";
        getline(cin, appoint_date);
        cout << "Enter appointment time: ";
        getline(cin, appoint_time);
        patient_data.insert(pair<string, patient_data_list>(patient_id, patient_data_list(patient_name, vac_name, fee, appoint_date, appoint_time)));
        cout << endl;
        return patient_data;
    }
    else
    {
        cout << "Appointment cannot be made as the vaccine is not available" << endl;
        cout << endl;
        return patient_data;
    }
}

void display_appointment(unordered_multimap<string, patient_data_list> patient_data) 
{
    string patient_id;
    while (true)
    {
        cout << "Enter patient's ID or type <back> to go back to main menu: ";
        getline(cin, patient_id);
        for (auto itr = patient_data.begin(); itr != patient_data.end(); itr++)
    {
        if ((*itr).first == patient_id)
        {
            cout << "Patient ID: " << (*itr).first << endl;
            cout << "Patient Name: " << (*itr).second.patient_name << endl;
            cout << "Vaccine Name: " << (*itr).second.vac_name << endl;
            cout << "Fee: $" << (*itr).second.fee << endl;
            cout << "Appointment Date: " << (*itr).second.appoint_date << endl;
            cout << "Appointment Time: " << (*itr).second.appoint_time << endl;
            cout << endl;
        }
    }
        transform(patient_id.begin(), patient_id.end(), patient_id.begin(), ::toupper);
        if (patient_id == "BACK")
        {
            cout << endl;
            return;
        }
    }
}

// Main
int main()
{
    welcome_message();

    return 0;
}
