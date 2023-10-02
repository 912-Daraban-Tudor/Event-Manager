
#include "UI.h"
#include <iostream>
#include <string>

using namespace std;

UI::UI(const Service& service) : service(service)
{
}

UI::~UI() = default;

void UI::run()
{
    try {
        while (true) {
            int command{0};
            cout << "1. Admin mode\n2. User mode\n0. Exit\nInput the command: ";
            cin >> command;
            cin.ignore();
            if (command == 0)
                return;
            switch (command) {
                case 1:
                    adminMode();
                    break;
                case 2:
                    userMode();
                    break;
                default:
                    cout << "Invalid command!\n";
                    break;
            }
        }
    }
    catch (const std::exception& exception) {
        cout << exception.what() << "\n";
    }
}

void UI::adminMode() {
    try {
        while (true) {
            int command{0};
            cout << "1. Add event\n2. Remove event\n3. Update event\n4. Display events\n0. Exit\nEnter a command: ";
            cin >> command;
            cin.ignore();
            if (command == 0)
                break;
            switch (command) {
                case 1:
                    addEventAdmin();
                    break;
                case 2:
                    removeEventAdmin();
                    break;
                case 3:
                    updateEventAdmin();
                    break;
                case 4:
                    displayEventsAdmin();
                    break;
                default:
                    cout << "Invalid command!\n";
                    break;
            }
        }
    }
    catch (const std::exception& exception) {
        cout << exception.what() << "\n";
    }
}

void UI::addEventAdmin() {
    std::string title, description, date, time, link;
    int numberOfPeople;
    cout << "Enter the title: ";
    getline(cin, title);
    cout << "Enter the description: ";
    getline(cin, description);
    cout << "Enter the date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter the time (HH:MM): ";
    getline(cin, time);
    cout << "Enter the number of people: ";
    cin >> numberOfPeople;
    cin.ignore();
    cout << "Enter the link: ";
    getline(cin, link);
    try
    {
        this->service.addEvent(title, description, date, time, numberOfPeople, link);
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::removeEventAdmin() {
    std::string title, description, date, time, link;
    int numberOfPeople;
    cout << "Enter the title: ";
    getline(cin, title);
    cout << "Enter the description: ";
    getline(cin, description);
    cout << "Enter the date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter the time (HH:MM): ";
    getline(cin, time);
    cout << "Enter the number of people: ";
    cin >> numberOfPeople;
    cin.ignore();
    cout << "Enter the link: ";
    getline(cin, link);
    try
    {
        this->service.removeEvent(title, description, date, time, numberOfPeople, link);
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::updateEventAdmin() {
    std::string oldTitle, oldDescription, newTitle, newDescription, date, time, link;
    int numberOfPeople;
    cout << "Enter the old title: ";
    getline(cin, oldTitle);
    cout << "Enter the old description: ";
    getline(cin, oldDescription);
    cout << "Enter the new title: ";
    getline(cin, newTitle);
    cout << "Enter the new description: ";
    getline(cin, newDescription);
    cout << "Enter the new date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter the new time (HH:MM): ";
    getline(cin, time);
    cout << "Enter the new number of people: ";
    cin >> numberOfPeople;
    cin.ignore();
    cout << "Enter the new link: ";
    getline(cin, link);

    try
    {
        this->service.updateEvent(oldTitle, oldDescription, newTitle,
                                  newDescription, date, time, numberOfPeople, link);
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::displayEventsAdmin() {
    string result = this->service.getAllAdmin();
    cout << result;
}


void UI::userMode() {
    try {
        while (true) {
            int command{0};
            cout << "1. Display events\n2. See my events\n3. Remove participation\n0. Exit\nEnter a command: ";
            cin >> command;
            cin.ignore();
            if (command == 0)
                break;
            switch (command) {
                case 1:
                    int month;
                    cout << "Please enter the month you want to search events for: ";
                    cin >> month;
                    userDisplayEventStart(month);
                    break;
                case 2:
                    userSeeMyEvents();
                    break;
                case 3:
                    userRemoveParticipation();
                    break;
                default:
                    cout << "Invalid command!\n";
                    break;
            }
        }
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::userSeeMyEvents() {
    string result = this->service.getAllUser();
    cout << result;
}

void UI::userRemoveParticipation() {
    std::string title, description, date, time, link;
    int numberOfPeople;
    cout << "Enter the title: ";
    getline(cin, title);
    cout << "Enter the description: ";
    getline(cin, description);
    cout << "Enter the date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter the time (HH:MM): ";
    getline(cin, time);
    cout << "Enter the number of people: ";
    cin >> numberOfPeople;
    cin.ignore();
    cout << "Enter the link: ";
    getline(cin, link);
    try
    {
        this->service.userRemoveParticipation(title, description, date, time, numberOfPeople, link);
    }
    catch (const std::exception& exception)
    {
        cout << exception.what() << "\n";
    }
}

void UI::userDisplayEventStart(int month) {
    try {
        string event = this->service.userDisplayEventStart(month);
        cout << event;
        while (true) {
            int command{0};
            cout << "1. Display next event\n2. Participate\n3. Open link in browser\n0. Exit\nEnter a command: ";
            cin >> command;
            cin.ignore();
            if (command == 0)
                break;
            switch (command) {
                case 1:
                    userDisplayEventNext(month);
                    break;
                case 2:
                    userParticipate();
                    break;
                case 3:
                    this->service.userOpenLink(this->service.getCurrent());
                    break;
                default:
                    cout << "Invalid command!\n";
                    break;
            }
        }
    }
    catch (const std::exception& exception) {
        cout << exception.what() << "\n";
    }
}

void UI::userDisplayEventNext(int month) {
    string event = this->service.userDisplayEventNext(month);
    cout << event;
}

void UI::userParticipate() {
    this->service.userParticipate();
}