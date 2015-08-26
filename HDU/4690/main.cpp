#include <iostream>
#include <cstdio>

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>

#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MP(x,y) make_pair(x,y)
#define CLR(a, b) memset(a, b, sizeof(a))
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

map<string, string> map1, map2;

void table() {
    map1["00"] = "NUL";
    map1["01"] = "SOH";
    map1["02"] = "STX";
    map1["03"] = "ETX";
    map1["05"] = "HT";
    map1["07"] = "DEL";
    map1["0B"] = "VT";
    map1["0C"] = "FF";
    map1["0D"] = "CR";
    map1["0E"] = "SO";
    map1["0F"] = "SI";

    map1["10"] = "DLE";
    map1["11"] = "DC1";
    map1["12"] = "DC2";
    map1["13"] = "DC3";
    map1["16"] = "BS";
    map1["18"] = "CAN";
    map1["19"] = "EM";
    map1["1C"] = "IFS";
    map1["1D"] = "IGS";
    map1["1E"] = "IRS";
    map1["1F"] = "IUSITB";

    map1["25"] = "LF";
    map1["26"] = "ETB";
    map1["27"] = "ESC";
    map1["2D"] = "ENQ";
    map1["2E"] = "ACK";
    map1["2F"] = "BEL";

    map1["32"] = "SYN";
    map1["37"] = "EOT";
    map1["3C"] = "DC4";
    map1["3D"] = "NAK";
    map1["3F"] = "SUB";

    map1["40"] = "SP";
    map1["4B"] = ".";
    map1["4C"] = "<";
    map1["4D"] = "(";
    map1["4E"] = "+";
    map1["4F"] = "|";

    map1["50"] = "&";
    map1["5A"] = "!";
    map1["5B"] = "$";
    map1["5C"] = "*";
    map1["5D"] = ")";
    map1["5E"] = ";";

    map1["60"] = "-";
    map1["61"] = "/";
    map1["6B"] = ",";
    map1["6C"] = "%";
    map1["6D"] = "_";
    map1["6E"] = ">";
    map1["6F"] = "?";

    map1["79"] = "`";
    map1["7A"] = ":";
    map1["7B"] = "#";
    map1["7C"] = "@";
    map1["7D"] = "'";
    map1["7E"] = "=";
    map1["7F"] = """";

    map1["81"] = "a";
    map1["82"] = "b";
    map1["83"] = "c";
    map1["84"] = "d";
    map1["85"] = "e";
    map1["86"] = "f";
    map1["87"] = "g";
    map1["88"] = "h";
    map1["89"] = "i";

    map1["91"] = "j";
    map1["92"] = "k";
    map1["93"] = "l";
    map1["94"] = "m";
    map1["95"] = "n";
    map1["96"] = "o";
    map1["97"] = "p";
    map1["98"] = "q";
    map1["99"] = "r";

    map1["A1"] = "~";
    map1["A2"] = "s";
    map1["A3"] = "t";
    map1["A4"] = "u";
    map1["A5"] = "v";
    map1["A6"] = "w";
    map1["A7"] = "x";
    map1["A8"] = "y";
    map1["A9"] = "z";

    map1["B0"] = "^";
    map1["BA"] = "[";
    map1["BB"] = "]";

    map1["C0"] = "{";
    map1["C1"] = "A";
    map1["C2"] = "B";
    map1["C3"] = "C";
    map1["C4"] = "D";
    map1["C5"] = "E";
    map1["C6"] = "F";
    map1["C7"] = "G";
    map1["C8"] = "H";
    map1["C9"] = "I";

    map1["D0"] = "}";
    map1["D1"] = "J";
    map1["D2"] = "K";
    map1["D3"] = "L";
    map1["D4"] = "M";
    map1["D5"] = "N";
    map1["D6"] = "O";
    map1["D7"] = "P";
    map1["D8"] = "Q";
    map1["D9"] = "R";

    map1["E0"] = "\\";
    map1["E2"] = "S";
    map1["E3"] = "T";
    map1["E4"] = "U";
    map1["E5"] = "V";
    map1["E6"] = "W";
    map1["E7"] = "X";
    map1["E8"] = "Y";
    map1["E9"] = "Z";

    map1["F0"] = "0";
    map1["F1"] = "1";
    map1["F2"] = "2";
    map1["F3"] = "3";
    map1["F4"] = "4";
    map1["F5"] = "5";
    map1["F6"] = "6";
    map1["F7"] = "7";
    map1["F8"] = "8";
    map1["F9"] = "9";

    map2["NUL"] = "00";
    map2["SOH"] = "01";
    map2["STX"] = "02";
    map2["ETX"] = "03";
    map2["EOT"] = "04";
    map2["ENQ"] = "05";
    map2["ACK"] = "06";
    map2["BEL"] = "07";
    map2["BS"] = "08";
    map2["HT"] = "09";
    map2["LF"] = "0A";
    map2["VT"] = "0B";
    map2["FF"] = "0C";
    map2["CR"] = "0D";
    map2["SO"] = "0E";
    map2["SI"] = "0F";

    map2["DLE"] = "10";
    map2["DC1"] = "11";
    map2["DC2"] = "12";
    map2["DC3"] = "13";
    map2["DC4"] = "14";
    map2["NAK"] = "15";
    map2["SYN"] = "16";
    map2["ETB"] = "17";
    map2["CAN"] = "18";
    map2["EM"] = "19";
    map2["SUB"] = "1A";
    map2["ESC"] = "1B";
    map2["IFS"] = "1C";
    map2["IGS"] = "1D";
    map2["IRS"] = "1E";
    map2["IUSITB"] = "1F";

    map2["SP"] = "20";
    map2["!"] = "21";
    map2[""""] = "22";
    map2["#"] = "23";
    map2["$"] = "24";
    map2["%"] = "25";
    map2["&"] = "26";
    map2["'"] = "27";
    map2["("] = "28";
    map2[")"] = "29";
    map2["*"] = "2A";
    map2["+"] = "2B";
    map2[","] = "2C";
    map2["-"] = "2D";
    map2["."] = "2E";
    map2["/"] = "2F";

    map2["0"] = "30";
    map2["1"] = "31";
    map2["2"] = "32";
    map2["3"] = "33";
    map2["4"] = "34";
    map2["5"] = "35";
    map2["6"] = "36";
    map2["7"] = "37";
    map2["8"] = "38";
    map2["9"] = "39";
    map2[":"] = "3A";
    map2[";"] = "3B";
    map2["<"] = "3C";
    map2["="] = "3D";
    map2[">"] = "3E";
    map2["?"] = "3F";

    map2["@"] = "40";
    map2["A"] = "41";
    map2["B"] = "42";
    map2["C"] = "43";
    map2["D"] = "44";
    map2["E"] = "45";
    map2["F"] = "46";
    map2["G"] = "47";
    map2["H"] = "48";
    map2["I"] = "49";
    map2["J"] = "4A";
    map2["K"] = "4B";
    map2["L"] = "4C";
    map2["M"] = "4D";
    map2["N"] = "4E";
    map2["O"] = "4F";

    map2["P"] = "50";
    map2["Q"] = "51";
    map2["R"] = "52";
    map2["S"] = "53";
    map2["T"] = "54";
    map2["U"] = "55";
    map2["V"] = "56";
    map2["W"] = "57";
    map2["X"] = "58";
    map2["Y"] = "59";
    map2["Z"] = "5A";
    map2["["] = "5B";
    map2["\\"] = "5C";
    map2["]"] = "5D";
    map2["^"] = "5E";
    map2["_"] = "5F";

    map2["`"] = "60";
    map2["a"] = "61";
    map2["b"] = "62";
    map2["c"] = "63";
    map2["d"] = "64";
    map2["e"] = "65";
    map2["f"] = "66";
    map2["g"] = "67";
    map2["h"] = "68";
    map2["i"] = "69";
    map2["j"] = "6A";
    map2["k"] = "6B";
    map2["l"] = "6C";
    map2["m"] = "6D";
    map2["n"] = "6E";
    map2["o"] = "6F";

    map2["p"] = "70";
    map2["q"] = "71";
    map2["r"] = "72";
    map2["s"] = "73";
    map2["t"] = "74";
    map2["u"] = "75";
    map2["v"] = "76";
    map2["w"] = "77";
    map2["x"] = "78";
    map2["y"] = "79";
    map2["z"] = "7A";
    map2["{"] = "7B";
    map2["|"] = "7C";
    map2["}"] = "7D";
    map2["~"] = "7E";
    map2["DEL"] = "7F";
}

int main() {
    table();
    string s, str;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i += 2) {
            string t;
            t += s[i];
            t += s[i + 1];
            cout << map2[map1[t]];
        }
        cout << endl;
    }
    return 0;
}