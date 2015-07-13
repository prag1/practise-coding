#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;


string decode(string input, int level)
{
    int in_start, in_run, out_start, out_run, even;
    int len = input.length();
    string output(len, '\0');
    int increIndex[level];
    int curLevel = 1;
    in_start = 0;
    out_start = 0;
    while(in_start<len) {
        in_run = in_start;
        out_run = out_start;
        even = 0;
        while(out_run<len) {
            //Place the input character in its right position
            if(output[out_run]=='\0'){ 
                output.replace(out_run,1, input, in_run, 1);
                in_run++;
            } 
            //Determine the next character position in output
            if(even==0 && level!=curLevel) {
                out_run +=  (level - curLevel)*2;
            } else if (even==1 && curLevel!=1) {
                out_run += (curLevel - 1)*2;
            } else {
                out_run += (level - 1)*2;
            }
            even = (even + 1)%2;
        }
        in_start = in_run;
        out_start++;
        curLevel++;
    }
    return output;

}

string encode(string input, int level) 
{
    int i,j;
    int len = input.length();
    vector< vector<char> > process_str(len);
    i = 0;
    
    while(i<len) {
        j=0;
        while(j<level && i<len) 
            process_str[j++].push_back(input[i++]);
        j = level - 2;;
        while(j>0 && i<len)
            process_str[j--].push_back(input[i++]);
    }
    string output;
    for(i=0; i<len; i++) {
        for(vector<char>::iterator it=process_str[i].begin(); it!=process_str[i].end(); it++)
            output.push_back(*it);
    }

    return output;
}

int main(int argc, char** argv) {
    string s = encode("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG", 4);
    cout << s << "\n";
    string s1 = encode("REDDITCOMRDAILYPROGRAMMER", 3);
    cout << s1 << "\n";
    string s3 = decode("RIMIRAREDTORALPORMEDCDYGM", 3);
    cout << s3 << "\n";
    string s4 = decode("AAPLGMESAPAMAITHTATLEAEDLOZBEN", 6);
    cout << s4 << "\n"; 
    
}
 
