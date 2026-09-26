#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    unsigned int balance = 0;
    char Select_option;
    char select_lang;
    
    // Initial PIN set to 8577
    int pin[4] = {8, 5, 7, 7};
    int user_entered_pin[4];
    int N_pin[4];

    cout << "\n\n\t\tWelcome!" << endl;
    cout << "\t\t Please insert Your card.\n";
    cout << "\nPress Enter...";
    getch();
    
    cout << "\n----------------------------------------------------------------";
    cout << "\n\t\tPlease Select Application ID\n";
    cout << "A. Domestic \t\t B. International\n";
    char choose;
    cout << "Choose: ";
    cin >> choose;
    cout << "----------------------------------------------------------------";

    switch (choose) {
        case 'A':
        case 'a':
            cout << "\n\t\tPlease Select Language\n";
            cout << "A. English \nB. Hindi\n";
            cout << "Select: ";
            cin >> select_lang;
            cout << "----------------------------------------------------------------";
            break;

        case 'B':
        case 'b':
            cout << "\nSorry your card is not international-enabled\n\nThank you";
            return 0;

        default:
            cout << "\nWrong option \n\nThank you";
            return 0;
    }

    // Language check outside the main loop
    if (select_lang == 'b' || select_lang == 'B') {
        cout << "\nSorry sir, Hindi is not available for now\n\nThank you";
        return 0;
    } else if (select_lang != 'a' && select_lang != 'A') {
        cout << "\nWrong option\n\nThank you";
        return 0;
    }

    // Main Transaction Loop
    for (int i = 1; i <= 20; i++) {
        cout << "\n\n\tDear Customer, Please Select Transaction\n\n";
        cout << "A. Withdrawal\t\tB. Balance Enquiry \nC. Pin Change\t\tD. Deposit \nE. Exit\t\t\tF. Mini Statement\n";

        cout << "\nSelect option: ";
        cin >> Select_option;
        cout << "----------------------------------------------------------------";

        switch (Select_option) {
            case 'a': // Withdrawal Section
            case 'A': {
                cout << "\n\t\tPlease Select Account Type\n";
                cout << "A. Credit \nB. Current \nC. Savings\n";
                cout << "Select: ";
                char select_acc;
                cin >> select_acc;
                cout << "----------------------------------------------------------------";

                if (select_acc == 'c' || select_acc == 'C') {
                    cout << "\n\t\tPlease Enter Amount\n";
                    cout << "\t(Cash Available : Rs 100 , 500)\n";
                    int Amt;
                    cout << "\nEnter Amount: ";
                    cin >> Amt;
                    cout << "----------------------------------------------------------------";

                    cout << "\nEnter PIN: ";
                    for (int k = 0; k < 4; k++) {
                        user_entered_pin[k] = getch() - '0';
                        cout << "*";
                    }

                    int right = 0;
                    for (int k = 0; k < 4; k++) {
                        if (user_entered_pin[k] == pin[k]) {
                            right++;
                        }
                    }

                    if (right == 4) {
                        if (Amt <= balance) {
                            balance -= Amt;
                            cout << "\n\n\tPlease Collect Cash and Take Your Card\n";
                            cout << "Press Enter...";
                            getch();

                            cout << "\nWould you like to Display the Balance on the Screen?\n";
                            cout << "A. Yes \nB. No\n";
                            cout << "Select: ";
                            char S;
                            cin >> S;

                            if (S == 'a' || S == 'A') {
                                cout << "\nYour Balance is : " << balance << endl;
                            } else {
                                cout << "\nThank You";
                                return 0;
                            }
                        } else {
                            cout << "\n\nInsufficient balance\n\nThank you";
                        }
                    } else {
                        cout << "\n\nWrong PIN \nTransaction Declined\n\nThank you";
                    }
                } else {
                    cout << "\nOption not available \n\nThank you";
                }
                break;
            }

            case 'b': // Balance enquiry
            case 'B': {
                cout << "\nEnter PIN: ";
                for (int k = 0; k < 4; k++) {
                    user_entered_pin[k] = getch() - '0';
                    cout << "*";
                }

                int right = 0;
                for (int k = 0; k < 4; k++) {
                    if (user_entered_pin[k] == pin[k]) {
                        right++;
                    }
                }

                if (right == 4) {
                    cout << "\n\nYour current balance: " << balance << endl;
                } else {
                    cout << "\n\nWrong PIN \n\nThank you";
                }
                break;
            }

            case 'c': // PIN change section
            case 'C': {
                cout << "\nEnter old PIN: ";
                for (int k = 0; k < 4; k++) {
                    user_entered_pin[k] = getch() - '0';
                    cout << "*";
                }

                int right = 0;
                for (int k = 0; k < 4; k++) {
                    if (user_entered_pin[k] == pin[k]) {
                        right++;
                    }
                }

                if (right == 4) {
                    cout << "\n\nEnter new PIN: ";
                    for (int k = 0; k < 4; k++) {
                        N_pin[k] = getch() - '0';
                        cout << "*";
                    }

                    cout << "\nConfirm your PIN: ";
                    for (int k = 0; k < 4; k++) {
                        user_entered_pin[k] = getch() - '0';
                        cout << "*";
                    }

                    int j = 0;
                    for (int k = 0; k < 4; k++) {
                        if (user_entered_pin[k] == N_pin[k]) {
                            j++;
                        }
                    }

                    if (j == 4) {
                        for (int k = 0; k < 4; k++) {
                            pin[k] = N_pin[k];
                        }
                        cout << "\n\nYour PIN has been successfully set!\n";
                    } else {
                        cout << "\n\nTransaction Declined \nNew PIN and Confirm PIN do not match";
                    }
                } else {
                    cout << "\n\nWrong PIN \n\nThank you";
                }
                break;
            }

            case 'd': // Deposit section
            case 'D': {
                cout << "\nDEPOSIT PER TRANSACTION LIMIT : 100000\n";
                cout << "A. Continue \nB. Cancel\n";
                char s2;
                cout << "\nSelect: ";
                cin >> s2;

                if (s2 == 'a' || s2 == 'A') {
                    int D_amt;
                    cout << "\nEnter amount: ";
                    cin >> D_amt;

                    cout << "\nEnter PIN: ";
                    for (int k = 0; k < 4; k++) {
                        user_entered_pin[k] = getch() - '0';
                        cout << "*";
                    }

                    int right = 0;
                    for (int k = 0; k < 4; k++) {
                        if (user_entered_pin[k] == pin[k]) {
                            right++;
                        }
                    }

                    if (right == 4) {
                        balance += D_amt;
                        cout << "\n\nSuccessfully added Rs " << D_amt << "\n";
                    } else {
                        cout << "\n\nWrong PIN \n\nThank you";
                    }
                } else {
                    cout << "\nTransaction Cancelled\n\nThank you";
                    return 0;
                }
                break;
            }

            case 'e': // Exit section
            case 'E':
                cout << "\n\t Thank You ";
                return 0;

            case 'f': // Mini Statement (Placeholder)
            case 'F':
                cout << "\nMini statement feature coming soon!\n";
                break;

            default:
                cout << "\nWrong input \n\n Thank you";
                return 0;
        }

        cout << "\n----------------------------------------------------------------";
        cout << "\n\nPress Enter...";
        getch();
    }

    cout << "\n\tThank You";
    getch();
    return 0;
}