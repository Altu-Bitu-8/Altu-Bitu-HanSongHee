#include <iostream>
#include <string>
using namespace std;
int main() {
    int words_num;
    cin >> words_num;
    string first_words, input_words;
    cin >> first_words;
    int word_frequency[26] = { 0 };
    for (char ch : first_words) {
        word_frequency[ch - 'A']++;
    }
    int similar = 0;
    for (int i = 1; i < words_num; i++) {
        cin >> input_words;
        int input_frequency[26] = { 0 };
        for (char ch : input_words) {
            input_frequency[ch - 'A']++;
        }
        int add_count = 0;
        int remove_count = 0;
        for (int k = 0; k < 26; k++) {
            if (word_frequency[k] > input_frequency[k]) {
                remove_count += word_frequency[k] - input_frequency[k];
            }
            if (word_frequency[k] < input_frequency[k]) {
                add_count += input_frequency[k] - word_frequency[k];
            }
        }
        if (add_count == 1 && remove_count == 1) {
            similar++;
        }
        else if (add_count + remove_count <= 1) {
            similar++;
        }
    }
    cout << similar;

}