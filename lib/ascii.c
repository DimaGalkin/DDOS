#include "acsii.h"

uint8 charToASCII(char charachter) {
    switch(charachter) {
        case ' ': return 32;
        case '!': return 33;
        case '"': return 34;
        case '#': return 35;
        case '$': return 36;
        case '%': return 37;
        case '&': return 38;
        case '\'': return 39;
        case '(': return 40;
        case ')': return 41;
        case '*': return 42;
        case '+': return 43;
        case ',': return 44;
        case '-': return 45;
        case '.': return 46;
        case '/': return 47;
        case '0': return 48;
        case '1': return 49;
        case '2': return 50;
        case '3': return 51;
        case '4': return 52;
        case '5': return 53;
        case '6': return 54;
        case '7': return 55;
        case '8': return 56;
        case '9': return 57;
        case ':': return 58;
        case ';': return 59;
        case '<': return 60;
        case '=': return 61;
        case '>': return 62;
        case '?': return 63;
        case '@': return 64;
        case 'A': return 65;
        case 'B': return 66;
        case 'C': return 67;
        case 'D': return 68;
        case 'E': return 69;
        case 'F': return 70;
        case 'G': return 71;
        case 'H': return 72;
        case 'I': return 73;
        case 'J': return 74;
        case 'K': return 75;
        case 'L': return 76;
        case 'M': return 77;
        case 'N': return 78;
        case 'O': return 79;
        case 'P': return 80;
        case 'Q': return 81;
        case 'R': return 82;
        case 'S': return 83;
        case 'T': return 84;
        case 'U': return 85;
        case 'V': return 86;
        case 'W': return 87;
        case 'X': return 88;
        case 'Y': return 89;
        case 'Z': return 90;
        case '[': return 91;
        case '\\': return 92;
        case ']': return 93;
        case '^': return 94;
        case '_': return 95;
        case '`': return 96;
        case 'a': return 97;
        case 'b': return 98;
        case 'c': return 99;
        case 'd': return 100;
        case 'e': return 101;
        case 'f': return 102;
        case 'g': return 103;
        case 'h': return 104;
        case 'i': return 105;
        case 'j': return 106;
        case 'k': return 107;
        case 'l': return 108;
        case 'm': return 109;
        case 'n': return 110;
        case 'o': return 111;
        case 'p': return 112;
        case 'q': return 113;
        case 'r': return 114;
        case 's': return 115;
        case 't': return 116;
        case 'u': return 117;
        case 'v': return 118;
        case 'w': return 119;
        case 'x': return 120;
        case 'y': return 121;
        case 'z': return 122;
        case '{': return 123;
        case '|': return 124;
        case '}': return 125;
        case '~': return 126;
        default: return 255;
        
    }
}

char ASCIItoChar(uint8 charachter) {
    switch(charachter) {
        case 32: return ' ';
        case 33: return '!';
        case 34: return '"';
        case 35: return '#';
        case 36: return '$';
        case 37: return '%';
        case 38: return '&';
        case 39: return '\'';
        case 40: return '(';
        case 41: return ')';
        case 42: return '*';
        case 43: return '+';
        case 44: return ',';
        case 45: return '-';
        case 46: return '.';
        case 47: return '/';
        case 48: return '0';
        case 49: return '1';
        case 50: return '2';
        case 51: return '3';
        case 52: return '4';
        case 53: return '5';
        case 54: return '6';
        case 55: return '7';
        case 56: return '8';
        case 57: return '9';
        case 58: return ':';
        case 59: return ';';
        case 60: return '<';
        case 61: return '=';
        case 62: return '>';
        case 63: return '?';
        case 64: return '@';
        case 65: return 'A';
        case 66: return 'B';
        case 67: return 'C';
        case 68: return 'D';
        case 69: return 'E';
        case 70: return 'F';
        case 71: return 'G';
        case 72: return 'H';
        case 73: return 'I';
        case 74: return 'J';
        case 75: return 'K';
        case 76: return 'L';
        case 77: return 'M';
        case 78: return 'N';
        case 79: return 'O';
        case 80: return 'P';
        case 81: return 'Q';
        case 82: return 'R';
        case 83: return 'S';
        case 84: return 'T';
        case 85: return 'U';
        case 86: return 'V';
        case 87: return 'W';
        case 88: return 'X';
        case 89: return 'Y';
        case 90: return 'Z';
        case 91: return ']';
        case 92: return '\\';
        case 93: return ']';
        case 94: return '^';
        case 95: return '_';
        case 96: return '`';
        case 97: return 'a';
        case 98: return 'b';
        case 99: return 'c';
        case 100: return 'd';
        case 101: return 'e';
        case 102: return 'f';
        case 103: return 'g';
        case 104: return 'h';
        case 105: return 'i';
        case 106: return 'j';
        case 107: return 'k';
        case 108: return 'l';
        case 109: return 'm';
        case 110: return 'n';
        case 111: return 'o';
        case 112: return 'p';
        case 113: return 'q';
        case 114: return 'r';
        case 115: return 's';
        case 116: return 't';
        case 117: return 'u';
        case 118: return 'v';
        case 119: return 'w';
        case 120: return 'x';
        case 121: return 'y';
        case 122: return 'z';
        case 123: return '}';
        case 124: return '|';
        case 125: return '}';
        case 126: return '~';
        default: return 255;
        
    }
}

uint8 charToInt(char charachter) {
    switch(charachter) {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        default: return 0;
    }
}

uint32 charsToInt(char* charachters) {
    uint32 result = 0;
    for (uint32 i = 0; i < strlen(charachters); ++i) {
        result += (charToInt(charachters[strlen(charachters) - i]) * (pow(10, i)));
    }

    return result;
}

void lower(char* name) {
    for(uint16 i = 0; i < strlen(name); ++i) {
        char str[2] = {name[i], 'E'};
        if(mstrcmp(str, "AE") == 1) {name[i] = 'a';}
        else if(mstrcmp(str, "BE") == 1) {name[i] = 'b';}
        else if(mstrcmp(str, "CE") == 1) {name[i] = 'c';}
        else if(mstrcmp(str, "DE") == 1) {name[i] = 'd';}
        else if(mstrcmp(str, "EE") == 1) {name[i] = 'e';}
        else if(mstrcmp(str, "FE") == 1) {name[i] = 'f';}
        else if(mstrcmp(str, "GE") == 1) {name[i] = 'g';}
        else if(mstrcmp(str, "HE") == 1) {name[i] = 'h';}
        else if(mstrcmp(str, "IE") == 1) {name[i] = 'i';}
        else if(mstrcmp(str, "JE") == 1) {name[i] = 'j';}
        else if(mstrcmp(str, "KE") == 1) {name[i] = 'k';}
        else if(mstrcmp(str, "LE") == 1) {name[i] = 'l';}
        else if(mstrcmp(str, "ME") == 1) {name[i] = 'm';}
        else if(mstrcmp(str, "NE") == 1) {name[i] = 'n';}
        else if(mstrcmp(str, "OE") == 1) {name[i] = 'o';}
        else if(mstrcmp(str, "PE") == 1) {name[i] = 'p';}
        else if(mstrcmp(str, "QE") == 1) {name[i] = 'q';}
        else if(mstrcmp(str, "RE") == 1) {name[i] = 'r';}
        else if(mstrcmp(str, "SE") == 1) {name[i] = 's';}
        else if(mstrcmp(str, "TE") == 1) {name[i] = 't';}
        else if(mstrcmp(str, "UE") == 1) {name[i] = 'u';}
        else if(mstrcmp(str, "VE") == 1) {name[i] = 'v';}
        else if(mstrcmp(str, "WE") == 1) {name[i] = 'w';}
        else if(mstrcmp(str, "XE") == 1) {name[i] = 'x';}
        else if(mstrcmp(str, "YE") == 1) {name[i] = 'y';}
        else if(mstrcmp(str, "ZE") == 1) {name[i] = 'z';}
    }
}