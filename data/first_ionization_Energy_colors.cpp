#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Element {
    int atomicNum;
    string symbol;
    double IE1; // 第一电离能 First ionization energy (kJ/mol)
};

// 1–118 第一电离能数据 Data of first ionization energy，104–118 使用理论值 Using theoretical values
Element elemList[] = {
{1,"H",1312.0}, {2,"He",2372.3}, {3,"Li",520.2}, {4,"Be",899.5}, {5,"B",800.6},
{6,"C",1086.5}, {7,"N",1402.3}, {8,"O",1313.9}, {9,"F",1681.0}, {10,"Ne",2080.7},
{11,"Na",495.8}, {12,"Mg",737.7}, {13,"Al",577.5}, {14,"Si",786.5}, {15,"P",1011.8},
{16,"S",999.6}, {17,"Cl",1251.2}, {18,"Ar",1520.6}, {19,"K",418.8}, {20,"Ca",589.8},
{21,"Sc",633.1}, {22,"Ti",658.8}, {23,"V",650.9}, {24,"Cr",652.9}, {25,"Mn",717.3},
{26,"Fe",762.5}, {27,"Co",760.4}, {28,"Ni",737.1}, {29,"Cu",745.5}, {30,"Zn",906.4},
{31,"Ga",578.8}, {32,"Ge",762.2}, {33,"As",947.0}, {34,"Se",941.0}, {35,"Br",1139.9},
{36,"Kr",1350.8}, {37,"Rb",403.03}, {38,"Sr",549.5}, {39,"Y",600.0}, {40,"Zr",640.1},
{41,"Nb",652.1}, {42,"Mo",684.3}, {43,"Tc",702.0}, {44,"Ru",710.2}, {45,"Rh",719.7},
{46,"Pd",804.4}, {47,"Ag",731.0}, {48,"Cd",867.8}, {49,"In",558.3}, {50,"Sn",708.6},
{51,"Sb",830.58}, {52,"Te",869.3}, {53,"I",1008.4}, {54,"Xe",1170.4}, {55,"Cs",375.7},
{56,"Ba",502.9}, {57,"La",538.1}, {58,"Ce",534.4}, {59,"Pr",527.2}, {60,"Nd",533.1},
{61,"Pm",535.9}, {62,"Sm",543.3}, {63,"Eu",547.1}, {64,"Gd",593.4}, {65,"Tb",565.8},
{66,"Dy",573.0}, {67,"Ho",581.0}, {68,"Er",589.3}, {69,"Tm",596.7}, {70,"Yb",603.4},
{71,"Lu",523.5}, {72,"Hf",658.5}, {73,"Ta",728.42}, {74,"W",758.76}, {75,"Re",755.8},
{76,"Os",814.17}, {77,"Ir",865.19}, {78,"Pt",864.4}, {79,"Au",890.1}, {80,"Hg",1007.1},
{81,"Tl",589.4}, {82,"Pb",715.6}, {83,"Bi",702.9}, {84,"Po",811.8}, {85,"At",899.0},
{86,"Rn",1037.0}, {87,"Fr",392.96}, {88,"Ra",509.3}, {89,"Ac",519.11}, {90,"Th",608.5},
{91,"Pa",568.0}, {92,"U",597.6}, {93,"Np",604.5}, {94,"Pu",584.7}, {95,"Am",576.38},
{96,"Cm",578.08}, {97,"Bk",601.0}, {98,"Cf",608.0}, {99,"Es",614.38}, {100,"Fm",627.0},
{101,"Md",635.0}, {102,"No",641.6}, {103,"Lr",478.6},
// 104~118 采用理论第一电离能 Using theoretical first ionization energy
{104,"Rf",581},
{105,"Db",656},
{106,"Sg",753},
{107,"Bh",743},
{108,"Hs",733},
{109,"Mt",800.8},
{110,"Ds",955.2},
{111,"Rg",1020},
{112,"Cn",1154.9},
{113,"Nh",704.9},
{114,"Fl",823.9},
{115,"Mc",538.3},
{116,"Lv",663.9},
{117,"Ts",742.9},
{118,"Og",860.1}
};
const int totalCnt = sizeof(elemList)/sizeof(Element);

// ========== 9分段渐变锚点 9-segment gradient anchor point，t∈0~100 ==========
const double anchors[9][4] =
{
    {255,204,204,   0.0}, // #FFCCCC
    {253,223,177,  12.5}, // #FDDFB1
    {254,248,166,  25.0}, // #FEF8A6
    {209,232,178,  37.5}, // #D1E8B2
    {153,221,216,  50.0}, // #99DDD8
    {204,227,242,  62.5}, // #CCE3F2
    {169,221,243,  75.0}, // #A9DDF3
    {233,212,233,  87.5}, // #E9D4E9
    {251,210,228, 100.0}  // #FBD2E4
};

// 归一化 Normalization [minV,maxV] → [0,100]
double normalize100(double val, double minV, double maxV)
{
    return 100.0 * (val - minV) / (maxV - minV);
}

// 根据t(0~100)插值得到RGB
//Interpolate to obtain RGB based on t (0–100)
void value2RGB(double t, int &r, int &g, int &b)
{
    int seg;
    if(t <= anchors[0][3]) seg = 0;
    else if(t <= anchors[1][3]) seg = 1;
    else if(t <= anchors[2][3]) seg = 2;
    else if(t <= anchors[3][3]) seg = 3;
    else if(t <= anchors[4][3]) seg = 4;
    else if(t <= anchors[5][3]) seg = 5;
    else if(t <= anchors[6][3]) seg = 6;
    else if(t <= anchors[7][3]) seg = 7;
    else seg = 8;

    if (seg == 0)
    {
        r = anchors[0][0];
        g = anchors[0][1];
        b = anchors[0][2];
        return;
    }
    int s0 = seg - 1;
    int s1 = seg;
    double t0 = anchors[s0][3];
    double t1 = anchors[s1][3];
    double frac = (t - t0) / (t1 - t0);

    r = static_cast<int>( anchors[s0][0] * (1-frac) + anchors[s1][0] * frac );
    g = static_cast<int>( anchors[s0][1] * (1-frac) + anchors[s1][1] * frac );
    b = static_cast<int>( anchors[s0][2] * (1-frac) + anchors[s1][2] * frac );
}

string toHex2(int x)
{
    string s;
    const char* hex = "0123456789ABCDEF";
    s += hex[(x>>4)&0x0F];
    s += hex[x&0x0F];
    return s;
}

int main()
{
    ofstream out("ionization1_out.txt");
    double minIE = 1e9, maxIE = -1e9;
    // 扫描全部元素（含超重理论值）求全局极值
	//Scan all elements (including theoretical values for superheavy elements) to find the global extrema
    for(int i=0;i<totalCnt;i++){
        double v = elemList[i].IE1;
        if(v < minIE) minIE = v;
        if(v > maxIE) maxIE = v;
    }
    cout << "Min IE1 = " << minIE << " kJ/mol" << endl;
    cout << "Max IE1 = " << maxIE << " kJ/mol" << endl;

    // 逐行输出 Line-by-line output
    for(int i=0;i<totalCnt;i++){
        auto &e = elemList[i];
        double t = normalize100(e.IE1, minIE, maxIE);
        int r,g,b;
        value2RGB(t,r,g,b);
        string hexStr = "#" + toHex2(r) + toHex2(g) + toHex2(b);
        out << e.atomicNum << "," << e.symbol << "," << fixed << setprecision(1) << e.IE1 << "," << hexStr << endl;
    }
    out.close();
    cout << "输出完成 Output's complete：ionization1_out.txt" << endl;
    return 0;
}
