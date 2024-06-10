#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>

using namespace std;

namespace ariel {
    class edge {
    private:
        int road;
        vector<int> vertices;
    public:
        edge(int road = 0); 
        void setroad(int road);
        int getroad() const;
        void addvertex(int vertex);
        vector<int> getvertices() const;
    };
}

#endif
