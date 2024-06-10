#include "board.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;
using namespace ariel;

board::board() {
    initializeMap();
}

void board::initializeMap() {
    // Initialize the map with the specified number of hexagons in each row
    map.push_back(vector<hexagon>(3, hexagon(0, 0))); // First row with 3 hexagons
    map.push_back(vector<hexagon>(4, hexagon(0, 0))); // Second row with 4 hexagons
    map.push_back(vector<hexagon>(5, hexagon(0, 0))); // Third row with 5 hexagons
    map.push_back(vector<hexagon>(4, hexagon(0, 0))); // Fourth row with 4 hexagons
    map.push_back(vector<hexagon>(3, hexagon(0, 0))); // Fifth row with 3 hexagons
    for (size_t j = 0; j < map.size(); ++j){
    for(size_t i = 0; i < map[j].size(); ++i){
        for(size_t k=0;k<6;k++){
        map[j][i].setedge(k, std::make_shared<edge>());
        map[j][i].setvertex(k, std::make_shared<vertex>());
        }
        }
    }
    // Initialize edges and vertices to ensure shared edges and vertices
    for (size_t i = 0; i < map.size(); ++i) {
        for (size_t j = 0; j < map[i].size(); ++j) {
            
            // Top-left edge (shared with the hexagon above)
            if ((i > 0 && j > 0)||(i>2)) {
                if (i>2){
                    map[i][j].setedge(1, map[i-1][j].getedge(4));
                    map[i][j].setvertex(2, map[i-1][j].getvertecs(4));
                    map[i][j].setvertex(1, map[i-1][j].getvertecs(5));
                    
                }
                else{
                    map[i][j].setedge(1, map[i-1][j-1].getedge(4));
                    map[i][j].setvertex(2, map[i-1][j-1].getvertecs(4));
                    map[i][j].setvertex(1, map[i-1][j-1].getvertecs(5));
                    
                }
            }

            // Top-right edge (shared with the hexagon above-right)
            if ((i > 0 && j < map[i-1].size())||(i>2)) {
                if (i>2){
                    map[i][j].setedge(0, map[i-1][j+1].getedge(3));
                    map[i][j].setvertex(0, map[i-1][j+1].getvertecs(4));
                    map[i][j].setvertex(1, map[i-1][j+1].getvertecs(3));
                    
                }
                else{
                    map[i][j].setedge(0, map[i-1][j].getedge(3));
                    map[i][j].setvertex(0, map[i-1][j].getvertecs(4));
                    map[i][j].setvertex(1, map[i-1][j].getvertecs(3));
                    
                }
                
            } 

            // Left edge (shared with the hexagon to the left)
            if (j > 0) {
                map[i][j].setedge(2, map[i][j-1].getedge(5));
                map[i][j].setvertex(2, map[i][j-1].getvertecs(0));
                map[i][j].setvertex(3, map[i][j-1].getvertecs(5));
                
            } 

            // // Bottom-left edge (shared with the hexagon below)
            if ((i + 1 < map.size() && j>0)||(i<2)) {
                if (i<2){
                    map[i][j].setedge(3, map[i+1][j].getedge(0));
                    
                }
                else{
                    map[i][j].setedge(3, map[i+1][j-1].getedge(0));
                    
                }
            } else {
                map[i][j].setedge(3, std::make_shared<edge>());
                
            }

            // // Bottom-right edge (shared with the hexagon below-right)
            if ((i + 1 < map.size() && j  < map[i+1].size())||(i<2)) {
                if (i<2){
                    map[i][j].setedge(4, map[i+1][j+1].getedge(1));
                   
                }
                else{
                    map[i][j].setedge(4, map[i+1][j].getedge(1));
                    
                }
            } else {
                map[i][j].setedge(4, std::make_shared<edge>());
                
            }

            // // Right edge (shared with the hexagon to the right)
            if (j + 1 < map[i].size()) {
                map[i][j].setedge(5, map[i][j+1].getedge(2));
                
            } else {
                map[i][j].setedge(5, std::make_shared<edge>());
             
            }

        
        }
    }
    // board::randomizeResourses();
    
}

void board::printmap()  {
    for (size_t i = 0; i < map.size(); ++i) {
        for (size_t j = 0; j < map[i].size(); ++j) {
            cout << "Hexagon " << i << "," << j << "(" << map[i][j].getresource() << " " << map[i][j].getcube() << ")" ;  
        }
            cout << endl;
    }
}

hexagon& board::gethexagon(size_t row, size_t col) {
    return map[row][col];
}
// hexagon& board::returnhexagonS(){
//     for (size_t i = 0; i < map.size(); ++i) {
//         for (size_t j = 0; j < map[i].size(); ++j) {
//             if (map[i][j].getresource()==0){
//                 return map[i][j];
//             }
//         }
//     }
//     return map[0][0];
// }
// hexagon& board::returnhexagonC(){
//     for (size_t i = 0; i < map.size(); ++i) {
//         for (size_t j = 0; j < map[i].size(); ++j) {
//             if (map[i][j].getcube()==0){
//                 return map[i][j];
//             }
//         }
//     }
//     return map[0][0];
// }

// void board::randomizeResourses() {
//     // Randomize the resources of each hexagon
//         // Create a vector of resources
//         std::vector<std::string> resources;
//         for (int i = 0; i < 4; ++i) resources.push_back("wood");
//         for (int i = 0; i < 3; ++i) resources.push_back("brick");
//         for (int i = 0; i < 4; ++i) resources.push_back("wheat");
//         for (int i = 0; i < 3; ++i) resources.push_back("ore");
//         for (int i = 0; i < 4; ++i) resources.push_back("wool");
//         resources.push_back("desert");

//         // Shuffle the resources vector
//         std::random_device rd;
//         std::mt19937 g(rd());
//         std::shuffle(resources.begin(), resources.end(), g);

//         // Assign resources to each hexagon in the map
//         size_t resource_index = 0;
//         for (size_t row = 0; row < map.size(); ++row) {
//             for (size_t col = 0; col < map[row].size(); ++col) {
//                 map[row][col].setresource(resources[resource_index]);
//                 resource_index++;
//             }
//         }
//     }

