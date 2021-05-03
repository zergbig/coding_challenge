     ____          _                  _   _                 _               
    |  _ \ ___  __| |_   _  ___ ___  | \ | |_   _ _ __ ___ | |__   ___ _ __ 
    | |_) / _ \/ _` | | | |/ __/ _ \ |  \| | | | | '_ ` _ \| '_ \ / _ \ '__|
    |  _ <  __/ (_| | |_| | (_|  __/ | |\  | |_| | | | | | | |_) |  __/ |   
    |_| \_\___|\__,_|\__,_|\___\___| |_| \_|\__,_|_| |_| |_|_.__/ \___|_|   
-----------------------------------------------------------------------------
reduce_number.cpp contains the source code for a program that calls the 
stubbed-out function 'int reduce_number(int number)'. The goal of 
reduce_number(int number) is to take the integer passed in, find and remove 
the digit that will result in the lowest remaining integer, and return that 
integer.

Example: If 246 were passed in, reduce_number(246) would remove the digit 6 and
return 24. (Removing 2 would result in 46; removing 4 would result in 26; both
are larger than 24.)

Implement the function reduce_number(int number).

To build your code change to the build directory 
(~/environment/coding_challenge/reduce_number/build/) and run __make__.

To run the executable can be run from the build directory by typing 
__./reduce_number \<some integer\>__. The return result from your 
implementation of 'int reduce_number(int number)' will be displayed.
