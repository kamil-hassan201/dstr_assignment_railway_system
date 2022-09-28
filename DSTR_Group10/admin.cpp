#include "admin.h"

admin * makeAdmins(){
    admin admin1, admin2, admin3;
    
    admin1.id = 1;
    admin1.pass = "1234";
    admin2.id = 2;
    admin2.pass = "2";
    admin3.id = 3;
    admin3.pass = "A784321";

    admin *admins = new admin[3];
    admins[0] = admin1;
    admins[1] = admin2;
    admins[2] = admin3;

    return admins;
}
