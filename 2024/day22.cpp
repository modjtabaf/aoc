
#include <cstdint>
#include <iostream>
#include <vector>
#include <valarray>

using Numbers = std::vector<uint64_t>;

Numbers sample_initial_numbers1{
    1,
    10,
    100,
    2024,
};    

Numbers sample_initial_numbers2{
    1,
    2,
    3,
    2024,
};    

Numbers initial_numbers{
    4832674,
    14802956,
    7210529,
    7709095,
    6063251,
    12294789,
    15666951,
    12074106,
    15427686,
    1214891,
    15165649,
    3609602,
    10200989,
    16451437,
    10915511,
    3479515,
    173864,
    1238342,
    3381843,
    14767788,
    16088065,
    15637051,
    15981887,
    15854806,
    4988920,
    7980791,
    11263142,
    8044640,
    4572291,
    328777,
    11851557,
    13706949,
    16451719,
    15991644,
    14668984,
    8852039,
    1685443,
    13814197,
    14117797,
    6281998,
    12395020,
    1681090,
    16476099,
    2171296,
    10155667,
    15490827,
    6723206,
    7272972,
    1788575,
    2950054,
    10917267,
    6862495,
    8153949,
    16559239,
    8572595,
    1821668,
    3417901,
    11375457,
    3878450,
    10863466,
    10890116,
    13055126,
    7451580,
    5815531,
    8335506,
    431487,
    201975,
    5841753,
    11744013,
    4498615,
    9261071,
    9953929,
    4630027,
    2227105,
    6260342,
    10375281,
    3015284,
    3789175,
    15843612,
    14432075,
    14847622,
    11501912,
    9079366,
    2550341,
    6931972,
    13371306,
    9601571,
    14504463,
    6162939,
    5361897,
    14900517,
    12748562,
    7519640,
    14694035,
    5566950,
    7688680,
    13810532,
    5654369,
    10957671,
    6886767,
    13114128,
    9355299,
    14808826,
    11001280,
    4983663,
    9915373,
    3356476,
    16519750,
    15826279,
    11122172,
    12902904,
    1010762,
    16214923,
    9519057,
    15931832,
    15664252,
    12750269,
    1110882,
    7854151,
    3509827,
    10328167,
    1494530,
    8712493,
    396534,
    15995697,
    7396815,
    3419574,
    14789278,
    14099072,
    15389372,
    6910648,
    649063,
    3609071,
    6004556,
    5054128,
    13730203,
    3554012,
    2766085,
    7133343,
    7566747,
    1194302,
    10446649,
    1529903,
    9036124,
    11725198,
    6479244,
    10287711,
    2219155,
    2360315,
    8169407,
    7841353,
    7486466,
    15297309,
    9336789,
    7225072,
    6248515,
    16154198,
    11100038,
    8584563,
    3753173,
    7371112,
    2481160,
    10954049,
    8009781,
    7381801,
    280810,
    11001420,
    14114713,
    4242475,
    1237360,
    6496866,
    15267044,
    1880781,
    8798544,
    5033766,
    5079684,
    11633848,
    16509688,
    8226900,
    15858455,
    16041151,
    5334220,
    15421957,
    2633967,
    8343560,
    14729378,
    9702409,
    5482505,
    2041087,
    9712582,
    3430735,
    10644043,
    9195957,
    1784419,
    14046333,
    2031279,
    12766582,
    12165573,
    14207224,
    14929506,
    11436548,
    13623882,
    12370036,
    7592923,
    228169,
    8988171,
    6688080,
    5492092,
    8212636,
    3736928,
    15352784,
    2612376,
    14843761,
    12308540,
    8404032,
    11632730,
    4404470,
    2599992,
    6807809,
    12044159,
    9795957,
    5307557,
    13144362,
    13941181,
    9362743,
    4957570,
    9950852,
    4069207,
    699043,
    13667685,
    12869414,
    5834836,
    8434557,
    13512362,
    5446646,
    16663243,
    10059682,
    231185,
    14405863,
    10532295,
    13752653,
    3266523,
    12926376,
    9013886,
    15683001,
    10524950,
    325867,
    15226063,
    15175724,
    15991383,
    13961546,
    15823957,
    9310375,
    5534565,
    2674761,
    13444598,
    9915920,
    1755544,
    1429896,
    14788650,
    5453166,
    10081466,
    2149840,
    16613385,
    2519989,
    7555351,
    7295534,
    12099546,
    3223009,
    2684428,
    8436395,
    5406395,
    836225,
    9962036,
    2847179,
    12880336,
    13215841,
    3498334,
    5985622,
    7700379,
    5785351,
    9938722,
    15810882,
    2349820,
    906893,
    2513825,
    10432278,
    13789913,
    2913486,
    9683268,
    2862417,
    4807276,
    16264545,
    6607564,
    10222512,
    2190055,
    11839341,
    2132714,
    153996,
    10874457,
    12023939,
    7748310,
    13452955,
    3246986,
    2892967,
    9561561,
    3280827,
    991231,
    13105708,
    16641479,
    273523,
    4832864,
    13832855,
    7903624,
    13242917,
    13379831,
    9085055,
    1473661,
    11031255,
    4126827,
    12754058,
    456062,
    14316218,
    6580848,
    11147440,
    1828704,
    15262845,
    557484,
    2406569,
    10393027,
    3363996,
    15821838,
    16365523,
    5566374,
    3723957,
    5186897,
    501767,
    10639559,
    3256585,
    2354615,
    1888438,
    11574106,
    11798800,
    12629659,
    6316600,
    3119025,
    14801938,
    7025953,
    14949782,
    7577552,
    14785389,
    8868837,
    11642113,
    14574465,
    8689963,
    16223594,
    14705685,
    16363438,
    1393194,
    5961465,
    16603208,
    8121071,
    15143692,
    7531645,
    6777163,
    8168251,
    15905711,
    2373414,
    1269213,
    2506356,
    1080789,
    2154403,
    11578189,
    6232867,
    10065427,
    15116084,
    15449140,
    12675436,
    14126594,
    8470014,
    2106625,
    12556109,
    12771090,
    1437370,
    16145074,
    6244539,
    6832665,
    13217078,
    5152936,
    15205635,
    12092447,
    15115231,
    2112929,
    13215959,
    11124896,
    14598714,
    15256810,
    9994507,
    11687859,
    11599901,
    5330801,
    13829820,
    1720133,
    11040068,
    4351948,
    9597919,
    10673331,
    6148104,
    12360792,
    9687192,
    11668420,
    10272257,
    7823976,
    6113203,
    8827921,
    5600165,
    6950138,
    9581746,
    15917691,
    6453798,
    11788226,
    15057269,
    9639028,
    5073513,
    15459362,
    14118507,
    7979569,
    4210224,
    5726357,
    10649449,
    14645020,
    3062620,
    14613306,
    13963982,
    14770179,
    15097265,
    1789308,
    12405157,
    7360698,
    6983540,
    9752726,
    8200080,
    5784060,
    13456865,
    4677699,
    3783161,
    13650051,
    9865655,
    13066800,
    1868022,
    5855823,
    15061710,
    11742417,
    2116233,
    15002417,
    904747,
    9455335,
    5203086,
    704685,
    902384,
    15284593,
    8328120,
    13587250,
    11550241,
    10950646,
    14876694,
    11393724,
    14576237,
    898540,
    8874901,
    5548732,
    11351523,
    2315166,
    9532824,
    11462685,
    1297628,
    3862586,
    16331382,
    9291789,
    2887008,
    2582973,
    4861709,
    15301133,
    8978897,
    533818,
    1565155,
    3829639,
    8438476,
    11901529,
    4287874,
    14934539,
    9009659,
    5258045,
    5532816,
    6947557,
    6589393,
    11253188,
    15784236,
    15013526,
    9885742,
    1528781,
    7841666,
    15896661,
    16158555,
    2925945,
    1483085,
    15134821,
    3942153,
    5632381,
    2313745,
    8933276,
    5029757,
    4451392,
    16329817,
    12711465,
    709033,
    11710003,
    7453681,
    16295691,
    3518608,
    4719562,
    10648147,
    16265294,
    13467919,
    12987827,
    2109938,
    13421963,
    12607493,
    8299846,
    15215804,
    1159601,
    9760167,
    3676111,
    8315807,
    16190054,
    12985094,
    16491047,
    2074887,
    7054808,
    12505505,
    4945186,
    11871596,
    3829532,
    4549220,
    3537316,
    13171724,
    3524750,
    13596281,
    10668191,
    14343317,
    6402806,
    2731753,
    11226897,
    11732551,
    1191547,
    710003,
    13414365,
    576363,
    7246745,
    4697745,
    5229751,
    15600244,
    14301601,
    3338331,
    16298879,
    14384682,
    6408525,
    15280318,
    9688637,
    6355281,
    16349247,
    648523,
    10698883,
    14054926,
    5519674,
    6454510,
    16758075,
    1165069,
    8912920,
    1527251,
    3900136,
    9222613,
    5020511,
    7533824,
    369187,
    13613125,
    11639709,
    7976771,
    14813561,
    15412296,
    2835811,
    4462998,
    2241290,
    12051954,
    10605034,
    4353890,
    2734623,
    14545688,
    15480613,
    13055133,
    1462650,
    11024714,
    7239200,
    12025450,
    3648919,
    15258003,
    8511775,
    2628484,
    9068511,
    3133930,
    7667217,
    11367562,
    5769440,
    15246465,
    5728372,
    13205569,
    15740596,
    3615298,
    14836664,
    9612987,
    14146126,
    11412926,
    14116820,
    1400204,
    10406150,
    6971309,
    903291,
    9299000,
    4087685,
    378819,
    1464323,
    13211780,
    16250732,
    8701210,
    10974400,
    5647208,
    7792973,
    10998483,
    14935593,
    4695854,
    7184396,
    10508479,
    15999407,
    13841017,
    4313497,
    12515047,
    14584250,
    7729382,
    5038544,
    3266225,
    6405834,
    14886277,
    3450766,
    12467989,
    13412140,
    7779145,
    1044577,
    8844258,
    2824239,
    11053451,
    16110836,
    16235669,
    3045420,
    7371691,
    8146436,
    10079833,
    2418199,
    160001,
    561132,
    12409106,
    12963240,
    14793370,
    3213305,
    6476068,
    13951373,
    10435663,
    977728,
    10553719,
    5802826,
    2202759,
    7475575,
    3484651,
    12090825,
    2790915,
    2311979,
    6230998,
    14710715,
    5646359,
    15384797,
    6918017,
    10148160,
    9717763,
    10765309,
    15221937,
    1353815,
    8693803,
    14010936,
    2433658,
    12344531,
    9331857,
    3057518,
    5949739,
    551580,
    9149738,
    6085049,
    2462235,
    9720615,
    8506209,
    16082173,
    14478707,
    8067336,
    1234593,
    8333370,
    6735257,
    13075865,
    1790109,
    8202554,
    2570233,
    6669472,
    10677174,
    10029922,
    13306645,
    4366284,
    12327184,
    10905430,
    12534692,
    16451558,
    16191113,
    11180698,
    2594620,
    1031760,
    10116189,
    9107417,
    4478138,
    12890992,
    9382914,
    16058706,
    13033976,
    532570,
    6065007,
    1758925,
    9694622,
    13520866,
    4878117,
    1658580,
    1362985,
    2979853,
    6543113,
    6192971,
    4432395,
    10005632,
    11506799,
    12524318,
    14388152,
    16762957,
    13123510,
    10011065,
    11800845,
    14015779,
    14745413,
    4124664,
    12983569,
    860822,
    1553891,
    11125149,
    14894924,
    12068277,
    145682,
    13860062,
    10840657,
    4844251,
    11230835,
    3606365,
    6739168,
    744716,
    485125,
    3085261,
    9599535,
    1739488,
    6278559,
    13058502,
    15965025,
    1264711,
    9263388,
    12727451,
    6277623,
    16298515,
    12646234,
    11629245,
    12370509,
    13400955,
    2497125,
    15451127,
    5535629,
    3564115,
    13021730,
    14602737,
    13916550,
    13481950,
    1073185,
    6064803,
    3084774,
    7740853,
    4781678,
    13414375,
    4782841,
    13462333,
    2742972,
    4460813,
    1165272,
    1412276,
    16614042,
    14291783,
    12990013,
    10917857,
    15810868,
    14471906,
    6176449,
    14477252,
    735370,
    13740470,
    6011438,
    5896124,
    3994877,
    6233517,
    8428498,
    16601817,
    3565545,
    16250156,
    6883924,
    7887103,
    1724892,
    1881392,
    4799632,
    10955976,
    3949874,
    4021775,
    15275820,
    3661287,
    402140,
    11767680,
    13712469,
    2037769,
    6622061,
    2097658,
    674305,
    4604149,
    2378461,
    6136466,
    14628435,
    12662229,
    11645902,
    12957327,
    4619923,
    7776847,
    10843330,
    316480,
    4306169,
    14004250,
    10210337,
    4048679,
    11468312,
    3669636,
    890080,
    12887418,
    487725,
    12730943,
    2736687,
    4813757,
    4249829,
    13425273,
    1125022,
    8202412,
    5694789,
    12710976,
    12449804,
    6170358,
    259414,
    5286822,
    6653678,
    8272636,
    3590439,
    16559882,
    9904755,
    3586213,
    7394337,
    6782836,
    7987600,
    4771710,
    14536322,
    6403233,
    4247578,
    4186513,
    7889869,
    14565363,
    8764613,
    811769,
    2319754,
    9067025,
    13469247,
    9782522,
    11290223,
    4661142,
    16317543,
    550481,
    15954977,
    9544850,
    13016120,
    9053085,
    6465114,
    15200584,
    7154435,
    6853955,
    5225177,
    9674475,
    14740819,
    13167524,
    15671279,
    10098048,
    10726650,
    1164927,
    11609277,
    5529492,
    13145560,
    16738384,
    13787197,
    1147040,
    3675949,
    14731711,
    13463633,
    8047484,
    1523058,
    9458636,
    4055447,
    10889810,
    10912856,
    7364610,
    5800364,
    8660235,
    8908488,
    4095217,
    7121098,
    12251427,
    6003079,
    13517173,
    10108697,
    10578504,
    5319077,
    16355939,
    3870510,
    2402583,
    4255698,
    15957051,
    924471,
    8022183,
    375390,
    14873565,
    9076520,
    7448434,
    1494734,
    9977500,
    4743412,
    15614077,
    4517593,
    5220884,
    9343580,
    3516784,
    9537754,
    13915843,
    7796570,
    12834187,
    13172476,
    4576503,
    6765106,
    12545834,
    12148670,
    11426213,
    16098455,
    5922223,
    14609353,
    1802176,
    4687063,
    5427050,
    10460602,
    12024360,
    13949223,
    6873634,
    10860022,
    15915422,
    2108014,
    1664154,
    13010045,
    6267185,
    12828055,
    1121106,
    11508307,
    14307684,
    12998557,
    13581979,
    1169704,
    2117286,
    6987454,
    6591165,
    12255170,
    12321295,
    12592150,
    7618744,
    16591315,
    11481868,
    3139049,
    551402,
    4059153,
    605565,
    576854,
    14286446,
    7302828,
    9128153,
    4426713,
    5540054,
    7754374,
    16175684,
    12396352,
    11863373,
    14114366,
    10779668,
    2057984,
    805363,
    10005594,
    7268579,
    3194303,
    1281447,
    176607,
    13805156,
    12310263,
    8060185,
    5302532,
    4064335,
    7724061,
    1083216,
    1223905,
    10800419,
    8790143,
    9948798,
    10131856,
    1429786,
    12720184,
    2024225,
    8748679,
    8857237,
    5525272,
    9749020,
    8140756,
    14286372,
    11540809,
    15717766,
    3705930,
    14119654,
    14262914,
    1279885,
    9390030,
    2578722,
    15604576,
    14260678,
    5724037,
    6008059,
    10252314,
    2813399,
    13610745,
    10475748,
    3353152,
    3209553,
    6260486,
    11599547,
    13169032,
    3322400,
    5064421,
    10297010,
    12924884,
    689597,
    13935260,
    15350775,
    6929312,
    5326798,
    9932245,
    14829464,
    13765595,
    8720317,
    7816225,
    913011,
    15632871,
    10882048,
    15754686,
    10462716,
    5673981,
    10449099,
    1042199,
    5911880,
    8826017,
    1055220,
    1970025,
    13183850,
    11621620,
    8403131,
    14882151,
    8937760,
    7846115,
    5417274,
    12844293,
    13691351,
    16361210,
    932856,
    357690,
    10309255,
    9640835,
    13599304,
    1291513,
    3941204,
    8126745,
    9525924,
    4993426,
    16647884,
    14934363,
    10922331,
    16436026,
    712306,
    5759137,
    2958432,
    875672,
    7874470,
    13723859,
    10085160,
    3208446,
    1041736,
    14144344,
    13842404,
    12992575,
    5568816,
    7324169,
    15805022,
    5990412,
    3109998,
    13882524,
    11364673,
    2692920,
    7139674,
    476312,
    16289888,
    10949752,
    5091018,
    7046950,
    10736871,
    14310857,
    16100195,
    11948894,
    11556693,
    15848730,
    2697860,
    9494163,
    2691397,
    5623704,
    3674505,
    11561012,
    13588199,
    4812944,
    10853134,
    1082718,
    4369465,
    16006382,
    12295801,
    11424504,
    3666120,
    7614979,
    2800524,
    1947005,
    3017979,
    2598786,
    9450408,
    4397289,
    7929187,
    7995035,
    6958207,
    3101520,
    16625377,
    4754522,
    1050919,
    856746,
    4205773,
    14424526,
    12973840,
    7857149,
    16675983,
    3663298,
    4502295,
    1820909,
    16014168,
    5458029,
    11065295,
    5861880,
    11833076,
    4408831,
    8855635,
    10133794,
    3034329,
    7581616,
    9130574,
    1940444,
    13573815,
    4026536,
    15388015,
    6597916,
    992531,
    9022219,
    4775532,
    8839995,
    9654877,
    527949,
    6172323,
    3596833,
    1951557,
    5562660,
    1785774,
    2153115,
    10571484,
    13532012,
    13077194,
    2596156,
    10553939,
    16719275,
    2967167,
    10685255,
    7515104,
    9455931,
    6826240,
    5942356,
    549521,
    713568,
    16374459,
    10638621,
    3520627,
    2739300,
    9554441,
    2364640,
    8734111,
    1459995,
    13647447,
    4858892,
    3938386,
    7736108,
    7990805,
    8356537,
    9773146,
    15561244,
    10155657,
    2236520,
    10130839,
    7832090,
    4153094,
    5155549,
    12204638,
    1648496,
    14793038,
    14153923,
    2178574,
    7769006,
    6479555,
    12058536,
    6903308,
    5559734,
    4070556,
    6655355,
    5246677,
    8174892,
    766155,
    16569690,
    14040993,
    7674903,
    12227631,
    4202393,
    10849436,
    3817484,
    14941581,
    4622185,
    16175431,
    11744942,
    12945983,
    1650246,
    373296,
    10163476,
    4965815,
    2183288,
    14431656,
    8225853,
    13700868,
    2975593,
    12491412,
    16008121,
    5718783,
    1529965,
    4023808,
    5457011,
    10795609,
    4553134,
    7419748,
    9452986,
    14101409,
    1244559,
    15860765,
    15190923,
    8186475,
    8368018,
    8339386,
    14693529,
    13915401,
    6590227,
    14533722,
    3388822,
    5671353,
    4588720,
    13651800,
    7193578,
    961007,
    14782730,
    10919686,
    6627646,
    10286682,
    2547686,
    2025803,
    11086105,
    2838357,
    15348500,
    9368629,
    3319620,
    3048405,
    15124122,
    15776971,
    10372761,
    12266409,
    2417873,
    11710583,
    14393748,
    745570,
    13055661,
    5514891,
    4974118,
    14666385,
    6677619,
    12538998,
    10838566,
    7104009,
    13131359,
    15430718,
    463622,
    8048512,
    10044757,
    7505134,
    4601747,
    14389087,
    14983876,
    4909957,
    522999,
    1429689,
    5062172,
    15956997,
    15370895,
    13657929,
    3395324,
    15663373,
    8554931,
    4295632,
    5279533,
    7821428,
    2227496,
    15063723,
    5398483,
    11044871,
    5695668,
    650320,
    623622,
    4774537,
    11026954,
    2642505,
    16361725,
    12250570,
    6500916,
    3429528,
    488267,
    15966834,
    16474012,
    322247,
    2722455,
    7655632,
    1571826,
    9109654,
    832254,
    16217813,
    12140603,
    8716322,
    2496275,
    11103687,
    10281945,
    340333,
    15316946,
    15302197,
    10145381,
    397686,
    10937163,
    13596926,
    5176836,
    11016373,
    9275388,
    16623887,
    878874,
    3228016,
    6341579,
    7341533,
    13560110,
    6304095,
    772983,
    4705853,
    10631752,
    6383444,
    9270308,
    13638061,
    4023339,
    5102566,
    13997339,
    1453715,
    14804611,
    7390173,
    8851023,
    15561321,
    6128724,
    3975902,
    885123,
    7354416,
    14822108,
    16514280,
    15552999,
    15918546,
    10822298,
    12506252,
    5503520,
    11433352,
    3820323,
    11731508,
    12616785,
    11962501,
    3193389,
    505232,
    16469099,
    14391186,
    10268765,
    10743080,
    9251988,
    15566926,
    8243537,
    1521741,
    15390371,
    11828785,
    5620923,
    13487327,
    16586491,
    2707571,
    15583852,
    412707,
    5164287,
    12322096,
    6289373,
    892793,
    3728943,
    14363189,
    7213267,
    2383641,
    4262853,
    2174965,
    11068341,
    5011685,
    13762823,
    4265794,
    11680366,
    7013398,
    6622254,
    14094660,
    6145991,
    8193830,
    12117404,
    794450,
    13597871,
    6919991,
    14377862,
    12156960,
    10354206,
    148311,
    16372712,
    8631727,
    9230583,
    15518073,
    3028333,
    1330766,
    5417665,
    7286351,
    4938640,
    15415009,
    1915369,
    1147960,
    7844785,
    9717849,
    15840235,
    6551365,
    631302,
    10471994,
    6594754,
    15043753,
    11544485,
    5622448,
    5967585,
    13097551,
    11677608,
    14429824,
    15523636,
    308980,
    13898334,
    1321680,
    11442846,
    5923862,
    310301,
    10953841,
    16441318,
    4280316,
    10531530,
    11638512,
    5775162,
    8427418,
    6671235,
    14304601,
    865542,
    9940084,
    14397965,
    9200173,
    15636030,
    8303209,
    16512940,
    401275,
    2984474,
    13075307,
    4708352,
    1504961,
    12295621,
    13499160,
    6191626,
    5598597,
    2927492,
    7201237,
    16284506,
    14080807,
    16508331,
    992618,
    14480511,
    9316816,
    10755021,
    9837624,
    5890646,
    14637760,
    14648220,
    3630832,
    8753340,
    10623395,
    4891720,
    7547687,
    14809674,
    5993955,
    7563337,
    16406164,
    16078672,
    5191732,
    11334675,
    11622017,
    9743909,
    1491172,
    3911061,
    1253583,
    14096676,
    14492845,
    14169598,
    3013442,
    4961581,
};

uint64_t generate_number(uint64_t number)
{
    // To mix a value into the secret number, calculate the bitwise XOR of the given value and the secret number. Then, the secret number becomes the result of that operation. (If the secret number is 42 and you were to mix 15 into the secret number, the secret number would become 37.)
    auto mix = [](uint64_t n1, uint64_t n2) -> uint64_t
    {
        return n1 ^ n2;
    };

    // To prune the secret number, calculate the value of the secret number modulo 16777216. Then, the secret number becomes the result of that operation. (If the secret number is 100000000 and you were to prune the secret number, the secret number would become 16113920.)
    auto prune = [](uint64_t n) -> uint64_t
    {
        return n & 0xffffff;
    };

    // Calculate the result of multiplying the secret number by 64. Then, mix this result into the secret number. Finally, prune the secret number.
    number = prune(mix(number, number << 6));
    // std::cout << number << "\n";

    // Calculate the result of dividing the secret number by 32. Round the result down to the nearest integer. Then, mix this result into the secret number. Finally, prune the secret number.
    number = prune(mix(number, number >> 5));
    // std::cout << number << "\n";

    // Calculate the result of multiplying the secret number by 2048. Then, mix this result into the secret number. Finally, prune the secret number.
    number = prune(mix(number, number << 11));

    return number;
}

uint64_t part1(const Numbers& initial_numbers)
{
    uint64_t ret{0};
    for (auto n: initial_numbers)
    {
        for (int k=0; k < 2000; k++) n = generate_number(n);
        ret += n;
    }
    return ret;
}

uint64_t part2(const Numbers& initial_numbers)
{
    std::valarray<int> sum_prices(0, 19 * 19 * 19 * 19);
    std::valarray<int> prices(0, 19 * 19 * 19 * 19);

    int v0, v1, v2, v3;
    for (auto n: initial_numbers)
    {
        v0 = n % 10;
        n = generate_number(n);
        v1 = n % 10;
        n = generate_number(n);
        v2 = n % 10;
        n = generate_number(n);
        v3 = n % 10;

        prices = -1;

        for (int k=4; k < 2000; k++)
        {
            n = generate_number(n);
            int v4 = n % 10;

            int ind = (v4 - v3 + 9) + 19 * ((v3 - v2 + 9) + 19 * ((v2 - v1 + 9) + 19 * (v1 - v0 + 9)));

            v0 = v1;
            v1 = v2;
            v2 = v3;
            v3 = v4;

            auto& price = prices[ind];
            if (price < 0) price = v4;
        }

        for (auto& price: prices) if (price < 0) price = 0;

        sum_prices += prices;
    }

    return sum_prices.max();
}

int main()
{
    std::cout << part1(sample_initial_numbers1) << std::endl;
    std::cout << part1(initial_numbers) << std::endl;
    std::cout << part2(sample_initial_numbers2) << std::endl;
    std::cout << part2(initial_numbers) << std::endl;
    return 0;
}
