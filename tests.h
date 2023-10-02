#pragma once

#ifndef A45_912_DARABAN_TUDOR_TESTS_H
#define A45_912_DARABAN_TUDOR_TESTS_H
#include <iostream>
#include "ServiceAdmin.h"
#include "Repo.h"

void testService() {
    // Create the admin repository
    Repo adminRepo;

    // Create the user repository
    Repo userRepo;

    // Create the service object
    Service service(adminRepo, userRepo);

    // Add an event
    service.addEvent("Concert", "Andra", "2023/02/19", "7:00", 0, "https://google.com");


    service.removeEvent("Concert", "Andra", "2023/02/19", "7:00", 0, "https://google.com");

    service.addEvent("Concert", "Andra", "2023/02/19", "7:00", 0, "https://google.com");
    // Update an event
    service.updateEvent("Concert", "Andra", "Event ", "Descr",
                        "2023/05/15", "10:00", 0, "https://google.com");

}


void testRepo() {
    // Create the repository object
    Repo repo;

    // Generate events
    repo.generateEvents();

    // Get the length of the repository
    int repoLength = repo.length();
    //std::cout << "Repository Length: " << repoLength << std::endl;

    // Get the current event
    Event currentEvent = repo.getCurrent();
    //std::cout << "Current Event:\n" << currentEvent.toString() << std::endl;

    // Display all events in the repository
    std::string allEvents = repo.getAll();
    //std::cout << "All Events:\n" << allEvents << std::endl;

    // Display events starting from a specific month
    std::string eventsStartMonth = repo.userDisplayEvent(4);
    //std::cout << "Events Starting from April:\n" << eventsStartMonth << std::endl;

    // Participate in the current event
    repo.userParticipate();
    currentEvent = repo.getCurrent();
    //std::cout << "Current Event (After Participation):\n" << currentEvent.toString() << std::endl;

    // Remove participation from the current event
    repo.userRemoveParticipation();
    currentEvent = repo.getCurrent();
    //std::cout << "Current Event (After Participation Removal):\n" << currentEvent.toString() << std::endl;
}


#endif //A45_912_DARABAN_TUDOR_TESTS_H
