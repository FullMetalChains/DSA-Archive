#include <iostream>
#include <vector>
#include <string>

using namespace std;

class z_algorithm{
public:
    string text, pattern;
    vector<int>ztable;

    z_algorithm(string t, string p){
        text = t;
        pattern = p;
        ztable.resize(text.size() + pattern.size());
    }

    vector<int> search(){
        constructTable();
        vector<int>pos;
        for(int i = 0;i<ztable.size();i++){
            if(ztable[i] >= pattern.size()){
                if(i - pattern.size() >= 0 && i - pattern.size() < pattern.size()){
                    pos.push_back(i - pattern.size());
                }
            }
        }
        return pos;
    }

    void constructTable(){
        string patternText = pattern + text;
        int n = patternText.size(), left = 0, right = 0;
        for(int k = 1;k < n;k++){
            if(k > right){
                int matchCounter = 0;
                while(k + matchCounter < n && patternText[matchCounter] == patternText[k + matchCounter]){
                        matchCounter++;
                }
                ztable[k] = matchCounter;
                if(matchCounter > 0){
                    left = k;
                    right = k + matchCounter - 1;
                }
            }
            else{
                int p = k - left;
                if(ztable[p] < right - k + 1){
                    ztable[k] = ztable[p];
                }
                else{
                    int i = right + 1;
                    while(i < n && patternText[i] == patternText[i - k]){
                        i++;
                    }
                    ztable[k] = i - k;
                    left = k;
                    right = i - 1;   
                }
            }
        }
    }
};
