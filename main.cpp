/*
    Name: Pig-Latin Encoder

    Author: Dovi Salomon

    Description: Reads in a file and prints a pig-latin version to
                 a file. The program leaves all whitespace and
                 punctutation alone.
*/

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>

using namespace std;

int main ()
{
    int c, word[50], letterCount=0, charCount=0, wordCount=0, j;

    //Opening file for input
    ifstream gettyburg;
    gettyburg.open("/Users/dovisalomon/test.txt");
    if ( !gettyburg.is_open() ) {
        //Sending error message to console.
        cerr << "\nERROR: Unable to open file.\n";
        exit(1);
    }
    gettyburg.clear();

    //Opening file for output
    ofstream outfile;
    outfile.open("/Users/dovisalomon/output.txt");

    int i=0; //setting the array index to first position

    c = gettyburg.get();
    while ( !gettyburg.eof() ) {
        //Skipping whitespace and punctuation before a word
        while (!isalpha(c)) {
            outfile.put(c);
            charCount++;
            c = gettyburg.get();
        }

        //reading a word into the array
        while (isalpha(c)) {
            word[i] = c;
            i++;
            c = gettyburg.get();
        }

        //If word begins in uppercase make the second word uppercase
        //and first letter to the end as lowercase.
        if ( isupper(word[0]) ) {
            word[1] = toupper(word[1]);
            word[i] = tolower(word[0]);
        }
        //If word begin lowercase, just add the first word to the end
        else
            word[i] = word[0];

        //adding 'a' and 'y' to the end of the word
        word[i+1] = 'a';
        word[i+2] = 'y';

        //sending the pig latin form of the word to the output file
        for (j=1; j<=i+2; j++) {
            outfile.put( word[j] );
            letterCount++;
        }
        wordCount++;

        //reading in the whitespace and punctutaion after the word
        while (!isalpha(c) && !gettyburg.eof() ) {
            outfile.put(c);
            charCount++;
            c = gettyburg.get();
        }
        i=0; //resetting the array index for the next word
    }

    //Final Report:
    outfile << endl << "Word Count: " << wordCount << endl;
    outfile << "Letter Count: " << letterCount << endl;
    outfile << "Character Count: " << charCount + letterCount << endl;

    //Message for the console:
    cout << endl
         << "Text from /Users/dovisalomon/test.txt has been encoded "
         << "into pig-latin" << endl
         << "Results can be found at /Users/dovisalomon/output.txt"
         << endl
         << "Thank you for using Dovi Salomon's Pig-latin encoder"
         << endl << endl;

    //housekeeping
    outfile.close();
    gettyburg.close();
    return 0;
}
