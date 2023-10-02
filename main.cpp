
#include "UI.h"
#include "tests.h"
int main(){
    testService();
    testRepo();
    Repo repo, repoUser;
    Service service(repo, repoUser);
    UI ui(service);
    ui.run();
    return 0;
}