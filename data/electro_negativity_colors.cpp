#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

// 5 gradient anchor points: Red → Orange → Yellow → Green → Blue
// 5个渐变锚点：红 → 橙 → 黄 → 绿 → 蓝
const int anchors[5][4] =
{
    {255, 204, 204,  0},   // #FFCCCC Minimum electronegativity｜#FFCCCC 最小电负性
    {253, 223, 177, 25},   // #FDDFB1
    {254, 248, 166, 50},   // #FEF8A6
    {209, 232, 178, 75},   // #D1E8B2
    {169, 221, 243, 100}   // #A9DDF3 Maximum electronegativity｜#A9DDF3 最大电负性
};

/**
 * @brief Convert Pauling electronegativity value to hex?color string
 * @param chi Pauling electronegativity
 * @return Hex color string e.g. "#RRGGBB"
 * @brief 将鲍林电负性数值转换为十六进制颜色字符串
 * @param chi 鲍林标度电负性
 * @return 十六进制颜色字符串，例如 "#RRGGBB"
 */
string chi2hex(double chi)
{
    // Pauling electronegativity range: 0.7 ~ 4.0
    // 鲍林电负性取值范围：0.7 ~ 4.0
    double t = (chi - 0.7) / 3.3;
    if (t < 0.0) t = 0.0;   // Clamp to lower bound｜限制为下界
    if (t > 1.0) t = 1.0;   // Clamp to upper bound｜限制为上界
    int t_pct = (int)round(t * 100);

    int r, g, b;
    double k;

    if (t_pct <= 25)
	{
        k = (t_pct - anchors[0][3]) / 25.0;
        r = round(anchors[0][0] + k * (anchors[1][0] - anchors[0][0]));
        g = round(anchors[0][1] + k * (anchors[1][1] - anchors[0][1]));
        b = round(anchors[0][2] + k * (anchors[1][2] - anchors[0][2]));
    }
    else if (t_pct <= 50)
	{
        k = (t_pct - anchors[1][3]) / 25.0;
        r = round(anchors[1][0] + k * (anchors[2][0] - anchors[1][0]));
        g = round(anchors[1][1] + k * (anchors[2][1] - anchors[1][1]));
        b = round(anchors[1][2] + k * (anchors[2][2] - anchors[1][2]));
    }
    else if (t_pct <= 75)
	{
        k = (t_pct - anchors[2][3]) / 25.0;
        r = round(anchors[2][0] + k * (anchors[3][0] - anchors[2][0]));
        g = round(anchors[2][1] + k * (anchors[3][1] - anchors[2][1]));
        b = round(anchors[2][2] + k * (anchors[3][2] - anchors[2][2]));
    }
    else
	{
        k = (t_pct - anchors[3][3]) / 25.0;
        r = round(anchors[3][0] + k * (anchors[4][0] - anchors[3][0]));
        g = round(anchors[3][1] + k * (anchors[4][1] - anchors[3][1]));
        b = round(anchors[3][2] + k * (anchors[4][2] - anchors[3][2]));
    }

    char buf[20];
    sprintf(buf, "#%02X%02X%02X", r, g, b);
    return string(buf);
}

// Element data structure: atomic number, symbol, Pauling electronegativity
// 元素结构体：原子序数、元素符号、鲍林电负性
struct Element
{
    int num;
    string sym;
    double en;
};

int main()
{
    // Element list: atomic number, symbol, Pauling?scale electronegativity
    // 元素列表：原子序数，元素符号，鲍林标度电负性（部分超重元素、稀有气体为理论计算值）
    vector<Element> elements = {
        {1,"H",2.20},      {2,"He",3.89},      {3,"Li",0.98},     {4,"Be",1.57},
        {5,"B",2.04},      {6,"C",2.55},     {7,"N",3.04},     {8,"O",3.44},
        {9,"F",3.98},     {10,"Ne",3.67},    {11,"Na",0.93},   {12,"Mg",1.31},
        {13,"Al",1.61},   {14,"Si",1.90},   {15,"P",2.19},    {16,"S",2.58},
        {17,"Cl",3.16},   {18,"Ar",3.3},    {19,"K",0.82},    {20,"Ca",1.00},
        {21,"Sc",1.36},   {22,"Ti",1.54},   {23,"V",1.63},    {24,"Cr",1.66},
        {25,"Mn",1.55},   {26,"Fe",1.83},   {27,"Co",1.88},   {28,"Ni",1.91},
        {29,"Cu",1.90},   {30,"Zn",1.65},   {31,"Ga",1.81},   {32,"Ge",2.01},
        {33,"As",2.18},   {34,"Se",2.55},   {35,"Br",2.96},   {36,"Kr",3.00},
        {37,"Rb",0.82},   {38,"Sr",0.95},   {39,"Y",1.22},    {40,"Zr",1.33},
        {41,"Nb",1.60},   {42,"Mo",2.16},   {43,"Tc",1.90},   {44,"Ru",2.20},
        {45,"Rh",2.28},   {46,"Pd",2.20},   {47,"Ag",1.93},   {48,"Cd",1.69},
        {49,"In",1.78},   {50,"Sn",1.96},   {51,"Sb",2.05},   {52,"Te",2.10},
        {53,"I",2.66},    {54,"Xe",2.67},    {55,"Cs",0.79},   {56,"Ba",0.89},
        {57,"La",1.10},   {58,"Ce",1.12},   {59,"Pr",1.13},   {60,"Nd",1.14},
        {61,"Pm",1.13},   {62,"Sm",1.17},   {63,"Eu",1.2},   {64,"Gd",1.20},
        {65,"Tb",1.1},   {66,"Dy",1.22},   {67,"Ho",1.23},   {68,"Er",1.24},
        {69,"Tm",1.25},   {70,"Yb",1.1},   {71,"Lu",1.27},   {72,"Hf",1.30},
        {73,"Ta",1.50},   {74,"W",2.36},    {75,"Re",1.90},   {76,"Os",2.20},
        {77,"Ir",2.20},   {78,"Pt",2.28},   {79,"Au",2.54},   {80,"Hg",2.00},
        {81,"Tl",1.62},   {82,"Pb",2.33},   {83,"Bi",2.02},   {84,"Po",2.00},
        {85,"At",2.20},   {86,"Rn",2.2},    {87,"Fr",0.70},   {88,"Ra",0.90},
        {89,"Ac",1.10},   {90,"Th",1.30},   {91,"Pa",1.50},   {92,"U",1.38},
        {93,"Np",1.36},   {94,"Pu",1.28},   {95,"Am",1.13},   {96,"Cm",1.28},
        {97,"Bk",1.30},   {98,"Cf",1.30},   {99,"Es",1.30},  {100,"Fm",1.30},
        {101,"Md",1.30}, {102,"No",1.28}, {103,"Lr",1.291}, {104,"Rf",1.70},
        {105,"Db",1.70}, {106,"Sg",1.75}, {107,"Bh",1.90}, {108,"Hs",2.20},
        {109,"Mt",1.90}, {110,"Ds",2.30}, {111,"Rg",2.85}, {112,"Cn",1.90},
        {113,"Nh",2.85}, {114,"Fl",1.80}, {115,"Mc",1.90}, {116,"Lv",2.00},
        {117,"Ts",2.20}, {118,"Og",2.59}
    };

    // Output CSV?style text file
    // 输出CSV格式文本文件
    ofstream fout("electro_negativity_colors.txt");
    fout << "序号 NO,符号 Symbol,电负性 χ,颜色代码 Color\n";

    for (auto& e : elements)
	{
        double val = e.en;
        string color = chi2hex(val);
        fout << e.num << "," << e.sym << "," << fixed << setprecision(2) << val << "," << color << "\n";
    }

    fout.close();
    cout << "? Generated file: electro_negativity_colors.txt" << endl;
    cout << "? 已生成文件：electro_negativity_colors.txt" << endl;
    return 0;
}
