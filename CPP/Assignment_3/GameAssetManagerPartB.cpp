//============================================================================
// Name        : GameAssetManagerPartB.cpp
// Author      : Mansi Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Shader {
private:
    string name;
    string type;

public:

    Shader(string n, string t) {
        name = n;
        type = t;

        cout << "[Shader Compiled]" << endl;
    }

    ~Shader() {
        cout << "[Shader Destroyed]" << endl;
    }
};

int main() {

    auto shader = make_shared<Shader>(
        "main_vert", "vertex"
    );

    cout << "Ref count: "
         << shader.use_count() << endl;

    {

        auto rendererRef = shader;

        cout << "Ref count: "
             << shader.use_count() << endl;

        auto editorRef = shader;

        cout << "Ref count: "
             << shader.use_count() << endl;
    }
    cout << "Ref count: "
         << shader.use_count() << endl;

    return 0;
}
