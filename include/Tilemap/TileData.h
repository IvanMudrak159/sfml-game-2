#pragma once
#include <string>
#include <array>

struct TileData {
    int type;         
    bool hasCollider;  
    std::string sprite;
};

const std::array<TileData, 4> tileSet = { {
    {0, false, "grass"},
    {1, true,  "water"},
    {2, true, "tree"},
    {3, false,  "floor"}
} };
