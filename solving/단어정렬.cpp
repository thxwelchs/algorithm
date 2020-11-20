#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Word {
    char cc;
    bool isEnd = false;
    int count = 0;
    Word* children[26];
    Word(): isEnd(false) {
        for(int i = 0; i < 26; i++) children[i] = NULL;
    }

    ~Word() {
        for (int i = 0; i < 26; i++) {
            if(children[i]) delete children[i];
        }
    }

    void insert(string s, bool isRoot) {
        if(s.size() > 1) {
            char c = s.at(0);

            int next = c - 'a';
            if(children[next] == NULL) children[next] = new Word();

            children[next] -> insert(s.substr(1, s.size()), false);
            children[next] -> cc = c;
        }
        isEnd = true;
        count++;
    }

    void find(string s) {
        if(isEnd){
            for(int i = 0; i < count; i++) {
                cout << s << '\n';
                cout << '\n';
            }
        } 

        for(int i = 0; i < 26; i++) {
            if(children[i] == NULL) continue;
            s += (char)( i + 'a' );
            children[i]->find(s);
        }
    }
};


Word* words[51];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < 51; i++) {
        words[i] = NULL;
    }

    int maxSize = 0;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int size = s.size();
        maxSize = max(maxSize, size);
        if(words[size] == NULL) {
            words[size] = new Word();
        }
        words[size]->insert(s, true);
        // words[size].count++;
        // words[size].insert(s);
    }

    // for(int i = 1; i <= maxSize; i++) {
    //     if(words[i] == NULL) continue;
    //     words[i]->find("");
    // }
    
    return 0;
}