
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

#define assertm(exp, msg) assert((void(msg), exp))

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

    void run(std::vector<uint8_t>& output)
    {
        output.clear();
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
                output.emplace_back(get_combo_operand(op) & 0b111);
                break;
            case 6: // bdv
                B = A >> get_combo_operand(op);
                break;
            case 7: // cdv
                C = A >> get_combo_operand(op);
                break;
            default:
                assertm(false, "invalid instruction!");
            }
        }
    }

};

Program sample_program{
    729,
    0,
    0,
    {0,1,5,4,3,0}
};

Program sample_program2{
    0,
    0,
    0,
    {0,3,5,4,3,0}
};

Program problem_program{
    23999685,
    0,
    0,
    {
        2,4,   // B = A & 0b111
        1,1,   // B = B ^ 1
        7,5,   // C = A >> B
        1,5,   // B = B ^ 0b101
        0,3,   // A = A >> 3
        4,4, // B = B ^ C
        5,5, // output B & 0b111
        3,0} // if (A != 0) go to beginning
};

uint64_t find_chunk(Program& program, uint64_t A, int n, std::vector<uint8_t>& output)
{
    int N = program.program.size();
    if (n == N) return A;

    for (int a=0; a < 8; a++)
    {
        program.A = (A << 3) + a;
        program.run(output);
        bool found{true};
        for (int k=0; k <= n && found; k++)
        {
            found = output[k] == program.program[N - 1 - n + k];
        }

        if (!found) continue;
        
        auto ret = find_chunk(program, (A << 3) + a, n + 1, output);
        if (ret > 0) return ret;
    }

    return 0;
}

int main()
{
    std::vector<uint8_t> output;
    int N = problem_program.program.size();
    output.reserve(N);

    sample_program.run(output);
    for (auto n: output) std::cout << int(n) << ",";
    std::cout << "\n";
    problem_program.run(output);
    for (auto n: output) std::cout << int(n) << ",";
    std::cout << "\n";

    std::cout << find_chunk(sample_program2, 0, 0, output) << "\n";
    std::cout << find_chunk(problem_program, 0, 0, output) << "\n";

    return 0;
}
