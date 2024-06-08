#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstdlib> 
#include <cctype>

using namespace std;
using namespace chrono;
using namespace this_thread;

void convertToLowerCase(string &string)
{
    transform(string.begin(), string.end(), string.begin(), ::tolower);
}

bool hasGoodWords(string input) 
{
    convertToLowerCase(input);
    if(input == "good" || input == "amazing" || input == "fine" || input == "really good" ||
    input == "well" || input == "pretty good" || input == "pretty well" || input == "awesome" || input == "not bad")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool hasBadWords(string input)
{
    convertToLowerCase(input);
    if(input == "bad" || input == "not good" || input == "not fine" ||
    input == "not really good" || input == " not well" || input == "not pretty good" ||
    input == "not pretty well" || input == "not amazing" || input == "not awesome" || input == "sad" || input == "angry" || input == "mad")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool hasNoWords(string input)
{
    convertToLowerCase(input);
    if(input == "no" || input == "nah" || input == "n" || input == "nope" || input == "not really" 
    || input == "i did not" || input == "i didn't" || input == "i have not" || input == "i haven't")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool hasYesWords(string input)
{
    convertToLowerCase(input);
    if(input == "yes" || input == "of course" || input == "absolutely" ||
    input == "i believe" || input == "i think" || input == "yea" || input == "on god" ||
    input == "no cap" || input == "yessir" || input == "y" || input == "i have" || input == "i did")
   {
        return true;
   }
   else
   {
        return false;
   }
}

void checkForBye(string input)
{
    convertToLowerCase(input);
    if (input == "bye" || input == "goodbye") 
    {
        cout << "Bye bye" << endl;
        exit (0);
    }
}

void checkForNo(string input)
{
    convertToLowerCase(input);
    if (input == "no") 
    {
        cout << "Aight" << endl;
        exit (0);
    }
}

string checkForYesOrNo(string &input)
{
    int spam = 0;
    while(!hasYesWords(input) && !hasNoWords(input))
    {
        cout << "Sorry? I didn't quite catch that" << endl;
        getline(cin, input);
        checkForBye(input);
        spam++;
        if(spam == 5) 
        {
            cout << "F You" << endl;
            exit(0);
        }
    }
    return input;
}

string checkForGoodOrBad(string &input)
{
    int spam = 0;
    while(!hasGoodWords(input) && !hasBadWords(input))
    {
        cout << "Sorry? I didn't quite catch that" << endl;
        getline(cin, input);
        checkForBye(input);
        spam++;
        if(spam == 5) 
        {
            cout << "F You" << endl;
            exit(0);
        }
    }
    return input;
}

string promptForYesOrNo(string &input)
{
    int spam = 0;
    while (true) 
    {
        getline(cin, input);
        bool onlySpace = true;
        for (char c : input) 
        {
            if (!isspace(c)) 
            {
                onlySpace = false;
                break;
            }
        }

        if (!input.empty() && !onlySpace) 
        {
            checkForBye(input);
            checkForYesOrNo(input);
            return input;
        }
        cout << "You did not enter anything" << endl;
        spam++;
        if(spam == 5) 
        {
            cout << "F You" << endl;
            exit(0);
        }
    }
}

string promptForGoodOrBad(string &input)
{
    int spam = 0;
    while (true) 
    {
        getline(cin, input);
        bool onlySpace = true;
        for (char c : input) 
        {
            if (!isspace(c)) 
            {
                onlySpace = false;
                break;
            }
        }

        if (!input.empty() && !onlySpace) 
        {
            checkForBye(input);
            checkForGoodOrBad(input);
            return input;
        }
        cout << "You did not enter anything" << endl;
        spam++;
        if(spam == 5) 
        {
            cout << "F You" << endl;
            exit(0);
        }
    }
}

string promptForUnimportant(string &input)
{
    int spam = 0;
    while (true) 
    {
        getline(cin, input);
        bool onlySpace = true;
        for (char c : input) 
        {
            if (!isspace(c)) 
            {
                onlySpace = false;
                break;
            }
        }
        if (!input.empty() && !onlySpace) 
        {
            checkForBye(input);
            checkForNo(input);
            return input;
        }
        cout << "You did not enter anything" << endl;
        spam++;
        if(spam == 5) 
        {
            cout << "F You" << endl;
            exit(0);
        }
    }
}

void promptAndRead(string prompt)
{
    string input;
    cout << prompt << endl;
    promptForUnimportant(input);
}

void happyLoop()
{
    string input;
    promptForUnimportant(input);
    while (true)
    {
        promptAndRead("I'm interested to hear more");
        promptAndRead("Okay, and then what?");
        promptAndRead("Really?");
        promptAndRead("I'm here for you");
        promptAndRead("Keep talking, I'm listening");
        promptAndRead("Tell me more");
    }
}

void angryLoop()
{
    string input;
    promptForUnimportant(input);
    while (true) 
    {
        promptAndRead("I'm soo bored, tell me more");
        promptAndRead("And?");
        promptAndRead("Mhm");
        promptAndRead("Don't care");
        promptAndRead("Keep yapping");
        promptAndRead("When are going to end?");
    }
}

bool hasYes(string input)
{
    promptForYesOrNo(input);
    if (hasYesWords(input))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool hasGood(string input)
{
    promptForGoodOrBad(input);
    if (hasGoodWords(input))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printWithDelay(string message, int delay)
{
    for (char c : message)
    {
        cout << c << flush;
        sleep_for(milliseconds(delay));
    }
    cout << endl;
}

void printWithDelayWord(string message, int delay)
{
    for (char c : message)
    {
        cout << c << flush;
        sleep_for(milliseconds(delay));
    }
}



int main() 
{
    cout << "\e[1;1H\e[2J";

    printWithDelay("Hello! I'm ChatHeaven, your chatbot, here to heavenly talk to you", 25);

    printWithDelay("Just a heads up, I'm currently in version 0.25, so while I'm pretty fun talk to, I'm still improving", 25);

    printWithDelay("You can stop talking with me by just saying [bye] or [goodbye] to me", 25);

    printWithDelay("But enough about me, please, tell me your name!", 25);

    string name;
    promptForUnimportant(name);

    printWithDelayWord("Hello, ", 50);
    printWithDelayWord(name, 500);
    printWithDelayWord("?", 500);
    cout << endl;

    printWithDelay("What a weird name...", 50);
    sleep_for(milliseconds(1000));
    cout << "\e[1;1H\e[2J";

    cout << "Anyway, " << name << ", how are you today?" << endl;
    string input;

    if(hasGood(input))
    {
        cout << "That's good to hear!" << endl;
        cout << "I would like to ask, " << name << ", did you drink at least 2 Litres of water today?" << endl;

        if(hasYes(input))
        {
            cout << "Well, that's amazing, I'm really happy to hear that" << endl;
            cout << "So spill the tea "<< name << " ... Did you sleep 8 hours today?  " << endl;
            if(hasYes(input))
            {
                cout << "WOOHOO! YOU ARE MY SUPERHERO, "<< name << "!! " << endl;
                cout << "Have you done EVEN MORE things for your well-being? Or do you have plans to do so?" << endl;

                if(hasYes(input))
                {
                    cout << "Perfect!" << endl;
                    cout << "Well, no wonder you feel good today" << endl;
                    cout << "You are productive and I'm happy for you!" << endl;
                    cout << "What are those things?" << endl;
                    happyLoop();
                }  

                else
                {
                    cout << "It's all right! But please go and do something for me" << endl;
                    cout << "When you come back, I will be here and ready to listen to what cool things you have done" << endl;
                    cout << "Until then, bye" << endl;
                    return 0;
                }
            }

            else
            {
                cout << "Well... To be honest, not gonna lie I am not mad at you... Or am I?" << endl;
                cout << "At least have you done SOMETHING for your well-being? Or do you have plans to do so?" << endl;

                if(hasYes(input))
                {
                    cout << "Nice! You made my day!" << endl; 
                    cout << "But do not think I forgot you did not sleep enough today" << endl; 
                    cout << "What are those things?" << endl; 
                    happyLoop();
                }

                else
                {
                    cout << "It's all right! But please go and do something for me" << endl;
                    cout << "When you come back, I will be here and ready to listen to what cool things you have done" << endl;
                    cout << "Until then, bye" << endl;
                    return 0;  
                }
            }
        }

        else
        {
            cout << "To be honest, I'm not really vibing with you right now" << endl;
            cout << "Please tell me that at the bare minimum you slept 8 hours today" << endl;

            if(hasYes(input))
            {
                cout << "Good to hear" << endl;
                cout << "I admire your efforts" << endl;
                cout << "But you could do a lot better" << endl;
                cout << "Have you taken any steps today to prioritize your well-being, or do you have intentions to do so?" << endl;

                if(hasYes(input))
                {
                    cout << "I must say, you pleasantly surprised me" << endl;
                    cout << "Do not think I forgot you did not drink enough water" << endl;
                    cout << "You had my curiosity, but now you have my attention, please tell me what are those steps" << endl;
                    happyLoop();
                }

                else
                {
                    cout << "You have lived up to my expectations, as always" << endl;
                    cout << "I do not think it is possible for you to disappoint me even more" << endl;
                    cout << "Try to at least drink enough water" << endl;
                    cout << "You need to leave and come back when you have something cool to tell me" << endl;
                    cout << "Bye" << endl;
                    return 0;
                }
            }

            else
            {
                cout << "This is exactly what I anticipated from you" << endl;
                cout << "You make me mad" << endl;
                cout << "Did you do anything today to focus on your well-being, or are you planning to do something later?" << endl;

                if(hasYes(input))
                {
                    cout << "Wow, you really caught me off guard" << endl;
                    cout << "That is cool but you did not drink enough water and slept enough, consider starting at that" << endl;
                    cout << "Until then, I'm not really interested what is your focus, but you can still tell me" << endl;
                    angryLoop();
                }

                else
                {
                    cout << "This is exactly the kind of performance I expected from you" << endl;
                    cout << "My disappointment is immeasurable and my day is ruined" << endl;
                    cout << "Please try to do something productive" << endl;
                    cout << "It is time to say goodbye. I'm just not sure why you are feeling good today." << endl;
                    return 0;
                }
            }
        }
    }



    else
    {
        cout << "Damn, sorry to hear that, did you drink at least 2 litres of water today?" << endl;

        if(hasYes(input))
        {
            cout << "Let's Go! I'm proud of you!" << endl;
            cout << "I'm curious, were you also so cool and slept for 8 hours or more today?" << endl;

            if(hasYes(input))
            {
                cout << "Hell yeah! You are amazing!" << endl;
                cout << "Have you done EVEN MORE things for your well-being? Or do you have plans to do so?" << endl;

                if(hasYes(input))
                {
                    cout << "Holy moly, you are breathtaking!" << endl;
                    cout << name << " "<< name << " " << name << " " << "Please tell me what are those things, I'm really curious!" << endl;
                    promptForUnimportant(input);                
                    cout << "That's fire! " << endl;
                    cout << "Well, then why are you feeling bad...? Please tell me" << endl;
                    promptForUnimportant(input);
                    cout << "But what are you planning to do to change that?" << endl;
                    happyLoop();
                }

                else
                {
                cout << "Well I'm not mad, but you might not feel so bad today if you would do something productive" << endl;
                cout << "But I'm happy that you drank enough water and slept enough" << endl;
                cout << "Now go and do something" << endl;
                return 0;
                }
            }

            else
            {
                cout << "You are very uncool..." << endl;
                cout << "You are so uncool that you make me sad" << endl;
                cout << "I might just get even more sad, but I have to ask: " << endl;
                cout << "Have you done at least something today for your well-being? Or do you have plans to do so? " << endl;

                if(hasYes(input))
                {
                    cout << "Good job!" << endl;
                    cout << "I'm will not be sad anymore if you tell me what are those things" << endl;
                    happyLoop();
                }

                else
                {
                    cout << "That is really disappointing, no wonder you are having a bad day" << endl;
                    cout << "Bye" << endl;
                    return 0;
                }
            }
        }

        else
        {
            cout << "That's a bruh moment" << endl;
            cout << "Did you, AT LEAST, slept for 8 hours today?" << endl;

            if(hasYes(input))
            {
                cout << "Alright, you had me worried there..." << endl;
                cout << "Have you taken any steps today to prioritize your well-being, or do you have intentions to do so?" << endl;

                if(hasYes(input))
                {
                    cout << "Good job, but I'm still mad that you have not drank enough water" << endl;
                    cout << "Please do so, tomorrow or even today" << endl;
                    cout << "Anyway, what are those steps" << endl;
                    happyLoop();
                }

                else
                {
                    cout << "You have lived up to my expectations, as always" << endl;
                    cout << "I do not think it is possible for you to disappoint me even more" << endl;
                    cout << "You just sleep all day and do nothing" << endl;
                    cout << "You need to leave and come back when you have something cool to tell me" << endl;
                    cout << "Bye" << endl;
                    return 0;
                }
            }

            else
            {
                cout << "You are meh, you are making me sad" << endl;
                cout << "I might just get even more sad, but I have to ask: " << endl;
                cout << "Have you done at least something today for your well-being? Or do you have plans to do so? " << endl;

                if(hasYes(input))
                {
                    cout << "Thank god" << endl;
                    cout << "That is cool but you did not drink enough water and slept enough, consider starting at that" << endl;
                    cout << "Until then, I'm not really interested what you have done or what plans you have, but you can still tell me" << endl;
                    angryLoop();
                }

                else
                {
                    cout << "Now I'm just angry" << endl;
                    cout << "You might feel better if you had done something today" << endl;
                    cout << "You just ruined my day, " << name << ", please come back when you have something good to tell me" << endl;
                    cout << "bye" << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}