
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

using WarehouseMap = std::vector<std::string>;

WarehouseMap sample_warehouse_map{
    "##########",
    "#..O..O.O#",
    "#......O.#",
    "#.OO..O.O#",
    "#..O@..O.#",
    "#O#..O...#",
    "#O..O..O.#",
    "#.OO.O.OO#",
    "#....O...#",
    "##########",
};

WarehouseMap sample_warehouse_map2{
    "####################",
    "##....[]....[]..[]##",
    "##............[]..##",
    "##..[][]....[]..[]##",
    "##....[]@.....[]..##",
    "##[]##....[]......##",
    "##[]....[]....[]..##",
    "##..[][]..[]..[][]##",
    "##........[]......##",
    "####################",
};

std::string sample_moves{
    "<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^"
    "vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v"
    "><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<"
    "<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^"
    "^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><"
    "^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^"
    ">^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^"
    "<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>"
    "^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>"
    "v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^"
};

WarehouseMap warehouse_map{
    "##################################################",
    "#O..O...OO...O...#...O.#OO#O....O.....O.........##",
    "#.#.O...O.O.#.....OO..O..O...O...OO..OO.....O...O#",
    "#.OOO..#.OOO...OOOO.#OO.OOOO...#......OO..O...OO.#",
    "#.O..#..O.....#O...O........#O.#O...#O..OO.#....O#",
    "#.....#........OO.#......#...O.O.....O#....O..#.##",
    "##..#..#........O....O...OO.O.O..OO..#..#.#..#...#",
    "#.OO.O.#.O.O.#..O....OO..O.....O........OOO.....O#",
    "#..O#..#..........OOO......OO.#......#.O.O.#OOOO.#",
    "#...O.O.......O...#.O.##O...O.....O.OO.....O..O.O#",
    "#..O......O#.....OO.O......OO#.OO#OOO..O...O.O..O#",
    "#......O..#....O....O.......O.O.O.OOO.O.#.O.OO...#",
    "#O#.O..#.....#O.O..O.O....#O...##O.OO.O.....O.O..#",
    "#.......OOO....#O..OO.OO......O...O..#...O.......#",
    "#O...O.........O..O..OOOO..O...OO.OO.O...O.......#",
    "#O.#O.OO.O..O....O.OO....O.....OO.O..O..O....O...#",
    "#.O..#.O...O......OOO.##O...O.O...O#O.O#.#..OO...#",
    "#...O......#..OO.O.OO....#.O..O.......O.#.#...OO.#",
    "#O.O#....#..O.......OOO...O#..#....#.#.O.#O.OO...#",
    "#..O....O.O.O.....O.OO.OOO..OO##OO...OOO..O...#.O#",
    "#......O....O.O.O.O......O.O...O..O....OO...OO.OO#",
    "#.O.#.O...#.O.O...O...O......O......OO..O...OO...#",
    "#O..O.......O..O..O...OOO#.O..O....OO......O..O.O#",
    "#.O...#.#..OO..#OO.......O.#...#.O..O.#...#...O..#",
    "##...O.#O#..O...O..#....@#.O....##.OO............#",
    "#O..O.....O.O##.O.O.#OOO.....O...O..O....OOO..##O#",
    "#....#.O......#..OOO.......#...#..O..O........O###",
    "#O#OO.....O##O..........O.O.O.OO.O..........O..OO#",
    "#OO..O#...O....O.....O....OO.OO....O..#OO.O..#.O.#",
    "#..........OO#OO..O#...O..O..OO.OO.O.#..O......#O#",
    "#.OOO...O....#...O..OO.......#..O.O.....OOO#..OOO#",
    "#..OO.OO......OO............O...#.O......O.###.#.#",
    "#O...........O...OOO..OO.#O..O#.#......OO.OO.O...#",
    "#O.......#.....O..#..O..O..OO#...O............#.O#",
    "#......#.......O..OO#...O.O..O.O#..#.O.OO.O.OO...#",
    "#OOO...O..O.O.O.O...OO.....#....#.......O......#O#",
    "#O....OO..#OOO..#..O....OO#OO.O...#..O.OO..OOO#..#",
    "##..O.O.O.OO..#OO....O....#..O.OO.....O....#.....#",
    "#....OO.....O..............O#....#.OO.#..O.OO.O..#",
    "#.OO..O.......O.....O.OO.O..#O.....O...#.O#..O.#.#",
    "#.....O...O.#..#.....#...O..O.OO..O.#OO.#.O.O..O.#",
    "#O.....OOO..O...##..OOO.#...O.....#.....O..#.O.O.#",
    "#....O.....O.#.OOO.O...........O..#....O..O.O..#.#",
    "#..O.#O.O.#O......OOO..OOO....#.O..#.....O...O...#",
    "#....OOO......#.............#O.O.....OO..O..#....#",
    "#O.O...O...........#....#.OO.##..#O...O#O....OO..#",
    "#..........O...#.......#..O..O.O#O....#..........#",
    "#..OO#.....#.O....O...O...##...O...O#O##...#.....#",
    "#....#.O......O.....O.#.OO.O..........#....O.OO.O#",
    "##################################################",
};

WarehouseMap warehouse_map2{
    "####################################################################################################",
    "##[]....[]......[][]......[]......##......[]..##[][]##[]........[]..........[]..................####",
    "##..##..[]......[]..[]..##..........[][]....[]....[]......[]......[][]....[][]..........[]......[]##",
    "##..[][][]....##..[][][]......[][][][]..##[][]..[][][][]......##............[][]....[]......[][]..##",
    "##..[]....##....[]..........##[]......[]................##[]..##[]......##[]....[][]..##........[]##",
    "##..........##................[][]..##............##......[]..[]..........[]##........[]....##..####",
    "####....##....##................[]........[]......[][]..[]..[]....[][]....##....##..##....##......##",
    "##..[][]..[]..##..[]..[]..##....[]........[][]....[]..........[]................[][][]..........[]##",
    "##....[]##....##....................[][][]............[][]..##............##..[]..[]..##[][][][]..##",
    "##......[]..[]..............[]......##..[]..####[]......[]..........[]..[][]..........[]....[]..[]##",
    "##....[]............[]##..........[][]..[]............[][]##..[][]##[][][]....[]......[]..[]....[]##",
    "##............[]....##........[]........[]..............[]..[]..[]..[][][]..[]..##..[]..[][]......##",
    "##[]##..[]....##..........##[]..[]....[]..[]........##[]......####[]..[][]..[]..........[]..[]....##",
    "##..............[][][]........##[]....[][]..[][]............[]......[]....##......[]..............##",
    "##[]......[]..................[]....[]....[][][][]....[]......[][]..[][]..[]......[]..............##",
    "##[]..##[]..[][]..[]....[]........[]..[][]........[]..........[][]..[]....[]....[]........[]......##",
    "##..[]....##..[]......[]............[][][]..####[]......[]..[]......[]##[]..[]##..##....[][]......##",
    "##......[]............##....[][]..[]..[][]........##..[]....[]..............[]..##..##......[][]..##",
    "##[]..[]##........##....[]..............[][][]......[]##....##........##..##..[]..##[]..[][]......##",
    "##....[]........[]..[]..[]..........[]..[][]..[][][]....[][]####[][]......[][][]....[]......##..[]##",
    "##............[]........[]..[]..[]..[]............[]..[]......[]....[]........[][]......[][]..[][]##",
    "##..[]..##..[]......##..[]..[]......[]......[]............[]............[][]....[]......[][]......##",
    "##[]....[]..............[]....[]....[]......[][][]##..[]....[]........[][]............[]....[]..[]##",
    "##..[]......##..##....[][]....##[][]..............[]..##......##..[]....[]..##......##......[]....##",
    "####......[]..##[]##....[]......[]....##........@.##..[]........####..[][]........................##",
    "##[]....[]..........[]..[]####..[]..[]..##[][][]..........[]......[]....[]........[][][]....####[]##",
    "##........##..[]............##....[][][]..............##......##....[]....[]................[]######",
    "##[]##[][]..........[]####[]....................[]..[]..[]..[][]..[]....................[]....[][]##",
    "##[][]....[]##......[]........[]..........[]........[][]..[][]........[]....##[][]..[]....##..[]..##",
    "##....................[][]##[][]....[]##......[]....[]....[][]..[][]..[]..##....[]............##[]##",
    "##..[][][]......[]........##......[]....[][]..............##....[]..[]..........[][][]##....[][][]##",
    "##....[][]..[][]............[][]........................[]......##..[]............[]..######..##..##",
    "##[]......................[]......[][][]....[][]..##[]....[]##..##............[][]..[][]..[]......##",
    "##[]..............##..........[]....##....[]....[]....[][]##......[]........................##..[]##",
    "##............##..............[]....[][]##......[]..[]....[]..[]##....##..[]..[][]..[]..[][]......##",
    "##[][][]......[]....[]..[]..[]..[]......[][]..........##........##..............[]............##[]##",
    "##[]........[][]....##[][][]....##....[]........[][]##[][]..[]......##....[]..[][]....[][][]##....##",
    "####....[]..[]..[]..[][]....##[][]........[]........##....[]..[][]..........[]........##..........##",
    "##........[][]..........[]............................[]##........##..[][]..##....[]..[][]..[]....##",
    "##..[][]....[]..............[]..........[]..[][]..[]....##[]..........[]......##..[]##....[]..##..##",
    "##..........[]......[]..##....##..........##......[]....[]..[][]....[]..##[][]..##..[]..[]....[]..##",
    "##[]..........[][][]....[]......####....[][][]..##......[]..........##..........[]....##..[]..[]..##",
    "##........[]..........[]..##..[][][]..[]......................[]....##........[]....[]..[]....##..##",
    "##....[]..##[]..[]..##[]............[][][]....[][][]........##..[]....##..........[]......[]......##",
    "##........[][][]............##..........................##[]..[]..........[][]....[]....##........##",
    "##[]..[]......[]......................##........##..[][]..####....##[]......[]##[]........[][]....##",
    "##....................[]......##..............##....[]....[]..[]##[]........##....................##",
    "##....[][]##..........##..[]........[]......[]......####......[]......[]##[]####......##..........##",
    "##........##..[]............[]..........[]..##..[][]..[]....................##........[]..[][]..[]##",
    "####################################################################################################",
};

std::string moves{
    "v><v><v<<v^^><^<<<^<v<^>^<^^^>^<><<>><v<vv><<vvv><>^v<^<<>>^<><><>^><><^<vvv^>v^^^<v>>^<<>^<vv>><v^v<<^<<<^v<<>^v>>^>v>^^^v<<^v>><v^<>^><^^v^><v^v>^^^>v><^v<<>^><^><v<<<>v<>^vvvv<>>><<^^<<>>v><^>><v>v>^>vv^>>^>^>v^vv^<<^^v><>v<v<v>^<<<^>^^<v^v<<><v<<<^<v^>vv<v<>v>v><vv^<^><v^<><v><v^<<^v><^v<v^<><vv<vv^<^><>^<^>v<<vvv>^v<^<vvv^<<<^v^v>^vv><vv<<v^v^<<>^^^<<>^v><v><^>vv^vv^v^vv^^>>^v>v>v><>v<vvv^>>^^<<^<<<^>>v>>^^<^>v^>^<>v>v>v^v<>^v>^^>v^>vv><<^v<>^vvv<^^^>>^v^^>v<<v<vv^v^<^>vv>>^v<^>><<><vv<v><v<v>^>v><<^vv<<>v>><>^<vv>v<>>>v<^<>><v^<<^<v^^>vv>^>^<vvv>^><<^v>>^>><<^<<<^<<v<v<<>v^vvv<>v<>vvv><>><^><v<<<>>>^<<v<<<vv<^><>v^>v^^<^v<vv<<vv^^>v<<<vvv>v>>vvvvvv<<>v><>>>vv^v^>v<<<vv>^>^<<v>v<>v^v>>^v^^v<<<<><^vv>v<<vvv^<v<vv<<v<>^><v>><^<>^^>>v<v<<<v><<^^<>>v<<^>^v<>>v>>v><>^^<v><v^^^^<>^vvv<<<>vv><>>v^v>>v<^<v^^>^v^v^<>v<><^^vv<^v>>><vv<<^<><^v<><^<^><v^><^vv<>^^<v<^^^^vv><>^<^>vv<v><<v^^^v<<><^<^<>^v<v^<^^<>v>^<^^^v<<v^^<^^^<<>v<vv^v><<^^>>^^^^v^>>><v<^v^<<<^><>v>^>vv^v<>>^<^v><^v>^v^^>>v><<"
    "v>v>^<><^v<v^<^^v<>v^vv^v>vv^^^^<^^>^vv>>^^<^<><^^>^<>^^>v>^v>>^v>^v><><>^<<^v^>v<^^v>v^vvv>^v<v<><v>>^^<>><^vvvvv^<v>v^v<<v>^<<>v^<<^v^vv<>^v<^>vv^v>^>^^>^<<<<<v<>>^<v><^>^>v^>>^>^^^^<<^<v<v^<<>>>vv<<vvv><^>v^^vv>>^><>>>^><^<<><^vvvvv<^^<>v<>v^^^<^^><^<v<>^^v<>v><^<<<^^<^^^^^v<^<><><vv^<^><^>v<^<>><>><><v<v^<vvv<<<<^v^v<^v>v^>v<>v<^><v^v^>v^<v^><<v<^v>><>>^><>>vv<v<<^<<vv<<^vv>>><vvv><vv^^^<<^<^vv<<><v<^v<^>>v<^v<v^<<>vv^v<^^^v><>><<^^vvvv>^v<v>v^>^^^>^^^>><><^^v><v><v<v^^^>>v<^^v>><^vv<^^v>>^<>v>^^v><<>v^>>v<v<v<vv<>>^>^<v>^><<<<>^<v>^^v^^<><v<^>^<v<><^<<>^><><^vvvv>>><v^<vv><v><<<v<<<v^vv^vv<<^v><v^<<v><><>v<>v^<v^v^v>v<v^><^<v><><^>v>vvv>v^v>vvvvvvvv<^v>v<^^vv<v>>^<>vv>vv>v^>vv>><^<^<v>v<>vvv<^>>>^>>^v>>>>>^<v>>>><<><>v^v^vv>>^>v^>v><<>^v^v^>>^^<>v^v>v<>^^^v<v^>v<^<^vv^^^v^><<vv><<^><^<<>v^<v<><v^<vv^>v>^^<^>><><^<^<^>^v<^v><>>vvv>v^>^^>^<<<v^<^>>v<^^<>>><v<>v>^v<^vv<vv^>>v<^<^vvv<^<^>>v^>>^>vv^v^vvv^v><vv^^^<><^<v>v^^>>^v>v^^v>^<>><v<>^>^^v>v^v<>>><^<<^>>^><v<>^vv>^v>><<<v>v^<><<v"
    ">>>^vv^>^>^<^><^>^v^^^<^vv><v^<v^>>><<<^v>^<v^<^^v<v^v<vvv<>>vv>v^vvv>>v^>^^<<>>v><<v^><v<>v^>^^>v><><<vvvv^v<v<>v>v><<^<^v<>^^<v<v>^v>^^^>vvv<<^><^v>>^^^>^<>>vv^^^v>>v<v><<^<>>v^^v^<>^^><v<<<>>^>vv<>v^>v^^<^>vvv>>>^^>^v>vv>v>><^^v>v<^<v<v>^^v>v>>>>vvv<v^>^^<vv><<>^<^^<^^vvvv>^v<^>^v^>>^<^<vvv>^>^v>^^>>><vv^>>^^^>vv^^^><<^<>>vv^v><v^^v><>>>v<^^>^^<^^<<^<><>v>^<><>^<<^<<^>^><^^^v<>>^v<<v^>^^>>v^v^>v>v<<v^>^>>vv<v^^v^>^>vv>^v><v<vv><<v<>^>>>v>>vv^v<>>>v<>^<v>>^v>^<^>^<<<<v>v>><v^>>><><>>^v>^^^<vv^>v>^<<^>vv^><><<>><>v<>v>^<^^<v><><^>><v<<v^^^v>vvv^>^><v>v<>v><^^^vv><<v^<<^<v>>^>><<v<<<v>>^<^v^vvv<>>><v^vvvv<<<>^><^>>^<<><<^><^>><^^>^<><v^>^v>v^v<<<^<<<<>^><^<<<>v<^>>>vvv<>^^v<<>^v^>^<v<>v<>^>v<^v<<<v^>>>v^v^^<>>>>^v<><v>>v^^<>vv^vv^v>^v^v>><>v^^>^>>v<^<>^v><<>>^><v^^>^v>>v<<^^>>^v<^<v^<<^^<vv^><v<^v<^><>^^v<^^<vvv<^^^>^v>v^>^^<v<v<vv^<^^^>^>>^<^>^^>^vv>^<>>v^>v>^<^>v><<><>>^^^^v^^>v>^v>><>>^^^vv<^<v<v<<v<<v^<>>^^v>>>>>v^^>v<>v>^^<>^^^v^^><<>^^^>>^>>v>v>>v<^<^>^^^><v>v<<^<<^^v^^>>>^>^v^><"
    "vv<<>>vv^vv><v><v<v<v<>^v>^>v<<v^><>^<><^<^^><^vv^^vv^>^<v^<v>v^v<^>v><>>v<^^^>vv>v^>vvvv^<^v^v^v><^<>>^^^>^>v<<vvv<>v>vv^>^>^v^<v<^^^><>v<>v>v<vv^>^^^^v^v^<><v<^<^><^<><^>^<<<<<>>><>^^^v>vv^<><v>^^<v><<<<^>>>v^v>^^^v^><v><v<vv^v<>>^<^^<>^<^<vvv>^v<^>v>>^>>v>v^><<^>v><^>^^^v>^^v^^^vv^^v<<<<<<^<>^<^>^^>>>>^<^>^>v<<vv<<><>><<v<>v>v^<>>v<^><<<vvv>v>v^>v^v<^v>^<>v<^v^vv<^vv^<<^<v<v>^^><<>v>^v>^<v<>>^<^>v><^^^<^v>v^>v^^>v><v<^>v^v^^^^>vvv><v>^>>^>^<vvv<vv>v^>^^v>v^>^>^<^^^<^v><^vv<<>><>^v>^^<^>vvv^<vv<<v<>>v^^>>v>^vv>^v>^^^<<<v<^^<>v>^>v<>>>^<<>>vv^^vvvv>v^v>v^<v>>^>>v<v><>><^<>v>^<<>v<><>v><v<<>vv><^<<vvv^>^v<>^v<<<<vvv^^^vv<>^<<>^^<vv<>v>>vv^<^>>vv<<>^vv^^vv>>v^<vvvvvv>^^^>>v<^<<>^<><<^<v^v><<v^^<<v^^^<^<vv>^<v<>^<^<<vvvvvv<<v<>>^^>v^^<^>v>>>>^v<<v><v>>^<<>>v^>^^v>^>v>>^^v>^>^>^<^<<vv^^<^><>>^^vvv><vv<<><^v^v^<<^^>v><v>v^^>>vv<<>>v<><>v<v<<>>^^>v^<>v^^>^^^v<v^>vvv^v>^v<v^v><<<<vv^^>>v<^v<^>^^v<><v^^^v<^<<^><vv>v^v><^^><<v<<^><<^<^<^<>^v>>^vvv^>><^>v>>vv>^>v>v^>>v^<<vv^<^^><<^^<>><>^vv<>v^"
    "v>>v<v^>><^><vv^^>>><^<v^<^>^<<<<^^<v^>v>^<^>v^^^v<v><<>><><^><<<v><<v^v<v^vvvv>>^<^>^<><<>^>><^>>><v><<vv^v>><^v^v<><v>><<<v<<<<v>>v>^^v>><^<<vv^<^<^<^^>^^^^<<<<^<^^>vvv<^^v<><>>>>><>v><>^<v<^>^vv>v>>vv^^v>v>vv>><^<<>v>v<<<<^<v^^v>^v<>^vv<<v<<v<><v^>v>>^<v^>^<v><>v^>><>^^^<>><<<<v<^^<^<<<>vv<>^vv<>><vv^^^<<<>vv<<^^^v<v>><><^v><^<^vv^<><^v^><><vv>><>>>><><v<>><<>vv<vv><^>vv>>v<v<<>><<v^v^<>>^v^<<>^^<>vv>^<^vvv^><^>v>^<<^vv>>^^><<>^^v^<v^v<^v>vv^<^>>v^<<^^><^>>^<><<v<^>><v<<^<^<v<>v^>^^^<^>v^v^^vv<v^<^>><^<>><>^>><<v^>^<v<^^<^<^<^<<v^><^>vv>><^>v^>>v>>v^^<v>^v<v^v<>>vvv<^^><>^<v>><<^<>v^<^v><<v<v<><><^>>^<^^>>^^<v><^<<<<^v>^<<v>v<<vv^^v>vvv<><<><v>^v<>v^><<vv<>v>><^<<>>>v>v>><^^><^<>^v<^><<<>^^<<^^<v^<v^<^^v^<v^>^^<>>><^v>^v<<>vv>><^>>^v<^vv^<<<<<v<<<<<<vvv<v^^vv>v>v<vv>>^vv^vv^><>>><>>^<^^<>v^v<<>v><<<v^^^^<v><^>^>^>>^v^>^^v<>>>^vv^v<>v^<>v^><<^v<v<<^<^<^^><^^v>^>v^v>v<v^v<><>>^<<<>>>vv^>^^>^<^vv<^>^<^>^^>^^<<><><<v^^^<<>>>vvvv^v>>v>>>^^>>vvv^<v^>><><><<^<<>>v>v>>^<<vv<<v><><^>>^v<<>><"
    "^^<<<><<^v<^v>v<^>^vv>^>v<v>^v^^v^><><vvvv>>v^>><^v<v<^>vv^<<^v^<<<<><vv<>v^>>^^v<><>><v^v<<>^v^<<<v<<^^^v^^^vvv<^<v^><<^v>>>vv>^>^^^>^^<<><^v<>^>>v>>>><^><<><>^^vv<^^^>v<<><>^<<<^^>^<><>^^^>v>^<v>v><><<v>v>^>>^><<^<>^>^^^>v>>>^>>v^>v<^<^v^v<>v>>v^v^<><^v>v^>v>v<^>v>>v^^^<<^v><v<<<<><<><>^^>v<^v<>^<vvv>>>>v^^>^<<^v>>^<<><>^v><v<v<v>^^><>><v^^><v<><<^v<>^^^>vv<^v<^^vv<>>>^vv^<^^>^vv<^^>^<v<>>^<>>><^>>vv^>v^<><v^v>^>^vv><>v<<vvv^>^v>v>>^>^<<<><><vv><vv><>^>>>><>vv<<vv<<><vvv<<>>>^v><^><^v^<v^^^vvv<^>v<<><<<><<v<<>>vv<vv<v><>^v^^v^>^^v<^^<>>v>v<<><^v^<<v^<>>v>v<<vv<^<><^>^^>v><v><<v^<><>>^>^^v^><v^^><<<^v<^>>v>^<<v^><v><v><<^>>^>>>^v<<^vv>><v>^vvv<^>v>v^^>^vvv>v^^<>v><<^^v<vv^^^v^<<v<v>^^vv>^<^>v<<>^v^^v^<v<^>^^v<><<v^v^<^^<>v<<^<v>v<^^^^^<><>^<>>vvv^><><v<^^>>><<vv^<<<<<v<v<^^<^<>>vv^^vv<<<>^<<<<v<^<^><v>v>v^vvv<vvv<^<>^v>vvv^vv^v<<^>>v><<<v^>v^v^^>v<^^>>>v^^>v^<^v^^>^<>^>^<v><<^<vvv>^^><^v<<^>>v^<>^v<^>^v>^>v^>>v>><vv>>^><v<<>^^<v^<>^<^<v>v>v<v><>^><v>v<>>vv^><^v^<>v^v<v><v^^v^vv>>^<>>^"
    "vvvv<^<>^<<^<><>>vv<^>v<>><>v<><>>^<<><v><vv>^<<<^^>^>>v><^>v^^^^v><<v<v<<v<v>^v<<^<>vv>v>^<^^^^^<vv>^<v<>v^^vv^>><>v><<<^v<^^v>vv^>><<v^<^v<<v^<<<<><<>v<<vv>><^^<^vvv^v<>v<>v^vv<vv^<<vv>v>^>v<^^>^<<^^^^v>^^^^^v^>^v><>>><vv>vv^<<>vv<^^<v<<>>>^<v^^<<v>>><><<v><^^>^<v^<<v>>v^^<<<^><^^^><^<><>vv>><vvv<v^^v<><vv<v>^^^>>>vv<>>>>^^v^<v<^<<<v^v^>^><<<v>>^v>v>>>^<^<>>>^^>><<v>><><v^^^<><>v<^>><^^^^v<^^^v><^^^>>v>vv^v^>^^^^<^^>v<>v^<v^<>^>><v<>v<>vvv^>v^^^<v<>><>>vv<^<<>v<>^v^vv<<^^<<v>^<vv<<<>v^<<>>v<><^^v>v<^<v<<<v><<<><v^<^v^v>vvvv<^<<<><v^v<v^v<>v<^^v^<vv>>>><<^<^^<v>>>>v<>vv^<vv>^>v^<vv>^<>^>^vv<v>vvv^^vv^v<<<<^<<v>^<<^v<vvv^^>>v>v^^<<<<<^>^v^<v>^>^<^>>><^>^<v><v<^>v^>v<<v^v<^<><<^^^v<^^<<^>^><<^v^vvvv>>>vv<vv<<<<^v<^v<^>><>v^>>>>v^<>^^^v<>^>^<^>>>><^^>v^<^v><<><vv^v>^^><>>^vv<v^^>>^>v<>^<v>^^^<<>>^<<><>><^<<<>^<<>>vv^^<<vv^>v>^<v^^^>v^^>>^v^><>^>^>v>v>>>><v>>v<<vv><v<v>v>>>vv<^><><<^<<v^<v<v^><v^v^<^>vv>>>>v<v<v>^<v^^v<vv<>v>^<><^vvv^^^^<>v^v^v>v>>>^><><^^>>>vv<^v>^^<^^<v<vv<>^^^>v^^>v>v>"
    "v<^^^^>>^^<v^v>v<^<>><v<v<>^v>^<^><^<v>v<>>v><<>v^>vv>v<>v<^^v^<<^vv>><<<v^<>>>v<<v><^><v>><>>><<>vv>><>^<>vvv>^v>vvvv>v^><v<^v>>^<v^<^>>^>><>^>^>v><<^>^>vv>^^<<>>v^v>v><><^v>vv<<^v^<^vv^v><^<<>v^>v>>^>>><v^>><>^vv^>><<^<>v>>^v^^>v>v^vv<<<<^^v^^<v^<<vv^v^>^v^v<^v>^^v<<v<^>vv<<>><^^^^<v><^>>v>><>v^<<>^v<v>^<v^^^^vv<><<>^<<v<v<vv<><>v<<<^^^<^v>><><<<<^^<>^v><>^^^^v><<>v>v<v>><vv^>v^<v^v<<<vv><v>^>>vv><vv^><vv<^><v>>^>^^^<vvv<<>v><<^><>^<<^<v^<>>^^<v<<<>>^><v>v^<<v^><><>v<>>v^>^<v<<^>>vv>v>>^^<<>>^^v<v<<^^^<><>><v^^><>^>vv^<v>v^vv>^^<^^<<<<<<^<v>>>vvv<^>>vv<><^>v><^><^^<<v^v<vv^><v^<>^<<>^^<v>^v^<v><>v>v<>v>v<v>^v^^><>^>^<^v<^<^>v^<v^>^^v^<v><><^^<^v><v^vv^^^><^<^v<v>^>><>v<<>>>v>^v^<v<<^^>^><<><>^>>^vv<<<v<^^v<>^<^>vvv>^><<>^><^>v><>>^v<vv^<<v><>vv^>>^^^^^>^<>^^^v>v<^^<vv^>^^v^<^><<^<<^><<v^v<^v<<v>^<<><>^^^<^>^^^^>^<><>v><^>>vv<>^<^<<v>vv^>vvv>vv^vvv<>>^>v<><^^^>v^<v<^<^v>^^>^vv^><v<^^<^v<vvv<<<>v<<<^<><<vvv><>^<>^>v^v^^<><v>v>>><><>><<v^<v<v>v<<<<vvv<<^^^^v<^>>^^^<v<^>v><><^>v<v><v>>vv"
    ">v<<v<^>^<^<<>v>>>v^>v<^^v>^<^^v>v>^<>^><^<>^vvv<vvv^<^^<<v><>><><v>vv<v><<>^v>^v^^><>^^><<^vv>vv>v^v><v>v>v><^>><^v>v^<v>^>>^>^^<vv>>^<<><^>><v>^^<>>>>^^vvv^v^<vv>>>^v>v^<v^^>v>^v>><^^^><^<^^>>v<<v^><^>>>v<<<v^^v^<vvv<v>^<>>>v>v<<<^<<<^><<v<v>v^<<v<<>^>>^v<v>>><>v<v^^<v^<v^v^<^^^<^>^<<^<<<<><>^>^<>v<>vv^<^><<>>v^>vv><<<^^^<>^^>^v^^^v^^<v>v<^<^><<<<^<<^>^^v><<><<vv><v^<<^<>v>v>>v<>v^<v>v^^><^v>^><^v^><^vv^^<^^^<<>><^v<<<<<^vv<^><><><vv>^^>>^v>^vv<v^^^<<>v>>^<<^>><<<><v>vv<>^<<v<v>^v>v>><<>>>^>>>vv>>>^^>^<^>v<^^>><<v>v<^><v^^<>vv>v^<>>vv>^>>>vv^>>>><vv>vv<<>v^vvvv>^<v<<>><^><^^>v^vvvv^>^v<^^vv>^vv^^>^v>^^>v^v^>v<>>vv>>v^><<v^<v^>v>^<><>><<<^^v^><vv^^vv<^<>^<<<<<^><^<>>^^v^<^>v<^vv>><vv>v>v^>^>><v>^>^^>vvv^^>^<<v<<^^^>><><v>^>><vvv<<v>^vv>v>vvv>><v^vv<v^<vv^<^vv<^>v>v^v><<^v^><<>><>v<v<v<<v^><^<>vv<^<^v>vv<<>v^<>><<v>>v^<<vv>v<v^^>>v^<>v><^>><>>^^><>>^^v>>^^<vv<^<^>v>^<v<^^>v^><><><v>>^v^><v^<v<<>v<v>>>^^<<v<vv<v^vv^vv<<v<>^^v>v><v<vv<<^<^v<vvv>>><<>^^^<vv^<^^v><>v<<><vv^vvv>>><>^^>vv<^v"
    "v>^v<vv<^<v>>^vv<<<^^<>^<>^vvv>v^^>^<vv<vv<>v^v<^<>>^^^^<v><^^><<>>>v>v^vvv<vvvv^<v<v>v^^^<>>v^^<v<>^v<v<vv^<v^<^^v>^^v<><vvv<^^>^>v><^<v>vv^<<>vv<>>v>>v>vvv<>>vv>>v^v^<<vv^v<^^^>vv<<><v>v>vv<<v<^^<^v<^><<<^v<><<>>^<<>>v^^^<^<vvv^>^<v>><^vvv<^>><>v><^^^^<v>>^^<<>^>^^vv^>^vv>v<v>v^v<v>^>>v<<<>v<><v><<v<>^^^v><>^<v<>^v^<>^^><v>>>v^>>^^^<v^<<<^v^<v^^>>v<^>^^<<^v^<>vvvv<<><v<v<v>^^^^^v^v^<v><<^^<v>>>>v>^^v>><^v<>>>v<>vv>^^><v>^>^><<v>>^^<><v^^^^<v^^v^>>v><<<v><v^vvv>><^^<v>>^>v^><><v^>v^>^<<<>v^vv><v><^^^v^vvvv>v^><v><^vvv<>^vv^<><<^^<vv<^v^v^v>^><^<^v<v><vv>^>v<^^v<<<^v>vv><^<v>vvvv<><>>^>^>^^<<>^>^^^>><^^v^^^<>^<v<v<v>^<<v^>v<v^^><v^^^>><>v<^>^>><^>>^^^v>>>v<<><v>^>>>><>>v><>v><<^<>v<<<^<vv<^v<vv<^<^^<^<<^>^<><>>vvv^<v><v^<v<><<>>vv<^v^^^vv^^><>^<<^^v<<^<<<^>v<>>^>><><><^>vv><<<^vvvv>^^^<<<>^<>>^<>^vv^vv<^<v>>>>>v^v^v<<<<vvv>><^<>v^^<>^v><^v<><v^^vv<^<^>><v>vv>><v<<<<<^>>><>><^<<<v^>^>>v<<^<^<v<>><>>v>^^v<^^>^>vvvv^>v<<<^<<<<^vv>^^^v><<<<^v^v<^^v^^>^>vv^<<^>v^<^v<<>>><<^>v<<>><<<^^^<><^>"
    "><>^^>>^vvvv<v>^v^>><vv<vv^>v>^v^>v<<^<^^<<<<<^v<<>>^^>>>v^>vv^>>>><^^v>><^vv^v<>v><<>v<^<<>v^<v>^<^v><^v^v<>>>^>>v>>^vvv<^^^>>^<<>>v<>><vv<v^^vv<<^^^^>^^<^^>^><<v>v^v^v<^<v<>^>^^>^<<v>^<^>vv<v^>>^v>v^vv>>vv>^>vv<>><<>^^<><>>^>>^><<^<<<>>>v^><>vv>^>v<^^>^><vv>>^vv>^>^v^v^>^^^^<^v<<v<^v<^<<<>^<^<vvv<><^^>v>>vvvv>vvvv^>vvvvv^>v>>vv<v>^^v<>^>v<<<<v<^>^>^<vvv<^v>v<<>^v^v>>>^^^^<^v^vvv>>v^><^vvvv^^<v<^>^><>v<>^v>^>^<<v>^v^<<<v<>^<v^^v^><<<^v<<<>><<vv>v<<>^<^<<^^><><<v>v>>^>>><<vvvv>v^v^^^v>^^v<^<v<>v<^v^>^^^>>><<>v><^^^<v^><v<<v^v<^^v>>^^<>^>^>>v><^<^v^vv>>>><v<^<<vv><^^>^v<v^>^<<<<^>^v><^^v<^<v<>^<>^v>v<>>v<v<v^v^v>^>^^^<>^>>>>^^<^>>v>v^^vv^<vv^^^^<>^><vv>>^v^^<vvv^^v^<<<>>^<<v^^<^>><<>vv><v>v<><v>><<^<v<v>>v>^v<^><>>>^vvv^^<^<^<^^>>v><v<vv^^>vv>>vv^<<^><vv><>v><>v<<<vv<^><^>><>vv<>>>^v>>>^^<<<<v><><^^<>^<<<v<vv^>>>v<>><v^<>v<<v>v^>^<^^v^^^vvv>^^^<^^>v^<<v^v<vv^vvv>vv^v^vv^^>>^>><>vvv^>><v<^v>><v<<>^v<v^><v^^vv<v^v<>v><<<v^v^^v>>v>^^vv^v>>^^^<<^<<>^><^<^^^^^<>^^^>^<>^>vv^^^vv><^^^v^><>><<^"
    "<>^><<v<<<vvv<<v>><>v<^<>^>>^<<>>v<<^vv<v>v>v><>vv<^v>^<<v>^^^>^v^>^>>v<v<>>v<vvvv><^>v<<^^^><v><<^^>^><<<v>v<v>>vv<^>^<v>^>^^^v^>>v<v^><^>>vv>v<<>v^^<^<<<><<^<<<v><^^<<^v<>vv>v^<vv<^^vv>>v<>>v<^^<vv^v^v<>>^>>^^>vvv<<<v<^>v^v>v^>^^<^>>v^<^^v^v><vv>^v>^<<<>>^^^^vv><vv>vv<<v<^<>>vv<>vvv><v>vv>^<<v^<>v^^>>v^v^v<>^>vv>vv^^<>^<^>v<><vv^^^vv<>v^v<^v<>^v><<>v>>^<<>v^<>v<><v^>><><>^v^><<^<^<v^^<vv<>>v<^><v^v<><^^>v<^>^<v^v^<<^v><>^v<v><v^v><^v^vv>v<v<<^^<>^<>>^<<<>v>^^>vvvv^v><^<>>^^^<v>^>v^>^><^v<>v<>><v>>><>>vv^^><<><^^vv<><>>v>^v<<>v<<^^<>><><<v>^<<><><><>^^>v^^<vv>^v>^^vv><<><^>vv^^<^<^v>>v^>v^vvv>v^vv^><v^^<>^>>vv>v^^>vvv<>^>v<<<<><^v^^<v<<><<^vv<<^v><<v^<^>^vvvv<v^>^<^>v<vv^<^>^<^^v>^>>^^<v><^<>v^<^><v>^vvv<<^<>^v^>^<^^<<v>><vv><^v>>v>>^<>vv>v<<v>^^<^<><><<<><>^^^^^v^<>v^^<v^<>v<v^<<<v^>>>^<v<<>v^v<^v><^<<vv^^v^<><<^vv^<vv<v><<^<<><^><^><v>^><v<^>^^v<^>^<>v^><^^<><<vv^>^<^v>v^<<vvv^vv^<^v<<^^v<v^^<<^><>^^>v>^v>^>>><^<>>>^<>>>>^<>v<>>v><>v>vv>v><^v>^<<^<<v>>^><vv^>v^<^^<^>^<>^><<^^^>^<><v"
    "<>^^^>>>>^><^>>^^^^<>>v<^<v^^><v>^vv>>><^<^<v<^<><vv>vvvv>v<vvv^>^v^vv<>^>^><v^>><^<v><^<v<>>v>v^v^>v^<<<vv^<>v<>><^v^<^^v<^^<>v>^v^^^v^<<>^v>v^v<<>^<^v>v><^^^<^<>>^<<v>>><<<^^^>^><v^^vv>>vv><v>^^^>>^<vv<>><>vv<^><><^v^^<>>><<>^<^vv<v^>vv^^v^^^<^^>^v>v<v<v><^>v<^<<v^><<v<^v>^>^>^>v^vv^^^<>^>v<^v>v^v^<v>^^v^^v<v^<>^>^>><<<<><^<>v^<>><vv>^><^<v^>v><v><>v>v<vv<<>v<>vv^^>>>v<^v<>^^>^v<^<vvv^v<v>v<<^>>^v>v^>^^<><<>>^<^><<<>><^v<^<>>^>>v<^>>>v^^^v><^><>>^vvv>v><<<>vv^<<^^^<>^><>^^>>^<^^>^vv>v^v<^v><>^<^>v^><vv><>v<><v>>>>><v<^<v<>^>^<<v^^v^><^<<>^>><^<><<><^v><><^>>>>^<<^^v>^^>><^>^^>>v>>vv<^<^^^<vv^<vv<^>>^<^v>^<<^>>v<<<^<v<^<^v^^^>^v^<^<^<^<<<<<<^>><<^>v<<>v^^>^^<<vvv^vv><v^<>^v>^>^>vv^<^>v>><>>>^<v><v^><^<^vv^^^^^v^^^><v<<>><>v<>^>>^<<<>v<>v>v<^vv>vv^<v^^^>vv<^^vvv><^^<vvvv^vv^v^v^^<vv^<v<v>^v^<>^^>vvv^<<<>>v>^<v^^v^v^^^>>><>>^v^<<v>^vvv>vvv^vvv>^^<><<vv^^<<>v><>^v>^<v^<<>>vv<>^>v><<>v^<<>>>v^<><^>v>^vv^v>v<<^<<><v<^v^<^>><<><vvv^<vvv<>^>^<<v>v><vvv><><>v<>^v>vv^>^><><^^>v<vvvv^^^v>>>v^v<"
    "v<>vvv<<v<<>vv<><>vvv<><^vv>vvv^<vv^v^^<v>v^^<>vvv<^^v>v<^^><>^<<^>><<<<<<<>>^>><>>v>>>>>^v<<<<<><>vv^<<>><^<^>v<>v>v>>^v>>v^^<v<<^vv<^>v<><vv^<^>^>^<v<><<<<<<v<<vvv<^v>><<^>vv<v^<^^vv<v<^vvv^<v^^>v><^^>v><vv<<^>><>v>v>^v<v><^^^^<<^<>vv^vv<vvv<v>^<v>^^^>^^^>>><^^v>><^^><<v^v<^>^<>^vvvvv<^vvvv>>v>>^^>>v>^v<<>>>><vv^vv^>>v<><^<<^v^>>>vv<>vv>vv>^^vv^^^>^>v<><^<>v<<>v^><v^vv<<^^<v<><^<v<>v>>^>v<>><<^<<<>vv^v^>v^>^v^v>v<v>v^^>^v<<<<v^^v<^^v<>^<^v^<<<>>>^<<v<v<vv<^^v^>^<^^v<v>v>>v<vv<<v>^^>vv^><>^<^^>^v^^<^v<^v>v><v<<vv^<v^><>>vv<^>v<>v^>v^>^^><<^^>>v><<vv^<>v>>^v^>v^^<<<>v>><>^<^<^<^<v<vvvv><^><<<^<>^<<vv>^><<^v>>>>v>>><<><>^v^^v>><<<>^v>vv><^>^<>>><>v^^<<<<^v^<>v><<>v<vv<v^^^<><>v^^>^>v>><^v><<v><^>v^v<v^>vvv^^>^^^^^>v><vv<<v<<>>^v>^^^^>v><><<>v<v^v>v^v<^v>>><vvv^<<>^v>^v^<v>vv><>v<>v^^>^v><v>>v>^<<v^>^<>^^<v>>^>>^v>^vv<<<>>>vv^<<v>>^><<>^><><<<>v><^<>^>v>>v<<^^><^^>v^^<<v^^vvvvvv>vv<^^<vv>v^<<>v<<<<<<<v^v><<^v<^v>^^>>v<<^v<vv^^^>^v<^<>^vv^v<<^>v<<v<v<>v>^<^v<^><>>>>>^^^>>v^^^v<^v>><>^^<vv"
    "<>vvv<^<^v<^><^^vv^v><^v<v^<>^^<><<<vv<v>>>^vv<>^><<v<^^<><^^v>v<<v<v^vv^^^^<>v><><^>v^<<v^v>>>^^>>^<^>>^>v<<>><>>^<<<<^<v>^<vv<<<^^><><><v^>><<^<^v<><<^^v^vv>v<><<vv<>^v<><<^v^<^vv^<v>^<>^^><><v<^>v>vv^v^<^><<v^v>^<<><vv>v>^>>v>v^v^v>v<^v<^<v^^v>v>^^<<vv^<^v><v>><^^><^>^<^^>>^v^<<v>^<<>^^^^v^><v<<>>^>v^^v^v^^^^>^v><<^<^<^v<>^<vv^<><<vv<v^v>><<vv^^>v>^v<>^<^<<v^><><<v^v^<<^<v><<^<>v^^>v>>v^>^v<^v<vv^>^^<<^<<v^>^>^><^v<v^^<v^v^^v>>v<>v>v^^>^<^^^>vv^vv>^<>^^^<v<<^<><<^v>^^v^<v^<v>^vv<>v<<^^^^<>^<v^^vv<<^^^vv^>^^v<^v><>^v><^vv<^v>>^^v<vv>v^v<<<^>^<^>^>^<^>>^^<^<^^<<v>^>vv>v<^><<v^<<^>^v<<>>v><<^vv<<^v>v><>>^vv<v^<<>><vv<^<v^^v>>^><v>^<<<^>^vvv>^>v>v<^v^<^v<v<v>^>v>v<vv<^>v<vv<<v><^v>vv>vvv^><^<^<>v>v^v>v>^<v<<^<<<>^<vvvv<<>vv^v><<^^<<>v<v^<^v<<>^<v<v<^vvv<v<>^<>^><v<^<<^^<<v<v<^<>v<<^>^^><><>^^<><v^v^<^^^>vvvvv^v>^>v^>^vvv>><^^v<<^^>v^>v>^v<<>vv>^v><^^^^>^v<<v<><^v><>><^^>vvvvv<>v<<v>v<v^^v<>><v^>^<>^<v>^^v<<v><^v<v^v><vvv<<>v>v^vv<v^^^>v^^>><<>>^>vvvv^<<vvvv<<><vv^><^<>vv>><^^v<<>v<<><>^"
    "^vv>v>^<vv^>v<<>><v^^v><^v^>>v>>v>^vv<v>^^>^<vvvvv^v<^v>v>>^>v><v>>>^<<>v^v^v^<^><v<<<v<^v<vv<><<<>^^vv^<v>>^^v><<>v><v<v^><><>>^<>v>v>v^<v^>^>vv^v<><><<^^<><>><vv^v>>v^^<^vv>v<>vv>^<>^vv<v^^^<><vvv^<>^v^>v>v>^^><^<v^<vv>^v^<v>><<^><v>>>><^>>v>^^><<^<>^^^>vv>v^<>v><v<<>v<>>v^v>^><^vvvvv^>^^^vv>><>>>^vv<vvv^>v<vv><<><<^^vv^>>^<v^>v><>^><<>^v<v>^v>>v^>>v>>^>v^><>v<<v>v>>>^v<vv^><><>>><^v><^>>^<^^v<<<v<v>v^<v^v^<>><^^v^<><vv><<<<>><>vv^><<^v<>^v><vv^>^v<^vv><^<><<vvv<v>^^^vv>vv^v<^^v^<>v<<^v><^<vvv<<<<v^<v<>v><>vvv^v><<^vvvv<v>vv>>^^^<^>>v<<^^>>vv^v^^^vvv>v^^><<v<><v^>^<^v>v>v<^v<>>>^<v<<<>>>>>^v^>vv>>>>v^^v^^<^>^v^v^v^<^><^v>><><v^vv^>>^>v>v^<^v>^v<>v<v^<^>v<<<v^v>v<^v>>^v^v^^^^v<v<v^<>v<<>^^^<<^^<>>v>^^vvv<vvv>^<<v><>>>>>v>>^<<>>^vv<vv^><>>^<v>^<>>v>>^>>>vv<vvv>>^v^v><>^v^<<<^^<^^<^<vvvv^v<^^<>>v<v>vvv>^><vvv<vv^v^v^^vv^>vvv<<<<v>>v^v><<v>>>>v<<<>^v<<^<>>v<^v^v^<^^>>>^^v<^v^v^<^^^><>>>>>^><^>v<^vv>><>>v>^<<vv<<>^vv^<<>v<<>^><>^<<>>v^^<<<<v^vv^>v^^v>>vvvv^<^v<<<<v><>><v^^^<^^>>^<<v<><<<<"
    ">><^^><<^>>^><><<^^>^<v<>v>vvv<v><<v<v>^>^><<><<>^><>>^^<<<<^<<v<^^v><^>^v>v^><^v<^>vv^>^v<v<^>v<^>>v^vvv<^<v>>^v^^v<>^vv<<>>v^^>v^^>>vv>v<^^^<^<v><v^^>v><v^<>^<<<^vv>vv^v>^v<>v>>>^<^<<><v^vv>^<>^>v<>^vv>><v<<vv<^><vv^<^<<<^<v<><^v<^<>vv><^<v^v<>>^^^>>><vv^<>^vv<^v>^>>><<^>^<>v^>^v^><<>>><><^^v^><<>><^^^^v^>^<<<v>><>><<^^^>>^<v>>^^<>v>><<>>><<<>vvv^^v^><v><v^>^<^^^>>^v<^><^<<^<>^><^v^><<<v>>^<^>v>>>^>^>^>vv>^>>v<^^^v<>^<^^v<vv<<>v^><^^>>><<v^<^<>^>^<^<>^<<v^^<^<v<<^v^v^<v^>v^v>>^v<<<>v^^>v><<^<>^<v>v<^^<v><v><^><^>v<v<>>^v^>v^v<^>^><<>><<>v>v^>^^<vv>><^<<^v^v<<v><^^><v>v><<v<^<v<>^^<^<>v>^<<>>^v<^v><vvvv><<v<<^^><v>^v><v^<^<^v<<>^^<^v^^v<^v>v><><vv<^>vv>>^^>>^vv><><^v>v^<>>^^>^vv^^>v>^>vv^^>v^<><>v>^vv>vvv>vv^^v><v^^<v^vvv^v<^>v^^>^v^<v>>>^^^<<v<^^^<^v>v<vv><^<^>>><v>>>^><^v^^v<<vvv><v<v^^vvv>><>v>>^^^<<^v^>^<^>>v^>vv^^v>v<>^>v><<^v^^<<<<v^<>><<>>>^<^<>>><>^<><>^<><^>vv><vvv>^>vv>>v><>v>><>v^>^<>v>v^^^>v^vv<vvv^>v>>v>^>>>v>^<^^><<<<<vv<<^v^>v<v<<><<^<>>vv<>^v>>>v>v<v>v><^>>>^v>>^<>><<>"
    "^><v<vvvv^>>>v>^<vvv<<v<^<^v^v><><v>><^<^^>^^>vv^>^>><>^<vv^>^^<^<^>>>>v^>v><><><v><>^>v<<^v>v^v<>^<^>v<^^<>v^>>v<vv><><<vv<>>^<<v<v>^><>^>^^<<<^v^v^<^^v^<^<>>v^v><<^>^vvv<<^^><<><^^^>^>^^>>v><<^<<v<v<v>v^><^><<>v<>^>>^<>v>vv>>^v<vv^<><<v^<<v><^v<>^v>v<>v<>v^^><^v>><><>><v<><^^>>v^<<><>><^><>vvv^>><^^<>>>v><^<v^v<>>><>^<<><>^>v^v<>^>v>v>v<^<vv^v<^>v>^>v><^<><v><<^v^><>^v<<^^v^><^>v<<<>v><^<><<<>^^v>><<^>^<>vvv^<>>^><<^v^<<v<>v^^>v^v^>v<>v<>^<><>>vv>^^^vv^<^^>v^^<^<v>v<v^>^^^>v^<vvvv>>^>^<>>^<^<<<>v>>v<<>v<<>^<v>>>><>>^v<v<<<><<^v<>^<^^>^<^>^<^v<<<v^^>^<^>v^v<<>^>^<<>>>^^><<>>vv^vv<v<v^^^^<^<^^<^<^^v>^<<v^^^^^vvvv<>^<vv^<<><v>^vv^^v>v^>>>><vv^^^><<<<^^<>>^<v>v>v^^>vv^>^<v^>^vv<><^>v><>^<v^v<>^v<<<<^>>vvv^<<<>vv<v<v^^><>^v>vv>^<>^vv>v^<v^<><^v<<>>^v^^^>^^v^>^^>>v<>^^v>^vv<^^^^^<^>v><<<v>v^<><v^<>^v<^>vv<v<vvv^v<v<^<^<<><>v>>>>^^>v^<^<^<>>^^^^vv^<^v>v<<>^^><>>vvvv<v><^>>^<<^v<^v<v<vv^v<v<v<<^v^v>><^v^^><<>^>v<<<<><vv><>v<>>>><vv>v>^>>>><<>>v<<<^v^^>>v>>^>>>^^^^>^>>>v^v^>v>v<^v^<vv>^<^^^v>"
    "<<>vv<v>^^^<><>^^>^<v<^><<><^v><<^^^<<>^<><<^<^^v<<^v><v>v^>v^^v^>^^vv>>v^^^v^<^>>v<><^v^^<>>^v>>>>^<>>v>>^v><vv<v>vv^^v<vv>v>><^<v>>^<v^><<>>>^<<>v<v^v<>^v><>>^v^^^^<><^<><<vv>v^^v^^v<v<^^<^v^>v^>^v>^<^v^^v^>>v<v><<vv>>^^^^<>v>v<<v^v>><><v><<<vv^^^^>>v^^vv>^^^>^<v^^><<>^><^<vv^<<vvv>v^>>v>v<^^^^v^v^^^^<^<^<vv<^^>>^^v><<v>>>>vvv<><<^v<v>>>v>v><><^^v>>^^^<^>vv^><^>>^^<<<v>v><<>^>^>vv>>^<v^>^^<v^<>^v<vv^<^<^^<^<<^<^v<<<<^<v<^^^>^><<><^vvv^v<>>^>v<<>^^>^>>^<vv>>vv^v>>^><<^^^><<>^^v<<v^><vv^>^<^^vvv>v<>^>v><v^><v<<vv^^^vv>><vv<>>v<>>v^>^v^<v><><v<^<^^<^v^<<^^><>^<^^vv^v<vv<^^>^v^^^<^^><v<<<^v^^v<>>^<^<vv><><>v^<v>v<<v<><<<<<><v^vvv<vv<v^>^<^^><^><>><>><v<>^<^^v>>^<<<<<^v><^<v><v^<>^><^vvv><^<<><>><^^v<^^<><v^>v<v^>>^<v^v<v<vv>^^<^v<^>vvv>vv^<>>^vvv<^><^>^v^^<v<<^vvv^>>^><>^<<<<^^v><>>>^v>>vv^^>><^><<<<^<<^v^><><^>>v>^>^v>><v<><>v><v<v^<v<vv<vv<^>^^><>vv>><^v<^vvv^v<<>>^<vv<<><v<><^<<<vv><<^^v<<^>^<^v><>^<>^>v<^>^^^^^<<>>><vv^>v<v><^>><v><><<^<>v^v^vv>>^vvv<v^><>^^>^^^^<<>vv<v^><>v^<<v><<v>"
    "^^>vv^<^v^v>>vv<v><>>v^v^^><^^^v>vv<>v<><><<vvv<^>^<vvvv<^v<<<><<<^<v>^<<v><>>>>vvv<^^>v<v>^><v^<<v^^<^^vvv<>>^<<>^<<><>v<^<v>^<>>v>><vv<>>v>^^^^<v^>^^v^^^>^>>><>v>>v>>^<<><^><<^<<v^<<<^^^^<^^<>^^vv<>^>^^v<vv^><^>>^>>>><v>vv^vv<^v^<<>^>v^<><><<^<><<><v>v<<<^><v^<><v^^v^^^<<>v>^^^v^^vv<^^>^><^vvv^v<v<<v^><^^v<^vv<><<^v^<<v<v>^v<v<^v<>^v<>>><><vv><vv<><>v><v>^v<^^v><^<v^<vvvv>><>^><><v<>>>^v><><<^>v>^>v><^<v^^><<^v<<^<^>vvvv<^^>^>>>>vv><<>v^>^<^vv>>>^>v^vv>>v><^v<>>^>>^<v^<<^<<<<v<^^>vvv^^^>^<v<^<>><<v^v><>>><v<^^>>^^^<v<^<<<<>>^v>^^^>v^<<v>^<v^><^<<^<><>>>^^<v^<^^vv>^>v><>^v<>^>^^><>v>^^^^vv^^<v>v>vv^^<>^<>^><>^<^><^^><>>vvv^>><<<^>v<v>vv^v^<v<<>vvv<>^v<<>v^>>v<v<<vvvvv>vv<v<^>^<^><vv^v>^>^v^<^>^<^<>>>v>^^v><v^>^><v^v>^>>>>^v^><v^^v^<><><><<v<><^^^<>>v<<vv<><vvv<>^<<<^^^v^v><><v><<v<^>>>^<<><v<v<>><>^<vvv^^^><>v><v><^><>>>v<>>>^<<v>>v^<>>^<><^<<vvv>^v>>^<v^^v<<<<v^<^<<^<>v<^<^>><<v<>>>><<>v>^><><^<vv<v>^^<^^^v<v^v^^>^<>^^v<>vv^<>v<vv^<v^v>><<^>^<v^^v<v>>v^><<<v<<^vv^v<<<><><>>>^v>^<<<>>"
};

std::pair<int, int> move_robot(WarehouseMap& map, int x, int y, char command)
{
    int dx,dy;
    switch(command)
    {
        case '<':
            dx = -1;
            dy = 0;
            break;
        case '^':
            dx = 0;
            dy = -1;
            break;
        case '>':
            dx = 1;
            dy = 0;
            break;
        case 'v':
            dx = 0;
            dy = 1;
            break;
    }

    int x2 = x;
    int y2 = y;
    int n_boxes=0;
    for (;;)
    {
        x2 += dx;
        y2 += dy;
        char c = map[y2][x2];
        if (c == '#') return std::make_pair(x, y);
        if (c != 'O') break;
        n_boxes++;
    }

    map[y][x] = '.';
    x += dx;
    y += dy;
    map[y][x] = '@';
    if (n_boxes > 0)
    {
        x2 = x + n_boxes * dx;
        y2 = y + n_boxes * dy;
        map[y2][x2] = 'O';
    }

    return std::make_pair(x, y);
}

std::pair<int, int> move_robot_h2(WarehouseMap& map, int x, int y, bool right)
{
    int dx = right ? 1 : -1;

    int x2 = x + dx;
    int n_boxes=0;
    for (;;)
    {
        char c = map[y][x2];
        if (c == '#') return std::make_pair(x, y);
        if (c != (right ? '[' : ']')) break;
        n_boxes++;
        x2 += 2 * dx;
    }

    map[y][x] = '.';
    x += dx;
    // y += dy;
    map[y][x] = '@';
    x2 = x;
    for (int k = 0; k < n_boxes; k++)
    {
        x2 += dx;
        map[y][x2] = right ? '[' : ']';
        x2 += dx;
        map[y][x2] = right ? ']' : '[';
    }

    return std::make_pair(x, y);
}

std::vector<std::pair<int, int>> stacked_boxes;

std::pair<int, int> move_robot_v2(WarehouseMap& map, int x, int y, bool down)
{
    int dy = down ? 1 : -1;

    stacked_boxes.clear();
    stacked_boxes.reserve(600); // there are 582 boxes

    std::function<bool(int, int)> count_stacked_boxes;
    count_stacked_boxes = [&](int x, int y) -> bool
    {
        int y2 = y + dy;
        if (y2 < 0 || y2 >= int(map.size())) return false;
        char c = map[y2][x];
        if (c == '[')
        {
            stacked_boxes.emplace_back(x, y2);
            return count_stacked_boxes(x, y2) && count_stacked_boxes(x + 1, y2);
        }
        else if (c == ']')
        {
            stacked_boxes.emplace_back(x - 1, y2);
            return count_stacked_boxes(x - 1, y2) && count_stacked_boxes(x, y2);
        }
        return c != '#';
    };

    if (!count_stacked_boxes(x, y)) return std::make_pair(x, y);

    std::sort(stacked_boxes.begin(), stacked_boxes.end(), [down](const auto& p1, const auto& p2) -> bool
    {
        return down ? (p1.second > p2.second) : (p1.second < p2.second);
    });

    for (const auto& sb: stacked_boxes)
    {
        map[sb.second + dy][sb.first] = '[';
        map[sb.second + dy][sb.first + 1] = ']';
        map[sb.second][sb.first] = '.';
        map[sb.second][sb.first + 1] = '.';
    }

    map[y][x] = '.';
    map[y + dy][x] = '@';

    return std::make_pair(x, y + dy);
}

std::pair<int, int> move_robot2(WarehouseMap& map, int x, int y, char command)
{
    switch(command)
    {
        case '<': return move_robot_h2(map, x, y, false);
        case '^': return move_robot_v2(map, x, y, false);
        case '>': return move_robot_h2(map, x, y, true);
        case 'v': return move_robot_v2(map, x, y, true);
    }
    return std::make_pair(x, y);
}

void draw_map(const WarehouseMap& map)
{
    for (const auto& row: map)
        std::cout << row << "\n";
    std::cout << std::endl;
}

uint64_t part1(WarehouseMap& map, const std::string& moves)
{
    int nx = map.front().size();
    int ny = map.size();

    // find the robot
    int x, y;
    bool found{false};
    for (y = 0; y < ny; y++)
    {
        for (x = 0; x < nx; x++)
        {
            found = map[y][x] == '@';
            if (found) break;
        }
        if (found) break;
    }
    // std::cout << "Initial\n";
    // draw_map(map);

    for (char move: moves)
    {
        // std::cout << "Move " << move << "\n";
        auto foo = move_robot(map, x, y, move);
        x = foo.first;
        y = foo.second;
        // draw_map(map);
    }

    uint64_t ret = 0;
    for (y = 0; y < ny; y++)
    {
        for (x = 0; x < nx; x++)
        {
            if (map[y][x] == 'O')
                ret += 100 * y + x;
        }
    }

    return ret;
}

uint64_t part2(WarehouseMap& map, const std::string& moves)
{
    int nx = map.front().size();
    int ny = map.size();

    // find the robot
    int x, y;
    bool found{false};
    for (y = 0; y < ny; y++)
    {
        for (x = 0; x < nx; x++)
        {
            found = map[y][x] == '@';
            if (found) break;
        }
        if (found) break;
    }

    // std::cout << "Initial\n";
    // draw_map(map);

    for (char move: moves)
    {
        // std::cout << "Move " << move << "\n";
        auto foo = move_robot2(map, x, y, move);
        x = foo.first;
        y = foo.second;
        // draw_map(map);
    }

    uint64_t ret = 0;
    for (y = 0; y < ny; y++)
    {
        for (x = 0; x < nx; x++)
        {
            if (map[y][x] == '[')
                ret += 100 * y + x;
        }
    }

    return ret;
}

int main()
{
    std::cout << part1(sample_warehouse_map, sample_moves) << std::endl;
    std::cout << part1(warehouse_map, moves) << std::endl;
    std::cout << part2(sample_warehouse_map2, sample_moves) << std::endl;
    std::cout << part2(warehouse_map2, moves) << std::endl;
    return 0;
}