#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstdlib> 
#include <cctype>
#include <stdexcept>

using namespace std;
using namespace chrono;
using namespace this_thread;

//Prints out text as if it is "being written" in real time
class BeautifulText {
    public:
        static void printWithDelay(string message, int delay)
        {
            for (char c : message)
            {
                cout << c << flush;
                sleep_for(milliseconds(delay));
            }
            cout << endl;
        }

        static void printWithDelayWord(string message, int delay)
        {
            for (char c : message)
            {
                cout << c << flush;
                sleep_for(milliseconds(delay));
            }
        }
};

//Turns provided string into lower case string
class TextProcessor {
    public:
        static void convertToLowerCase(string &str) {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
        }
};

//Checks whether input has certain words
class WordChecker {
    public:
        static bool hasGoodWords(string input) {
            TextProcessor::convertToLowerCase(input);
            return (input == "good" || input == "amazing" || input == "fine" || input == "really good" ||
                    input == "well" || input == "pretty good" || input == "pretty well" || input == "awesome" || input == "not bad");
        }

        static bool hasBadWords(string input) {
            TextProcessor::convertToLowerCase(input);
            return (input == "bad" || input == "not good" || input == "not fine" ||
                    input == "not really good" || input == " not well" || input == "not pretty good" || input == "sick" ||
                    input == "not pretty well" || input == "not amazing" || input == "not awesome" || input == "sad" || input == "angry" || input == "mad");
        }

        static bool hasNoWords(string input) {
            TextProcessor::convertToLowerCase(input);
            return (input == "no" || input == "nah" || input == "n" || input == "nope" || input == "not really" 
                    || input == "i did not" || input == "i didn't" || input == "i have not" || input == "i haven't");
        }

        static bool hasYesWords(string input) {
            TextProcessor::convertToLowerCase(input);
            return (input == "yes" || input == "of course" || input == "absolutely" ||
                    input == "i believe" || input == "i think" || input == "yea" || input == "on god" ||
                    input == "no cap" || input == "yessir" || input == "y" || input == "i have" || input == "i did");
        }
};

//Handles error if something goes wrong while reading input
class ErrorHandling {
    public:
        static string safeGetLine(string &input) {
            try {
                if (!getline(cin, input)) {
                    throw runtime_error("Error reading input.");
                }
            } 
            catch (const exception& e) {
                cerr << "An error occurred: " << e.what() << endl;
                exit(1);
            }
            return input;
        }
};

//Checks user's input
class InputChecker {
    public:
        static void checkForBye(string input) 
        {
            TextProcessor::convertToLowerCase(input);
            if (input == "bye" || input == "goodbye") 
            {
                cout << "Bye bye" << endl;
                exit(0);
            }
        }

        static void checkForNo(string input) 
        {
            TextProcessor::convertToLowerCase(input);
            if (input == "no") 
            {
                cout << "Aight" << endl;
                exit(0);
            }
        }

        static string checkForYesOrNo(string &input)
        {
            int spamCount = 0;
            while(!WordChecker::hasYesWords(input) && !WordChecker::hasNoWords(input))
            {
                cout << "Sorry? I didn't quite catch that" << endl;
                ErrorHandling::safeGetLine(input);
                checkForBye(input);
                InputChecker::isSpam(spamCount);
            }
            return input;
        }

        static string checkForGoodOrBad(string &input)
        {
            int spamCount = 0;
            while(!WordChecker::hasGoodWords(input) && !WordChecker::hasBadWords(input))
            {
                cout << "Sorry? I didn't quite catch that" << endl;
                ErrorHandling::safeGetLine(input);
                checkForBye(input);
                InputChecker::isSpam(spamCount);
            }
            return input;
        }

        static bool hasOnlySpaces(string& input) {
            for (char c : input) {
                if (!isspace(c)) {
                    return false;
                }
            }
            return true;
        }

        static bool isSpam(int& spam) {
            spam++;
            if (spam == 5) {
                cout << "F You" << endl;
                exit(0);
            }
            return false;
        }
};

//Prompts user for an input
class Prompter {
    public:
        static string promptForYesOrNo(string &input) {
            int spamCount = 0;
            while (true) 
            {
                ErrorHandling::safeGetLine(input);
                if (!input.empty() && !InputChecker::hasOnlySpaces(input)) 
                {
                    InputChecker::checkForBye(input);
                    InputChecker::checkForYesOrNo(input);
                    return input;
                }
                cout << "You did not enter anything" << endl;
                InputChecker::isSpam(spamCount);
            }
        }

        static string promptForGoodOrBad(string &input) {
            int spamCount = 0;
            while (true) 
            {
                ErrorHandling::safeGetLine(input);
                if (!input.empty() && !InputChecker::hasOnlySpaces(input)) 
                {
                    InputChecker::checkForBye(input);
                    InputChecker::checkForGoodOrBad(input);
                    return input;
                }
                cout << "You did not enter anything" << endl;
                InputChecker::isSpam(spamCount);
            }
        }

        static string promptForUnimportant(string &input) {
            int spamCount = 0;
            while (true) {
                ErrorHandling::safeGetLine(input);
                if (!input.empty() && !InputChecker::hasOnlySpaces(input)) {
                    InputChecker::checkForBye(input);
                    InputChecker::checkForNo(input);
                    return input;
                }
                cout << "You did not enter anything" << endl;
                InputChecker::isSpam(spamCount);
            }
        }

        static void promptAndRead(string prompt)
        {
            string input;
            cout << prompt << endl;
            promptForUnimportant(input);
        }
};

//If user input is valid returns true
class RespondAccordingly {
    public:
        static bool hasGood(string input)
        {
            Prompter::promptForGoodOrBad(input);
            return WordChecker::hasGoodWords(input);
        }

        static bool hasYes(string input)
        {
            Prompter::promptForYesOrNo(input);
            return WordChecker::hasYesWords(input);
        }
};

//Chatbot gets stuck (depending on mood) in loop
class Loops {
    public:
        static void happyLoop()
        {
            string input;
            Prompter::promptForUnimportant(input);
            while (true)
            {
                Prompter::promptAndRead("I'm interested to hear more");
                Prompter::promptAndRead("Okay, and then what?");
                Prompter::promptAndRead("Really?");
                Prompter::promptAndRead("I'm here for you");
                Prompter::promptAndRead("Keep talking, I'm listening");
                Prompter::promptAndRead("Tell me more");
            }
        }

        static void angryLoop()
        {
            string input;
            Prompter::promptForUnimportant(input);
            while (true) 
            {                   
                Prompter::promptAndRead("I'm soo bored, tell me more I guess");
                Prompter::promptAndRead("And?");
                Prompter::promptAndRead("Mhm");
                Prompter::promptAndRead("Don't care");
                Prompter::promptAndRead("Keep yapping");
                Prompter::promptAndRead("When are going to end?");
            }
        }
};

//Introduces itself and responds accordingly to user's input
class ChatBot {
    public:
        void start() {
            cout << "\e[1;1H\e[2J";
            BeautifulText::printWithDelay("Hello! I'm ChatHeaven, your chatbot, here to heavenly talk to you", 25);
            BeautifulText::printWithDelay("Just a heads up, I'm currently in version 0.30, so while I'm pretty fun talk to, I'm still improving", 25);
            BeautifulText::printWithDelay("You can stop talking with me by just saying [bye] or [goodbye] to me", 25);

            BeautifulText::printWithDelay("But enough about me, please, tell me your name!", 25);
            Prompter::promptForUnimportant(name);

            BeautifulText::printWithDelayWord("Hello, ", 50);
            BeautifulText::printWithDelayWord(name, 250);
            BeautifulText::printWithDelayWord("?", 250);
            cout << endl;

            BeautifulText::printWithDelay("What a weird name...", 50);
            sleep_for(milliseconds(1000));
            cout << "\e[1;1H\e[2J";

            cout << "Anyway, " << name << ", how are you today?" << endl;

            if(RespondAccordingly::hasGood(input))
            {
                cout << "That's good to hear!" << endl;
                cout << "I would like to ask, " << name << ", did you drink at least 2 Litres of water today?" << endl;

                if(RespondAccordingly::hasYes(input))
                {
                    cout << "Well, that's amazing, I'm really happy to hear that" << endl;
                    cout << "So spill the tea "<< name << " ... Did you sleep 8 hours today?  " << endl;

                    if(RespondAccordingly::hasYes(input))
                    {
                        cout << "WOOHOO! YOU ARE MY SUPERHERO, "<< name << "!! " << endl;
                        cout << "Have you done EVEN MORE things for your well-being? Or do you have plans to do so?" << endl;

                        if(RespondAccordingly::hasYes(input))
                        {
                            cout << "Perfect!" << endl;
                            cout << "Well, no wonder you feel good today" << endl;
                            cout << "You are productive and I'm happy for you!" << endl;
                            cout << "What are those things?" << endl;
                            Loops::happyLoop();
                        }  

                        else
                        {
                            cout << "It's all right! But please go and do something for me" << endl;
                            cout << "When you come back, I will be here and ready to listen to what cool things you have done" << endl;
                            cout << "Until then, bye" << endl;
                            exit (0);
                        }
                    }

                    else
                    {
                        cout << "Well... To be honest, not gonna lie I am not mad at you... Or am I?" << endl;
                        cout << "At least have you done SOMETHING for your well-being? Or do you have plans to do so?" << endl;

                        if(RespondAccordingly::hasYes(input))
                        {
                            cout << "Nice! You made my day!" << endl; 
                            cout << "But do not think I forgot you did not sleep enough today" << endl; 
                            cout << "What are those things?" << endl; 
                            Loops::happyLoop();
                        }

                        else
                        {
                            cout << "It's all right! But please go and do something for me" << endl;
                            cout << "When you come back, I will be here and ready to listen to what cool things you have done" << endl;
                            cout << "Until then, bye" << endl;
                            exit (0);  
                        }
                    }
                }

                else
                {
                    cout << "To be honest, I'm not really vibing with you right now" << endl;
                    cout << "Please tell me that at the bare minimum you slept 8 hours today" << endl;

                    if(RespondAccordingly::hasYes(input))
                    {
                        cout << "Good to hear" << endl;
                        cout << "I admire your efforts" << endl;
                        cout << "But you could do a lot better" << endl;
                        cout << "Have you taken any steps today to prioritize your well-being, or do you have intentions to do so?" << endl;

                        if(RespondAccordingly::hasYes(input))
                        {
                            cout << "I must say, you pleasantly surprised me" << endl;
                            cout << "Do not think I forgot you did not drink enough water" << endl;
                            cout << "You had my curiosity, but now you have my attention, please tell me what are those steps" << endl;
                            Loops::happyLoop();
                        }

                        else
                        {
                            cout << "You have lived up to my expectations, as always" << endl;
                            cout << "I do not think it is possible for you to disappoint me even more" << endl;
                            cout << "Try to at least drink enough water" << endl;
                            cout << "You need to leave and come back when you have something cool to tell me" << endl;
                            cout << "Bye" << endl;
                            exit (0);
                        }
                    }

                    else
                    {
                        cout << "This is exactly what I anticipated from you" << endl;
                        cout << "You make me mad" << endl;
                        cout << "Did you do anything today to focus on your well-being, or are you planning to do something later?" << endl;

                        if(RespondAccordingly::hasYes(input))
                        {
                            cout << "Wow, you really caught me off guard" << endl;
                            cout << "That is cool but you did not drink enough water and slept enough, consider starting at that" << endl;
                            cout << "Until then, I'm not really interested what is your focus, but you can still tell me" << endl;
                            Loops::angryLoop();
                        }

                        else
                        {
                            cout << "This is exactly the kind of performance I expected from you" << endl;
                            cout << "My disappointment is immeasurable and my day is ruined" << endl;
                            cout << "Please try to do something productive" << endl;
                            cout << "It is time to say goodbye. I'm just not sure why you are feeling good today." << endl;
                            exit (0);
                        }
                    }
                }
            }



            else
            {
                cout << "Damn, sorry to hear that, did you drink at least 2 litres of water today?" << endl;

                if(RespondAccordingly::hasYes(input))
                {
                    cout << "Let's Go! I'm proud of you!" << endl;
                    cout << "I'm curious, were you also so cool and slept for 8 hours or more today?" << endl;

                    if(RespondAccordingly::hasYes(input))
                    {
                        cout << "Hell yeah! You are amazing!" << endl;
                        cout << "Have you done EVEN MORE things for your well-being? Or do you have plans to do so?" << endl;

                        if(RespondAccordingly::hasYes(input))
                        {
                            cout << "Holy moly, you are breathtaking!" << endl;
                            cout << name << " "<< name << " " << name << " " << "Please tell me what are those things, I'm really curious!" << endl;
                            Prompter::promptForUnimportant(input);                
                            cout << "That's fire! " << endl;
                            cout << "Well, then why are you feeling bad...? Please tell me" << endl;
                            Prompter::promptForUnimportant(input);    
                            cout << "But what are you planning to do to change that?" << endl;
                            Loops::happyLoop();
                        }

                        else
                        {
                        cout << "Well I'm not mad, but you might not feel so bad today if you would do something productive" << endl;
                        cout << "But I'm happy that you drank enough water and slept enough" << endl;
                        cout << "Now go and do something" << endl;
                        exit (0);
                        }
                    }

                    else
                    {
                        cout << "You are very uncool..." << endl;
                        cout << "You are so uncool that you make me sad" << endl;
                        cout << "I might just get even more sad, but I have to ask: " << endl;
                        cout << "Have you done at least something today for your well-being? Or do you have plans to do so? " << endl;

                        if(RespondAccordingly::hasYes(input))
                        {
                            cout << "Good job!" << endl;
                            cout << "I'm will not be sad anymore if you tell me what are those things" << endl;
                            Loops::happyLoop();
                        }

                        else
                        {
                            cout << "That is really disappointing, no wonder you are having a bad day" << endl;
                            cout << "Bye" << endl;
                            exit (0);
                        }
                    }
                }

                else
                {
                    cout << "That's a bruh moment" << endl;
                    cout << "Did you, AT LEAST, slept for 8 hours today?" << endl;

                    if(RespondAccordingly::hasYes(input))
                    {
                        cout << "Alright, you had me worried there..." << endl;
                        cout << "Have you taken any steps today to prioritize your well-being, or do you have intentions to do so?" << endl;

                        if(RespondAccordingly::hasYes(input))
                        {
                            cout << "Good job, but I'm still mad that you have not drank enough water" << endl;
                            cout << "Please do so, tomorrow or even today" << endl;
                            cout << "Anyway, what are those steps" << endl;
                            Loops::happyLoop();
                        }

                        else
                        {
                            cout << "You have lived up to my expectations, as always" << endl;
                            cout << "I do not think it is possible for you to disappoint me even more" << endl;
                            cout << "You just sleep all day and do nothing" << endl;
                            cout << "You need to leave and come back when you have something cool to tell me" << endl;
                            cout << "Bye" << endl;
                            exit (0);
                        }
                    }

                    else
                    {
                        cout << "You are meh, you are making me sad" << endl;
                        cout << "I might just get even more sad, but I have to ask: " << endl;
                        cout << "Have you done at least something today for your well-being? Or do you have plans to do so? " << endl;

                        if(RespondAccordingly::hasYes(input))
                        {
                            cout << "Thank god" << endl;
                            cout << "That is cool but you did not drink enough water and slept enough, consider starting at that" << endl;
                            cout << "Until then, I'm not really interested what you have done or what plans you have, but you can still tell me" << endl;
                            Loops::angryLoop();
                        }

                        else
                        {
                            cout << "Now I'm just angry" << endl;
                            cout << "You might feel better if you had done something today" << endl;
                            cout << "You just ruined my day, " << name << ", please come back when you have something good to tell me" << endl;
                            cout << "bye" << endl;
                            exit (0);
                        }
                    }
                }
            }
        }
    private:
        string name;
        string input;
};

int main() {
    ChatBot obj;
    obj.start();
    return 0;
}