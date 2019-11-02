#pragma once

const char* neigA_left = "lcdmnswtreh";
const char* neigA_right = "ntsrldcm";

const char* neigB_left = "ybntudosae";
const char* neigB_right = "eluoaybr";

const char* neigC_left = "uosnaile";
const char* neigC_right = "hoeaitrlk";

const char* neigD_left = "rilane";
const char* neigD_right = "eitaou";

const char* neigE_left = "cbemvdslntrh";
const char* neigE_right = "rdsnatmeco";

const char* neigF_left = "snfdaieo";
const char* neigF_right = "toeiarfu";

const char* neigG_left = "oduriean";
const char* neigG_right = "ehoratfwis";

const char* neigH_left = "gewsct";
const char* neigH_right = "eaio";

const char* neigI_left = "fmwenldsrht";
const char* neigI_right = "ntsocremal";

const char* neigJ_left = "ywtsnecbac";
const char* neigJ_right = "uoaemw";

const char* neigK_left = "yuinaroc";
const char* neigK_right = "einats";

const char* neigL_left = "mptibuoela";
const char* neigL_right = "eiyoadu";

const char* neigM_left = "sdmriaoe";
const char* neigM_right = "eaoipm";

const char* neigN_left = "ueoai";
const char* neigN_right = "ndtgeasoic";

const char* neigO_left = "odlphnecfsirt";
const char* neigO_right = "nfrutmlswo";

const char* neigP_left = "rltnipmaoues";
const char* neigP_right = "oearluptis";

const char* neigQ_left = "onledrs";
const char* neigQ_right = "u";

const char* neigR_left = "piutaoe";
const char* neigR_right = "eoatisy";

const char* neigS_left = "dtournsiae";
const char* neigS_right = "teoisahpu";

const char* neigT_left = "uodtfeinsa";
const char* neigT_right = "hioeatr";

const char* neigU_left = "pftlbdso";
const char* neigU_right = "nstrlpbc";

const char* neigV_left = "ruoaie";
const char* neigV_right = "eioa";

const char* neigW_left = "gdynstoe";
const char* neigW_right = "ahieon";

const char* neigX_left = "unie";
const char* neigX_right = "ptiaucko";

const char* neigY_left = "bnaterl";
const char* neigY_right = "aostwhiedm";

const char* neigZ_left = "onai";
const char* neigZ_right = "eiw";

/*
a Left: cdehlmnrstw
a Right: cdlmnrst
b Left: abdenostuy
b Right: abeloruy
c Left: aeilnosu
c Right: aehiklort
d Left: aeilnr
d Right: aeiotu
e Left: bcdehlmnrstv
e Right: acdemnorst
f Left: adefinos
f Right: aefiortu
g Left: adeinoru
g Right: aefhiorstw
h Left: cegstw
h Right: aeio
i Left: defhlmnrstw
i Right: acelmnorst
j Left: abccenstwy
j Right: aemouw
k Left: acinoruy
k Right: aeinst
l Left: abeilmoptu
l Right: adeiouy
m Left: adeimors
m Right: aeimop
n Left: aeiou
n Right: acdeginost
o Left: cdefhilnoprst
o Right: flmnorstuw
p Left: aeilmnoprstu
p Right: aeiloprstu
q Left: delnors
q Right: u
r Left: aeioptu
r Right: aeiosty
s Left: adeinorstu
s Right: aehiopstu
t Left: adefinostu
t Right: aehiort
u Left: bdflopst
u Right: bclnprst
v Left: aeioru
v Right: aeio
w Left: degnosty
w Right: aehino
x Left: einu
x Right: acikoptu
y Left: abelnrt
y Right: adehimostw
z Left: aino
z Right: eiw
Table LEFT:
-1 -1 2 2 1 -1 -1 1 -1 -1 -1 2 2 2 -1 -1 -1 1 1 1 -1 -1 1 -1 -1 -1 -1 -1 -1
1 2 -1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 2 1 -1 -1 -1 1 2 2 -1 -1 -1 2 -1 -1 -1 -1
1 -1 -1 -1 1 -1 -1 -1 1 -1 -1 1 -1 2 2 -1 -1 -1 2 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 1 -1 -1 -1 2 -1 -1 2 -1 1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 2 2 2 2 -1 -1 1 -1 -1 -1 1 2 1 -1 -1 -1 1 1 1 -1 2 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 2 1 2 -1 -1 1 -1 -1 -1 -1 2 1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 2 1 -1 -1 -1 1 -1 -1 -1 -1 1 2 -1 -1 2 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 1 -1 2 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 -1 -1 2 -1 -1 -1 -1 -1 -1
-1 -1 -1 1 2 2 -1 1 -1 -1 -1 1 2 2 -1 -1 -1 1 1 1 -1 -1 2 -1 -1 -1 -1 -1 -1
1 1 1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 2 -1 -1 -1 -1 2 2 -1 -1 2 -1 2 -1 -1 -1 -1
1 -1 1 -1 -1 -1 -1 -1 2 -1 -1 -1 -1 2 1 -1 -1 1 -1 -1 2 -1 -1 -1 2 -1 -1 -1 -1
1 2 -1 -1 1 -1 -1 -1 2 -1 -1 1 2 -1 1 2 -1 -1 -1 2 1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 2 1 -1 -1 -1 1 -1 -1 -1 2 -1 1 -1 -1 2 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 2 -1 -1 -1 1 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 1 2 1 1 -1 2 1 -1 -1 2 -1 2 2 2 -1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 1 -1 -1 -1 2 -1 -1 2 1 2 1 2 -1 2 1 2 1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 1 1 -1 -1 -1 -1 -1 -1 2 -1 2 2 -1 -1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 1 -1 -1 -1 2 -1 -1 -1 -1 -1 1 2 -1 -1 -1 1 2 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 2 1 -1 -1 -1 1 -1 -1 -1 -1 1 2 -1 -1 2 1 2 2 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 2 1 2 -1 -1 1 -1 -1 -1 -1 1 2 -1 -1 -1 1 2 2 -1 -1 -1 -1 -1 -1 -1 -1
-1 1 -1 1 -1 2 -1 -1 -1 -1 -1 2 -1 -1 1 2 -1 -1 1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 1 -1 -1 -1 1 -1 -1 -1 -1 -1 2 -1 -1 2 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 2 1 -1 2 -1 -1 -1 -1 -1 -1 2 1 -1 -1 -1 1 1 -1 -1 -1 -1 2 -1 -1 -1 -1
-1 -1 -1 -1 1 -1 -1 -1 1 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
2 2 -1 -1 1 -1 -1 -1 -1 -1 -1 1 -1 2 -1 -1 -1 1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 2 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Table Right:
-1 -1 1 1 -1 -1 -1 -1 -1 -1 -1 1 1 2 -1 -1 -1 2 2 2 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 1 -1 -1 2 -1 -1 -1 -1 -1 -1 2 -1 -1 2 -1 -1 1 -1 -1 2 -1 -1 -1 1 -1 -1 -1 -1
2 -1 -1 -1 2 -1 -1 2 1 -1 1 1 -1 -1 2 -1 -1 1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 2 -1 -1 -1 2 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 2 1 -1 -1 -1 -1 -1 -1 -1 -1
2 -1 1 2 1 -1 -1 -1 -1 -1 -1 -1 1 2 1 -1 -1 2 2 1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 2 1 -1 -1 2 -1 -1 -1 -1 -1 2 -1 -1 1 -1 2 1 -1 -1 -1 -1 -1 -1 -1 -1
2 -1 -1 -1 2 1 -1 2 1 -1 -1 -1 -1 -1 2 -1 -1 2 1 1 -1 -1 1 -1 -1 -1 -1 -1 -1
2 -1 -1 -1 2 -1 -1 -1 1 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 2 -1 1 -1 -1 -1 -1 -1 -1 1 1 2 2 -1 -1 1 2 2 -1 -1 -1 -1 -1 -1 -1 -1 -1
2 -1 -1 -1 1 -1 -1 -1 -1 -1 -1 -1 1 -1 2 -1 -1 -1 -1 -1 2 -1 1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 2 -1 -1 -1 2 -1 -1 -1 -1 2 -1 -1 -1 -1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 1 2 -1 -1 -1 2 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 1 -1 -1 -1 2 -1 -1 -1 -1
2 -1 -1 -1 2 -1 -1 -1 1 -1 -1 -1 1 -1 2 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 1 2 2 -1 2 -1 1 -1 -1 -1 -1 2 1 -1 -1 -1 1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 1 1 2 1 -1 -1 2 1 2 2 -1 1 -1 -1 -1 -1 -1 -1
2 -1 -1 -1 2 -1 -1 -1 1 -1 -1 2 -1 -1 2 1 -1 2 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1
2 -1 -1 -1 2 -1 -1 -1 1 -1 -1 -1 -1 -1 2 -1 -1 -1 1 1 -1 -1 -1 -1 1 -1 -1 -1 -1
1 -1 -1 -1 2 -1 -1 1 2 -1 -1 -1 -1 -1 2 1 -1 -1 1 2 1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 1 -1 -1 2 2 -1 -1 -1 -1 -1 2 -1 -1 1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 -1 2 -1 1 -1 2 2 2 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 -1 -1 -1 2 -1 -1 -1 2 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
2 -1 -1 -1 1 -1 -1 2 2 -1 -1 -1 -1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
2 -1 1 -1 -1 -1 -1 -1 2 -1 1 -1 -1 -1 1 2 -1 -1 -1 2 1 -1 -1 -1 -1 -1 -1 -1 -1
2 -1 -1 1 1 -1 -1 1 1 -1 -1 -1 1 -1 2 -1 -1 -1 2 2 -1 -1 2 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 2 -1 -1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/