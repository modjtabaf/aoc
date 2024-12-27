
#include <cassert>
#include <cstdint>
#include <endian.h>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

using Codes = std::vector<std::string>;
using Pos = std::pair<int, int>;
using Keypad = std::vector<std::string>;
using CommandsMap = std::unordered_map<int, std::vector<std::string>>;
using ShortestCommand = std::unordered_map<int, uint64_t>;

Codes sample_codes{
    "029A",
    "980A",
    "179A",
    "456A",
    "379A",
};

Codes problem_codes{
    "341A",
    "803A",
    "149A",
    "683A",
    "208A",
};

CommandsMap door_cmds_map;
CommandsMap robot_cmds_map;

int get_index(const Pos& pos1, const Pos& pos2)
{
    return (pos1.first + pos1.second * 4) * 16 + (pos2.first + pos2.second * 4);
}

void generate_paths(const Pos& pos1, const Pos& pos2, const Pos& avoid, int index, std::string cmd, CommandsMap& cmds_map)
{
    if (pos1 == avoid) return;
    if (pos1 == pos2)
    {
        if (cmd.empty() || cmd[cmd.size() - 1] != 'A') cmd += 'A';
        cmds_map[index].push_back(cmd);
        return;
    }

    if (pos1.first < pos2.first)
        generate_paths({pos1.first + 1, pos1.second}, pos2, avoid, index, cmd + ">", cmds_map);
    else if (pos1.first > pos2.first)
        generate_paths({pos1.first - 1, pos1.second}, pos2, avoid, index, cmd + "<", cmds_map);

    if (pos1.second < pos2.second)
        generate_paths({pos1.first, pos1.second + 1}, pos2, avoid, index, cmd + "v", cmds_map);
    else if (pos1.second > pos2.second)
        generate_paths({pos1.first, pos1.second - 1}, pos2, avoid, index, cmd + "^", cmds_map);
}

Pos get_door_keypad_pos(char ch)
{
    if (ch == 'A') return {2, 3};
    if (ch == '0') return {1, 3};
    int n = ch - '0' - 1;
    assert(n >= 0 && n <= 8);
    return {n % 3, 2 - n / 3};
}

Pos get_robot_keypad_pos(char ch)
{
    switch (ch)
    {
    case '^': return {1, 0};
    case '<': return {0, 1};
    case 'v': return {1, 1};
    case '>': return {2, 1};
    }
    assert(ch == 'A');
    return {2, 0};
}

class Robot
{
protected:
    ShortestCommand shortest_cmd_map_;
    bool is_door_{false};
    std::shared_ptr<Robot> next_robot_;
    Pos init_pos_;

public:
    Robot(bool is_door, const std::shared_ptr<Robot>& next_robot, const Pos& init_pos) :
        is_door_(is_door), next_robot_(next_robot), init_pos_(init_pos) {}

    uint64_t get_command(const std::string& code)
    {
        uint64_t ret{0};
        Pos pos1{init_pos_};
        for (auto ch: code)
        {
            auto pos2 = is_door_ ? get_door_keypad_pos(ch) : get_robot_keypad_pos(ch);
            auto index = get_index(pos1, pos2);
            auto it = shortest_cmd_map_.find(index);
            if (it == shortest_cmd_map_.end())
            {
                const auto& cmds = is_door_ ? door_cmds_map[index] : robot_cmds_map[index];
                uint64_t shortest{std::numeric_limits<uint64_t>::max()};
                for (const auto& cmd: cmds)
                {
                    auto next_cmd = next_robot_ ? next_robot_->get_command(cmd) : cmd.length();
                    if (next_cmd < shortest) shortest = next_cmd;
                }
                ret += shortest;
                shortest_cmd_map_[index] = shortest;
            }
            else
            {
                ret += it->second;
            }
            pos1 = pos2;
        }
        return ret;
    }
};

uint64_t solve(const Codes& codes, int n_robots)
{
    auto robot = n_robots > 0 ? std::make_shared<Robot>(false, nullptr, Pos{2, 0}) : nullptr;
    for (int k=1; k < n_robots; k++)
    {
        robot = std::make_shared<Robot>(false, robot, Pos{2, 0});
    }
    robot = std::make_shared<Robot>(true, robot, Pos{2, 3});

    uint64_t ret{0};
    for (const auto& code: codes)
    {
        auto command = robot->get_command(code);
        ret += command * std::stoul(code);
    }
    return ret;
}

int main()
{
    Pos pos1;
    Pos pos2;

    for (pos1.first=0; pos1.first < 3; pos1.first++)
    {
        for (pos1.second=0; pos1.second < 4; pos1.second++)
        {
            if (pos1.first == 0 && pos1.second == 3) continue;
            for (pos2.first=0; pos2.first < 3; pos2.first++)
            {
                for (pos2.second=0; pos2.second < 4; pos2.second++)
                {
                    if (pos2.first == 0 && pos2.second == 3) continue;
                    int index = (pos1.first + pos1.second * 4) * 16 + (pos2.first + pos2.second * 4);
                    generate_paths(pos1, pos2, {0, 3}, index, "", door_cmds_map);
                }
            }
        }
    }

    for (pos1.first=0; pos1.first < 3; pos1.first++)
    {
        for (pos1.second=0; pos1.second < 2; pos1.second++)
        {
            if (pos1.first == 0 && pos1.second == 0) continue;
            for (pos2.first=0; pos2.first < 3; pos2.first++)
            {
                for (pos2.second=0; pos2.second < 2; pos2.second++)
                {
                    if (pos2.first == 0 && pos2.second == 0) continue;
                    auto index = get_index(pos1, pos2);
                    generate_paths(pos1, pos2, {0, 0}, index, "", robot_cmds_map);
                }
            }
        }
    }

    std::cout << solve(sample_codes, 2) << "\n";
    std::cout << solve(problem_codes, 2) << "\n";
    std::cout << solve(problem_codes, 25) << "\n";

    return 0;
}
