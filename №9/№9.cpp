#include <iostream> 
#include<fstream> 
#include <string> 
using namespace std;

typedef struct word {
    int j;
    char* a;
}word;

int main() {

    int n, t, k, count = 0;
    cin >> n;

    char c;
    //unordered_map <int, char*> a; 
    word* w = (word*)malloc(n * sizeof(word));
    w->j = 0;
    for (int i = 0; i < n; i++) {

        cin >> t;
        cin >> k;

        switch (t)
        {
        case 0: {
            w[w->j].a = (char*)malloc(k + 2 * sizeof(char));
            cin >> w[w->j].a;
            w->j++;
        }break;
        case 1: {
            free(w[k].a);

        }break;
        case 2: {
            printf("%s\n", w[k].a);

        }break;
        case 3: {
            count = 0;
            cin >> c;
            int h = strlen(w[k].a);
            for (int i = 0; i < h; i++) {
                if (w[k].a[i] == c) {
                    count++;
                }
            }
            cout << count << "\n";

        }break;
        }
    }
}