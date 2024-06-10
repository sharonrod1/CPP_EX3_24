#ifndef BOARD_HPP
#define BOARD_HPP
#include "hexagon.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <utility>
using namespace std;
namespace ariel{
    class board
    {
    private:
        vector<vector<hexagon>> map;
        void initializeMap();
    public:
        board();
        void setsettlement(int x, int y);
        void randomizeResourses();
        void randomsizeCube();
        void setcity(int x, int y);
        void setvillage(int x, int y);
        void setroad(int x, int y);
        void printmap()  ;
        hexagon& gethexagon(size_t row, size_t col); // Add this method
        hexagon& returnhexagonS();
        hexagon& returnhexagonC();
        // void sethexagon(int x, int y, hexagon h);
        // pair<int,int> getint(int x);
        // void randomizeResourses();
        // void randomsizeCube();
    };
    
    // board::board(/* args */)
    // {
    // }
    
    // // board::~board()
    // // {
    // // }

    
 }
#endif 