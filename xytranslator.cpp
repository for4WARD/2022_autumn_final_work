//
// Created by 50207 on 2022/12/2.
//

#include "xytranslator.h"

#include <iostream>

int xytranslator::translator(int x) {
    int absolute=x-25;
    for(int i=0;i<19;i++)
    {
        if(absolute>=41*i-15&&absolute<=41*i+15)
        {
            return (i+1);
        }
    }
}

using namespace std;