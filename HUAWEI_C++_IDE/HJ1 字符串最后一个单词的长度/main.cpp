#include<iostream>
using namespace std;
#if 0
//Ê¹ÓÃcinÂß¼­
int main() {
    string s;
    while (cin >> s);
    cout << s.size();
    return 0;
}
#endif

#if 1
int main() {
    char ch;
    int size = 0;
    do{
        ch = getchar();
        if (ch == ' ') {
            size = 0;
        }
        else if (ch != '\n') {
            size++;
        }
        else {
        
        }
    } while (ch != '\n');
    cout << size << endl;
    return 0;
}
#endif
