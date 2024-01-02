#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>  
#include <numeric>     
#include <vector>      
using namespace std;

int main() {
    // Variables to store charity names and donation totals
    string charityNames[3];
    double charityTotals[3] = {0.0, 0.0, 0.0};

    // Input charity names
    for (int i = 0; i < 3; ++i) {
        cout << "Enter the name of Charity " << (i + 1) << ": ";
        getline(cin, charityNames[i]);
    }

    // Input the choice of charity and shopping bill for each customer
    int numCustomers;
    cout << "\nEnter the number of customers or -1 to show totals so far: ";
    cin >> numCustomers;

    while (numCustomers != -1) {
        if (numCustomers < 1) {
            cout << "Invalid input. Please enter a positive number of customers or -1 to show totals so far.\n";
            cout << "\nEnter the number of customers or -1 to show totals so far: ";
            cin >> numCustomers;
            continue;
        }

        for (int customer = 1; customer <= numCustomers; ++customer) {
            int charityChoice;
            cout << "\nCustomer " << customer << ":\n";
            cout << "Enter the number (1, 2, or 3) to choose a charity: ";
            cin >> charityChoice;

            if (charityChoice == -1) {
                // Show the totals so far
                cout << "\nCharity Totals So Far:\n";
                vector<pair<string, double>> charityTotalPairs;

                // Populate vector with charity names and totals
                for (int i = 0; i < 3; ++i) {
                    charityTotalPairs.push_back(make_pair(charityNames[i], charityTotals[i]));
                }

                // Sort the vector in descending order of totals
                sort(charityTotalPairs.begin(), charityTotalPairs.end(),
                    [](const pair<string, double>& a, const pair<string, double>& b) {
                        return a.second > b.second;
                    });

                // Display charities' names and totals
                for (const auto& pair : charityTotalPairs) {
                    cout << pair.first << ": $" << std::fixed << std::setprecision(2) << pair.second << endl;
                }

                // Calculate and display the grand total
                double grandTotal = accumulate(charityTotals, charityTotals + 3, 0.0);
                cout << "\nGRAND TOTAL DONATED TO CHARITY: $" << std::fixed << std::setprecision(2) << grandTotal << endl;

                return 0;
            }

            // Validate charity choice
            if (charityChoice < 1 || charityChoice > 3) {
                cout << "Invalid charity choice. Skipping customer.\n";
                continue; // Skip to the next customer
            }

            // Input the customer's shopping bill
            double shoppingBill;
            cout << "Enter the customer's shopping bill: $";
            cin >> shoppingBill;

            // Calculate the donation
            double donation = shoppingBill * 0.1; // Assuming a donation of 10% of the shopping bill

            // Update the total for the chosen charity
            charityTotals[charityChoice - 1] += donation;

            // Display donation details for each customer
            cout << "\nDonation Details for Customer " << customer << ":\n";
            cout << "Chosen Charity: " << charityNames[charityChoice - 1] << endl;
            cout << "Shopping Bill: $" << std::fixed << std::setprecision(2) << shoppingBill << endl;
            cout << "Donation Amount: $" << std::fixed << std::setprecision(2) << donation << endl;
        }

        cout << "\nEnter the number of customers or -1 to show totals so far: ";
        cin >> numCustomers;
    }

    return 0;
}
