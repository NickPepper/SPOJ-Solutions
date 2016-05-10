%%
%% Solution for FCTRL problem
%%
%% ATTENTION!
%% this solution gives the RESULT: time limit exceeded  !!!
%%

-module(factorial). 
-export([main/0]). 

main() -> 
    {ok, [No_of_cases]} = io:fread("", "~d"), 
    loop(No_of_cases). 

loop(0) -> 
    %init:stop(); 
    halt(1); 
loop(No_of_cases) -> 
    {ok, [Number]} = io:fread("", "~d"), 
    ResultFactorial = find_factorial(Number,1), 
    io:format("~p~n",[ResultFactorial]), loop(No_of_cases-1). 

%% nica tail recursion
find_factorial(0,Product) -> 
    Product; 
find_factorial(Number,Product) -> 
    find_factorial(Number-1,Product*Number). 

