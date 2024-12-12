
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>

using RawStones = std::vector<uint64_t>;
using Stones = std::unordered_map<uint64_t, uint64_t>;

RawStones sample_raw_stones{125,17};

RawStones raw_stones{
    7568, 155731, 0, 972, 1, 6919238, 80646, 22
};

void add_stone(Stones& stones, uint64_t stone, uint64_t count)
{
    auto it = stones.find(stone);
    if (it == stones.end())
        stones[stone] = count;
    else
        it->second += count;
}

uint64_t solve(const RawStones& raw_stones, int num_blinks)
{
    Stones stones1, stones2;

    for (auto stone: raw_stones)
        add_stone(stones1, stone, 1);

    Stones *stones_curr{&stones1}, *stones_new{&stones2};

    for (int blink = 0; blink < num_blinks; blink++)
    {
        stones_new->clear();

        for(auto& p: *stones_curr)
        {
            if (p.first == 0)
            {
                add_stone(*stones_new, 1, p.second);
            }
            else
            {
                std::string str = std::to_string(p.first);
                if ((str.size() & 1) == 0)
                {
                    add_stone(*stones_new, std::stoul(str.substr(str.size() / 2).c_str()), p.second);
                    add_stone(*stones_new, std::stoul(str.substr(0, str.size() / 2).c_str()), p.second);
                }
                else
                {
                    add_stone(*stones_new, p.first * 2024, p.second);
                }
            }
        }

        std::swap(stones_new, stones_curr);
    }

    uint64_t ret = 0;
    for (const auto& p: *stones_curr)
        ret += p.second;
    return ret;
}

int main()
{
    std::cout << solve(sample_raw_stones, 25) << std::endl;
    std::cout << solve(raw_stones, 25) << std::endl;
    std::cout << solve(sample_raw_stones, 75) << std::endl;
    std::cout << solve(raw_stones, 75) << std::endl;
    return 0;
}
