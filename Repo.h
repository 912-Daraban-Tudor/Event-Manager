#pragma once
#ifndef A45_912_DARABAN_TUDOR_REPO_H
#define A45_912_DARABAN_TUDOR_REPO_H
#include "Event.h"
#include "DynArr.h"

class Repo {
private:
    DynamicVector<Event> events;
    int current;
public:
    Repo();
    ~Repo();

    void addEvent(const Event& event);
    void removeEvent(const Event& event);
    void updateEvent(const Event& oldEvent, const Event& newEvent);
    int length() const;
    Event getElement(int index) const;
    Event getCurrent() const;
    string getLink(Event event) const;
    void next();
    void previous();
    void setStart();
    string getAll() const;
    string userDisplayEvent(int month);
    void userParticipate();
    void userRemoveParticipation();
    void generateEvents();
};
#endif //A45_912_DARABAN_TUDOR_REPO_H
