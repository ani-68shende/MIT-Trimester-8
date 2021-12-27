// Name : Aniruddha Shende
// Roll no : PE04
// Batch : E1
// Panel : E
#include <iostream>
using namespace std;

// This function receives str and shift and
// returns the encrypted str
string encrypt(string str, int s)
{
    string encrypted_string = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i]) >= 'A' && (str[i]) <= 'Z')
            encrypted_string += char(int(str[i] + s - 65) % 26 + 97);
        else
            encrypted_string += char(int(str[i] + s - 97) % 26 + 65);
    }
    return encrypted_string;
}

string decrpyt(string str, int s)
{
    string decrypted_string = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i]) >= 'A' && (str[i]) <= 'Z')
            decrypted_string += char(int(str[i] - s - 65) % 26 + 97);
        else
            decrypted_string += char(int(str[i] - s - 97) % 26 + 65);
    }
    return decrypted_string;
}

// Driver program to test the above function
int main()
{
    char ch = true;
    while (ch == true)
    {
        string str;
        cout << "Enter the string you want to Encrypt or Decrypt : ";
        cin >> str;
        int s;
        cout << "Enter Key : ";
        cin >> s;
        cout << "1. Encrypt \n2. Decrypt \n\nEnter your choice\n";
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "\nEncrypted str is: " << encrypt(str, s);
        }
        else if (n == 2)
        {
            cout << "\nDecrypted str is: " << decrpyt(str, s);
        }
        else
        {
            return 0;
        }
        cout << "\n\nDo you want to continue ?? (1->yes)";
        int choice;
        cin >> choice;
        (choice == 1) ? ch = true : ch = false;
    }
    return 0;
}