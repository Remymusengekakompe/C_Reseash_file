#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
void DetailFille();



int main(int argc, char *argv[]){
    DetailFille();
   
    return 0;    
}









/*""""""""""""""""""""""""My fonction"""""""""""""""""""""""""""""""""""""""""""""*/

void DetailFille(){
     struct _finddata_t c_file;
    intptr_t hFile;

    if((hFile = _findfirst("*.c", &c_file)) == -1L)
        printf("No files !\n");
    else{
        printf("RECHERCE DES FICHIERS .....\n");

        
        do{

            char buffer[30];
            printf((c_file.attrib & _A_RDONLY) ? "" : "Nom : ");
            
            printf((c_file.attrib & _A_ARCH) ? "" : "");

            ctime_s(buffer,  _countof(buffer), &c_file.time_write);
            printf( "%-12s  %.24s  %91d ", c_file.name, buffer, c_file.size );

        }while(_findnext(hFile, &c_file) == 0);
        _findclose(hFile);
    }

}