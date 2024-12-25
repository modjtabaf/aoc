
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <utility>
#include <vector>

struct Gate
{
    std::string in1;
    std::function<int(int, int)> func;
    std::string in2;
    std::string out;
    bool evaluated{false};
    bool swapped{false};
};

auto AND = [](int in1, int in2) -> int
    {
        if (in1 < 0 || in2 < 0) return -1;
        return in1 > 0 && in2 > 0 ? 1 : 0;
    };

auto OR = [](int in1, int in2) -> int
    {
        if (in1 < 0 || in2 < 0) return -1;
        return in1 > 0 || in2 > 0 ? 1 : 0;
    };

auto XOR = [](int in1, int in2) -> int
    {
        if (in1 < 0 || in2 < 0) return -1;
        return (in1 > 0) ^ (in2 > 0) ? 1 : 0;
    };

using Values = std::unordered_map<std::string, int>;
using Gates = std::vector<Gate>;

Values sample_init_values{
    {"x00", 1},
    {"x01", 0},
    {"x02", 1},
    {"x03", 1},
    {"x04", 0},
    {"y00", 1},
    {"y01", 1},
    {"y02", 1},
    {"y03", 1},
    {"y04", 1},
};

Gates sample_gates{
    {"ntg", XOR, "fgs", "mjb"},
    {"y02", OR, "x01", "tnw"},
    {"kwq", OR, "kpj", "z05"},
    {"x00", OR, "x03", "fst"},
    {"tgd", XOR, "rvg", "z01"},
    {"vdt", OR, "tnw", "bfw"},
    {"bfw", AND, "frj", "z10"},
    {"ffh", OR, "nrd", "bqk"},
    {"y00", AND, "y03", "djm"},
    {"y03", OR, "y00", "psh"},
    {"bqk", OR, "frj", "z08"},
    {"tnw", OR, "fst", "frj"},
    {"gnj", AND, "tgd", "z11"},
    {"bfw", XOR, "mjb", "z00"},
    {"x03", OR, "x00", "vdt"},
    {"gnj", AND, "wpb", "z02"},
    {"x04", AND, "y00", "kjc"},
    {"djm", OR, "pbm", "qhw"},
    {"nrd", AND, "vdt", "hwm"},
    {"kjc", AND, "fst", "rvg"},
    {"y04", OR, "y02", "fgs"},
    {"y01", AND, "x02", "pbm"},
    {"ntg", OR, "kjc", "kwq"},
    {"psh", XOR, "fgs", "tgd"},
    {"qhw", XOR, "tgd", "z09"},
    {"pbm", OR, "djm", "kpj"},
    {"x03", XOR, "y03", "ffh"},
    {"x00", XOR, "y04", "ntg"},
    {"bfw", OR, "bqk", "z06"},
    {"nrd", XOR, "fgs", "wpb"},
    {"frj", XOR, "qhw", "z04"},
    {"bqk", OR, "frj", "z07"},
    {"y03", OR, "x01", "nrd"},
    {"hwm", AND, "bqk", "z03"},
    {"tgd", XOR, "rvg", "z12"},
    {"tnw", OR, "pbm", "gnj"},
};

// Values sample_init_values2{
//     {"x00", 0},
//     {"x01", 1},
//     {"x02", 0},
//     {"x03", 1},
//     {"x04", 0},
//     {"x05", 1},
//     {"y00", 0},
//     {"y01", 0},
//     {"y02", 1},
//     {"y03", 1},
//     {"y04", 0},
//     {"y05", 1},
// };

Gates sample_gates2{
    {"x00", AND, "y00", "z05"},
    {"x01", AND, "y01", "z02"},
    {"x02", AND, "y02", "z01"},
    {"x03", AND, "y03", "z03"},
    {"x04", AND, "y04", "z04"},
    {"x05", AND, "y05", "z00"},
};

Values problem_init_values{
    {"x00", 1},
    {"x01", 1},
    {"x02", 0},
    {"x03", 0},
    {"x04", 0},
    {"x05", 1},
    {"x06", 0},
    {"x07", 1},
    {"x08", 1},
    {"x09", 0},
    {"x10", 1},
    {"x11", 0},
    {"x12", 0},
    {"x13", 0},
    {"x14", 1},
    {"x15", 0},
    {"x16", 0},
    {"x17", 1},
    {"x18", 0},
    {"x19", 1},
    {"x20", 0},
    {"x21", 1},
    {"x22", 0},
    {"x23", 1},
    {"x24", 0},
    {"x25", 0},
    {"x26", 1},
    {"x27", 0},
    {"x28", 0},
    {"x29", 0},
    {"x30", 0},
    {"x31", 1},
    {"x32", 1},
    {"x33", 1},
    {"x34", 1},
    {"x35", 1},
    {"x36", 1},
    {"x37", 1},
    {"x38", 0},
    {"x39", 1},
    {"x40", 1},
    {"x41", 0},
    {"x42", 1},
    {"x43", 1},
    {"x44", 1},
    {"y00", 1},
    {"y01", 0},
    {"y02", 1},
    {"y03", 1},
    {"y04", 0},
    {"y05", 0},
    {"y06", 1},
    {"y07", 1},
    {"y08", 0},
    {"y09", 1},
    {"y10", 1},
    {"y11", 1},
    {"y12", 1},
    {"y13", 0},
    {"y14", 1},
    {"y15", 1},
    {"y16", 0},
    {"y17", 0},
    {"y18", 0},
    {"y19", 1},
    {"y20", 1},
    {"y21", 0},
    {"y22", 0},
    {"y23", 1},
    {"y24", 1},
    {"y25", 1},
    {"y26", 0},
    {"y27", 1},
    {"y28", 0},
    {"y29", 0},
    {"y30", 0},
    {"y31", 1},
    {"y32", 1},
    {"y33", 0},
    {"y34", 1},
    {"y35", 0},
    {"y36", 0},
    {"y37", 0},
    {"y38", 1},
    {"y39", 0},
    {"y40", 1},
    {"y41", 0},
    {"y42", 1},
    {"y43", 1},
    {"y44", 1},
};

Gates problem_gates{
    {"x21", XOR, "y21", "hgv"},
    {"cpr", OR, "tmw", "dhb"},
    {"cpq", AND, "tkb", "jqs"},
    {"nbp", AND, "tnq", "cpr"},
    {"scj", AND, "btd", "tpk"},
    {"ffg", OR, "tpj", "jrb"},
    {"pft", AND, "qcp", "bcq"},
    {"djg", OR, "djr", "nbf"},
    {"qdg", AND, "fqp", "trd"},
    {"jkm", AND, "wrg", "vsk"},
    {"x39", AND, "y39", "rjk"},
    {"frt", AND, "pgs", "vfq"},
    {"nqk", OR, "mdk", "tbs"},
    {"y00", AND, "x00", "ktt"},
    {"pks", OR, "ptm", "dnd"},
    {"ntj", AND, "fbk", "dps"},
    {"y44", AND, "x44", "dgh"},
    {"wgw", OR, "qqp", "rnc"},
    {"y33", AND, "x33", "jpc"},
    {"x13", AND, "y13", "ntm"},
    {"y38", XOR, "x38", "spf"},
    {"fnq", OR, "pcv", "scj"},
    {"hjs", OR, "vwj", "hhp"},
    {"y38", AND, "x38", "pgc"},
    {"ftg", AND, "mhv", "njj"},
    {"wvw", OR, "rdt", "trw"},
    {"gkk", AND, "nrd", "smk"},
    {"jjc", AND, "mpf", "gvt"},
    {"x14", AND, "y14", "tmw"},
    {"mwp", OR, "vsb", "jqc"},
    {"mks", OR, "jqs", "jrr"},
    {"y40", XOR, "x40", "cvb"},
    {"hjm", AND, "jrr", "rpj"},
    {"x04", AND, "y04", "csm"},
    {"kdm", AND, "cgt", "sch"},
    {"jkm", XOR, "wrg", "z33"},
    {"wjh", XOR, "cpv", "z17"},
    {"bfn", OR, "gwm", "smd"},
    {"x06", AND, "y06", "kfb"},
    {"sqr", XOR, "wpd", "z25"},
    {"dkq", OR, "jsf", "frt"},
    {"x40", AND, "y40", "wgw"},
    {"sqt", OR, "wnv", "hww"},
    {"y12", AND, "x12", "djr"},
    {"y18", XOR, "x18", "qcp"},
    {"cpq", XOR, "tkb", "z23"},
    {"bsr", OR, "njd", "cpq"},
    {"rqp", XOR, "hcd", "z10"},
    {"ckt", XOR, "jwg", "z20"},
    {"x19", AND, "y19", "z19"},
    {"y37", AND, "x37", "gqf"},
    {"hqv", XOR, "bcf", "z34"},
    {"x41", XOR, "y41", "mfp"},
    {"x14", XOR, "y14", "nbp"},
    {"x42", XOR, "y42", "qsg"},
    {"y25", XOR, "x25", "wpd"},
    {"x27", AND, "y27", "jqg"},
    {"y05", AND, "x05", "fjd"},
    {"y28", XOR, "x28", "gkk"},
    {"x17", AND, "y17", "bpg"},
    {"y26", XOR, "x26", "tmk"},
    {"bgs", OR, "rpc", "nqq"},
    {"x13", XOR, "y13", "fnc"},
    {"x31", AND, "y31", "jsf"},
    {"y34", XOR, "x34", "bcf"},
    {"ftg", XOR, "mhv", "z06"},
    {"y10", AND, "x10", "wnv"},
    {"x00", XOR, "y00", "z00"},
    {"y15", AND, "x15", "ptm"},
    {"fnc", AND, "nbf", "mwj"},
    {"qmj", XOR, "jqc", "z36"},
    {"bcf", AND, "hqv", "cwc"},
    {"gkk", XOR, "nrd", "z28"},
    {"kbm", AND, "dgv", "vsb"},
    {"y34", AND, "x34", "gbk"},
    {"y33", XOR, "x33", "jkm"},
    {"y08", AND, "x08", "wvw"},
    {"y39", XOR, "x39", "fkg"},
    {"hhp", XOR, "tjm", "dsd"},
    {"cwc", OR, "gbk", "dgv"},
    {"dnd", XOR, "nqd", "z16"},
    {"dts", XOR, "gpv", "z07"},
    {"njf", XOR, "jsb", "djg"},
    {"y36", AND, "x36", "hjs"},
    {"y31", XOR, "x31", "qvw"},
    {"stm", OR, "mgr", "cpv"},
    {"y02", AND, "x02", "kwm"},
    {"x03", AND, "y03", "jmr"},
    {"wcc", OR, "jjp", "fqp"},
    {"btd", XOR, "scj", "z43"},
    {"y24", AND, "x24", "hjm"},
    {"y32", XOR, "x32", "pgs"},
    {"y12", XOR, "x12", "jsb"},
    {"y23", XOR, "x23", "tkb"},
    {"kfb", OR, "njj", "gpv"},
    {"y22", XOR, "x22", "kvp"},
    {"x16", XOR, "y16", "nqd"},
    {"dhr", AND, "cvb", "qqp"},
    {"y25", AND, "x25", "ffg"},
    {"fbk", XOR, "ntj", "z03"},
    {"wqw", AND, "mtm", "rdt"},
    {"qvw", AND, "smd", "dkq"},
    {"kgm", OR, "smk", "rmg"},
    {"hww", XOR, "fkc", "z11"},
    {"dcc", OR, "wkn", "njf"},
    {"x09", XOR, "y09", "pmb"},
    {"fbf", OR, "npg", "gtk"},
    {"y15", XOR, "x15", "ktv"},
    {"nbp", XOR, "tnq", "z14"},
    {"tbs", AND, "kvp", "njd"},
    {"qcp", XOR, "pft", "z18"},
    {"sqr", AND, "wpd", "tpj"},
    {"jmr", OR, "dps", "mpf"},
    {"y20", AND, "x20", "rpc"},
    {"tmc", OR, "tpk", "fjb"},
    {"fsc", OR, "bcq", "qjc"},
    {"qdg", XOR, "fqp", "z27"},
    {"x28", AND, "y28", "kgm"},
    {"y32", AND, "x32", "psb"},
    {"y17", XOR, "x17", "wjh"},
    {"mcq", OR, "rpj", "sqr"},
    {"dsd", XOR, "spf", "z38"},
    {"mfp", AND, "rnc", "fbf"},
    {"dgh", OR, "vpj", "z45"},
    {"jsb", AND, "njf", "z12"},
    {"kgp", OR, "kmb", "rkn"},
    {"dmn", XOR, "rkw", "z30"},
    {"csm", OR, "gvt", "cgt"},
    {"y03", XOR, "x03", "fbk"},
    {"y05", XOR, "x05", "kdm"},
    {"hhp", AND, "tjm", "spj"},
    {"qjc", XOR, "kbs", "sbg"},
    {"rqp", AND, "hcd", "sqt"},
    {"x01", XOR, "y01", "rvb"},
    {"y30", XOR, "x30", "rkw"},
    {"wqw", XOR, "mtm", "z08"},
    {"y08", XOR, "x08", "wqw"},
    {"mrf", OR, "pgc", "kvh"},
    {"x24", XOR, "y24", "mcq"},
    {"jpc", OR, "vsk", "hqv"},
    {"hww", AND, "fkc", "dcc"},
    {"dhb", AND, "ktv", "pks"},
    {"tbs", XOR, "kvp", "z22"},
    {"trd", OR, "jqg", "nrd"},
    {"jfn", AND, "fjb", "vpj"},
    {"trw", AND, "pmb", "pvb"},
    {"cpv", AND, "wjh", "jtp"},
    {"kbm", XOR, "dgv", "z35"},
    {"hhm", XOR, "rmg", "z29"},
    {"y07", XOR, "x07", "dts"},
    {"whm", OR, "qss", "mtm"},
    {"nqq", AND, "hgv", "mdk"},
    {"dmn", AND, "rkw", "gwm"},
    {"x43", AND, "y43", "tmc"},
    {"rmg", AND, "hhm", "ktc"},
    {"jjc", XOR, "mpf", "z04"},
    {"y23", AND, "x23", "mks"},
    {"frt", XOR, "pgs", "z32"},
    {"x19", XOR, "y19", "kbs"},
    {"kvh", AND, "fkg", "qns"},
    {"bnh", OR, "sbg", "jwg"},
    {"qsg", AND, "gtk", "fnq"},
    {"y11", XOR, "x11", "fkc"},
    {"vfq", OR, "psb", "wrg"},
    {"bpg", OR, "jtp", "pft"},
    {"x29", AND, "y29", "rwk"},
    {"qsg", XOR, "gtk", "z42"},
    {"x07", AND, "y07", "qss"},
    {"x41", AND, "y41", "npg"},
    {"kvh", XOR, "fkg", "z39"},
    {"jrb", AND, "tmk", "wcc"},
    {"y36", XOR, "x36", "qmj"},
    {"ntm", OR, "mwj", "tnq"},
    {"y11", AND, "x11", "wkn"},
    {"fjb", XOR, "jfn", "z44"},
    {"rwk", OR, "ktc", "dmn"},
    {"ktt", XOR, "rvb", "z01"},
    {"mfp", XOR, "rnc", "z41"},
    {"hgv", XOR, "nqq", "z21"},
    {"x35", XOR, "y35", "kbm"},
    {"y35", AND, "x35", "mwp"},
    {"x42", AND, "y42", "pcv"},
    {"dsd", AND, "spf", "mrf"},
    {"y02", XOR, "x02", "ssq"},
    {"x18", AND, "y18", "fsc"},
    {"y04", XOR, "x04", "jjc"},
    {"rkn", XOR, "ssq", "z02"},
    {"x43", XOR, "y43", "btd"},
    {"dhb", XOR, "ktv", "z15"},
    {"x20", XOR, "y20", "ckt"},
    {"jqc", AND, "qmj", "vwj"},
    {"y21", AND, "x21", "nqk"},
    {"x01", AND, "y01", "kgp"},
    {"qjc", AND, "kbs", "bnh"},
    {"fhf", OR, "pvb", "rqp"},
    {"fnc", XOR, "nbf", "z13"},
    {"dts", AND, "gpv", "whm"},
    {"smd", XOR, "qvw", "z31"},
    {"fjd", OR, "sch", "ftg"},
    {"y06", XOR, "x06", "mhv"},
    {"tmk", XOR, "jrb", "z26"},
    {"y27", XOR, "x27", "qdg"},
    {"x44", XOR, "y44", "jfn"},
    {"qns", OR, "rjk", "dhr"},
    {"kdm", XOR, "cgt", "z05"},
    {"kwm", OR, "vsc", "ntj"},
    {"x22", AND, "y22", "bsr"},
    {"cvb", XOR, "dhr", "z40"},
    {"y37", XOR, "x37", "tjm"},
    {"x16", AND, "y16", "mgr"},
    {"rkn", AND, "ssq", "vsc"},
    {"ktt", AND, "rvb", "kmb"},
    {"x10", XOR, "y10", "hcd"},
    {"pmb", XOR, "trw", "z09"},
    {"spj", OR, "gqf", "z37"},
    {"y30", AND, "x30", "bfn"},
    {"x26", AND, "y26", "jjp"},
    {"jrr", XOR, "hjm", "z24"},
    {"jwg", AND, "ckt", "bgs"},
    {"x29", XOR, "y29", "hhm"},
    {"x09", AND, "y09", "fhf"},
    {"dnd", AND, "nqd", "stm"},
};

void collect_wires(const Gates& gates, Values& wires)
{
    wires.clear();
    wires.reserve(3 * gates.size());
    for (const auto& gate: gates)
    {
        wires.try_emplace(gate.in1, -1);
        wires.try_emplace(gate.in2, -1);
        wires.try_emplace(gate.out, -1);
    }
}

uint64_t get_wires_value(const Values& values, char ch)
{
    char label[12];
    char format_str[] = "x%02d";
    format_str[0] = ch;
    uint64_t bit{1};
    uint64_t ret{0};
    for(int n=0;; n++)
    {
        std::sprintf(label, format_str, n);
        if (!values.contains(label)) break;
        if (values.at(label)) ret |= bit;
        bit <<= 1;
    }
    return ret;
}

uint64_t part1(const Values& init_values, Gates& gates, Values& wires)
{
    if (wires.empty()) collect_wires(gates, wires);

    for (const auto& iv: init_values) wires[iv.first] = iv.second;
    for (auto& gate: gates) gate.evaluated = false;

    int n_unknowns;
    do
    {
        n_unknowns = 0;
        for (auto& gate: gates)
        {
            if (gate.evaluated) continue;
            auto v = gate.func(wires[gate.in1], wires[gate.in2]);
            if (v < 0) continue;
            gate.evaluated = true;
            wires[gate.out] = v;
            n_unknowns++;
        }
    } while (n_unknowns > 0);

    return get_wires_value(wires, 'z');
};

bool try_swap(const Values& init_values, Gates& gates, Values& wires, Gates::iterator begin, int depth, uint64_t result)
{
    if (depth > 0)
    {
        for (auto it1 = begin; it1 != gates.end(); it1++)
        {
            if (it1->swapped) continue;
            it1->swapped = true;
            for (auto it2 = it1 + 1; it2 != gates.end(); it2++)
            {
                if (it2->swapped) continue;
                it2->swapped = true;
                auto foo = it1->out;
                it1->out = it2->out;
                it2->out = foo;
                if (try_swap(init_values, gates, wires, it1 + 1, depth - 1, result)) return true;
                it2->out = it1->out;
                it1->out = foo;
                it2->swapped = false;
            }
            it1->swapped = false;
        }
        return false;
    }

    return part1(init_values, gates, wires) == result;
}

void part2(Gates& gates, int depth)
{
    Values wires;
    collect_wires(gates, wires);

    for (auto& gate: gates) gate.evaluated = false;

    Values init_values;
    init_values.reserve(wires.size());
    for (const auto& w: wires)
    {
        if (w.first[0] == 'x' || w.first[0] == 'y')
        {
            init_values.emplace(w.first, std::rand() > RAND_MAX / 2 ? 1 : 0);
        }
    }

    auto x = get_wires_value(init_values, 'x');
    auto y = get_wires_value(init_values, 'y');

    std::cout << x << " + " << y << " = " << (x + y) << std::endl;
    if (!try_swap(init_values, gates, wires, gates.begin(), depth, x + y)) return;
    for (const auto& gate: gates)
    {
        if (!gate.swapped) continue;
        std::cout << gate.out << ",";
    }
    std::cout << "\n";
}

int main()
{
    Values wires;
    std::cout << part1(sample_init_values, sample_gates, wires) << std::endl;
    wires.clear();
    std::cout << part1(problem_init_values, problem_gates, wires) << std::endl;
    // part2(sample_gates2, 2);
    // part2(problem_gates, 4);
    return 0;
}
