#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}


//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
//TODO
bool WordMean::operator< (const WordMean& wm2) const {
     return (this->word < wm2.word);
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
//TODO
void Dictionary::readFile(ifstream &f) {
    string word, mean;
    while (!f.eof()) {
        getline(f, word );
        getline(f, mean);
        WordMean p(word,mean);
        words.insert(p);


    }

}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {

    for(set<WordMean>::iterator i = words.begin(); i != words.end(); i++) {
        cout << i->getWord() << '\n' << i->getMeaning() << '\n';
    }
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    previous = WordMean("", "");
    next = WordMean("","");
    string res = "word not found";
    set<WordMean>::iterator tmp = words.begin();
    tmp++;
    for (set<WordMean>::iterator it = words.begin(); it != words.end(); it++, tmp++) {
        if (it->getWord()  == w1) {
            return it->getMeaning();
        }
        if(  it->getWord() < w1 && w1 < tmp->getWord()) {
            previous = *it;
            next = *tmp;
        }

    }

    return res;







    return "";
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
bool Dictionary::update(string w1, string m1) {
    return true;
}
