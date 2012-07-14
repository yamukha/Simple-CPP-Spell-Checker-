//Spell_Checker.cpp 
//by yamukha@ukr.net 2012 (c)

#include "stdafx.h"
#include <windows.h>
#include <cstdio>      
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define LEVEL_FULL    0x01

using namespace std;

class Speller 
{
public:
    Speller (){};

    bool CheckerFull (char * sample, char * dictionary_word)
    {
        int res ;
        res = strncmp(sample, dictionary_word, 100);
        if ( 0 == res) return true;
        else return false;
    }

    bool CheckerFull (string sample, string dictionary_word)
    {
        int res;
        res = sample.compare(dictionary_word);
        if ( 0 == res) return true;
        else return false;
    }

    string CheckerSwap (string sample, string dictionary_word)
    {
        int length;
        char *char_array;
        char *char_temp;
        char *char_dict;
        char temp;
        bool result;
        char *resulting_string = NULL;

        char_array = new char [100] ;
        char_temp  = new char [100] ;
        char_dict = new char [100] ;
          
        length = strlen (sample.c_str());

        strcpy (char_temp, sample.c_str());
        strcpy (char_array, sample.c_str());
        strcpy (char_dict, dictionary_word.c_str());

        for (int i = 0; i < length - 1 ; i++)
        {
            temp = char_array [ i ] ;
            char_array [ i ]     = char_array [ i + 1 ] ;
            char_array [ i + 1 ] = temp ;

            result = CheckerFull (char_array, char_dict);
            if ( result )
                 {
                     resulting_string = new char [255]; 
                     strcpy ( resulting_string, char_dict );
                 };
                 strcpy (char_array,char_temp);
        }

        delete char_array;
        delete char_temp;
        delete char_dict;

        if ( NULL != resulting_string )
        {
             string swap_result (resulting_string);
             delete resulting_string;
             return swap_result;
        }
        else 
        {
            string swap_result;   
            delete resulting_string;
            return swap_result;          
        }
    }

    string CheckerDelete (string sample, string dictionary_word)
    {
        int length;
        char *char_array;
        char *char_temp;
        char *char_dict;
        char *resulting_string = NULL;
        bool result;
        string str;

        char_array = new char [100] ;
        char_temp  = new char [100] ;
        char_dict  = new char [100] ;

        strcpy (char_temp,sample.c_str());
        strcpy (char_array,sample.c_str());
        strcpy (char_dict,dictionary_word.c_str());

        length = strlen ( sample.c_str());

        for (int i = 1; i < length  ; i++)
	    {
            str = sample;
            str.erase (i,1);
            strcpy(char_array, str.c_str());

            result = CheckerFull (char_array,  char_dict);
            if ( result )
            {
                resulting_string = new char [255]; 
                strcpy ( resulting_string, char_dict);
            };
     }

    delete char_array;
    delete char_temp;
    delete char_dict;

     if ( NULL != resulting_string )
     {
         string del_result (resulting_string);   
         delete resulting_string;
         return del_result;
     }
     else 
     {
         string del_result;   
         delete resulting_string;
         return del_result;          
     }
 } 

    string CheckerInsert (string sample, string dictionary_word)
    {
        int length;
        char *char_array;
        char *char_temp;
        char *char_dict;
        char *resulting_string = NULL;
        bool result;

        char_array = new char [100] ;
        char_temp  = new char [100] ;
        char_dict =  new char [100] ;
          
        strcpy(char_dict, dictionary_word.c_str());
        strcpy(char_temp, sample.c_str());
        length = strlen ( sample.c_str());

        string str(char_temp);
        str.resize (length+1);
        strcpy(char_array, str.c_str());
        strcpy(char_temp, str.c_str());

        for (int i = 0; i < length + 1 ; i++)
        {
            for (char j = 'a' ; j <= 'z'; j++ )
            {
                 str.insert (i,1,j);
                 strcpy (char_array,str.c_str());
                 result = CheckerFull (char_array, char_dict);
              
                 if ( result )
                 {
                     resulting_string = new char [255]; 
                     strcpy ( resulting_string, str.c_str() );
                 };
                 str.erase (i,1);
            }
        }

        delete char_array;
        delete char_temp;
        delete char_dict;

        if ( NULL != resulting_string )
        {
            string ins_result (resulting_string);   
            delete resulting_string;
            return ins_result;
        }
        else 
        {
             string ins_result;   
             delete resulting_string;
             return ins_result;          
        }
    }
     
    string CheckerReplace (string sample, string dictionary_word)
    {
        int length;
        char *char_array;
        char *char_temp;
        char *char_dict;
        char *resulting_string = NULL;
        bool result;
        string str;

        char_array = new char [100] ;
        char_temp  = new char [100] ;
        char_dict =  new char [100] ;
          
        strcpy(char_dict, dictionary_word.c_str());
        strcpy(char_temp, sample.c_str());
        length = strlen ( sample.c_str());

        strcpy(char_array, str.c_str());
        strcpy(char_temp, str.c_str());

        for (int i = 0; i < length ; i++)
        {
            for (char j = 'a' ; j <= 'z'; j++ )
            {
                str = sample;
                str.erase (i,1);
                str.insert (i,1,j);
                strcpy (char_array,str.c_str());
                result = CheckerFull (char_array, dictionary_word);

                if ( result )
                {
                     resulting_string = new char [255]; 
                     strcpy ( resulting_string, str.c_str() );
                };  
            }
        }

        delete char_array;
        delete char_temp;
        delete char_dict;

        if ( NULL != resulting_string )
        {
            string ins_result (resulting_string);   
            delete resulting_string;
            return ins_result;
        }
        else 
        {
            string ins_result;   
            delete resulting_string;
            return ins_result;          
        }
    }
};// Class

string parseLine (char* line, int position, int *index) 
{
    char text[100];
    int j = 0;

    for( int i = position; line[i] != '\0'; i++, j++)
    {
         text[j] = line[i]; 
         if ( isspace ( line [i] ) || ispunct(line[i]) )
         {
             break;
         }
    }
    text[j ]= '\0';
    string parsedResult(text);
    return parsedResult;  
}

char  sampleTestFile []= "sample.txt";
char  fileToWrite [] = "spellout.txt";
bool result;
 
int _tmain(int argc, _TCHAR* argv[])
{
    Speller* WordChecker = new Speller();

    ifstream sampleFile;
    ofstream outFile;

    sampleFile.open(sampleTestFile);
    char output[1000];
    string word ;
    bool dictionary_text = true;
    int* positionInLine = 0;
    int  position ;
    int* indexInCollection = 0;
    int lineSize;
    string lineToParse;
    vector <string> samplesToCheck;
    vector <string> dictionary;

// read and parse file 
    if (sampleFile.is_open()) 
    {
         printf("\nOpen file \"%s\" \n", sampleTestFile);
         while (!sampleFile.eof()) 
         {
             sampleFile.getline (output, 256);
             position = 0;

             if (WordChecker->CheckerFull ( output,"===")) 
             {
                 dictionary_text = false;
             }

             else 
             {
                 if (!dictionary_text)
                 {
                     lineToParse = string (output);
                     lineSize = lineToParse.length(); 
                     int cnt = count(lineToParse.begin(), lineToParse.end(), ' ');
                                     
                     for (int k = 0; k <= cnt; k++)
                     {
                         word = parseLine (output, position, indexInCollection) ;
                         position = lineToParse.find(' ', position ) + 1;          
                         samplesToCheck.push_back(word);
                     }
                 }

                 else
                 {
                     lineToParse = string (output);
                     lineSize = lineToParse.length(); 
                     int cnt = count(lineToParse.begin(), lineToParse.end(), ' ');

                     for (int k = 0; k <= cnt; k++)
                     {
                         word = parseLine (output, position, indexInCollection) ;
                         position = lineToParse.find(' ', position ) + 1;          
                         dictionary.push_back(word);
                     }
                 }
             }
         }
         sampleFile.close();
         printf("File \"%s\" closed. \n", sampleTestFile);
    }

    else 
    {
         printf("No file found %s \n", sampleTestFile);
    }
    
    cout << "\nPrint out containers content:\n";
    for (unsigned n = 0; n < samplesToCheck.size (); n++) 
    {
        cout << samplesToCheck.at ( n ) << " ";
    }
    cout << "\n";

    for (unsigned n = 0; n < dictionary.size (); n++) 
    {
        cout << dictionary.at ( n ) << " ";
    }
    cout << "\n";
    
    cout << "\nSpell checker result:\n";
    string final_str;
    for (unsigned n = 0; n < samplesToCheck.size (); n++) 
    {
        string str1,str2,str3; 
        string strout;
        int match_level;
        int match_count;

        str1 = samplesToCheck.at ( n );
        match_level = 0;
        match_count = 0;
        strout.clear();

        for (unsigned m = 0; m < dictionary.size (); m++) 
        {
            str2 =  dictionary.at ( m );
            result = WordChecker->CheckerFull (str1, str2); 

            if (result) 
            {
                strout = str1 + " ";
                match_level |= 1 ;
                match_count = 1;
            }

            else
            {
                str3 = WordChecker->CheckerSwap    (str1, str2); 
                if (!str3.empty () ) 
                {
                    strout = strout + str3 + " ";
                    match_level |= 2;
                    match_count++;
                };

                str3 = WordChecker->CheckerDelete  (str1, str2); 
                if (!str3.empty () ) 
                {
                    strout = strout + str3 + " ";
                    match_level |= 4;
                    match_count++;                        
                };

                str3 = WordChecker->CheckerInsert  (str1, str2); 
                if (!str3.empty () )
                {
                    strout = strout + str3 + " ";
                    match_level |= 8;
                    match_count++;
                };

                str3 = WordChecker->CheckerReplace (str1, str2); 
                if (!str3.empty () )
                {
                    strout = strout + str3 + " ";
                    match_level |= 0x10;
                    match_count++;
                };
            }// else
        }// for (m)
  
        if ( 1 == (match_level & LEVEL_FULL))
        {
            final_str += str1 + " ";
        };
        if ( 0 == match_level )
        {
            final_str += "{?" + str1 + "?} ";
        };

        if (  (1  != (match_level & LEVEL_FULL)) &&  ( 1 == match_count ))
        {
            final_str += strout;
        };

        if ( (1 != (match_level & LEVEL_FULL )) &&  ( 1 < match_count ))
        {
            final_str += "{?" + strout.erase(strout.length() - 1 ,1) + "?} ";
        };
    }// for (n)

    cout << "\n" + final_str + "\n";
    outFile.open (fileToWrite);

    if (outFile.good ())
    {
        printf ("\nWritting result to file \"%s\".",fileToWrite );
        outFile << final_str;
        outFile.close();
    }
    else 
        cout << "File write error!";

    cout << "\nPress \"Enter\" to exit!";
    getchar();
    return 0;
}