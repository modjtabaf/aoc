
#include <cstdio>
#include <cstring>
#include <iostream>

const char* sample_memory1 = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";
const char* sample_memory2 = "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))";

const char* memory =
    "^+'*>,,why()mul(229,919)&$-#^~mul(187,600)@<select()mul(430,339)<)*/"
    "-when()%mul(248,922)~+when()<do()^}%where()@select() "
    "what()why()who(809,724)mul(617,192)$*from()what(168,899)mul(333,411)()$select(){+how()%mul(284,904)when();who()"
    "mul(218,212)>[#' "
    "*+&mul(388,743):~^&;do()when()&^&^mul(415,678)>what(180,378)when()/"
    ")!#how()~&do()(((]how()[~{;what()mul(792,328)[;(,why()#mul(767,729)(what()@-why()}who()how()where(373,159),mul(91,"
    "503)select()~;where()@+;;++don't()mul(766,411)~'&%what(217,603)>why()mul(528,603);how() "
    "&who()mul(418,950)-select()mul(440,425)mul(42,798):what()[^%mul(28,566)from()<%>]//"
    "(<mul(167,358)'%](#mul(77,714)mul(748,367)]*mul(124,693);where(156,464)^(^[what()why();do()<>*mul(121,164)+/)@}/"
    "why()([mul(94,107)where()why()$what()} "
    "~when()who()when()mul(51,763)&:$)mul(117,974)*%?]%;who()>mul(224,518)@/"
    "<*,}mul(681,258)(%{#select()&*who()where()mul(301,302) "
    "don't()who()][!from()>mul(410,170)do())what()##mul(873,748)$~}mul(797,721):when()how()[:-where()>mul(959,163)mul("
    "992,12)%/"
    ")$why()*mul(141,535)how()mul(681,821)'&how()],mul(123,886)+#don't(),>[mul(119,227)>!@*when(720,847)%where()+what()"
    "mul(525,607)*+&mul(918,604)where()'$]>mul(138,66),';@!where()mul(251,314)[;/"
    "do()who()mul(843,719)?mul(193,439)why()/;don't()/"
    "::mul(677,473)($*[@mul(729,623)~+from(),(how();when()mul(496,695)+):mul(403,498)mul(723,890)#from()when()*why(153,"
    "516))why(364,80)who()+!mul(723,971)mul(805,935)#$@+!{@#mul(110,950){mul(161,461)~*/;,/"
    "mul(115,959)}:how()':,@'what()mul(816,844)mul(568,840)?do()[,how()*mul(601,790)where()select()#+select()why()mul("
    "27,586)(}how(570,902);where()?+]-mul(425,554);how(812,935)where(),what()%&^mul(623,585)@ "
    "why()mul(995,90)#+%'do()>~#}what()mul(374,323)mul(249,230)~,>+select()when())mul(741,526)%{{mul(373,937)when()mul("
    "523,799)mul(438,812)how()~}<{select()where()(]who()mul(774,128)what()}:$!$%where()>(mul(376,393)+where()(&)*[how()"
    "!mul(388,253)#-when()#>$,@ mul(37,722)how()mul(272,60)~@&%</mul(301,857){[!],]<']mul(536,697);-> "
    "why()}mul(806,354);}where()how() ^mul(707,617)*when()*[{$where(191,569)]when()mul(475,36)'what();-] "
    "mul(409,381)select() "
    "do()};mul(106,765)@mul(962,693)select()@+where()how()select()%[mul(594<&(mul(838,166)]from()[,how()};>[,mul(407,"
    "924)mul(305,306)'+,]mul(755,425),)don't()mul(119,487):mul(143,902)-{'from()*,>,>@mul(378,307)%,mul(204,648)(:mul("
    "812,89)$*+*,##mul(397how()[]@mul(593,676)&#why()what():mul(561,33)*do()$}''!$)>who(955,135)mul(428,61) "
    "what()@!from()[+:<mul(116,657)%mul(243,605)who()('%how():[!where()mul(85,278)''where()}$select()<$mul(421,930)"
    "where(){^]mul-mul(325,145)from()#>:where())mul(242,136){why()<when()mul(223,291)#^what(310,803)mul(280,922) "
    "select()what()}:%why()from()when()mul(136,869)what()@%@@{what()#how()from()don't(),!+who()-#>!how()why()mul(789,"
    "485)':mul(950,684)-mul(734,60)!+'where()(mul(897,715)why()(?mul(344,613)mul(945}/"
    "[$mul(354,310)why():*!mul(162,884)when()why()-*}<)%mul(999,479)%how()^<who()~how())mul(801,769)?when()do()#what()-"
    "&&*< "
    "*+mul(859,153)^-^mul(968,909)?how()when()why()from()$/"
    "from()who()why()mul(164,591)how()@+*!how()from()mul(198,449)#from()&]>?[mul(549,221)?mul(10,487)mul(473,495):from("
    "):how()+@mul(409,356)@where(424,972)mul(245,522),^mul(830,352)^['select()+?mul(348,779)^)where()+ "
    "{select()mul(631,610)from():+!mul(364,859)from()+,what()-/*who()$mul(381,350)"
    "select()#'mul$%({]!how()^mul(832,589)' "
    "(>?{:when()}mul(558!&mul(315,787)what()[when()mul(331,479)^#<:^!when()<do()'%-&mul(693,126);%< "
    "%mul(969,600)how()%/"
    "mul(214,616)~+%+,&^}who(){mul(855,428)$how():^mul(334,489)who()'select())when()<mul(110,881)'? ?where()})# "
    "mul(138,273),,mul(89,161 "
    ",mul(749,786));}where()*<$'mul(179,995)mul(933]from()++@where()mul(475,52)$;what()why()?why()how())mul(75,799) "
    "from()^select() "
    "$*mul(700,332)((;&!+who()mul(942,3)from())what()!}]who()mul(987,195)&}mul(901,207))mul(887,450)mul(302,276)>mul("
    "705,411)from() :from()/*}{mul(173,420(~]#mul(812,264)why()mul(170,516)!#:;mul(115[mul(41,851) "
    "%when()?)<!what(481,876)mul(10,905)*from()mul(479,534)when():mul(251,951)+#':why()'+from()when()mul(143,289)<>"
    "select()}who()mul(766,808)when()mul(358,761){where()'when()}[$;^'mul(170,223)who()who()mul(990,347)<?///"
    ";{mul(346,803)when(925,701)where()who()%mul(972,647)mul(305%when()mul(113,574)?:+,:+!{mul[>))}^[[?select()}mul("
    "540,811)%mul(384,379))*+ "
    "who()&from()>)don't()why()!(mul(443,371)when())??do()&'!&mul(836,469)+},)mul(661who()'select()~<?mul(888,841)"
    "select()mul(696,36)!-why()}where()who()mul(458,301)where(){'^,when()[}how()mul(575,266)+]why();;)}mul(731,33)what("
    "),$^mul(53,430)@(mul?,mul(586,117)~![~:@select()'from()mul(229,295)*do()mul(993,128)*%mul(853,954)from():-why()#("
    "mul(941,420)!select(984,864)who()+what()how()-{mul!select()*'+@mul(537,993) "
    "@from()?%@>%why()do()mul(794,923)!select()@!'mul(805,982)!~)from()mul(388,599~who()):mul(638,751)(>'mul(443,735)"
    "how()select(){)what()%do()when()) "
    "what())mul(272,487),#select(),when()do()][]what()}%mul(28,452)mul(178,145)mul(396,673)};%^@where()why()mul(648,"
    "926)^do()why()select()where(245,854)from()^&;mul(960-<mul(340,339)+<mul(358,858)}why(817,557)when(305,30)^*mul("
    "642,325)from()^#&;select()}~#select()mul(532,676);do()'select()what(99,23)'select()<mul(162,432)(#where()when(286,"
    "141)mul~where()from(),mul(747,115)~mul(525,823)&how()where(),select()when(455,325)-+<mul(314,239{[<~:}%mul(541,"
    "522)<,-/:who()[*mul(6,198)[select(589,841)-when()mul(677,201)){-when()%don't()how();from()mul(814,453)-,}^^{/"
    "mul(94,604)/"
    ">what(446,263)mul(810,6)*>)#@<what()mul(21,433)select()#:+~?who(448,713)mul(126,405)select()select()-what();~"
    "where()}mul(507,6)mul(450,464)[&([mul(838,970):?where()select()from();[!~/"
    "mul(781,815),;^~:how()%}don't()when()>&mul(211,423when()mul(937,149)*from(288,317)mul(103,75)/'!:& "
    "mul(788,232)what()mul(52,428)from()?what()*{@:(why()why()mul(195,781)*]]$who()>don't() "
    "/how();'mul(610,736)mul(852,398)mul(690,890)(]~~mul(905,20)*<what() "
    "'@'@*)mul(313,797)when()mul(87,940)when()<;@'&}#&/mul(494,222)?#/+$where(742,449)who()/"
    "~mul(773,971),(^mul(4,95)where(289,324)'%&~mul(828,517)<!(from()' :?mul(126,975)mul(874,818) "
    "&,;who()'+who(902,587)+mul(382,802):[what()when()mul(167,696)>how()@ "
    "*}%]don't()%when()++,^how()mul(630,398)[select()who():?(how()*&mul(344,752)don't()+{#%?select())^mul-&what()mul("
    "651,800)}'[,(mul(528,222)[where()~/mul(341,14)what()}[when()%!what()mul(781,771);/"
    ":why()^%mul(609,662)who(),{+&mul(412,515)/~don't()?+ :@?} "
    "mul(453/"
    "^mul(581,391)select()from()(mul(896when()from()from()#{!mul(953,253)!select()~?&from()mul(656,409)how()who()~when("
    ")@''$!mul(139,643)how(776,270)from()[&<'mul};!{how()'!mul(534,208)why()do()-$*how()where()^when()!mul(421,915)who("
    ")~#+mul(143,731)don't()-/-,>mul(637,233)-mul(730,106)$mul(416,413)@^;~> "
    "what()~mul(382,92)}&)when()how()mul(127,684)}':how()where()mul(20,220)~how()select()}when():* "
    "mul(243,419)mul(352,910)#who()&#when()do()when()'!^#why()!@>mul(695,556)>who()<what()!!@mul(870,233)from()]@@@:"
    "mul(90,29)^ @why(),[@<!#mul(667,307@mul(880,98)"
    "mul(64,639)why()?<*%mul(244,640)+what()+mul(262,110)select()+what()from()%mul(733,807)select()~who()how()&select()"
    "where();/"
    "%mul(210,195)when()>*mul(397,920)}who()(;[##do()~mul(773,279)*}where()%}~*mul(643,570){mul(105,506)$~who()~^@don'"
    "t()select()(%(;^:mul(229,887)@#''[how()mul(788,362)>(@mul(723,439)-where()where()what()from()?~~mul(843,893)mul("
    "474,427)why():];(do(),{'!^(mul(15,142)mul(876,153),,-$?select();[{mul(664,520)-where())where()}@&?where()mul(785,"
    "595)from()when()>:mul(888,328)~(select()>how()?what()mul(633,692)mul(173,839)'mul(204,278)!+~,(~@mul(451,395)mul("
    "785,151):where()]~^(when()from()do()who()mul(790,654)'&>where()when(710,794)from(47,899) "
    "who()&mul(806,984)@where(65,953)@!-#what()/"
    "who(634,853)+mul(861,224)[()who()!~mul(899,370)mul(549,105)%(-why()'~mul(725,344)]mul(41,164)?,*^@ "
    "}):mul(955,760)]>?from()>+-mul(827,250-mul(50,448)&&mul "
    "$>mul(315,814)&mul(194,503)>how()%/who()who():/>@mul(223,541)from()(//what()*what() "
    "mul(364,778)why()?/"
    "$mul(47,912)from();why()how()from()when()mul>where(){mul(693,8)',;where();:mul(528,520)~}+&**:who()mul(401,20)["
    "mul(274,431)from()where()what()select(930,392)' "
    "^mul(733,66)mul(463,265)why()>from()who(553,550)why()^%&mul(225,388)'!#!@mul(593,40)/@@!*,mul(773,292))$/"
    "%where()@*^from()mul(910,722)mul(983,696)where()^^~why()-what()where()don't()!{;what():mul(216,52))}#mul(105,130) "
    "~when()>+#, "
    "~mul(26,766)([?+!mul(178,420)**mul(317,607)where()how()[mul(654,90),mul(931,884)#why()/"
    "when(){mul>^?!mul(298,763)%mul(355,538)]mul(43,357)mul(810,34)from()why()}select()'mul(33,953){mul(459,607)what()~"
    "]$why(30,320)mul(266,245)[why()-@who()$}{mul(322,346)$!)/"
    "mul(418,539)mul(678,561)mul(800,662)from()-];?where()when()^mul(648,356)->@}(mul(891,938)mul'&#(*from(265,14)mul("
    "707,267)#&mul%+>#~%mul(50,976)  "
    "^%(where()!why(315,655)'from()mul(33,958]<{'mul(927,525),>when(597,620)#mul(365,283)>{# "
    "!,who()what(730,791)don't()')mul(2,790):how()~/*;who()mulwho()^&]%+{/%/mul(884,224)where() "
    "&who(837,688)?where(),['&don't()^>{?)/,]!&mul'<?@who()mul(719,571)&<how()when()-why()mul(56,936when()> select() "
    "(:*mul(113,260)what()*%;where()mul(614,724)%mul(718,620)>-~{}why()]mul(416,163):/{ what()where(913,318) "
    "!mul(205,361)mul(412,549)[[who()('}why()why()[how(530,659)mul(721,436)]what() "
    "@**mul(573,713)&}%@mul(201,630);;do()#select(),what()mul(448,64) "
    "%who()^@$mul(679,387)where()]>)!-mul(486,701)who(996,660)?mul(559,794)mul(627,726)what(){;how(){mul(550,422)"
    "select()why()#^<why()~mul(500,999)what()when()<why()##]*where()%mul(890,188)%%:mul(669,810)^: "
    "mul(760,372)when()*#'(}how()mul(141,133)>]mul(339,807)!]why() "
    "<what()?,:-mul(414why()<%{from()-'-mul(243,407)!why()when()(@( "
    "mul(741,399)(#)-!~?;mul(457,257):why()mul(471,231)#why()<mul(641,452)[)don't()when()~]mul(73,976):+where()^,,'mul("
    "705,884)#^~where()mul(290,778)-mul(516,908+<}:,) "
    "mul(671,324)how()%mul(257,809)(?$what()[*mul(668,794),who(776,745)*@',who()?'-mul(432,410)?,]!%$&/"
    "'^mul(228,972),mul(514,675)+how()/ "
    "mul(378,242)mul(319,946)-mul(503,990)<}!?[(mul(914,201@mul(398,34))'mul(811,158)how()> "
    "%<+$mul(662,33){^~what()^?$> "
    ",mul(148,900))*~mul(60,504)-/(/who()+/"
    "mul(44,663)#!&$'}]how():%mul(285,731)]}]when()select(525,368)mul(268,251){;^select()mul(478,141%>}who()how()<<-+})"
    "mul(653,304)[#$)#!/usr/bin/perl~mul(445,156)?,what()'mul(57,772)"
    "mul(155,845)<@-<),#!&mul(408+#/"
    "+select()select(589,946)why()select()when()$^mul(126,507):^mul(59,335)*}why()?>+'when()!mul(448,637)(+;from()mul("
    "100,753)why(274,266)mul(383,541)!-mul(858,418)*mul(632,981)what()]?when()~/'why()!when()mul(964,498),/"
    "mul(763,71)why(391,517)(where()what()}mul(465,534)select():'[';/^^/mul(440when()*]( 'why() "
    "&^)mul(532,924)((-,&why();)where()-mul(123,757)#}!)'mul(263,796){&;:when()),: }mul(530,962)( "
    "'/"
    "+mul(353,976)!>-~}*where()%mul(579,525)>mul(623,336)^']~:~$don't()when();where()%when()(')}mul(731,106)when()from("
    "),from()how()/}(#when()mul(73,364(when()$/-mul(74,496)from()mul(411,383)+])%from(803,142)/"
    "][(mul(500,546),)-@mul(981'do()where()mul(756,84)!]what()what()@>]select(374,28)!+mul(767,508)don't()&;:where()"
    "mul(587,258)&mul(254,192)!mul(80,230)* "
    ":+$?/what(){;mul(187,528)from();-;$[>when()&mul(816,345)?(&why();{mul(497^select(912,851)((}%!mul(39,99)/<#;[*{~/"
    "&mul(678,429(*#@&mul(769,236)%~mul(23,229)$>&&from()$-#mul(619,573)%}[where()+mul(981,353)@why()what()when()what()"
    ",mul(482,105)from()who()from(){from(590,820)mul(269,29)+}<@why()where()?how()mul(123,830)} "
    "mul(589,571)what()from(),where()) mul(971,260)?why()when()<+from()( "
    ">mul(663,513)*how()%where(){:{who()why()mul(691,983)'#mul(465,961)mul(231,307)}*>:-*mul(511,596)what(){$$,(why()$%"
    "(mul(694,486)-[!;-]**mul(606*{select()+ "
    "{)';-mul(769,112)how();{?mul(281,824)-(}%from()!mul(557,222),@&>who()#mul(965,925){when(),}: "
    "mul(72,17),mul(366,881)$who()~(why(),-@select()mul(816,410)?how(191,3) $what(){/~what()who()mul(392,824) / "
    "@mul(744,684)}who()'{mul(808,581)where()mul(580,161)!*mul(517,629):@$what()what()when()select()mul(252,204)~] "
    "!who()-from()(mul)>[)mul(915,708)~{from(),mul(244,280)}@[^/@mul(127,150)]^mul(189,40)from()^?mul(631,283)' "
    "!-what(),#select()mul(242,34)how():+how()mul(625,833)~~mul(570,337)'how()!mul(827,377)>select():}'(&+mul(175,219)"
    "select()<{+{{$mul(96,718) "
    ">,;{from()^mul*#/]@from()'>]}%mul(602,848)/"
    "~)where();#mul(844,941)$:<]!mul(192,246)^!&what()mul(876,655)*select()&who() "
    "-mul(711-$when()>where()from()*@how())from()mul(202,362)what(){,@]/"
    "!%mul(812,546)!how())do()&^-~mul(937,389):';'~what()mul(7,641)from(825,618)what() "
    "')~mul(604,895)when()#$~mul(762,876)~+!@+mul(953,72)@}mul(771,143)from()/"
    "+,')do()why():mul(127,841)~+why()mul(324,780)*what()~from()()%+select(19,530)where(567,447)don't()mul(330,681)^ "
    "what()#how()when()$!mul(624,186) "
    "mul(57,174)~mul(825,181)-'mul(560,884)-]mul(524,985)[:select(962,509)mul(781,265)+;!&#&/"
    "select()mul(533,308)#@where(472,118),/"
    "what()>,what()mul(327,56);where()+what()}what(),mul(422,317)mul(777,506)from()what(649,57)mul#?)['()/"
    "from()don't()$from()?(who()mul(64,560)who()mul(329,383)!where()?mul(859,391)/"
    "-}from()%#!where()'mul(144,512)*from()how()mul(875,781)^>{how()from()where()@who()+]mul(669,466)%;$where()select()"
    "mul(941,765)mul(421,766)mul(728,922)>mul(387,851)#~;? {: mul^??^/why()why() "
    "mul(870,458):,who()?<mul(130,181)/"
    "[@{(;~why()mul(693,900)why()$when()&when()how()why()(>mul(335,421)when(730,409)select()+)+mul(186,867)?$&''who()%#"
    "^mul(907,175)][don't()]what()@select()!'why()[where()?mul(475,57)mul(107,393)who()*[>>$why()~mul(620,425)]>mul("
    "818,900)do()when() "
    "}:$*where()mul(790,845)why()why()'^~who()/~@/mul(181,583)what(182,109)}how()^{#;mul(532,225),/"
    "&)mul(510,91)+how()[}#&]&)mul(193,421);$[/"
    "~mul(421,747)why()%;mul(542,99)-from()where()from()from(){+mul(200,487):'^*,&$from()>mul(689,957)$]${*}where()mul("
    "12,272)*{from(275,255)~who()*-%how()mul(501,743)"
    "[^what()-select()mul(455,700),mul(39,833)?+mul(804,222) "
    "from()who()mul(45,702)[when()#don't()}}where()(#}#from()]mul(584--'-^#<why()->mul(858,680):)>&$}^what()mul(645,"
    "272){where():}&mul(313,324)what()who():!who()select()?mul(401,708),mul(656,174)why()?~)mul(679,594) "
    "where()#*,:from()!mul(45,422)~+ "
    ">~mul<:-/"
    "$$from(630,159)+<#do()])%how()^:?@]]mul(342,700)[[from()select()mul(333,963)!%$<:-^mulwhat()mul(947,945)!select("
    "726,266)when()why()}&mul(494,61)<'why()mul(605,463^who()when(){?why(520,809)^where()>)^mul(842,681)how()how()[/"
    "^$&mul(535,168)@what()from()where()from()+[mul(926,493)/'<mul(150,741)+[when()select()<!%^ "
    "mul(56,868)how()]mul#^what() [++who()mul(747,999)from() "
    "when()>/mul(175,156)mul(884,607)};#mul(998,216)mul(279,631@($(';++what()&don't():^:why()+when(391,664)/"
    "[{-mul(693,809)@)~/^>,#what()mul(942,229))/*{/^why()from()-}mul(653,168)do()who()+ "
    "mul(849,72)?,@when()!what()<mul(186,911),how()*-~what()mul(679,485)what()from()/"
    "?;^:mul(426,354)?[)*$;(what()mul(287,918)>]~when()when()how()%mul(449,449)#^;{$(where()mul(24,301)~]]!!#mul(753,"
    "855)'#$don't()~where()who()mul(26,763)'!#where(430,52)what()where()<!mul(21,581)'>]!*/;mul(20,683)~mul(471,401)  "
    "$+](who()^;mul&*} "
    ")>mul(120,505)where()when()^~mul(586,106)/"
    "#<}+'}mul(56,277)<what()do()]%where()*(!->%mul(944,864)>#^^!,select():!mul(5,629)(&{*;^@select())mul(544,161)how()"
    "/from()> ,~mul(531,531$^mul(693,695)where()#, +[mul(201,445) "
    "<:[$select()why()-mul(65,416)#-&(/"
    "mul(632,729)&#^+mul(18,292)mul(87,905)[do()from()<^why()what()(mul(292,732){}how(),why(302,606)]($%mul(577,286)--"
    "who()'from()^#,-where()do(),?>from()@@ "
    "%what()>mul(62,435)^:!^where(530,516)*(mul(605,627<who()why()select())[))*why()$mul(298,421)}/"
    "%%how()who()mul(593,593)-how():from()mul(826,174) "
    "what(){what()who(848,124)from();from()/"
    "mul(128,77)[{*!,!how()mul(576,352)]#;how())from()%mul(288,458)#![{%:#mul(39,137)^#/"
    "$<[mul(168,86~*>^&mul(638,58)@*,when()]*mul],;]-:*?mul(605,171)?>/"
    "select(449,616),-#[[+mul(178,672)*)#select(),mul'*+when(608,345)mul(671,276) "
    "'#where()*don't()]where()<;%select()select()[;/mul(653,417)>where();-}${->mul(3,376)!how()what(204,543)why() "
    "}:mul(531,438)?$!#select()from()*select()mul(482,192):* ^$mul(521,492) &mul(376,921);what() '*who()mul(631,117) "
    "who()select()#>select()]mul(665,901)when()*mul(787,27)/"
    ":where(356,180)from()mul(942,346)who()(mul(946,745)what()%who(){from()mul(166,509){:$who(58,738)]$&~when()select()"
    "mul(233,332)[]<;mul(831,96)how()[/"
    "((%mul(996,261)]?)):mul(581,265:!-why(796,972)^mul(921,535)why(),;[why()$mul(202,157when()!from()what(607,94)%"
    "from()from()what()+~$mul(578,993)@@ "
    ",how()mul(224,265)mul(818,106)$:]&,>who(156,132)mul(828,230)+>from()<)who()^who()*:mul(633,389)who();from():&$mul("
    "337why()*&<how()]!:$%don't()from() "
    ">)mul(148,542)(who()who()?mul(58,849)')***mul(138,264)mul(656,693)<don't()mul(569,843)'mul(801,506)why()(}when()["
    "why()when()'$mul(939,273)select()when()-%how() "
    "mul(987,122))when()what()']'mul(759,278)&@+)what()]^mul(252,967}!?'*]+<@;do()when()>mul(292,571)#from()!mul(854,"
    "593)*!mul(93,255)/"
    "<why(36,40)#@+:;]mul(139,648)#$mul(805,139)+<^what()~]don't()when(),why()?mul(458,17)how(183,678)~mul(931,326]&[+"
    "why() "
    "+?mul(844,128)how()what()select()<mul(327,739)+&mul(860,80)(what():,<who(373,509)^when()?select()mul(252,542)$ "
    "who()}mul(253,232)/mul(988,240)/"
    "#)?when()#how()}mul(141,538)]don't()>from():;:,?mul(938,2)$mul(882,42)who()mul(535^[mul(662,987)(^mul(86,164)*/$/"
    "mul(218,726)+-[where(119,390)^$mul(388,958)<#from()why()+select()#>%mul(24,167),mul(759,582)&$why()%mul(45,313)}-~"
    "&]how()when()from()mul(396,35)why()@+@where()mul(854,611):[mul(43,673)*what()@why()mul(914,638)--why()*mul(428,"
    "597)mul(478,658)(%mul(515,571)from()$select(),why(905,38)do()mul(892,588)"
    " (mul(4,214)?}{},<mul(802,248)from()-from()when()~where(384,668)>%don't():mul(6,78)% "
    ")from()mul(682,475)^;~%:mul(87,597)(mul(944,631)mul(976,495)[(%#mul(221,797)]from())mul(871,394),^don't()mul(808,"
    "119)why()&<mul(776,592)don't()'$?#-%@mul(423,83))]> "
    "mul)mul(459,746)from():(<when()%/mul(16,981),#}mul(372,418)~/~how()why()mul(408,215))/((>~what(),mul(961,433)/"
    "{when()^ "
    "?*{[mul(687,148)where()#mul(793,57)mul(791,305>where()~(/"
    "mul(416,515)what(562,107)$%~mul(578,152)select()'<select(725,318)(don't()who()/"
    "mul(44,687)?select()}+>*{select()~from(778,947)mul(456,779)mul(610,422)$(:%~select(632,803)mul(652,488)]what()why("
    ")/"
    "select()@don't()mul(812,692){<[&why()don't()mul(339,986),what()-'>,mul(356,656)':$what()%{&when()from()mul(385,"
    "923){]>@(~&why()-mul(201,731)]mul(599,610)?why()@,&how()#mul(204,373){'from()}!#{%<mul(558,269)what()-!( "
    "*}mul(744,656)mul(986,907)where()where() "
    "<;))mulfrom()>select()%^?}where(6,733)mul(118,396),)#:-when()'select()mul(788,521)'&#&($do()from()$,~!mul+mul(245,"
    "72)?<mul(262,717):@/"
    "where()why()]mul(806,380):?*mul,~*how())';select()why()mul(954,891)where()how()^*?[mul(52,145);&mul(645,872)why("
    "679,273)[<+mul(255,174)what()??$)#(mul(839,305)&(-(why();~$,mul(572,454)>;when()!')!who(450,16)how()#mul(341,203)["
    ">how()who()'mul(116,924)@+#mul(536,362)when()select()why(),!, "
    ">+?mul(674,414)/%*mul(499,509)&)})+*{/"
    "mul(125,544)[who())+}]why()'mul(694,107)#-mul(589,269)<:,*what()what(),from())mul(779,394)?{+)[from()what()/"
    "&^mul(418,402)^from()]mul(771,556)mul(48,471)^mul(5,471) "
    "%,[who()mul(584,991)$$select()when()%,when()mul(662,976)&mul(378,372)-how(),select()-mul(693,943)^ "
    "mul(71,492)^{;(,from()*}$mul(325,434)'from()mul(39,981)% "
    "why();~mul(962,307)who()*what()select()when()mul(442,854)who()~select()from()why(848,680)where()/&mul(138,127)- "
    "+?when()where()select()!-mul(74,742)]who(449,197)-mul(58,606) <%mul(563,278)<when() "
    "$select()[,select()mul(117,459)',$+when()from(998,869)when()when()$mul(473,512)where()who()>where()when()mul(167,"
    "344)do()-where()what(196,552)]why()%,((%mul(508,557)what()from():^what()mul(858,144)what()from(),mul(332,118)mul("
    "805,968)how()@!- "
    "mul(31,7)(from():select()who()*}^+mul(790,338)?mul(876,269)what()$?>who()mul(705,526)*%;mul(284,73)/"
    "%!mul(336,280)&select()why()mul(841,593)##?:mul(611,712)%&:who()/[ who();do(),?)# "
    "}mul(10,584),where()^@,from()what()%;(mul(776,536):*!mul(440,957)where()# "
    "^when()#*mul(282,762)]<~;#who()#*when()?mul(945,443)>*);why()[:mul(174,224)&~ "
    "who()how();when()@^mul(301,546)mul(180,572)select()<%#:&mul(642,14)why()~from()'where()#-:mul(711,95)what()^,<-!"
    "what()/#mul(787,954)from()/mul(449,665);why()-)mul(465,877)+#/"
    "what()who()$'<&mul(908,857)[@>!mul(190,564)from()who()&,mul(539,109)-why()/"
    "&{;,how()!>mul(381,931)>>]select()+mul(451,520)don't()from()when(),<^-+mul(198,363)mul(469,259)?<how())+)mul(676,"
    "280)mul(631,824)~<)select()(what()who()-mul(270,524):mul(253,506))?{%}when()$*where(137,14)&mul(901,230)>@where()}"
    "~{select()-(<mul(353,334)?&when()^ #+where()~,mul(589,243)/*'where()what()^<+mul(668,536)/,@^--<( "
    "mul(221,71),when()'//(why()mul(822,686)+'%<where(),*@mul(208,127)#(<@},'-'mul(334,658))&* "
    "where()who()%from()mul(39,503)/+:how()'select()@mul(283,149)";

int find_uncorrupted_mul_instructions_sum(const char* str, bool enabled_only = false)
{
    int n1, n2;
    char c;
    int sum      = 0;
    bool enabled = true;

    for (;;)
    {
        if (enabled_only && !enabled)
        {
            const char* str_do = strstr(str, "do()");
            if (str_do == nullptr) break;
            str     = str_do + strlen("do()");
            enabled = true;
            continue;
        }

        const char* str_mul = strstr(str, "mul(");
        if (str_mul == nullptr) break;

        if (enabled_only)
        {
            const char* str_dont = strstr(str, "don't()");
            if (str_dont != nullptr && str_dont < str_mul)
            {
                str     = str_dont + strlen("don't()");
                enabled = false;
                continue;
            }
        }

        if (sscanf(str_mul, "mul(%d,%d%c", &n1, &n2, &c) != 3)
        {
            str = str_mul + 1;
            continue;
        }

        if (c == ')' && n1 >= 0 && n1 < 1000 && n2 >= 0 && n2 < 1000)
        {
            sum += n1 * n2;
            str = str_mul + strlen("mul(1,1)");
        }
        else
            str = str_mul + 1;
    }

    return sum;
}

int main()
{
    std::cout << find_uncorrupted_mul_instructions_sum(sample_memory1) << std::endl;
    std::cout << find_uncorrupted_mul_instructions_sum(memory) << std::endl;
    std::cout << find_uncorrupted_mul_instructions_sum(sample_memory2, true) << std::endl;
    std::cout << find_uncorrupted_mul_instructions_sum(memory, true) << std::endl;
    return 0;
}
