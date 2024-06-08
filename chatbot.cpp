#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;
 
void Lower(string &string) {
    std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}

bool Empty(string input) {
    if (input.empty())
    {
        cout << "You did not enter anything" << endl;
        cout << "Exiting..." << endl;
        return true;
    }
     else
    {
    return false;
    }
}

bool CheckForBye(string input) {
    Lower(input);
    if (input == "bye" || input == "goodbye") 
    {
        cout << "Bye bye" << endl;
        return true;
    }
    else
    {
    return false;
    }
}

void PromptAndRead(string prompt) {
    string interesting;
    cout << prompt << endl;
    getline(cin, interesting);
    if (Empty(interesting)) exit(0);
    if (CheckForBye(interesting)) exit(0);
}

void loop() {
    while (true)
    {
        PromptAndRead("I'm interested to hear more");
        PromptAndRead("Okay, and then what?");
        PromptAndRead("Really?");
        PromptAndRead("I'm here for you");
        PromptAndRead("Keep talking, I'm listening");
        PromptAndRead("Tell me more");
    }
}

void loop2() {
    while (true) 
    {
        PromptAndRead("I'm soo bored, tell me more");
        PromptAndRead("And?");
        PromptAndRead("Mhm");
        PromptAndRead("Don't care");
        PromptAndRead("Keep yapping");
        PromptAndRead("When are going to end?");
    }
}

void PrintWithDelay(string message, int delay) {
    for (char c : message) {
        cout << c << flush;
        sleep_for(milliseconds(delay));
    }
    cout << endl;
}

void PrintWithDelay2(string message, int delay) {
    for (char c : message) {
        cout << c << flush;
        sleep_for(milliseconds(delay));
    }
}

int main() {
    cout << "\e[1;1H\e[2J";
    string name;

    string hello = "Hello! I'm ChatHeaven, your chatbot 🤖, here to heavenly talk to you.";
    PrintWithDelay(hello, 25);

    string hello1 = "Just a heads up, I'm currently in version 0.24, so while I'm pretty fun talk to, I'm still improving";
    PrintWithDelay(hello1, 25);

    string hello0 = "You can stop talking with me by just saying [bye] or [goodbye] to me";
    PrintWithDelay(hello0, 25);

    string hello2 = "But enough about me, please, tell me your your name!";
    PrintWithDelay(hello2, 25);

    getline(cin, name);
    if (Empty(name)) exit(0);
    if (CheckForBye(name)) exit(0);

    string hello3 = "Hello, ";
    PrintWithDelay2(hello3, 50);
    PrintWithDelay2(name, 500);
    cout << "?" << endl;
    string hello4 = "What a weird name...";
    PrintWithDelay(hello4, 50);

sleep_for(milliseconds(1000));
cout << "\e[1;1H\e[2J";
cout << "Anyway, " << name << ", how are you today?" << endl;
string mood;
getline(cin, mood);
Lower(mood);
if (Empty(mood)) exit(0);
if (CheckForBye(mood)) exit(0);

if(mood == "good" || mood == "amazing" || mood == "fine" || mood == "really good" || mood == "well" || mood == "pretty good" || mood == "pretty well" || mood == "yes" || mood == "awesome")
{
    cout << "That's good to hear!" << endl;
    string water;
    cout << "I would like to ask, " << name << ", did you drink at least 2 Litres of water today?" << endl;
    getline(cin, water);
    Lower(water);
    if (Empty(water)) exit(0);
    if (CheckForBye(water)) exit(0);
    if(water == "yes" || water == "of course" || water == "absolutely" || water == "i believe" || water == "i think" || water == "yea" || water == "on god" || water == "no cap" || water == "yessir")
    {
    cout << "Well, that's amazing, I'm really happy to hear that" << endl;
    cout << "So spill the tea "<< name << " ... Did you sleep 8 hours today?  " << endl;
    string teasleep;
    getline(cin, teasleep);
    Lower(teasleep);
    if (Empty(teasleep)) exit(0);
    if (CheckForBye(teasleep)) exit(0); 
    if(teasleep == "yes" || teasleep == "of course" || teasleep == "absolutely" || teasleep == "i believe" || teasleep == "i think" || teasleep == "yea" || teasleep == "on god" || teasleep == "no cap" || teasleep == "yessir")
    {
    cout << "WOOHOO! YOU ARE MY SUPERHERO, "<< name << "!! " << endl;
    cout << "Have you done EVEN MORE things for your well-being? Or do you have plans to do so?" << endl;
    string thiss;
    getline(cin, thiss);
    Lower(thiss);
    if (Empty(thiss)) exit(0);
    if (CheckForBye(thiss)) exit(0);
    if(thiss == "yes" || thiss == "of course" || thiss == "absolutely" || thiss == "i believe" || thiss == "i think" || thiss == "yea" || thiss == "on god" || thiss == "no cap" || thiss == "yessir")
    {
    cout << "Perfect!" << endl;
    cout << "Well, no wonder you feel good today" << endl;
    cout << "You are productive and I'm happy for you!" << endl;
    cout << "What are those things?" << endl;
       string amazing;
       getline(cin, amazing);
       Lower(amazing);
       if (Empty(amazing)) exit(0);
        if (CheckForBye(amazing)) exit(0);
       loop();
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
        string being;
        getline(cin, being);
        Lower(being);
        if (Empty(being)) exit(0);
        if (CheckForBye(being)) exit(0);
    if(being == "yes" || being == "of course" || being == "absolutely" || being == "i believe" || being == "i think" || being == "yea" || being == "on god" || being == "no cap" || being == "yessir")
    {
       cout << "Nice! You made my day!" << endl; 
       cout << "But do not think I forgot you did not sleep enough today" << endl; 
       cout << "What are those things?" << endl; 
       string tths;
       getline(cin, tths);
       Lower(tths);
       if (Empty(tths)) exit(0);
       if (CheckForBye(tths)) exit(0);
       loop();
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
    string bare;
    getline(cin, bare);
    Lower(bare);
    if (Empty(bare)) exit(0);
    if (CheckForBye(bare)) exit(0);
     if(bare == "yes" || bare == "of course" || bare == "absolutely" || bare == "i believe" || bare == "i think" || bare == "yea" || bare == "on god" || bare == "no cap" || bare == "yessir")
     {
        cout << "Good to hear" << endl;
        cout << "I admire your efforts" << endl;
        cout << "But you could do a lot better" << endl;
        cout << "Have you taken any steps today to prioritize your well-being, or do you have intentions to do so?" << endl;
        string priot;
        getline(cin, priot);
        Lower(priot);
        if (Empty(priot)) exit(0);
        if (CheckForBye(priot)) exit(0);
        if(priot == "yes" || priot == "of course" || priot == "absolutely" || priot == "i believe" || priot == "i think" || priot == "yea" || priot == "on god" || priot == "no cap" || priot == "yessir")
        {
            cout << "I must say, you pleasantly surprised me" << endl;
            cout << "Do not think I forgot you did not drink enough water" << endl;
            cout << "You had my curiosity, but now you have my attention, please tell me what are those steps" << endl;
            string b;
            getline(cin, b);
            Lower(b);
            if (Empty(b)) exit(0);
            if (CheckForBye(b)) exit(0);
            loop();
        }
        else
        {
            cout << "You have lived up to my expectations, as always" << endl;
            cout << "I do not think it is possible for you to dissapoint me even more" << endl;
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
            string focus;
            getline(cin, focus);
            Lower(focus);
            if (Empty(focus)) exit(0);
            if (CheckForBye(focus)) exit(0);
            if(focus == "yes" || focus == "of course" || focus == "absolutely" || focus == "i believe" || focus == "i think" || focus == "yea" || focus == "on god" || focus == "no cap" || focus == "yessir")
            {
                    cout << "Wow, you really caught me off guard" << endl;
                    cout << "That is cool but you did not drink enough water and slept enough, consider starting at that" << endl;
                    cout << "Untill then, I'm not really interested what is your focus, but you can still tell me" << endl;
                    string still;
                    getline(cin, still);
                    Lower(still);
                    if (Empty(still)) exit(0);
                    if (CheckForBye(still)) exit(0);
                    loop2();

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
    string water2;
    getline(cin, water2);
    Lower(water2);
    if (Empty(water2)) exit(0);
    if (CheckForBye(water2)) exit(0);
    if(water2 == "yes" || water2 == "of course" || water2 == "absolutely" || water2 == "i believe" || water2 == "i think" || water2 == "yea" || water2 == "on god" || water2 == "no cap" || water2 == "yessir")
    {
        cout << "Let's Go! I'm proud of you!" << endl;
        cout << "I'm curious, were you also so cool and slept for 8 hours or more today?" << endl;
        string sleepp;
        getline(cin, sleepp);
        Lower(sleepp);
        if (Empty(sleepp)) exit(0);
        if (CheckForBye(sleepp)) exit(0);
         if(sleepp == "yes" || sleepp == "of course" || sleepp == "absolutely" || sleepp == "i believe" || sleepp == "i think" || sleepp == "yea" || sleepp == "on god" || sleepp == "no cap" || sleepp == "yessir")
         {
            cout << "Hell yeah! You are amazing!" << endl;
            cout << "Have you done EVEN MORE things for your well-being? Or do you have plans to do so?" << endl;
            string wells;
            getline(cin, wells);
            Lower(wells);
            if (Empty(wells)) exit(0);
            if (CheckForBye(wells)) exit(0);
            if(wells == "yes" || wells == "of course" || wells == "absolutely" || wells == "i believe" || wells == "i think" || wells == "yea" || wells == "on god" || wells == "no cap" || wells == "yessir")
            {
                cout << "Holy moly, you are breathtaking!" << endl;
                cout << name << " "<< name << " " << name << " " << "Please tell me what are those things, I'm really curious!" << endl;
                string things;
                getline(cin, things);
                Lower(things);
                if (Empty(things)) exit(0);
                if (CheckForBye(things)) exit(0);
                cout << "That's fire! " << endl;
                cout << "Well, then why are you feeling bad...? Please tell me" << endl;
                string badthings;
                getline(cin, badthings);
                Lower(badthings);
                if (Empty(badthings)) exit(0);
                if (CheckForBye(badthings)) exit(0);
                cout << "But what are you planning to do to change that?" << endl;
                string badthings2;
                getline(cin, badthings2);
                Lower(badthings2);
                if (Empty(badthings2)) exit(0);
                if (CheckForBye(badthings2)) exit(0);
                string interesting;
                loop();
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
            string have;
            getline(cin, have);
            Lower(have);
            if (Empty(have)) exit(0);
            if (CheckForBye(have)) exit(0);
            if(have == "yes" || have == "of course" || have == "absolutely" || have == "i believe" || have == "i think" || have == "yea" || have == "on god" || have == "no cap" || have == "yessir")
            {
                cout << "Good job!" << endl;
                cout << "I'm will not be sad anymore if you tell me what are those things" << endl;
                string what;
                getline(cin, what);
                Lower(what);
                if (Empty(what)) exit(0);
                if (CheckForBye(what)) exit(0);
                loop();
            }
            else
            {
                cout << "That is really dissapointing, no wonder you are having a bad day" << endl;
                cout << "Bye" << endl;
                return 0;
            }
         }
    }
    else
    {
        cout << "That's a bruh moment" << endl;
        cout << "Did you, AT LEAST, slept for 8 hours today?" << endl;
        string ssleep;
        getline(cin, ssleep);
        Lower(ssleep);
        if (Empty(ssleep)) exit(0);
        if (CheckForBye(ssleep)) exit(0);
        if(ssleep == "yes" || ssleep == "of course" || ssleep == "absolutely" || ssleep == "i believe" || ssleep == "i think" || ssleep == "yea" || ssleep == "on god" || ssleep == "no cap" || ssleep == "yessir")
        {
            cout << "Alright, you had me worried there..." << endl;
            cout << "Have you taken any steps today to prioritize your well-being, or do you have intentions to do so?" << endl;
            string steps;
            getline(cin, steps);
            Lower(steps);
            if (Empty(steps)) exit(0);
            if (CheckForBye(steps)) exit(0);
            if(steps == "yes" || steps == "of course" || steps == "absolutely" || steps == "i believe" || steps == "i think" || steps == "yea" || steps == "on god" || steps == "no cap" || steps == "yessir")
            {
                cout << "Good job, but I'm still mad that you have not drank enough water" << endl;
                cout << "Please do so, tommorow or even today" << endl;
                cout << "Anyway, what are those steps" << endl;
                string ssteps;
                getline(cin, ssteps);
                Lower(ssteps);
                if (Empty(ssteps)) exit(0);
                if (CheckForBye(ssteps)) exit(0);
                loop();
            }
            else
            {
            cout << "You have lived up to my expectations, as always" << endl;
            cout << "I do not think it is possible for you to dissapoint me even more" << endl;
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
            string least;
            getline(cin, least);
            Lower(least);
            if (Empty(least)) exit(0);
            if (CheckForBye(least)) exit(0);
            if(least == "yes" || least == "of course" || least == "absolutely" || least == "i believe" || least == "i think" || least == "yea" || least == "on god" || least == "no cap" || least == "yessir")
            {
                cout << "Thank god" << endl;
                cout << "That is cool but you did not drink enough water and slept enough, consider starting at that" << endl;
                cout << "Untill then, I'm not really interested what you have done or what plans you have, but you can still tell me" << endl;
                string idk;
                getline(cin, idk);
                Lower(idk);
                if (Empty(idk)) exit(0);
                if (CheckForBye(idk)) exit(0);
                string interesting;
                loop2();
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