#pragma once

#include "models.h"
#include"poly.h"
#include<vector>

class models
{
public:

    std::vector<poly> lab();
    std::vector<poly> cube();

    models();
    ~models();
};
