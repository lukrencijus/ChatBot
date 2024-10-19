1. Write a chatbot for console (in C++ or Java), which is subject to the following requirements: 
a) the bot greets you and asks for your name and then uses that name to address you throughout the program 
b) it is able to have an indefinite conversation (which never ends) - user can finish the conversation by closing the console (or eg. by saying bye or something), but there is an execution path which allows to continue forever (eg. bot asks if a user wants to continue and starts over) 
c) it has nested logic (there is a control structure within another control structure) and the bot makes decisions based on the user input 
d) it has a state, meaning, there are variables that track certain conditions which can change during the program (eg. the bot can be happy or sad, calm or furious, based on how the conversation is going etc; or it gives problems of different complexity based on how the user is doing etc)
Other considerations: 
- the program is contained in a single file and no other files are required (submit a single .cpp file to Moodle before the next week's lecture) 
- the conversation can be about anything 
- you can get creative - make the bot reflect your interests and/or personality! 
- it can be as simple or as complex as you decide 
- it is ok to show off what you can do, but manage your time also 
- we will continue this for a while, so it is not a one-week project - you will have time to build on this later 
- after this we move on to code reviews, meaning, your colleagues will be able to see and review what you submit 
- feel free to ask questions and clarify, PM me on Facebook directly
- most important - have fun
2. For this week you are asked to submit v2.0 of the bot, subject to following changes:
a) consider the border cases (not just a happy case) and make the program fool-proof, which requires you to add validation
b) separate the data from the logic, ensuring the data does not clutter your algorithms, and also is easy(easier) to change
c) consider splitting the code into reusable functions, considering them tools that simplify/shorten the code rather than just steps of the program, such that you can reuse them multiple times (now or later in some other project) or give to somebody else also (it is ok to "trade" functions and work on your bots together, i.e. "i write this function and you write that" - just make sure to add the comment where did it come from)
d) consider reducing clutter and duplication and simplifying the code as well as restructuring/rewriting so that it looks nicer and logically makes more sense
e) if you find bugs or have missing features from before - fix them
f) if you got feedback to act upon or got inspired by ideas from other people - feel free to improve on anything, really
I would encourage you to have a changelog at the top of the file, providing version history, as well as working on the bot using Github and adhering to the workflow proposed there (init, clone, fetch, push, pull, commit, merge, etc), not required, but recommended, especially given that you will do projects later in the course that do require Github, so it makes more sense to get familiar with that as early as possible. If you know it already - use it. If not - find the time somewhere in the course to start (check the links proposed).
Rules for submissions and reviews as they relate to grades will be as for v1.0.
3. The requirements for Chatbot 3.0:
a) split your code into classes, which generally you should design as modules, designed for reuse in other programs; that is, instead of thinking of the class as just a place for code of your current project, think of the class a library you are building for somebody else, to facilitate creating a project similar to that of your own. Following up on this, there has to be at least one class, which has state that is protected (private) from outside use, and methods are used instead; class, which is specifically intended for reuse, meaning, has nicely written methods, also documentation etc.
b) one should aim for purely object-oriented code, that is, all code (except main for C++) should be in some class, and if responsibilities differ - then it means putting the code in separate classes. For the least, one should not confuse UI and logic (aka "front end" and "back end"), and follow the principle of single responsibility. If you need (global) functions - consider using static methods instead. Generally, main (as the application part) should be in a separate file, and there should be one class per file (there can be exceptions if good reasons exist and it makes your code better).
c) one should use exceptions for error handling, more specifically - classes should throw them, and main (or some other place designed for it) has to catch and handle as they come. Code in main should always be within the try block, to handle any unexpected exceptions. You are asked also to create your own exception class (reuse the standard exception clases in the language), which will represent all the custom exceptions from your project (eg. MyProjectException, obviously change the name accordingly).
