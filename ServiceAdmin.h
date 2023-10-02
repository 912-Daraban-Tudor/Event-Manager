#pragma once
#ifndef A45_912_DARABAN_TUDOR_SERVICEADMIN_H
#define A45_912_DARABAN_TUDOR_SERVICEADMIN_H
#include "Repo.h"
#include "Event.h"
#include "DynArr.h"

class Service {
private:
    Repo repo;
    Repo repoUser;
public:
    Service(Repo &repoEvents, Repo &repoUserEvents);
    ~Service();

    void addEvent(const string& title, const string& description, const string& date,
                  const string& time, int peopleGoing, const string& link);
    void removeEvent(const string& title, const string& description, const string& date,
                     const string& time, int peopleGoing, const string& link);
    void updateEvent(const string& oldTitle, const string& oldDescription,
                     const string& title, const string& description, const string& date,
                     const string& time, int peopleGoing, const string& link);
    int length() const;
    Event getElement(int index) const;
    Event getCurrent() const;
    void next();
    void previous();
    string getAllAdmin();
    string getAllUser();
    string userDisplayEventStart(int month);
    string userDisplayEventNext(int month);
    void userParticipate();
    void userRemoveParticipation(const string &title, const string &description, const string &date,
                                 const string &time, int peopleGoing, const string &link);

    void userOpenLink(Event event);
};


#endif //A45_912_DARABAN_TUDOR_SERVICEADMIN_H
