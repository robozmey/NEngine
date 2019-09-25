//
//  models.cpp
//  NEngine
//
//  Created by Vladimir Rachkin on 25/09/2019.
//  Copyright © 2019 Vladimir Rachkin. All rights reserved.
//

#include "models.h"


std::vector<poly> models::lab(){
    std::vector <poly> ans;
    
    std::vector <int> a[6];
    a[0] = {1, 0, 0, 0, 0, 0, 1 };
    a[1] = {1, 0, 0, 0, 0, 0, 1 };
    a[2] = {1, 0, 0, 1, 0, 1, 1 };
    a[3] = {1, 1, 0, 1, 1, 1, 1 };
    a[4] = {1, 0, 0, 0, 0, 0, 1 };
    a[5] = {1, 1, 1, 1, 1, 1, 1 };
    
    int sz = 3;
    int t = 0;
    int h = 5;

    
    for (double i = t; i <= h; i++) {
        for (double j = -sz; j <= sz; j++) {
            if ((i == 0 && j == 0) || !a[int(i)][int(j) + sz]) {
                //i += 1;
                i *= -2;
                j *= -2;
                ans.push_back(poly({ i - 1, j + 1, 1 }, { i + 1, j - 1, 1 }, { i + 1, j + 1, 1 }, {0, 0, 255}));
                ans.push_back(poly({ i - 1, j - 1, 1 }, { i + 1, j - 1, 1 }, { i - 1, j + 1, 1 }, {0, 0, 128}));
                ans.push_back(poly({ i - 1, j + 1, -1 }, { i + 1, j - 1, -1 }, { i + 1, j + 1, -1 }, {0, 0, 255}));
                ans.push_back(poly({ i - 1, j - 1, -1 }, { i + 1, j - 1, -1 }, { i - 1, j + 1, -1 }, {0, 0, 128}));
                //nengine.Polys.push_back(poly({ i - 1, j - 1, -2 }, { i + 1, j - 1, -2 }, { i - 1, j + 1, -2 }, RGB(0, 128, 255)));
                i /= -2;
                j /= -2;
                //i -= 1;
            }
            else {
                i *= -2;
                j *= -2;
                ans.push_back(poly({ i - 1, j + 1, 1 }, { i - 1, j + 1, -1 }, { i - 1, j - 1, -1 }, {0, 128, 0}));
                ans.push_back(poly({ i - 1, j + 1, 1 }, { i - 1, j - 1,  1 }, { i - 1, j - 1, -1 }, {0, 255, 0}));
                //nengine.Polys.push_back(poly({ i - 1.00001, j + 1.00002, 1.00003 }, { i - 1, j - 1,  1 }, { i - 1, j - 1.00008, -1.00009 }, RGB(0, 255, 0)));
                
                ans.push_back(poly({ i - 3, j + 1, 1 }, { i - 3, j + 1, -1 }, { i - 3, j - 1, -1 }, {0, 128, 0}));
                ans.push_back(poly({ i - 3, j + 1, 1 }, { i - 3, j - 1,  1 }, { i - 3, j - 1, -1 }, {0, 255, 0}));
                
                //////////////////////////////////////////////////////////
                
                ans.push_back(poly({ i - 3, j + 1, 1 }, { i - 5, j + 1, 1 }, { i - 5, j + 1, -1 }, {255, 0, 0}));
                ans.push_back(poly({ i - 3, j + 1, 1 }, { i - 3, j + 1, -1 }, { i - 5, j + 1, -1 }, {128, 0, 0}));
                
                ans.push_back(poly({ i - 3, j - 1, 1 }, { i - 5, j - 1, 1 }, { i - 5, j - 1, -1 }, {255, 0, 0}));
                ans.push_back(poly({ i - 3, j - 1, 1 }, { i - 3, j - 1, -1 }, { i - 5, j - 1, -1 }, {128, 0, 0}));
                
                i /= -2;
                j /= -2;
                
            }
        }
    }
    return ans;
}

models::models(){
    
}

models::~models(){
    
}

