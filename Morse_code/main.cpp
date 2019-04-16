#include <string>
#include <iostream>
#include <algorithm>
#include<windows.h>
#include<time.h>
using namespace std;
string texttomorse(string);
string morsetotext(string);
void dot();
void dash();
void soundplayer(string x);

char text[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
 '1','2','3','4','5','6','7','8', '9','0' };

 string morse[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
 ".----","..---","...--","....-",".....","-....","--....","---..","----.","-----"};

string vig_generate_key(string str, string key)
{
    int x = str.size();

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}


string vig_cipherText(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++)
    {

        int x = (str[i] + key[i]) %26;


        x += 'A';

        cipher_text.push_back(x);
    }
    return cipher_text;
}


string vig_originalText(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0 ; i < cipher_text.size(); i++)
    {

        int x = (cipher_text[i] - key[i] + 26) %26;


        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

string convert_to_ceaser(string s, int key)
{
    int n = s.length();
    int k = 0;
    string c="";
    while(n--)
    {
        int a = s[k];
        a = (a-65);
        a = (a + key)%26;
        char ch = (a+65);
        string s(1,ch);
        c  = c+s;
        k++;
    }
cout<<endl;
return c;
}
string back_to_org(string s,int key)
{
    int n = s.length();
    int k = 0;
    string c="";

    while(n--)
    {
        int a = s[k];
        a = (a -65);
        a = (a-key);
        if(a<0)
            a = a + 26;
        //cout<<a<<" ";
        char ch = (a + 65);
        string s(1,ch);
        c  = c+s;
        k++;
    }
return c;
}

int main()
{
    string str1;
    string str;
    cout << "Enter the Text You Wish to transfer via Morse Code : ";
    getline(cin,str1);
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    int n = str1.length();
    int i = 0;
    while(n--)
    {
        char ch = str1[i];
        if(ch!=' ')
            str+=ch;
        i++;
    }
    //cout<<str<<" ";
    //calling vignere cipher
    cout<<endl<<"****Applying Vigenere cipher****"<<endl<<endl;
    cout<<"Vigenere cipher original message: "<<str<<endl<<endl;
    string vig_k = "AMAR";
    vig_generate_key(str, vig_k);
    string vig_key = vig_generate_key(str, vig_k);
    string vig_cipher_text = vig_cipherText(str, vig_key);
    cout << "Vigenere Ciphertext (Encrypted Message ): "<<vig_cipher_text <<endl<<endl;

    cout<<endl<<"****Applying Additive cipher****"<<endl<<endl;
    srand(time(0));
    int add_a = rand()%26;
    string additive_cipher_text = convert_to_ceaser(vig_cipher_text,add_a);
    cout<<"Original Message for Additive cipher:"<<vig_cipher_text<<endl<<endl;
    cout<<"Additive Cipher Text is :"<<additive_cipher_text<<endl<<endl;



    cout<<endl<<"****Applying Morse Code****"<<endl<<endl;
    cout << "Your Entered Text in Morse Code:\n"<<endl;
    string morse_cipher = texttomorse(additive_cipher_text);
    cout<<endl<<endl<<"Morse code cipher-text is :"<<morse_cipher<<" "<<endl;
    string plain_text = morsetotext(morse_cipher);
    cout<<"Morse Code Original Message(Plain-Text) :"<<plain_text<<endl<<endl;

    cout<<"Additve cipher Original message after Decryption is :"<<back_to_org(additive_cipher_text,add_a)<<endl;

    cout<<endl<<endl<<"The Vignere original Message (Plain-Text) is :"<<vig_originalText(vig_cipher_text, vig_key)<<endl<<endl;
}

string texttomorse(string str)
{
    string temp="";
    for (int i = 0; i<str.length(); ++i)
    {
        for (int counter = 0; counter < 36; counter++)
        {
            if(str[i] == text[counter])
            {
                temp+=morse[counter];
                temp+="$";
                cout << morse[counter];
                soundplayer(morse[counter]);
            }
        }
    }
    return temp;
}
string morsetotext(string mc)
{
    string temp1="";
    cout<<endl<<endl;
    int n = mc.length();
    cout<<"Recovering Original Morse Message .../-"<<endl;
    for (int i = 0; i < n; i++)
    {
         string temp="";

            while(i < n && mc[i] != '$')
            {
                temp+=mc[i];
                i++;
            }

        for (int counter = 0; counter < 36; counter++)
        {
            if (temp == morse[counter])
            {
                cout<<temp<<" -> ";
                temp1+=text[counter];
                cout << text[counter]<<endl;
                break;
            }
        }
    }
    return temp1;
}
void soundplayer(string x)
{
    if (x==".-")
    {
        dot();
        dash();
    }
    else if (x=="-...")
    {
        dash();
        dot();
        dot();
        dot();
    }
    else if (x=="-.-.")
    {
        dash();
        dot();
        dash();
        dot();
    }
    else if (x == "-..")
    {
        dash();
        dot();
        dot();
    }
    else if (x == ".")
    {
        dot();
    }
    else if (x == "..-")
    {
        dot();
        dot();
        dash();
    }
    else if (x == "--.")
    {
        dash();
        dash();
        dot();
    }
    else if (x == "....")
    {
        dot();
        dot();
        dot();
        dot();
    }
    else if (x == "..")
    {
        dot();
        dot();
    }
    else if (x == ".---")
    {
        dot();
        dash();
        dash();
        dash();
    }
    else if (x == "-.-")
    {
        dash();
        dot();
        dash();
    }
    else if (x == ".-..")
    {
        dot();
        dash();
        dot();
        dot();
    }
    else if (x == "--")
    {
        dash();
        dash();
    }
    else if (x == "-.")
    {
        dash();
        dot();
    }
    else if (x == "---")
    {
        dash();
        dash();
        dash();
    }
    else if (x == ".--.")
    {
        dot();
        dash();
        dash();
        dot();
    }
    else if (x == "--.-")
    {
        dash();
        dash();
        dot();
        dash();
    }
    else if (x == ".-.")
    {
        dot();
        dash();
        dot();
    }
    else if (x == "...")
    {
        dot();
        dot();
        dot();
    }
    else if (x == "-")
    {
       dash();
    }
    else if (x == "..-")
    {
        dot();
        dot();
        dash();
    }
    else if (x == "...-")
    {
        dot();
        dot();
        dot();
        dash();
    }
    else if (x == ".--")
    {
        dot();
        dash();
        dash();
    }
    else if (x == "-..-")
    {
        dash();
        dot();
        dot();
        dash();
    }
    else if (x == "-.--")
    {
        dash();
        dot();
        dash();
        dash();

    }
    else if (x == "--..")
    {
        dash();
        dash();
        dot();
        dot();
    }
    else if (x == ".----")
    {
        dot();
        dash();
        dash();
        dash();
        dash();
    }
    else if (x == "..---")
    {
        dot();
        dot();
        dash();
        dash();
        dash();
    }
    else if (x == "...--")
    {
        dot();
        dot();
        dot();
        dash();
        dash();
    }
    else if (x == "....-")
    {
        dot();
        dot();
        dot();
        dot();
        dash();
    }
    else if (x == ".....")
    {
        dot();
        dot();
        dot();
        dot();
        dot();

    }
    else if (x == "-....")
    {
        dash();
        dot();
        dot();
        dot();
        dot();

    }
    else if (x == "--...")
    {
        dash();
        dash();
        dot();
        dot();
        dot();
    }
    else if (x == "---..")
    {
        dash();
        dash();
        dash();
        dot();
        dot();

    }
    else if (x == "----.")
    {
        dash();
        dash();
        dash();
        dash();
        dot();
    }
    else if (x == "-----")
    {
        dash();
        dash();
        dash();
        dash();
        dash();
    }
}
void dot()
{
    Beep(900,100);
}

void dash()
{
    Beep(900,300);
}
