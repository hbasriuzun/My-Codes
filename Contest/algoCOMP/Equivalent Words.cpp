#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

#include <array>


using namespace std;

void Find_number_of_each_letter(vector<pair<string,map<char,int>>>* Omer_words){
    char letter = 'a';
    for (size_t i = 0; i < Omer_words->size() ; i++)
    {
            for(int j; j < 23 ;j++){
            Omer_words->at(i).second[letter++] = 0;
        }
    }

    for (size_t i = 0; i < Omer_words->size(); i++)
    {
        for (size_t j = 0; j < Omer_words->at(i).first.size(); j++)
        {
            Omer_words->at(i).second[Omer_words->at(i).first[j]]++;
        }
    }
}

vector<vector<int>> equivalent_words(vector<pair<string,map<char,int>>>* Omer_word, vector<pair<string,map<char,int>>>* Murat_word){
    vector<vector<int>> result(Murat_word->size()); 

    for (size_t i = 0; i < Murat_word->size(); i++)
    {
        for (size_t j = 0; j < Omer_word->size(); j++)
        {
            if(Omer_word->at(i).second == Murat_word->at(j).second){
                result.at(i).push_back(j+1);
            }
            
        }
    }

    
    return result;
}

int main(){
    int Omer_words_number, Murat_words_number;
    cin >> Omer_words_number >> Murat_words_number;

    vector<pair<string,map<char,int>>> Omer_words(Omer_words_number);
    vector<pair<string,map<char,int>>> Murat_words(Murat_words_number);

    for(int i = 0; i < Omer_words_number; i++){
        cin >> Omer_words[i].first;
    }

    for(int i = 0; i < Murat_words_number; i++){
        cin >> Murat_words[i].first;
    }

    Find_number_of_each_letter(&Omer_words);
    Find_number_of_each_letter(&Murat_words);

    vector<vector<int>> result = equivalent_words(&Omer_words, &Murat_words);

    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}