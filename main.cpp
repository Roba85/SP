// Author: Roba Ahmed
// This program ciphers and deciphers text using xor enctyption
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string xorHexaValidation();
string xorKeyValidation ();
void xorEncryption();
void xorDecryption ();

int main()
{
    // Main menu
    cout << "Welcome to XOR encryption\n";
    while (true)
    {
        cout << "Please choose:\nA. Encrypt a text\nB. Decrypt a cipher hexadecimal\nC. Exit\n";
        char xChoice;
        cin >> xChoice;
        xChoice = toupper(xChoice);
        // Directing the user towards the appropriate function
        switch (xChoice) {
            case 'A':
                xorEncryption();
                break;
            case 'B':
                xorDecryption();
                break;
            case 'C':
                cout << "===== OK BYE =====";
                return 0;
            default:
                cerr << "Error. Please enter a valid choice\n";
        }
    }
}

void xorEncryption ()
{
    cout << "===== Encryption =====\n";
    string xPlain;
    cout << "Please input the plain text\n";
    getline(cin >> ws, xPlain);
    string xKey = xorKeyValidation();
    vector<int> xorInt;
    // Making sure the key is not shorter than the plain text
    int nPlain = xPlain.length();
    while (xKey.length() < nPlain)
    {
        xKey += xKey;
    }

    cout << "Cipher Text: ";
    for (int i = 0; i < nPlain; i++)
    {
        // Performing XOR on each character
        int xTemp = static_cast<int>(xPlain[i] ^ xKey[i]);
        xorInt.push_back(xTemp);
        // Character is printed if it is within range
        if (xTemp >= 32 && xTemp <= 126)
        {
            cout << static_cast<char>(xTemp);
        }
    }
    cout << '\n';
    // Printing as hexadecimal
    for (int i = 0; i < nPlain; i++)
    {
        cout << hex << xorInt[i] << ' ';
    }
    cout << '\n';
}
void xorDecryption ()
{
    cout << "===== Decryption =====\n";
    string xKey = xorKeyValidation(), xCipherHex = xorHexaValidation();
    // Converting hexadecimal values to decimal
    vector<int> xDec;
    for (int j = 0, nHex = xCipherHex.length(); j < nHex; j += 2)
    {
        if (xCipherHex[j] == 32)
        {
            j++;
        }
        string xTempHexa = xCipherHex.substr(j, 2);
        int xDecTemp = stoi(xTempHexa, 0, 16);
        xDec.push_back(xDecTemp);
    }
    // Ensuring the key and the encrypted text are the same length
    int nDec = xDec.size();
    while (xKey.length() < nDec)
    {
        xKey += xKey;
    }
    // Performing XOR on each character
    string xDeciphered;
    for(int k = 0; k < nDec; k++)
    {
        xDeciphered += static_cast<char>(xKey[k] ^ xDec[k]);
    }
    cout << "The word is " << xDeciphered << '\n';
}

string xorKeyValidation ()
{
    string xCode;
    cout << "Please input the key\n";
    // Ensuring the key contains only letters
    bool isValid = true;
    while ((isValid))
    {
        // ws is used to ignore any whitespaces
        getline(cin >> ws, xCode);
        for (int i = 0; i < xCode.length(); i++)
        {
            isValid = false;
            if (!(isalpha(xCode[i])))
            {
                cout << "The key must be all alphabet with no spaces\n";
                // Setting the flag to continue the loop
                isValid = true;
                break;
            }
        }
    }
    return xCode;
}

string xorHexaValidation()
{
    cout << "Cipher hexa: ";
    string xHex;
    bool isHexa = true;
    while (isHexa)
    {
        getline(cin >> ws, xHex);
        isHexa = false;
        for (int i = 0, nHex = xHex.length(); i < nHex; i++)
        {
            // Checking if the character is hexadecimal or space. Other values are rejected
            if ((xHex[i] < '0' || xHex[i] > '9') && (xHex[i] < 'a' || xHex[i] > 'f') && (xHex[i] != 32))
            {
                cout << "Please enter a hexadecimal value\n";
                isHexa = true;
                break;
            }
        }
    }
    return xHex;
}