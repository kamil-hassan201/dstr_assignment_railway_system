#pragma once

#include <iostream>

struct admin {
    int id;
    std::string pass;
};

admin* makeAdmins();
