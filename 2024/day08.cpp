
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using Spot = int32_t;
using RawMap = std::vector<std::string>;
using Antennas = std::unordered_map<char, std::vector<Spot>>;
using Spots = std::unordered_set<Spot>;

RawMap sample_raw_map{
    "............",
    "........0...",
    ".....0......",
    ".......0....",
    "....0.......",
    "......A.....",
    "............",
    "............",
    "........A...",
    ".........A..",
    "............",
    "............",
};

RawMap raw_map{
    "...............................s..................",
    "..................s..............q.............p..",
    ".....a............................................",
    "........c......Y.......Q..........................",
    "............................................4.....",
    "........Y.........y............m..........4.......",
    "......................Y...s..........S............",
    ".........................................S........",
    "...............N.............y....................",
    "...........a.......y..................1...........",
    "................................................S.",
    "...c........k.............q....t............S.....",
    ".............................qM...................",
    "........a.........................................",
    "..................................................",
    "..................................................",
    "..c..........k...Q..q....P........................",
    "5.................Q...................8...........",
    "......yc..........................................",
    "........................E............4............",
    ".........6........................u..p.....4......",
    ".........5.............P..n......1.........N......",
    "6..............................1.........J.t......",
    "..6..................................3.u..t.....p.",
    "....5...k..........................u..............",
    ".......................E..................u....x..",
    "..................E.................x.............",
    "...k..................P.............3.............",
    "...........0.....9.5...........E.........31e....N.",
    "......0.................................N.........",
    ".................CU.....................t....x....",
    "......7....................e......................",
    "....0..........K......C...........................",
    ".....6....j......M............................J...",
    "......K.................................p.........",
    ".....9........................U...................",
    "............................3....n................",
    ".............K.........2.....C..................x.",
    "....................P........UJ...................",
    ".....0......X...C.........T..............U........",
    ".......M.....8j....7.............2........Q.......",
    "9...............K.................................",
    "....e.....8.........................2.A.m.........",
    "..e......8.........s...n..........................",
    ".....................................T..nm........",
    "...................X............2.........m......A",
    "......................X..j....................T...",
    ".........7..M......j.............T................",
    "....9...7....................................A....",
    "..........................................A.......",
};

void find_antennas(const RawMap& map, Antennas& antennas)
{
    int32_t row = 0;
    for (const auto& row_str: map)
    {
        int32_t col = 0;
        for (char c: row_str)
        {
            if (c != '.')
            {
                auto& spots = antennas[c];
                spots.emplace_back((row << 16) | col);
            }
            col++;
        }
        row++;
    }
}

void find_spots(int16_t nrows, int16_t ncols, const Antennas& antennas, Spots& spots)
{
    for (const auto& antenna: antennas)
    {
        for (auto spot1 = antenna.second.begin(); spot1 != antenna.second.end(); spot1++)
        {
            int32_t row1 = *spot1 >> 16;
            int32_t col1 = *spot1 & 0xffff;

            for (auto spot2 = spot1 + 1; spot2 != antenna.second.end(); spot2++)
            {
                int32_t row, col;

                int32_t row2 = *spot2 >> 16;
                int32_t col2 = *spot2 & 0xffff;

                row = 2 * row1 - row2;
                col = 2 * col1 - col2;
                if (row >= 0 && row < nrows && col >= 0 && col < ncols)
                    spots.insert((row << 16) | col);

                row = 2 * row2 - row1;
                col = 2 * col2 - col1;
                if (row >= 0 && row < nrows && col >= 0 && col < ncols)
                    spots.insert((row << 16) | col);
            }
        }
    }
}

void find_spots_part2(int16_t nrows, int16_t ncols, const Antennas& antennas, Spots& spots)
{
    for (const auto& antenna: antennas)
    {
        if (antenna.second.size() < 2) continue;

        for (auto spot1 = antenna.second.begin(); spot1 != antenna.second.end(); spot1++)
        {
            spots.insert(*spot1);

            int32_t row1 = *spot1 >> 16;
            int32_t col1 = *spot1 & 0xffff;

            for (auto spot2 = spot1 + 1; spot2 != antenna.second.end(); spot2++)
            {
                int32_t row2 = *spot2 >> 16;
                int32_t col2 = *spot2 & 0xffff;

                int32_t drow = row1 - row2;
                int32_t dcol = col1 - col2;

                int32_t row, col;

                row = row1 + drow;
                col = col1 + dcol;
                while (row >= 0 && row < nrows && col >= 0 && col < ncols)
                {
                    spots.insert((row << 16) | col);
                    row += drow;
                    col += dcol;
                }

                row = row2 - drow;
                col = col2 - dcol;
                while (row >= 0 && row < nrows && col >= 0 && col < ncols)
                {
                    spots.insert((row << 16) | col);
                    row -= drow;
                    col -= dcol;
                }
            }
        }
    }
}

int part1(const RawMap& map)
{
    Antennas antennas;
    Spots spots;
    find_antennas(map, antennas);
    find_spots(map.size(), map[0].size(), antennas, spots);
    return spots.size();
}

int part2(const RawMap& map)
{
    Antennas antennas;
    Spots spots;
    find_antennas(map, antennas);
    find_spots_part2(map.size(), map[0].size(), antennas, spots);
    return spots.size();
}

int main()
{
    std::cout << part1(sample_raw_map) << std::endl;
    std::cout << part1(raw_map) << std::endl;
    std::cout << part2(sample_raw_map) << std::endl;
    std::cout << part2(raw_map) << std::endl;
    return 0;
}
