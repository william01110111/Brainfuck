
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

bool loadFile(string filename, string& contents, bool debug=false);
bool writeFile(string filename, string& contents, bool debug=false);

string getDirOfPath(string path);
