#include<stdio.h>
#include<iostream>

#include "update.h"

using namespace std;

int main(int argc, char* args[]){
    if(!init()){
        printf("Initialization failed %s\n",SDL_GetError());
        return 1;
    }

    update();

    finish();

    return 0;
}
