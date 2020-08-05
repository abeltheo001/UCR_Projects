/*
    CS 111  Winter 2020
    Coded by Fiorello Estuar and Abel Theodoros
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <numeric>
#include <fstream>
#include <unordered_map>

using namespace std;

void gatherInput(int &e, int &n, char &encr_or_decr)
{
    //Gathering input
    cout << "Input your public key (e,n) starting with e: " << endl;
    cin >> e;
    cout << endl;
    
    cout << "Input n: " << endl;
    cin >> n;
    cout << endl;

    cout << "Type e for encryption or d for decryption: " << endl;
    cin >> encr_or_decr;
    cout << endl;
};

void encrypt(const int e, const int n) 
{
    ifstream inFile ("message.txt");
    ofstream outFile ("incrypted.txt");
    //message to vector of chars. 
    vector <char> encore;
    string temp;
    while (getline(inFile,temp))
    {
        for (char i : temp)
        {
            encore.push_back(i);
        }
    }
    //create map to compare letters to numbers. 
    unordered_map<char,int> m;
    char a = 'A';
    int x = 2;
    while (a <= 'Z')
    {
        m[a] = x;
        a++;
        x++;
    }
    m[' '] = 28;

    //vector of chars to vector of ints
    vector<int> values;
    for (char y: encore)
    {
        values.push_back(m[y]);
    }cout << endl;

    //begin encryption
    for (vector <int>::iterator it = values.begin(); it != values.end(); it++)
    {

        int result = 1;
        x = *it;
        int y = e;
        int p = n;
        cout << "x = " << x << ", y = " << y << ", p = " << p << endl;

        x = x%p;
        while (y > 0)
        {
            if (y % 2 != 0)
            {
                result = (result*x) % p;
            }
            y = y/2;
            x = (x*x) % p;
        }
        cout << result << " " << endl;

        *it = result;

    }

    for (int let : values)
    {
        outFile << let << " ";
    }
    
};

bool Primer(int n)
{
    int i;
    bool pri = true;
    for(i = 2; i <= n/2; ++i)
    {
        if(n % i == 0)
        {
            pri = false;
            break;
        }
    }
    return pri;
}

void decrypt(const int& e, const int& n)
{
    ifstream inFile ("chiphertext.txt");
    ofstream outFile ("decrypted.txt");
    //find p and q
    int p; 
    int q;
    int phiN;
    int d; 

    //create duplicate map for finding numbers to letters;
    unordered_map<int,char> newM;
    char l = 'Z';
    int y = 27;
    newM[28] = ' ';
    while (l >= 'A')
    {
        newM[y] = l;
        y--;
        l--;
    }

    for (int i = 2; i <= n/2; i++)
    {
        if (Primer(i))
        {
            if (Primer(n/i))
            {
                p = i;
                q = n/i;
            }
        }

    }
    //find phi(n) = (p-1)(q-1)
    phiN = (p-1)*(q-1);

    //find d = e^-1 (mod phi(n))
    d = pow(e,-1);
    d %= n;




    return;
};


int main()
{
    int e;
    int n;
    char enc_or_dec;

    //Gathering input
    gatherInput(e, n, enc_or_dec);

    if (enc_or_dec == 'e')
        {
            cout << "encrypt";
            encrypt(e, n);
        }
        
    else if (enc_or_dec == 'd')
        {
            decrypt(e, n);
        }
    
    return 0;
};

