
#include <cstdint>
#include <iostream>
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

            switch (inst)
            {
            case 0: // adv
                A = A >> get_combo_operand(op);
                break;
            case 1: // bxl
                B = B ^ op;
                break;
            case 2: // bst
                B = get_combo_operand(op) & 0b111;
                break;
            case 3: // jnz
                if (A != 0) p = program.begin() + op;
                break;
            case 4: // bxc
                B = B ^ C;
                break;
            case 5: // out
                if (part1)
                    std::cout << (get_combo_operand(op) & 0b111) << ",";
                else if ((get_combo_operand(op) & 0b111) != *(ref++)) return n_match;
                n_match++;
                break;
            case 6: // bdv
                B = A >> get_combo_operand(op);
                break;
            case 7: // cdv
                C = A >> get_combo_operand(op);
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

int main()
{
    sample_program.run(true);
    program.run(true);
    return 0;
}
