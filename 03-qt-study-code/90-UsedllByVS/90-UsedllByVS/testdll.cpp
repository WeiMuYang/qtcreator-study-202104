#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef void (*showWiget)(); //����ָ������
typedef void (*DisplayInto)(); //����ָ������
int main(){
    // HINSTANCE Hint = LoadLibrary("qtdialog.dll");//�������Ǹղ����ɵ�dll
    // HINSTANCE Hint = LoadLibrary(".\\Dll\\qtdialog.dll");//�������Ǹղ����ɵ�dll
    HINSTANCE Hint = LoadLibraryEx("F:\\GithubRepository\\WeiMuYang\\qtcreator-study\\03-qt-study-code\\90-UsedllByVS\\90-UsedllByVS\\qtdialog.dll",NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	DisplayInto PrintDll = (DisplayInto)GetProcAddress(Hint, "DisplayIntoDll");
    showWiget showWidget = (showWiget)GetProcAddress(Hint, "showWidget");
 
    PrintDll();
	getchar();
    showWidget();
    FreeLibrary(Hint);//ж��dll�ļ���
	return 0;
}
