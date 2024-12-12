
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>

using Map = std::vector<std::string>;

Map sample_map{
    "AAAA",
    "BBCD",
    "BBCC",
    "EEEC",
};

std::pair<uint32_t, uint32_t> eval_plot(Map& map, int row, int col, int nrow, int ncol)
{
    uint32_t area{1}, perim{0};
    char c = map[row][col];
    map[row][col] = '.';
    std::cout << c << ":" << row << ", " << col << std::endl;
    if (row > 0 && row < nrow && map[row-1][col] == c)
    {
        auto ret = eval_plot(map, row - 1, col, nrow, ncol);
        area += ret.first;
        perim += ret.second;
    }
    else
        perim++;
    if (row >= 0 && row + 1 < nrow && map[row+1][col] == c)
    {
        auto ret = eval_plot(map, row + 1, col, nrow, ncol);
        area += ret.first;
        perim += ret.second;
    }
    else
        perim++;
    if (col > 0 && col < ncol && map[row][col-1] == c)
    {
        auto ret = eval_plot(map, row, col - 1, nrow, ncol);
        area += ret.first;
        perim += ret.second;
    }
    else
        perim++;
    if (col >= 0 && col + 1 < ncol && map[row][col+1] == c)
    {
        auto ret = eval_plot(map, row, col + 1, nrow, ncol);
        area += ret.first;
        perim += ret.second;
    }
    else
        perim++;
    return std::make_pair(area, perim);
}

uint32_t part1(Map& map)
{
    int nrow = map.size();
    int ncol = map[0].size();
    uint32_t ret{0};

    int row{0};
    for (auto& map_row: map)
    {
        int col{0};
        for (auto c: map_row)
        {
            if (c != '.')
            {
                auto foo = eval_plot(map, row, col, nrow, ncol);
                std::cout << foo.first << ", " << foo.second << std::endl;
                ret += foo.first * foo.second;
            }
            col++;
        }
        row++;
    }
    return ret;
}

int main()
{
    std::cout << part1(sample_map) << std::endl;
    return 0;
}
