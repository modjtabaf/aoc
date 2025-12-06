
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using ID = uint64_t;
using IDRange = std::pair<ID, ID>;
using IDRanges = std::vector<IDRange>;

IDRanges sample_ranges = {
    {11, 22},
    {95, 115},
    {998, 1012},
    {1188511880, 1188511890},
    {222220, 222224},
    {1698522, 1698528},
    {446443, 446449},
    {38593856, 38593862},
    {565653, 565659},
    {824824821, 824824827},
    {2121212118, 2121212124}
};

IDRanges ranges = {
    {69810572, 69955342},
    {3434061167, 3434167492},
    {76756725, 76781020},
    {49, 147},
    {296131, 386620},
    {910523, 946587},
    {34308309, 34358652},
    {64542, 127485},
    {640436, 659023},
    {25, 45},
    {35313993, 35393518},
    {753722181, 753795479},
    {1544, 9792},
    {256, 647},
    {444628, 483065},
    {5863911, 6054673},
    {6969623908, 6969778569},
    {658, 1220},
    {12631, 63767},
    {670238, 830345},
    {1, 18},
    {214165106, 214245544},
    {3309229, 3355697},
};

ID eval_chunk(uint n, ID min, ID max)
{
    ID mask = std::pow<ID>(10, n) + 1;

    ID start = min / mask;
    if (start * mask < min) ++start;
    start = std::max<ID>(start, std::pow<ID>(10, n - 1));

    ID end = max / mask;
    end = std::min(end, mask - 2);

    if (start > end) return 0;

    ID sum1 = start * (start - 1) / 2;
    ID sum2 = end * (end + 1) / 2;
    return mask * (sum2 - sum1);
}

void eval_chunk_ex(uint n, uint n_chunks, ID min, ID max, std::set<ID>& invalid_ids)
{
    ID factor = std::pow<ID>(10, n);
    ID mask{1};
    for (uint k=1; k < n_chunks; ++k)
        mask = factor * mask + 1;

    ID start = min / mask;
    if (start * mask < min) ++start;
    start = std::max<ID>(start, std::pow<ID>(10, n - 1));

    ID end = max / mask;
    end = std::min(end, factor - 1);

    for (auto id=start; id <= end; ++id)
        invalid_ids.emplace(id * mask);
}

ID part1(const IDRanges& ranges)
{
    ID ret{0};
    for (auto range: ranges)
    {
        uint n1 = std::to_string(range.first).length();
        n1 = (n1 + 1) / 2;

        uint n2 = std::to_string(range.second).length();
        n2 /= 2;

        for (uint n=n1; n <= n2; ++n)
            ret += eval_chunk(n, range.first, range.second);
    }
    return ret;
}

ID part2(const IDRanges& ranges)
{
    std::set<ID> invalid_ids;
    for (auto range: ranges)
    {
        uint l1 = std::to_string(range.first).length();
        uint l2 = std::to_string(range.second).length();
        uint l = std::max(l1, l2);

        for (uint n_chunks=2; n_chunks <= l; ++n_chunks)
        {
            uint n1 = (l1 + 1) / n_chunks;
            uint n2 = l2 / n_chunks;

            for (uint n=n1; n <= n2; ++n)
                eval_chunk_ex(n, n_chunks, range.first, range.second, invalid_ids);
        }
    }

    ID ret{0};
    for (ID id: invalid_ids)
        ret += id;
    return ret;
}

int main()
{
    std::cout << part1(sample_ranges) << std::endl;
    std::cout << part1(ranges) << std::endl;
    std::cout << part2(sample_ranges) << std::endl;
    std::cout << part2(ranges) << std::endl;
    return 0;
}
