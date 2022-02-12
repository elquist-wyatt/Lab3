//
//  main.cpp
//  Lab3
//
//  Created by Wyatt Elquist on 2/11/22.
//

#include <iostream>
#include <fstream>
using namespace std;

class copyandAppend{
public:
    
    copyandAppend (string i, string o, string a){
        string word;
        string line;
        ifstream aFile (i);
        ofstream file (o);
        file << "What follows is the contents of " << i << "\n";
        if (aFile.is_open()){
                while( getline (aFile, word)){
                    file << word << "\n";
                }
                } else {
                cout << "unable to access file\n";
            }
        aFile.close();
        file.close();
        
        ifstream outfile (o);
        ofstream appendfile (a, ios::app);
        if (outfile.is_open()){
            while (getline (outfile, line)){
                appendfile << line << "\n";
            }
        }else {
            cout << "unable to append";
        }
        outfile.close();
        appendfile.close();
    }
    
    ~copyandAppend(){
        cout << "The job is done\n";
    }
private:
    
};

int main() {
    copyandAppend ("input-File.txt", "output-File.txt", "appendme.txt");
    return 0;
}
