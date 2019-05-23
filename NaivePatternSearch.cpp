#include <iostream>
using namespace std;
void search(char *pat, char* txt)
{
    int pattern_length = strlen(pat);
    int txt_length = strlen(txt);
    int pat_check;
    int i, j, idx_i;
    /*cout<<txt_length<<endl;
    cout<<"\n";
    cout<<pattern_length<<endl;*/
    i = 0; j = 0; pat_check = 0;
    while( i < txt_length )
    {
        idx_i = i;
        pat_check = 0;
        j = 0;
        while(txt[idx_i] == pat[j])
        {
            idx_i++;
            j++;
            pat_check++;
        }

        if(pat_check == pattern_length)
        {
            cout<<idx_i - pattern_length<<endl;
        }
        
        i++;
    }
}
int main(int argc, char const *argv[])
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";

    search(pat, txt);
    return 0;
}