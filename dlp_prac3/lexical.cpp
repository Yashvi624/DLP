#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Set of C keywords
const unordered_set<string> keywords = {
    "int", "char", "return", "if", "else", "while", "for", "float", "double", "void", "main"
};

void analyze(const string& code) {
    regex keyword_regex("\\b[a-zA-Z_][a-zA-Z0-9_]*\\b");
    regex punctuation_regex("[{}();=,]|'.'");
    regex error_regex("\\b[a-zA-Z_][a-zA-Z0-9_]*[0-9]+\\b|\\b[0-9]+[a-zA-Z_]+\\b|[^\\s]+@");
    smatch match;

    int keyword_count = 0;
    vector<string> identified_keywords;
    int punctuation_count = 0;
    vector<string> identified_punctuations;
    vector<string> errors;

    string::const_iterator search_start = code.cbegin();

    // Find and categorize keywords
    while (regex_search(search_start, code.cend(), match, keyword_regex)) {
        string token = match[0];
        if (keywords.count(token)) {
            keyword_count++;
            identified_keywords.push_back(token);
        }
        search_start = match.suffix().first;
    }

    // Find and categorize punctuation marks
    search_start = code.cbegin();
    while (regex_search(search_start, code.cend(), match, punctuation_regex)) {
        punctuation_count++;
        identified_punctuations.push_back(match[0]);
        search_start = match.suffix().first;
    }

    // Find errors
    search_start = code.cbegin();
    while (regex_search(search_start, code.cend(), match, error_regex)) {
        errors.push_back(match[0]);
        search_start = match.suffix().first;
    }

    // Output results
    cout << "Keywords found (" << keyword_count << "): ";
    for (const string& kw : identified_keywords) cout << kw << " ";
    cout << endl;

    cout << "Punctuation marks found (" << punctuation_count << "): ";
    for (const string& punct : identified_punctuations) cout << punct << " ";
    cout << endl;

    cout << "Errors found (" << errors.size() << "): ";
    for (const string& err : errors) cout << err << " ";
    cout << endl;
}

int main() {

    vector<string> files = {"file1.c", "file2.c", "file3.c","input.c"};

    for (const string& file : files) {
        ifstream input_file(file);
        if (!input_file) {
            cerr << "Error: Could not open " << file << endl;
            continue;
        }

        string code((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
        input_file.close();

        cout << "\nAnalyzing " << file << "\n";
        analyze(code);
    }

    return 0;
}
