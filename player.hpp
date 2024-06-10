#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include <string>
using namespace std;
namespace ariel{
    class player{
        private:
        static int id;
        int playerid;
        string name;
        vector<int> resources;
        int points;
        vector<int> wildcards;
        public:
        player();
        player( const string &name);
        
    };
    
    }
#endif