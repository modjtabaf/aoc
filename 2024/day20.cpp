
#include <cstdint>
#include <endian.h>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <unordered_set>

using Map = std::vector<std::string>;
using Spots = std::unordered_set<int>;

std::array<std::pair<int, int>, 4> dxdy{{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
}};

Map sample_map{
    "###############",
    "#...#...#.....#",
    "#.#.#.#.#.###.#",
    "#S#...#.#.#...#",
    "#######.#.#.###",
    "#######.#.#...#",
    "#######.#.###.#",
    "###..E#...#...#",
    "###.#######.###",
    "#...###...#...#",
    "#.#####.#.###.#",
    "#.#...#.#.#...#",
    "#.#.#.#.#.#.###",
    "#...#...#...###",
    "###############",
};

Map map{
    "#############################################################################################################################################",
    "###...#...#.......#.....#.....#.....#...###.......#...#...........#...............#...#.......#...#.....#.........#.....###.....###.....#...#",
    "###.#.#.#.#.#####.#.###.#.###.#.###.#.#.###.#####.#.#.#.#########.#.#############.#.#.#.#####.#.#.#.###.#.#######.#.###.###.###.###.###.#.#.#",
    "#...#.#.#...#...#.#.#...#...#.#...#.#.#.....#.....#.#.#.........#.#.......#.......#.#.#...#...#.#.#.#...#.....#...#...#...#...#...#...#.#.#.#",
    "#.###.#.#####.#.#.#.#.#####.#.###.#.#.#######.#####.#.#########.#.#######.#.#######.#.###.#.###.#.#.#.#######.#.#####.###.###.###.###.#.#.#.#",
    "#...#.#.......#.#.#.#.....#.#.###.#...#.....#.#...#.#.#.....#...#.......#.#.....#...#.###.#.###.#.#.#.#...###.#...###...#...#.#...#...#...#.#",
    "###.#.#########.#.#.#####.#.#.###.#####.###.#.#.#.#.#.#.###.#.#########.#.#####.#.###.###.#.###.#.#.#.#.#.###.###.#####.###.#.#.###.#######.#",
    "###.#.#...#.....#.#.#.....#.#.#...#.....###...#.#...#.#...#.#.........#...#...#.#.#...#...#...#.#.#.#.#.#...#.#...#...#.#...#.#.###...#.....#",
    "###.#.#.#.#.#####.#.#.#####.#.#.###.###########.#####.###.#.#########.#####.#.#.#.#.###.#####.#.#.#.#.#.###.#.#.###.#.#.#.###.#.#####.#.#####",
    "#...#...#.#.....#...#.......#...#...#...#...###.#.....###.#.###...###...#...#...#.#.#...#...#.#.#.#.#.#...#.#.#.###.#...#.#...#.....#.#.#...#",
    "#.#######.#####.#################.###.#.#.#.###.#.#######.#.###.#.#####.#.#######.#.#.###.#.#.#.#.#.#.###.#.#.#.###.#####.#.#######.#.#.#.#.#",
    "#...#...#.....#.#...............#.....#.#.#...#.#.#.......#.#...#.#...#.#.....#...#...#...#...#.#.#.#...#.#.#.#.....#...#...#...#...#.#.#.#.#",
    "###.#.#.#####.#.#.#############.#######.#.###.#.#.#.#######.#.###.#.#.#.#####.#.#######.#######.#.#.###.#.#.#.#######.#.#####.#.#.###.#.#.#.#",
    "#...#.#.....#.#...#.....#.....#.#.......#...#.#.#.#.......#.#...#.#.#.#.#.....#.......#.#.....#.#.#.#...#.#...#.......#.......#...#...#...#.#",
    "#.###.#####.#.#####.###.#.###.#.#.#########.#.#.#.#######.#.###.#.#.#.#.#.###########.#.#.###.#.#.#.#.###.#####.###################.#######.#",
    "#.....#...#.#.#...#...#.#...#.#.#.###...#...#...#.#.....#.#.#...#...#...#...#...#.....#.#...#.#.#...#.....#.....#.....#.......###...#.......#",
    "#######.#.#.#.#.#.###.#.###.#.#.#.###.#.#.#######.#.###.#.#.#.#############.#.#.#.#####.###.#.#.###########.#####.###.#.#####.###.###.#######",
    "#.......#...#...#...#.#.....#.#.#.....#.#.....#...#...#.#.#.#...........#...#.#.#.....#.#...#...#...........#...#...#.#.#.....#...#...#.....#",
    "#.#################.#.#######.#.#######.#####.#.#####.#.#.#.###########.#.###.#.#####.#.#.#######.###########.#.###.#.#.#.#####.###.###.###.#",
    "#...............#...#.#.....#.#.#.......###...#.#.....#...#.#.......#...#...#.#.#...#.#.#.......#.###.....#...#...#.#...#...###...#.#...#...#",
    "###############.#.###.#.###.#.#.#.#########.###.#.#########.#.#####.#.#####.#.#.#.#.#.#.#######.#.###.###.#.#####.#.#######.#####.#.#.###.###",
    "#.........#...#.#.###.#.#...#...#...#...#...#...#.........#.#.#.....#.....#.#.#.#.#.#.#...###...#.....#...#.#.....#.#.....#...###.#.#.#...###",
    "#.#######.#.#.#.#.###.#.#.#########.#.#.#.###.###########.#.#.#.#########.#.#.#.#.#.#.###.###.#########.###.#.#####.#.###.###.###.#.#.#.#####",
    "#.......#.#.#...#...#...#.#.......#.#.#.#...#.#...#...###.#.#.#.###.....#.#.#.#...#...#...#...#.........#...#...#...#...#.....#...#...#.....#",
    "#######.#.#.#######.#####.#.#####.#.#.#.###.#.#.#.#.#.###.#.#.#.###.###.#.#.#.#########.###.###.#########.#####.#.#####.#######.###########.#",
    "#...#...#.#.....#...#...#...#.....#.#.#.#...#.#.#.#.#.#...#.#.#...#...#.#.#.#...#...#...#...#...#...#...#.#.....#.#...#.......#...#.........#",
    "#.#.#.###.#####.#.###.#.#####.#####.#.#.#.###.#.#.#.#.#.###.#.###.###.#.#.#.###.#.#.#.###.###.###.#.#.#.#.#.#####.#.#.#######.###.#.#########",
    "#.#.#...#.......#...#.#.#...#.....#.#.#...#...#.#.#.#.#.#...#...#...#.#.#.#...#.#.#...###...#.#...#...#.#.#...###.#.#.#.......#...#.###...###",
    "#.#.###.###########.#.#.#.#.#####.#.#.#####.###.#.#.#.#.#.#####.###.#.#.#.###.#.#.#########.#.#.#######.#.###.###.#.#.#.#######.###.###.#.###",
    "#.#.....#...#...#...#.#.#.#.#...#.#.#.....#...#.#...#...#.....#...#.#.#...#...#.#.....#...#.#.#.#.....#.#.#...#...#.#.#.#.....#...#.....#...#",
    "#.#######.#.#.#.#.###.#.#.#.#.#.#.#.#####.###.#.#############.###.#.#.#####.###.#####.#.#.#.#.#.#.###.#.#.#.###.###.#.#.#.###.###.#########.#",
    "#.#.....#.#.#.#.#...#.#.#.#...#...#...#...#...#.....#.........#...#.#.....#...#.#.....#.#.#.#.#.#...#...#.#...#.#...#...#.#...#...#...#...#.#",
    "#.#.###.#.#.#.#.###.#.#.#.###########.#.###.#######.#.#########.###.#####.###.#.#.#####.#.#.#.#.###.#####.###.#.#.#######.#.###.###.#.#.#.#.#",
    "#.#.#...#.#...#...#.#.#.#.........#...#...#.#...###.#.###...###...#.#...#.#...#.#.#...#.#.#.#.#...#.#...#.#...#.#.....#...#.#...#...#...#.#.#",
    "#.#.#.###.#######.#.#.#.#########.#.#####.#.#.#.###.#.###.#.#####.#.#.#.#.#.###.#.#.#.#.#.#.#.###.#.#.#.#.#.###.#####.#.###.#.###.#######.#.#",
    "#.#.#...#.#.......#.#.#.###.......#...#...#.#.#...#.#.....#.#...#.#.#.#.#.#.#...#.#.#...#.#.#...#.#.#.#...#.....#.....#.#...#.#...#...###.#.#",
    "#.#.###.#.#.#######.#.#.###.#########.#.###.#.###.#.#######.#.#.#.#.#.#.#.#.#.###.#.#####.#.###.#.#.#.###########.#####.#.###.#.###.#.###.#.#",
    "#...###.#.#.......#.#.#...#.........#.#...#...#...#.....###.#.#...#...#.#.#.#.#...#.#.....#...#...#.#.#...........#...#.#.....#.....#...#...#",
    "#######.#.#######.#.#.###.#########.#.###.#####.#######.###.#.#########.#.#.#.#.###.#.#######.#####.#.#.###########.#.#.###############.#####",
    "#.......#.#.......#...#...#...#...#.#.#...#.....#...#...#...#.......#...#.#.#.#...#.#...#.....#.....#.#...#.........#...#.....#.......#.....#",
    "#.#######.#.###########.###.#.#.#.#.#.#.###.#####.#.#.###.#########.#.###.#.#.###.#.###.#.#####.#####.###.#.#############.###.#.#####.#####.#",
    "#.#.......#.#.....#...#...#.#...#...#...#...#...#.#.#...#...#.....#.#...#.#...#...#.###.#.....#.....#.#...#.#.....#...#...#...#.....#.......#",
    "#.#.#######.#.###.#.#.###.#.#############.###.#.#.#.###.###.#.###.#.###.#.#####.###.###.#####.#####.#.#.###.#.###.#.#.#.###.#######.#########",
    "#...#.....#.#.#...#.#...#...#...........#.#...#.#.#.#...#...#...#...###.#.....#...#...#.#...#.....#...#...#.#.###...#...###.........###...###",
    "#####.###.#.#.#.###.###.#####.#########.#.#.###.#.#.#.###.#####.#######.#####.###.###.#.#.#.#####.#######.#.#.#########################.#.###",
    "#...#...#...#.#.#...###.....#.#.......#.#.#.#...#.#.#...#.....#.......#...#...#...#...#...#.......#...###...#.......#.....#.......###...#...#",
    "#.#.###.#####.#.#.#########.#.#.#####.#.#.#.#.###.#.###.#####.#######.###.#.###.###.###############.#.#############.#.###.#.#####.###.#####.#",
    "#.#.###.......#...#...#.....#.#.#...#...#...#...#.#.#...#.....#...#...###.#.###...#.#.....#.........#.........#.....#.#...#...#...#...#.....#",
    "#.#.###############.#.#.#####.#.#.#.###########.#.#.#.###.#####.#.#.#####.#.#####.#.#.###.#.#################.#.#####.#.#####.#.###.###.#####",
    "#.#.............#...#.#...#...#...#.....#...###...#...###.....#.#...#.....#...#...#...#...#.................#...#...#.#.###...#...#.#...#...#",
    "#.#############.#.###.###.#.###########.#.#.#################.#.#####.#######.#.#######.###################.#####.#.#.#.###.#####.#.#.###.#.#",
    "#.#...........#.#...#...#.#.#...........#.#.#...#...###...#...#.....#.....#...#...#...#...#.................###...#...#...#.#.....#.#...#.#.#",
    "#.#.#########.#.###.###.#.#.#.###########.#.#.#.#.#.###.#.#.#######.#####.#.#####.#.#.###.#.###################.#########.#.#.#####.###.#.#.#",
    "#...#.....#...#.....#...#...#...#.........#...#...#...#.#...#.....#...#...#.....#.#.#...#.#...#.......#...#...#.....#...#...#.....#...#...#.#",
    "#####.###.#.#########.#########.#.###################.#.#####.###.###.#.#######.#.#.###.#.###.#.#####.#.#.#.#.#####.#.#.#########.###.#####.#",
    "#...#...#.#.....#...#...#...###...#################...#.#...#...#.#...#.....#...#.#.#...#.#...#.#...#...#.#.#.......#.#.#...#...#.....#...#.#",
    "#.#.###.#.#####.#.#.###.#.#.#######################.###.#.#.###.#.#.#######.#.###.#.#.###.#.###.#.#.#####.#.#########.#.#.#.#.#.#######.#.#.#",
    "#.#.....#...###...#...#.#.#.#..S###################...#...#.#...#.#.....###.#...#.#.#.....#.....#.#.......#.#.....#...#...#...#.#...#...#...#",
    "#.#########.#########.#.#.#.#.#######################.#####.#.###.#####.###.###.#.#.#############.#########.#.###.#.###########.#.#.#.#######",
    "#.........#...#.......#...#...#########...#.....#####...#...#...#.#.....#...#...#...###.....#.....#...#.....#...#...#...#.....#.#.#.#.......#",
    "#########.###.#.#######################.#.#.###.#######.#.#####.#.#.#####.###.#########.###.#.#####.#.#.#######.#####.#.#.###.#.#.#.#######.#",
    "#.......#.#...#...............#########.#...#...#######E#...#...#.#...###...#.#.......#...#.#.....#.#...#.....#.......#.#.#...#.#.#...#...#.#",
    "#.#####.#.#.#################.#########.#####.#############.#.###.###.#####.#.#.#####.###.#.#####.#.#####.###.#########.#.#.###.#.###.#.#.#.#",
    "#.#...#...#...#...#...........#.....###.#.....###.....#...#.#.###...#.....#...#.....#.#...#.......#.#...#...#.#.......#...#...#...###...#...#",
    "#.#.#.#######.#.#.#.###########.###.###.#.#######.###.#.#.#.#.#####.#####.#########.#.#.###########.#.#.###.#.#.#####.#######.###############",
    "#.#.#...#...#.#.#.#.........#...###.....#...#...#...#.#.#.#.#.....#.#.....###...#...#...#...#.......#.#.....#.#.....#...#...#...............#",
    "#.#.###.#.#.#.#.#.#########.#.#############.#.#.###.#.#.#.#.#####.#.#.#######.#.#.#######.#.#.#######.#######.#####.###.#.#.###############.#",
    "#.#.###...#.#.#.#.#...#...#...#...#.........#.#...#.#.#.#.#...#...#.#.#.......#...#.....#.#...###...#.......#.#...#...#.#.#.#.....#...#...#.#",
    "#.#.#######.#.#.#.#.#.#.#.#####.#.#.#########.###.#.#.#.#.###.#.###.#.#.###########.###.#.#######.#.#######.#.#.#.###.#.#.#.#.###.#.#.#.#.#.#",
    "#...#...#...#...#...#...#.......#...#.........#...#.#...#...#...###.#.#.#.......#...###...###...#.#.#...#...#...#...#.#.#.#...###.#.#.#.#...#",
    "#####.#.#.###########################.#########.###.#######.#######.#.#.#.#####.#.###########.#.#.#.#.#.#.#########.#.#.#.#######.#.#.#.#####",
    "###...#...#...#...#...#...#.....#.....#...#...#.....#.....#.......#...#...#.....#...#.........#...#...#...#...#...#...#...###.....#.#.#.....#",
    "###.#######.#.#.#.#.#.#.#.#.###.#.#####.#.#.#.#######.###.#######.#########.#######.#.#####################.#.#.#.###########.#####.#.#####.#",
    "#...#.....#.#.#.#.#.#...#...###...#...#.#.#.#.......#...#.#...#...#...#...#.........#.........#...#.........#...#...........#.......#.....#.#",
    "#.###.###.#.#.#.#.#.###############.#.#.#.#.#######.###.#.#.#.#.###.#.#.#.###################.#.#.#.#######################.#############.#.#",
    "#...#.#...#.#.#.#...#...............#...#...#.....#.....#...#.#...#.#...#.#.......#.....#...#...#...#.......................#...........#.#.#",
    "###.#.#.###.#.#.#####.#######################.###.###########.###.#.#####.#.#####.#.###.#.#.#########.#######################.#########.#.#.#",
    "###...#...#.#.#...#...#...#...#...........###.#...###.......#.....#.#...#.#...#...#...#...#.......###...............#.......#...#.....#.#...#",
    "#########.#.#.###.#.###.#.#.#.#.#########.###.#.#####.#####.#######.#.#.#.###.#.#####.###########.#################.#.#####.###.#.###.#.#####",
    "#.......#.#.#.....#...#.#.#.#.#.#.......#.....#.......#.....#.....#.#.#.#.....#.......#.........#...............#...#.#.....#...#...#...#...#",
    "#.#####.#.#.#########.#.#.#.#.#.#.#####.###############.#####.###.#.#.#.###############.#######.###############.#.###.#.#####.#####.#####.#.#",
    "#.....#...#.#.......#...#...#...#.....#.....#.........#.#...#.#...#...#.........#.....#.#.......#...#.........#.#.....#.....#.#.....#.....#.#",
    "#####.#####.#.#####.#################.#####.#.#######.#.#.#.#.#.###############.#.###.#.#.#######.#.#.#######.#.###########.#.#.#####.#####.#",
    "#.....#...#.#.....#...................#...#.#.......#.#...#...#.....#.........#...#...#.#...#...#.#...#.......#.............#.#.......#.....#",
    "#.#####.#.#.#####.#####################.#.#.#######.#.#############.#.#######.#####.###.###.#.#.#.#####.#####################.#########.#####",
    "#.....#.#...###...#...#.................#.#.........#...............#.......#.#...#.....#...#.#...#...#...........#...........#...#...#.....#",
    "#####.#.#######.###.#.#.#################.#################################.#.#.#.#######.###.#####.#.###########.#.###########.#.#.#.#####.#",
    "#.....#.#...#...#...#...#...............#...###...#...#.....#...#...###...#.#...#.###...#.....###...#...........#...#...........#...#.......#",
    "#.#####.#.#.#.###.#######.#############.###.###.#.#.#.#.###.#.#.#.#.###.#.#.#####.###.#.#########.#############.#####.#######################",
    "#.....#.#.#.#...#.###...#.......#...###...#.....#.#.#.#.#...#.#.#.#.....#.#.....#.#...#.#.......#.............#.#...#.........#.....#.......#",
    "#####.#.#.#.###.#.###.#.#######.#.#.#####.#######.#.#.#.#.###.#.#.#######.#####.#.#.###.#.#####.#############.#.#.#.#########.#.###.#.#####.#",
    "#.....#.#.#...#...#...#...#...#...#.....#.#...#...#.#.#.#.###.#.#...#.....#.....#...#...#.#...#.#...........#.#.#.#...#.....#...#...#.#.....#",
    "#.#####.#.###.#####.#####.#.#.#########.#.#.#.#.###.#.#.#.###.#.###.#.#####.#########.###.#.#.#.#.#########.#.#.#.###.#.###.#####.###.#.#####",
    "#.......#.#...#...#.#...#...#...#.......#...#.#.###.#.#.#...#.#.#...#.#...#.....#.....###...#.#.#.........#...#...#...#...#.#...#.....#.....#",
    "#########.#.###.#.#.#.#.#######.#.###########.#.###.#.#.###.#.#.#.###.#.#.#####.#.###########.#.#########.#########.#####.#.#.#.###########.#",
    "#.........#...#.#.#...#.....#...#...###...###.#.#...#.#.#...#.#.#.#...#.#.#...#.#.........#...#...........#...#...#.......#...#.#...#...#...#",
    "#.###########.#.#.#########.#.#####.###.#.###.#.#.###.#.#.###.#.#.#.###.#.#.#.#.#########.#.###############.#.#.#.#############.#.#.#.#.#.###",
    "#.#...#.....#...#.#.........#.#...#...#.#...#...#...#.#.#...#.#...#.#...#.#.#.#.#.........#.........#.......#...#.............#.#.#.#.#...###",
    "#.#.#.#.###.#####.#.#########.#.#.###.#.###.#######.#.#.###.#.#####.#.###.#.#.#.#.#################.#.#######################.#.#.#.#.#######",
    "#...#.#.#...#...#.#.........#...#.....#...#...#.....#.#.#...#.#.....#...#.#.#.#.#.#...#...###...###...#.....#.................#...#.#.......#",
    "#####.#.#.###.#.#.#########.#############.###.#.#####.#.#.###.#.#######.#.#.#.#.#.#.#.#.#.###.#.#######.###.#.#####################.#######.#",
    "#...#...#.....#.#...........#.......#.....#...#.....#.#.#...#.#.#...#...#.#.#.#.#.#.#.#.#...#.#.#.....#...#...#...#...#...........#.#.....#.#",
    "#.#.###########.#############.#####.#.#####.#######.#.#.###.#.#.#.#.#.###.#.#.#.#.#.#.#.###.#.#.#.###.###.#####.#.#.#.#.#########.#.#.###.#.#",
    "#.#...........#.......#...#...#.....#...#...###...#.#.#.#...#.#.#.#.#...#.#.#.#.#.#.#.#...#.#.#.#...#.###.......#...#...#...#.....#...###...#",
    "#.###########.#######.#.#.#.###.#######.#.#####.#.#.#.#.#.###.#.#.#.###.#.#.#.#.#.#.#.###.#.#.#.###.#.###################.#.#.###############",
    "#...........#.###...#...#.#.#...#.....#.#.#...#.#.#.#.#.#.#...#...#.#...#.#.#...#.#.#...#.#.#.#.#...#.#...#.........#...#.#.#...........#...#",
    "###########.#.###.#.#####.#.#.###.###.#.#.#.#.#.#.#.#.#.#.#.#######.#.###.#.#####.#.###.#.#.#.#.#.###.#.#.#.#######.#.#.#.#.###########.#.#.#",
    "#...........#.....#.......#.#...#...#.#.#.#.#.#.#...#.#.#.#.....#...#.###...#.....#.###.#.#...#.#.#...#.#.#.......#...#...#.......#.....#.#.#",
    "#.#########################.###.###.#.#.#.#.#.#.#####.#.#.#####.#.###.#######.#####.###.#.#####.#.#.###.#.#######.###############.#.#####.#.#",
    "#.....#.......#.....#.....#.#...#...#.#.#...#.#.#.....#.#.....#.#...#.......#.#...#...#...###...#.#.#...#.......#.......#.......#...#...#.#.#",
    "#####.#.#####.#.###.#.###.#.#.###.###.#.#####.#.#.#####.#####.#.###.#######.#.#.#.###.#######.###.#.#.#########.#######.#.#####.#####.#.#.#.#",
    "###...#.#.....#.###.#...#.#.#...#.#...#...#...#.#.....#.....#.#...#...#...#.#...#...#.#.......#...#.#.......#...#.....#...#...#.#...#.#...#.#",
    "###.###.#.#####.###.###.#.#.###.#.#.#####.#.###.#####.#####.#.###.###.#.#.#.#######.#.#.#######.###.#######.#.###.###.#####.#.#.#.#.#.#####.#",
    "#...#...#.#...#.#...#...#.#.###.#.#...#...#.#...#.....#...#.#.#...#...#.#...###...#.#.#.#.....#.###...#.....#...#.###.......#...#.#...#...#.#",
    "#.###.###.#.#.#.#.###.###.#.###.#.###.#.###.#.###.#####.#.#.#.#.###.###.#######.#.#.#.#.#.###.#.#####.#.#######.#.###############.#####.#.#.#",
    "#...#...#...#...#...#.###.#.#...#.###.#.###...#...#...#.#...#.#...#...#.........#.#...#...#...#...#...#.......#.#.......#.......#.#...#.#.#.#",
    "###.###.###########.#.###.#.#.###.###.#.#######.###.#.#.#####.###.###.###########.#########.#####.#.#########.#.#######.#.#####.#.#.#.#.#.#.#",
    "###...#.#...........#.#...#.#.....#...#.....###...#.#.#.....#.#...#...#.....#.....#.....#...#.....#.#...#...#.#.......#...#.....#.#.#...#...#",
    "#####.#.#.###########.#.###.#######.#######.#####.#.#.#####.#.#.###.###.###.#.#####.###.#.###.#####.#.#.#.#.#.#######.#####.#####.#.#########",
    "#####...#...#...#...#.#.#...#.....#.....#...#...#.#.#.#...#.#.#...#...#.###.#.....#.#...#...#.....#.#.#.#.#...###.....#...#.#...#.#.....#...#",
    "###########.#.#.#.#.#.#.#.###.###.#####.#.###.#.#.#.#.#.#.#.#.###.###.#.###.#####.#.#.#####.#####.#.#.#.#.#######.#####.#.#.#.#.#.#####.#.#.#",
    "###...#.....#.#.#.#.#.#.#...#...#.......#...#.#...#.#.#.#.#.#.#...###.#...#.#...#...#.#...#.#...#.#.#.#.#.......#.....#.#...#.#.#.#.....#.#.#",
    "###.#.#.#####.#.#.#.#.#.###.###.###########.#.#####.#.#.#.#.#.#.#####.###.#.#.#.#####.#.#.#.#.#.#.#.#.#.#######.#####.#.#####.#.#.#.#####.#.#",
    "#...#...#.....#...#.#.#.....#...#.......#...#.....#.#.#.#.#.#.#.....#.....#.#.#.....#.#.#...#.#...#.#.#...#...#...###.#.......#...#.....#.#.#",
    "#.#######.#########.#.#######.###.#####.#.#######.#.#.#.#.#.#.#####.#######.#.#####.#.#.#####.#####.#.###.#.#.###.###.#################.#.#.#",
    "#.........#.........#.###...#...#.#.....#.#...#...#.#.#.#.#.#.#...#...#.....#.....#.#.#.....#.....#.#.###.#.#.#...#...#...#.....#.......#.#.#",
    "###########.#########.###.#.###.#.#.#####.#.#.#.###.#.#.#.#.#.#.#.###.#.#########.#.#.#####.#####.#.#.###.#.#.#.###.###.#.#.###.#.#######.#.#",
    "#...........#.....#...#...#.....#.#.....#...#.#.#...#.#.#.#.#.#.#.....#.#.....#...#...###...#...#.#.#...#...#.#...#.#...#.#...#.#.........#.#",
    "#.###########.###.#.###.#########.#####.#####.#.#.###.#.#.#.#.#.#######.#.###.#.#########.###.#.#.#.###.#####.###.#.#.###.###.#.###########.#",
    "#.#.......#...#...#.###.....#...#...#...#.....#...###...#.#.#.#.#.......#.#...#.......#...#...#.#.#.#...#.....#...#...###...#.#.#...#...#...#",
    "#.#.#####.#.###.###.#######.#.#.###.#.###.###############.#.#.#.#.#######.#.#########.#.###.###.#.#.#.###.#####.###########.#.#.#.#.#.#.#.###",
    "#...#.....#...#...#.#.......#.#.....#...#...............#.#.#...#.#.....#.#.#...#...#.#.....#...#.#.#...#.....#...........#.#.#.#.#...#.#...#",
    "#####.#######.###.#.#.#######.#########.###############.#.#.#####.#.###.#.#.#.#.#.#.#.#######.###.#.###.#####.###########.#.#.#.#.#####.###.#",
    "###...#...#...###.#.#.....#...#.....###...#.......#.....#.#...#...#.#...#.#.#.#.#.#.#.......#.....#.#...#.....#...#.......#.#.#.#.....#.#...#",
    "###.###.#.#.#####.#.#####.#.###.###.#####.#.#####.#.#####.###.#.###.#.###.#.#.#.#.#.#######.#######.#.###.#####.#.#.#######.#.#.#####.#.#.###",
    "#...#...#.#...#...#.#.....#...#...#.#.....#.....#.#.###...#...#...#.#...#.#...#...#.#.....#.....#...#...#...#...#.#.......#.#.#.#...#.#.#...#",
    "#.###.###.###.#.###.#.#######.###.#.#.#########.#.#.###.###.#####.#.###.#.#########.#.###.#####.#.#####.###.#.###.#######.#.#.#.#.#.#.#.###.#",
    "#.#...#...#...#...#.#.#...#...#...#...#...#...#.#.#...#...#...#...#.#...#.....#.....#...#...#...#...#...#...#.#...#...#...#.#.#.#.#.#.#.#...#",
    "#.#.###.###.#####.#.#.#.#.#.###.#######.#.#.#.#.#.###.###.###.#.###.#.#######.#.#######.###.#.#####.#.###.###.#.###.#.#.###.#.#.#.#.#.#.#.###",
    "#...###.....#####...#...#...###.........#...#...#.....###.....#.....#.........#.........###...#####...###.....#.....#...###...#...#...#...###",
    "#############################################################################################################################################",
};

using MapScores = std::vector<std::vector<std::pair<uint64_t, int>>>; // score, max_steps
using AllScores = std::vector<MapScores>;

void draw_map(const Map& map)
{
    for (const auto& row: map)
        std::cout << row << "\n";
    std::cout << std::endl;
}

constexpr uint64_t invalid_score = std::numeric_limits<uint64_t>::max();
constexpr uint64_t unknown_score = invalid_score - 1;

std::pair<uint64_t, int> try_move(const Map& map, AllScores& all_scores, int x, int y, int dir, int nx, int ny, int max_steps, bool find_best, bool try_backwards=false)
{
    if (max_steps <= 0) return std::make_pair(invalid_score, 0);
    if (x < 0 || x >= nx || y < 0 || y >= ny) return std::make_pair(invalid_score, 0);

    auto& score = all_scores[dir][y][x];
    if (score.first != unknown_score)
    {
        if (score.first == invalid_score)
        {
            if (max_steps <= score.second) return std::make_pair(invalid_score, score.second);
        }
        else
        {
            if (!find_best) return score;
            if (max_steps < score.second) return std::make_pair(invalid_score, max_steps);
            if (max_steps == score.second) return score;
        }
    }

    auto [dx, dy] = dxdy[dir];

    std::pair<uint64_t, int> min_score{score.first != unknown_score ? score.first : invalid_score, max_steps};

    auto score_new = try_move(map, all_scores, x + dx, y + dy, dir, nx, ny, max_steps - 1, find_best);
    if (score_new.first != invalid_score)
    {
        min_score.first = score_new.first + 1;
        min_score.second = score_new.second + 1;
        if (!find_best)
        {
            score = min_score;
            return min_score;
        }
    }

    int dir1 = dir == 3 ? 0 : dir + 1;
    score_new = try_move(map, all_scores, x - dy, y + dx, dir1, nx, ny, max_steps - 1, find_best);
    if (score_new.first != invalid_score)
    {
        score_new.first++;
        if (score_new.first < min_score.first)
        {
            min_score.first = score_new.first;
            min_score.second = score_new.second + 1;
            if (!find_best)
            {
                score = min_score;
                return min_score;
            }
        }
    }

    int dir2 = dir == 0 ? 3 : dir - 1;
    score_new = try_move(map, all_scores, x + dy, y - dx, dir2, nx, ny, max_steps - 1, find_best);
    if (score_new.first != invalid_score)
    {
        score_new.first++;
        if (score_new.first < min_score.first)
        {
            min_score.first = score_new.first;
            min_score.second = score_new.second + 1;
            if (!find_best)
            {
                score = min_score;
                return min_score;
            }
        }
    }

    if (try_backwards)
    {
        int dir3 = dir + 2;
        if (dir3 > 3) dir3 -= 4;
        score_new = try_move(map, all_scores, x - dx, y - dy, dir3, nx, ny, max_steps - 1, find_best);
        if (score_new.first != invalid_score)
        {
            score_new.first++;
            if (score_new.first < min_score.first)
            {
                min_score.first = score_new.first;
                min_score.second = score_new.second + 1;
                if (!find_best)
                {
                    score = min_score;
                    return min_score;
                }
            }
        }
    }

    score = min_score;
    return min_score;
}

void init_all_scores(const Map& map, AllScores& all_scores)
{
    int nx = map.front().size();
    int ny = map.size();

    all_scores.clear();
    all_scores.reserve(4);
    for (int k = 0; k < 4; k++)
    {
        auto& map_scores = all_scores.emplace_back();

        map_scores.reserve(ny);
        for (int y=0; y < ny; y++)
        {
            auto& row = map_scores.emplace_back();
            row.reserve(nx);
            for (int x=0; x < nx; x++)
            {
                map[y][x] == '#' ?
                    row.emplace_back(std::make_pair(invalid_score, std::numeric_limits<int>::max())) :
                    row.emplace_back(std::make_pair(unknown_score, std::numeric_limits<int>::max()));
            }
        }
    }
}

uint64_t part1(Map& map, bool find_best, int n_save)
{
    int nx = map.front().size();
    int ny = map.size();

    int max_steps = 2;
    for (const auto& row: map)
        for (auto c: row)
            if (c == '.') max_steps++;

    // find the start and end positions
    int x_start, y_start;
    int x_end, y_end;
    for (int y = 0; y < ny; y++)
    {
        for (int x = 0; x < nx; x++)
        {
            if (map[y][x] == 'S')
            {
                x_start = x;
                y_start = y;
            }
            else if (map[y][x] == 'E')
            {
                x_end = x;
                y_end = y;
            }
        }
    }
    // std::cout << "Initial\n";
    // draw_map(map);

    AllScores all_scores;
    init_all_scores(map, all_scores);

    for (auto& scores: all_scores)
    {
        scores[y_end][x_end].first = 0;
        scores[y_end][x_end].second = 0;
    }

    auto score_orig = try_move(map, all_scores, x_start, y_start, 0, nx, ny, max_steps, find_best, true).first;
    std::cout << score_orig << "\n";

    int n_cheats{0};

    int y{-1};
    for (auto& row: map)
    {
        y++;

        int x{-1};
        for (auto& c: row)
        {
            x++;

            if (c != '#') continue;

            if ((x - 1 >= 0 && row[x - 1] != '#' && x + 1 < nx && row[x + 1] != '#') ||
                (y - 1 >= 0 && map[y - 1][x] != '#' && y + 1 < ny && map[y + 1][x] != '#'))
            {
                auto c_old = c;
                c = '.';

                init_all_scores(map, all_scores);

                for (auto& scores: all_scores)
                {
                    scores[y_end][x_end].first = 0;
                    scores[y_end][x_end].second = 0;
                }

                auto ret = try_move(map, all_scores, x_start, y_start, 0, nx, ny, max_steps, find_best, true);
                if (ret.first != invalid_score && ret.first + n_save <= score_orig)
                {
                    // draw_map(map);
                    std::cout << "found at " << x << ", " << y << " = " << ret.first << "\n";
                    n_cheats++;
                }

                c = c_old;
            }
        }
    }

    return n_cheats;
}

void find_spots(Spots& spots, const AllScores& all_scores, int x, int y, int dir, int nx, int ny, bool just_one)
{
    auto score = all_scores[dir][y][x].first;

    spots.emplace(x + y * nx);

    for (int k=0; k < 4; k++)
    {
        auto [dx, dy] = dxdy[dir];
        int x2{x + dx};
        int y2{y + dy};
        if (x2 >= 0 && x2 < nx && y2 >= 0 && y2 < ny)
        {
            auto& score2 = all_scores[dir][y2][x2];
            if (score2.first != invalid_score && score2.first + 1 == score)
            {
                find_spots(spots, all_scores, x2, y2, dir, nx, ny, just_one);
                if (just_one) break;
            }
        }

        dir = dir == 3 ? 0 : dir + 1;
    }
}

int main()
{
    std::cout << part1(sample_map, true, 12) << std::endl;
    std::cout << part1(map, true, 100) << std::endl;

    return 0;
}