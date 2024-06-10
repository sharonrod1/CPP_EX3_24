#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "player.hpp"

using namespace std;

namespace ariel {
    class vertex {
    private:
        int building; // Example attribute, similar to `road` in `edge`
        player d; // Player attribute
         // Example attribute to hold edges connected to this vertex
    public:
        vertex(int building = 0);
        void setbuilding(int building);
        int getbuilding() const;
        void setplayer(const player& p);
        player getplayer() const;
       
    };
}

#endif
