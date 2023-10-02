
#include "Event.h"


using namespace std;

Event::Event() : title(""), description(""), date(Date()), time(Time()), peopleGoing(0), link("")
{
}

Event::Event(const string& title, const string& description, const Date& date, const Time& time, int peopleGoing,
             const string& link) : title(title), description(description), date(date), time(time),
             peopleGoing(peopleGoing), link(link)
{
    this->title = title;
    this->description = description;
    this->date = date;
    this->time = time;
    this->peopleGoing = peopleGoing;
    this->link = link;
}

bool Event::operator==(const Event & e)
{
    return (this->title == e.title && this->description == e.description);
}

string Event::toString()
{
    return "Title: " + this->title + " | Description: " + this->description + " | Date: " + to_string(this->date.getDay()) + "/" +
           to_string(this->date.getMonth()) + "/" + to_string(this->date.getYear()) + " | Hour: " +
           to_string(this->time.getMinutes()) + ":" + to_string(this->time.getSeconds()) + " | Atendees:" +
           to_string(this->peopleGoing) + " | Event Link:" + this->link;
}

