#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef std::vector<int> int_vec;
#define TWIDTH 25 // table width

// PrettyTable table({"Operation", "Output"});

int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6}; // p10 permutation
int P8[8] = {6, 3, 7, 4, 8, 5, 10, 9};         // p8 permutation
int P4[4] = {2, 4, 3, 1};                      // p4 permutation
int IP[8] = {2, 6, 3, 1, 4, 8, 5, 7};          // initial permutation
int INVERSE_IP[8] = {4, 1, 3, 5, 7, 2, 8, 6};  // inverse initial permutation
int EP[8] = {4, 1, 2, 3, 2, 3, 4, 1};          // expansion permutation
int S0[4][4] = {
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}}; // S0
int S1[4][4] = {
    {0, 1, 2, 3},
    {2, 0, 1, 3},
    {3, 0, 1, 0},
    {2, 1, 0, 3}}; // S1

string vector_to_string(int_vec v)
{
    string s = "";
    for (int i = 0; i < v.size(); i++)
    {
        s += to_string(v[i]);
        s += " ";
    }
    return s;
}

void print_vector(int_vec &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print_table_header()
{
    cout << "| " << setw(TWIDTH) << left << "Operation"
         << " | " << setw(TWIDTH) << "Output"
         << " |" << endl;
    cout << "| " << setw(TWIDTH) << left << " "
         << " | " << setw(TWIDTH) << " "
         << " |" << endl;
}

void print_table_row(vector<string> row)
{
    cout << "| " << setw(TWIDTH) << row[0] << " | "
         << setw(TWIDTH) << row[1] << " |"
         << endl;
}

class Bits
{
public:
    int size;
    int_vec bits, original_bits;
    Bits(int _size)
    {
        size = _size;
        bits.resize(size);
        original_bits.resize(8);
    }
    void set_bit(int_vec _bits)
    {
        if (_bits.size() != size)
        {
            cout << "Error: Size of bits is not equal to size of the object" << endl;
            return;
        }
        bits = _bits;
    }
    Bits *RLshift()
    {
        int start = size / 2;
        int temp = bits[start];
        for (int i = start; i < size - 1; i++)
        {
            bits[i] = bits[i + 1];
        }
        bits[size - 1] = temp;
        return this;
    }
    Bits *LLshift()
    {
        int end = (size / 2) - 1;
        int temp = bits[0];
        for (int i = 0; i < end; i++)
        {
            bits[i] = bits[i + 1];
        }
        bits[end] = temp;
        return this;
    }
    Bits *Lshift()
    {
        this
            ->RLshift()
            ->LLshift();
        print_table_row({"LeftShift", vector_to_string(bits)});
        return this;
    }
    Bits *P10()
    {
        if (size != 10)
        {
            cout << "Error: P10 on non 10-bit data" << endl;
            return this;
        }
        int_vec temp(10);
        for (int i = 0; i < 10; i++)
        {
            temp[i] = bits[::P10[i] - 1];
        }
        bits = temp;
        print_table_row({"P10", vector_to_string(bits)});
        return this;
    }
    Bits *P8()
    {
        int_vec temp(8);
        for (int i = 0; i < 8; i++)
        {
            temp[i] = bits[::P8[i] - 1];
        }
        bits = temp;
        size = 8;
        print_table_row({"P8", vector_to_string(bits)});
        return this;
    }
    Bits *P4()
    {
        if (size != 8)
        {
            cout << "Error: Size of bits is not equal to 8 bit" << endl;
            return this;
        }
        int_vec temp(8);
        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
                temp[i] = bits[i];
            else
                temp[i] = bits[::P4[i - 4] - 1 + 4];
        }
        bits = temp;
        print_table_row({"P4", vector_to_string(bits)});
        return this;
    }
    Bits *R_xor_with(Bits *b)
    {
        if (size != 12)
        {
            cout << "Error: Size of bits is not equal to 12 bit" << endl;
            return this;
        }
        int_vec temp(size);
        for (int i = 0; i < 12; i++)
        {
            if (i < 4)
                temp[i] = bits[i];
            else
                temp[i] = bits[i] == b->bits[i - 4] ? 0 : 1;
        }
        bits = temp;
        print_table_row({"R_xor_with", vector_to_string(bits)});
        return this;
    }
    Bits *R_xor_with_L()
    {
        if (size != 8)
        {
            cout << "Error: Size of bits is not equal to 8 bit" << endl;
            return this;
        }
        int_vec temp(size);
        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
                temp[i] = bits[i];
            else
                temp[i] = bits[i] == bits[i - 4] ? 0 : 1;
        }
        bits = temp;
        for (int i = 0; i < 4; i++)
        {
            temp[i] = bits[i + 4];
            temp[i + 4] = original_bits[i + 4];
        }
        bits = temp;
        print_table_row({"R_xor_with_L", vector_to_string(bits)});
        return this;
    }
    Bits *IP()
    {
        if (size != 8)
        {
            cout << "Error: Size of bits is not equal to 8 bit" << endl;
            return this;
        }
        int_vec temp(8);
        for (int i = 0; i < 8; i++)
        {
            temp[i] = bits[::IP[i] - 1];
        }
        original_bits = bits = temp;
        print_table_row({"IP", vector_to_string(bits)});
        return this;
    }
    Bits *INVERSE_IP()
    {
        if (size != 8)
        {
            cout << "Error: Size of bits is not equal to 8 bit" << endl;
            return this;
        }
        int_vec temp(8);
        for (int i = 0; i < 8; i++)
        {
            temp[i] = bits[::INVERSE_IP[i] - 1];
        }
        bits = temp;
        print_table_row({"INVERSE_IP", vector_to_string(bits)});
        return this;
    }
    Bits *EP()
    {
        int_vec temp(12);
        for (int i = 0; i < 12; i++)
        {
            if (i < 4)
                temp[i] = bits[i];
            else
                temp[i] = bits[::EP[i - 4] - 1 + 4];
        }
        size = 12;
        bits = temp;
        print_table_row({"EP", vector_to_string(bits)});
        return this;
    }
    Bits *shrink()
    {
        if (size != 12)
        {
            cout << "Error: Size of bits is not equal to 12 bit" << endl;
            return this;
        }
        int_vec temp(8);
        for (int i = 0; i < 4; i++)
        {
            temp[i] = bits[i];
        }
        // for s0
        int a = bits[4], b = bits[7], c = bits[5], d = bits[6]; // ab = row , cd = col
        int row = a * 2 + b, col = c * 2 + d;
        int corresponding_value = S0[row][col];
        temp[4] = corresponding_value / 2;
        temp[5] = corresponding_value % 2;

        // for s1
        a = bits[8], b = bits[11], c = bits[9], d = bits[10]; // ab = row , cd = col
        row = a * 2 + b;
        col = c * 2 + d;
        corresponding_value = S1[row][col];
        temp[6] = corresponding_value / 2;
        temp[7] = corresponding_value % 2;

        size = 8;
        bits = temp;
        print_table_row({"shrink", vector_to_string(bits)});
        return this;
    }
    Bits *swap()
    {
        int_vec temp = bits;
        for (int i = 0; i < 4; i++)
        {
            bits[i] = temp[4 + i];
            bits[4 + i] = temp[i];
        }
        original_bits = bits;
        print_table_row({"SWAP", vector_to_string(bits)});
        return this;
    }
    Bits *complex(Bits *key)
    {
        return this
            ->EP()
            ->R_xor_with(key)
            ->shrink()
            ->P4()
            ->R_xor_with_L();
    }
    void print()
    {
        print_vector(bits);
    }
};

/**
 * @brief Handles SimplifiedDES operations on string
 *
 */
class SimplifiedDES
{
public:
    Bits *plaintext;
    Bits *key, *key1, *key2;
    Bits *ciphertext;
    SimplifiedDES()
    {
        plaintext = new Bits(8);
        key = new Bits(10);
        key1 = new Bits(10);
        key2 = new Bits(10);
        ciphertext = new Bits(8);
    }
    void set_key(int_vec _key)
    {
        key->set_bit(_key);
        key1->set_bit(_key);
    }
    void set_plaintext(int_vec _plaintext)
    {
        plaintext->set_bit(_plaintext);
    }
    void execute()
    {
        cout << endl
             << "KEY 1:" << endl;
        print_table_header();
        Bits *temp_plaintext = new Bits(8);
        temp_plaintext->set_bit(plaintext->bits);
        // generate key1 and key2
        key1->P10()
            ->Lshift();
        key2->set_bit(key1->bits); // copy key1 to key2
        key1->P8();
        cout << endl
             << "KEY 2:" << endl;
        print_table_header();
        key2
            ->Lshift()
            ->Lshift()
            ->P8();

        // now start encryption
        cout << endl
             << "PLain Text:" << endl;
        print_table_header();
        ciphertext = temp_plaintext
                         ->IP()
                         ->complex(key1)
                         ->swap()
                         ->complex(key2)
                         ->INVERSE_IP();
    }
    void display()
    {
        cout << endl
             << "Plaintext: ";
        plaintext->print();
        cout << "Key: ";
        key->print();
        cout << "Sub Key1: ";
        key1->print();
        cout << "Sub Key2: ";
        key2->print();
        cout << "Ciphertext: ";
        ciphertext->print();
        cout << endl;
    }
};

int main()
{
    int choice = 0;
    int temp_int = 0;
    int_vec temp;
    SimplifiedDES encryptor;
    // encryptor.set_key({1, 0, 1, 0, 0, 0, 0, 0, 1, 0});
    // encryptor.set_plaintext({1, 0, 0, 1, 0, 1, 1, 1});
    // encryptor.execute();
    // encryptor.display();
    // return 0;
    choice = 1;
    do
    {
        cout << endl
             << "0. Exit" << endl
             << "1. Set Key" << endl
             << "2. S-DES" << endl
             << "Enter choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter key: ";
            temp.clear();
            for (int i = 0; i < 10; i++)
            {
                cin >> temp_int;
                temp.push_back(temp_int);
            }
            encryptor.set_key(temp);
            break;
        case 2:
            cout << "Enter plaintext: ";
            temp.clear();
            for (int i = 0; i < 8; i++)
            {
                cin >> temp_int;
                temp.push_back(temp_int);
            }
            encryptor.set_plaintext(temp);
            encryptor.execute();
            encryptor.display();
            break;
        default:
            cout << endl
                 << "Invalid Choice!";
        }
        cout << endl;
    } while (choice != 0);
    cout << endl;
    return 0;
}
// 1 1 0 1 0 0 0 0 0 1 0 2 1 0 0 1 0 1 1 1

/*

* user entry
?data    = 1 0 0 1 0 1 1 1
?key     = 1 0 1 0 0 0 0 0 1 0

* InitialPermutation
?ip      = 2 6 3 1 4 8 5 7
?ip^-1   = 4 1 3 5 7 2 8 6

* permutations
?p10 = 3 5 2 7 4 10 1 9 8 6
?p8  = 6 3 7 4 8 5 10 9
?p4  = 2 4 3 1
?E/P = 4 1 2 3 2 3 4 1

* key generation
p10(key)    = 1 0 0 0 0 0 1 1 0 0
!Lshift	    = 0 0 0 0 1 1 1 0 0 0
?P8,key1	= 1 0 1 0 0 1 0 0
!2Lshift	= 0 0 1 0 0 0 0 0 1 1
?P8,key2	= 0 1 0 0 0 0 1 1

* encryption
!ip(data)       = 0 1 0 1 1 1 0 1
!E/P(R)         = 0 1 0 1 1 1 1 0 1 0 1 1
!XOR(key1)      = 0 1 0 1 0 1 0 0 1 1 1 1
!S0,S1(R)       = 0 1 0 1 1 1 1 1
!p4(R)          = 0 1 0 1 1 1 1 1
!XOR(L)         = 1 0 1 0 1 1 0 1
?SWAP(R,L)      = 1 1 0 1 1 0 1 0
!E/P(R)         = 1 1 0 1 0 1 0 1 0 1 0 1
!XOR(key2)      = 1 1 0 1 0 0 0 1 0 1 1 0
!S0,S1(R)       = 1 1 0 1 1 1 1 1
!p4(R)          = 1 1 0 1 1 1 1 1
!XOR(L)         = 0 0 1 0 1 0 1 0
!ip-1(data)     = 0 0 1 1 1 0 0 0

*/

/*

0 1 0 0 1 1 1 1

0 1 0 0

row = 00 = 0
col = 10 = 2
s0 = 3 = 11

1111 = 11

1111

*/