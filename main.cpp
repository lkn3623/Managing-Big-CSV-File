#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> book_rating[3000001];
int length = 0;

void read_file() {
        string line, word, tmp;

        int i = 0;
        ifstream fin("Books_rating.csv");

        while (!fin.eof()) {
                getline(fin, line);
                book_rating[i].clear();
                stringstream s(line);

                while (getline(s, word, ','))
                        book_rating[i].push_back(word);
                i++;
        }

        length = i;
        fin.close();
}

bool cmp(vector <string> x, vector <string> y) {
        return x[0] < y[0];
}

void output_file() {
        fstream fout;

        fout.open("sorted_books_rating.csv", ios::out | ios::app);

        for (int i = 0; i < length; i++) {
                for (int j = 0; j < book_rating[i].size(); j++)
                        fout << book_rating[i][j] << ',';
                fout << '\n';
        }
        fout.close();
}

int main() {
        read_file();
        sort(book_rating+1, book_rating+length, &cmp);
        output_file();

        return 0;
}
