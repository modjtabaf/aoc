
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <utility>
#include <vector>

struct Program
{
    uint64_t A;
    uint64_t B;
    uint64_t C;
    std::vector<uint8_t> program;

    uint8_t get_combo_operand(uint8_t op)
    {
        switch (op)
        {
        case 4: return A;
        case 5: return B;
        case 6: return C;
        }
        return op;
    }

    int run(bool part1)
    {
        int n_match = 0;
        auto ref = program.begin();
        for (auto p=program.begin(); p != program.end();)
        {
            auto inst = *(p++);
            auto op = *(p++);

            // std::cout << int(inst) << ":" << int(op) << "\n";

            switch (inst)
            {
            case 0: // adv
                A = A >> get_combo_operand(op);
                // std::cout << "A = " << std::bitset<3>(A) << "\n";
                break;
            case 1: // bxl
                B = B ^ op;
                // std::cout << "B = " << std::bitset<3>(B) << "\n";
                break;
            case 2: // bst
                B = get_combo_operand(op) & 0b111;
                // std::cout << "B = " << std::bitset<3>(B) << "\n";
                break;
            case 3: // jnz
                if (A != 0) p = program.begin() + op;
                break;
            case 4: // bxc
                // std::cout << "B = B ^ C" << "\n";
                B = B ^ C;
                // std::cout << "B = " << std::bitset<3>(B) << "\n";
                break;
            case 5: // out
                // std::cout << "out B & 0b111\n";
                if (part1)
                    std::cout << (get_combo_operand(op) & 0b111) << ",";
                else if ((get_combo_operand(op) & 0b111) != *(ref++)) return n_match;
                n_match++;
                // std::cout << "out " << std::bitset<3>(get_combo_operand(op) & 0b111) << std::endl;
                break;
            case 6: // bdv
                B = A >> get_combo_operand(op);
                // std::cout << "B = " << std::bitset<3>(B) << "\n";
                break;
            case 7: // cdv
                // std::cout << "C = A >> " << int(get_combo_operand(op)) << "\n";
                C = A >> get_combo_operand(op);
                // std::cout << "C = " << std::bitset<3>(C) << "\n";
                break;
            default:
                std::cout << "invalid instruction!" << std::endl;
                return false;
            }
        }

        if (part1) std::cout << std::endl;
        return n_match;
    }

};

Program sample_program{
    729,
    0,
    0,
    {0,1,5,4,3,0}
};

Program sample_program2{
    2024,
    0,
    0,
    {0,3,5,4,3,0}
};

Program program{
    23999685,
    0,
    0,
    {
        2,4,
        1,1,
        7,5,
        1,5,
        0,3,
        4,4,
        5,5,
        3,0}
};

uint64_t part2(Program& program)
{
    uint64_t A = 0;
    // uint64_t A = 0b101010010010100010;
    auto B = program.B;
    auto C = program.C;
    uint32_t n_match = 1;
    int shift = 0;
    while (n_match <= 3)//program.program.size())
    {
        for(uint64_t k=0; k < 8; k++)
        {
            program.A = (k << shift) | A;
            std::cout << std::bitset<9>(program.A) << std::endl;
            program.B = B;
            program.C = C;
            auto foo = program.run(false);
            std::cout << "foo = " << foo << std::endl;
            if (foo == n_match)
            {
                A = (k << shift) | A;
                std::cout << n_match << std::endl;
                shift += 3;
                break;
            }
        }
        n_match++;
    }
    return A;
}

int main()
{
    // sample_program.run(true);
    // program.run(true);
    // std::cout << part2(sample_program2) << std::endl;
    std::cout << std::bitset<64>(part2(program)) << std::endl;
    // part2(program);
    return 0;
}
