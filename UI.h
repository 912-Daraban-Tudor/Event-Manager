#pragma once

#ifndef A45_912_DARABAN_TUDOR_UI_H
#define A45_912_DARABAN_TUDOR_UI_H
#include "ServiceAdmin.h"
class UI{
private:
    Service service;
public:
    UI(const Service& service);
    ~UI();

    void run();
    void adminMode();
    void userMode();
    void addEventAdmin();
    void removeEventAdmin();
    void updateEventAdmin();
    void displayEventsAdmin();
    void userDisplayEventStart(int month);
    void userDisplayEventNext(int month);
    void userSeeMyEvents();
    void userParticipate();
    void userRemoveParticipation();



};
#endif //A45_912_DARABAN_TUDOR_UI_H
