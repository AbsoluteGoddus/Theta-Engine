#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include <fstream>

using namespace std;

bool a = false;
bool debug = false;

float vPos[2][2] = {
    {1.0, 1.0},
    {1.0, 1.0}
};

double toDegrees(int a) {
    return a * (M_PI / 360);
}

double toRadians(int a) {
    return a * (M_PI / 180);
}

void add_Force1d(int unit, float Angle, float force1d) {
        vPos[unit][0] += cos(toRadians(Angle)) * force1d;
        vPos[unit][1] += sin(toRadians(Angle)) * force1d;
}
void add_Force2d(int unit, float Angle, float force1d,float force2d) {
        vPos[unit][0] += cos(toRadians(Angle)) * force1d;
        vPos[unit][1] += sin(toRadians(Angle)) * force1d;
        vPos[unit][0] += cos(toRadians(Angle + 90)) * force2d;
        vPos[unit][1] += sin(toRadians(Angle + 90)) * force2d;
}
void add_Force3d(int unit, float Angle, float force1d, float force2d, float force3d) {
        vPos[unit][0] += cos(toRadians(Angle)) * force1d;
        vPos[unit][1] += sin(toRadians(Angle)) * force1d;
        vPos[unit][0] += cos(toRadians(Angle + 90)) * force2d;
        vPos[unit][1] += sin(toRadians(Angle + 90)) * force2d;
        vPos[unit][0] += cos(toRadians(Angle + 180)) * force3d;
        vPos[unit][1] += sin(toRadians(Angle + 180)) * force3d;
}

void initializer(string version) {
    cout << "using Theta-Engine v." << version << endl << "Developed by CSS and RT studios." << endl << "state: STABLE" << endl << "Debug? ";
    string an;
    cin >> an;
    if (an == "y" || an == "yes" || an == "true") {
        cout << "[Debug] debugMode.state == true" << endl;
        debug = true;
    } else if (an == "n" || an == "no" || an == "false") {
        cout << "[Debug] debugMode.state == false" << endl;
        debug = false;
    } else {
        cout << "Invalid command!" << endl << "[Debug] debugMode.state == false" << endl;
        debug = false;
    }
}

string Readline(const string& location, const string& name, int line) {
    ifstream file(location + name);
    string out;

    if (!file.is_open()) {
        return "ERR: Unable to open file!";
    }

    // Check if line is within the valid range
    int totalLines = 0;
    string temp;
    while (getline(file, temp)) {
        totalLines++;
    }

    file.clear(); // Reset file flags
    file.seekg(0, ios::beg); // Move file cursor to the beginning

    if (line <= 0 || line > totalLines) {
        file.close();
        return "ERR: Invalid line number (" + to_string(line) + "/" + to_string(totalLines) + ")!";
    }

    // Read the desired line
    for (int i = 1; i <= line; i++) {
        if (!getline(file, out)) {
            file.close();
            return "ERR: Error reading line " + to_string(i) + "!";
        }
    }

    file.close();
    return out;
}







void inputHandler() {
    string input = "";
    string last_print = "";
    string tmp0 = "";
    string tmp1 = "";
    string tmp2 = "";
    string tmp3 = "";
    string tmp4 = "";
    string tmp5 = "";
    string tmp6 = "";
    string tmp7 = "";
    string tmp8 = "";
    string tmp9 = "";
    int tmp10 = 0;
    int tmp11 = 0;
    int tmp12 = 0;
    int tmp13 = 0;
    int tmp14 = 0;
    int tmp15 = 0;
    int tmp16 = 0;
    int tmp18 = 0;
    int tmp19 = 0;
    float tmp20 = 0.0;
    float tmp21 = 0.0;
    float tmp22 = 0.0;
    float tmp23 = 0.0;
    float tmp24 = 0.0;
    float tmp25 = 0.0;
    float tmp26 = 0.0;
    float tmp27 = 0.0;
    float tmp28 = 0.0;
    float tmp29 = 0.0;
    bool tmp30 = false;
    bool tmp31 = false;
    bool tmp32 = false;
    bool tmp33 = false;
    bool tmp34 = false;
    bool tmp35 = false;
    bool tmp36 = false;
    bool tmp37 = false;
    bool tmp38 = false;
    bool tmp39 = false;

    cout << "Please enter a Command" << endl;
    cin >> input;

    if (input == "exit" || input == "quit") {
        a = true;
    } else if (input == "vPos") {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << vPos[i][j] << " ";
                last_print += to_string(vPos[i][j]) + " ";
            }
            cout << endl;
        }
    } else if (input == "add_Force") {
        cout << "Dimension: ";
        cin >> tmp1;
        if (stoi(tmp1.substr(0, tmp1.length() - 1)) >= 1){
            tmp12 = stoi(tmp1.substr(0, tmp1.length() - 1));
        }
            cout << endl << "Vertex: ";
            cin >> tmp11;
            cout << endl << "Angle: ";
            cin >> tmp20;
        if (tmp12 == 1){
            cout << endl << "Force: ";
            cin >> tmp21;
            tmp30 = true;
        }else if (tmp12 == 2){
            cout << endl << "Force X: ";
            cin >> tmp21;
            cout << endl << "Force Y: ";
            cin >> tmp22;
            tmp30 = true;
        }else if (tmp12 == 3){
            cout << endl << "Force X: ";
            cin >> tmp21;
            cout << endl << "Force Y: ";
            cin >> tmp22;
            cout << endl << "Force Z: ";
            cin >> tmp23;
            tmp30 = true;
        }else{
            cout << "invalid Dimension";
        }
        cout << endl;
        
        if (tmp30){
            if (tmp1 == "1d"){ 
                add_Force1d(tmp11, tmp20, tmp21);
            }else if (tmp1 == "2d"){
                add_Force2d(tmp11, tmp20, tmp21, tmp22);
            }else if (tmp1 == "3d"){

            }
        }
    } else if (input == "clear" || input == "home") {
        system("cls");
    } else if (input == "c_vPos") {
        system("cls");
                for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << vPos[i][j] << " ";
                last_print += to_string(vPos[i][j]) + " ";
            }
            cout << endl;
        }
    }else if (input == "getBuffer" && debug == true){
        cout << "[Debug] location?";
        cin >> tmp0;
        cout << endl;
        cout << "[Debug] Name?";
        cin >> tmp1;
        cout << endl;
        cout << "[Debug] Line?";
        cin >> tmp10;
        cout << endl;
        if (tmp0 == "empty" || tmp0 == "null"){
           tmp0 = ""; 
        }
        cout << Readline(tmp0, tmp1, tmp10) << endl;
    } else {
        cout << "!invalid command!" << endl;
    }
}

int main() {
    initializer("0.1.2");
    while (!a) {
        inputHandler();
    }

    return 0;
}