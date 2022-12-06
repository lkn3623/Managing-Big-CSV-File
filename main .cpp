#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

vector <string> book_rating[3000001];
int length = 0;

void doc()
{
    int i = 0;
    ifstream input("Books_rating.csv");
    string line, word, tmp;
    while (!input.eof()) {
            getline(input, line);
            book_rating[i].clear();
            stringstream s(line);
            while (getline(s, word, ','))
                    book_rating[i].push_back(word);
            i++;
    }
    length = i;
    input.close();
}

int main()
{
    doc();
}
