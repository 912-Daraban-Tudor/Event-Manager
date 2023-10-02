//
// Created by tdara on 5/14/2023.
//
#include "Repo.h"
#include <string>


Repo::Repo() {
    this->current = 0;
}

Repo::~Repo() = default;

void Repo::addEvent(const Event &event) {
    if (events.findPosition(event) != -1) {
        throw exception();
    }
    else
        this->events.add(event);
}

void Repo::removeEvent(const Event &event) {
    /*
     * Function that removes an event from the repository by use of the find index function of the DynArr class
     * */
    int index = events.findPosition(event);
    this->events.remove(index);
}

void Repo::updateEvent(const Event &oldEvent, const Event &newEvent) {
    /*
     * Function that changes fields of an object in the repo by use of the find index function of the DynArr class
     * */
    int index = events.findPosition(oldEvent);
    this->events.update(index, newEvent);
}

int Repo::length() const {
    return this->events.length();
}

Event Repo::getElement(int index) const {
    return this->events.getElement(index);
}

Event Repo::getCurrent() const {
    return this->events.getElement(this->current);
}

void Repo::next() {
    /*
     * Parse function, circular list implementation
     * */
    this->current++;
    if (this->current == this->length()) {
        this->current = 0;
    }
}

void Repo::previous() {
    /*
     * Reverse parse function, circular list implementation
     * */
    this->current--;
    if (this->current == -1) {
        this->current = this->length() - 1;
    }
}

void Repo::setStart() {
    this->current = 0;
}

string Repo::getAll() const {
    /*
     * Function that returns a string containing all the events in the repo
     * */
    string result;
    for (int i = 0; i < this->length(); i++) {
        result += this->getElement(i).toString() + "\n";
    }
    return result;
}

string Repo::getLink(Event event) const {
    return this->getCurrent().getLink();
}

string Repo::userDisplayEvent(int month) {
    /*
     * Function that returns a string containing all the events in the repo that take place in a given month
     * after storing the result, the current event is set to the next event to avoid repetition
     * returns a string type
     * */
    while (this->getCurrent().getDate().getMonth() != month) {
        next();
    }
    string result;
    result += this->getCurrent().toString() + "\n";
    next();
    return result;
}

void Repo::userParticipate() {
    /**
     * Finds the position of the current user accesed event and increases its position
     * */
    int index = events.findPosition(this->getCurrent());
    this->events.getElement(index).setPeopleGoing(this->events.getElement(index).getPeopleGoing() + 1);
}

void Repo::userRemoveParticipation() {
    int index = events.findPosition(this->getCurrent());
    this->events.getElement(index).setPeopleGoing(this->events.getElement(index).getPeopleGoing() - 1);
}

void Repo::generateEvents() {
    // Generate and add 10 events
    for (int i = 0; i < 10; i++) {
        // Create unique event properties
        string title = "Party " + to_string(i + 1);
        string description = "Place " + to_string(i + 1);
        string date = "15/4/2023";  // Set a specific date for all events
        string time = "20:00";       // Set a specific time for all events
        int participants = i * 4 + 1;
        string link = "https://youtu.be/5jnZMW8C6wA";

        // Create the event object
        Date dateObj(date);
        Time timeObj(time);
        Event event(title, description, dateObj, timeObj, participants, link);

        // Add the event to the repository
        addEvent(event);
    }
}
