#include "player.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace ariel{
    int player::id=0;

    player :: player( const string &name){
        this->name=name;
        this->points=0;
        this->resources={0,0,0,0,0};
        this->wildcards={0,0,0,0,0};
        this->playerid=this->id++;
    }
    player :: player(){
        
    }
    
}